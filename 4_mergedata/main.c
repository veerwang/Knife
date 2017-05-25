/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年05月18日 16时31分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), wwei@landicorp.com 
 *        Company:  landicorp 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

//#define MESG1S( formate,str ) do { printf(formate,str); } while(0)
#define MESG1S( formate,str ) do { ; } while(0)

	static
int calculate_sum_value(const char* file,int* sum)
{
	*sum = 0;
	FILE* fpd = fopen(file,"r");
	if ( fpd == NULL )
	{
		MESG1S ( "open file: %s fail\n",file );
		return -1;
	}
	clearerr(fpd);

	char data;
	size_t num = fread((void *)(&data),1,1,fpd);
	while( num == 1 )
	{
		*sum += data;
		num = fread((void *)(&data),1,1,fpd);
	}

	if ( feof(fpd) )
	{
		fclose(fpd);
		return 0;
	}

	return -1;
}

	static
int attach_sum_value(const char* src,const char* des,int sum)
{
	FILE* fpr = fopen(src,"r");
	if ( fpr == NULL )
	{
		MESG1S ( "open src file: %s fail\n",src );
		return -1;
	}

	FILE* fpd = fopen(des,"w");
	if ( fpd == NULL )
	{
		MESG1S ( "open des file: %s fail\n",des );
		fclose(fpr);
		return -1;
	}

	char tmp[9] = {0};
	sprintf(tmp,"%08x",sum);
	MESG1S (" tmp = %s\n",tmp);

	if ( fwrite(tmp,1,8,fpd) != 8 )
	{
		fclose(fpr);
		fclose(fpd);
		return -1;
	}

	char data;
	size_t num = fread((void *)(&data),1,1,fpr);
	while( num == 1 )
	{
		fwrite(&data,1,1,fpd);
		num = fread((void *)(&data),1,1,fpr);
	}

	if ( feof(fpr) )
	{
		fclose(fpr);
		fclose(fpd);
		return 0;
	}

	fclose(fpr);
	fclose(fpd);
	return -1;
}

	static
int check_sum_value(const char* file)
{
	FILE* fpr = fopen(file,"r");
	if ( fpr == NULL )
	{
		MESG1S ( "open src file: %s fail\n",file );
		return -1;
	}

	char tmp[9] = {0};
	if ( fread(tmp,1,8,fpr) != 8 )
	{
		fclose(fpr);
		return -1;
	}

	int sum = strtol(tmp,NULL,16);
	MESG1S (" read sum = %08x\n",sum);

	char data;
	int nsum = 0;
	size_t num = fread((void *)(&data),1,1,fpr);
	while( num == 1 )
	{
		nsum += data;
		num = fread((void *)(&data),1,1,fpr);
	}
	MESG1S (" !ead sum = %08x\n",nsum);

	if ( feof(fpr) && nsum == sum )
	{
		fclose(fpr);
		return 0;
	}

	fclose(fpr);
	return -1;
}

	static
int dispatch_file(const char* mergefile,const char* disable,const char* enable)
{
	FILE* fpm = fopen(mergefile,"r");
	if ( fpm == NULL )
	{
		MESG1S ( "open src file: %s fail\n",mergefile );
		return -1;
	}

	char tmp[9] = {0};
	if ( fread(tmp,1,8,fpm) != 8 )
	{
		fclose(fpm);
		return -1;
	}

	FILE* fpd = fopen(disable,"w");
	if ( fpd == NULL )
	{
		MESG1S ( "open src file: %s fail\n",disable);
		fclose(fpm);
		return -1;
	}

	int sum = strtol(tmp,NULL,16);
	MESG1S (" dispatch read sum = %08x\n",sum);
	char data;
	size_t num = fread((void *)(&data),1,1,fpm);
	while( num == 1 && sum != 0 )
	{
		fwrite(&data,1,1,fpd);
		sum --;
		num = fread((void *)(&data),1,1,fpm);
	}
	fclose(fpd);

	FILE* fpe = fopen(enable,"w");
	if ( fpe == NULL )
	{
		MESG1S ( "open src file: %s fail\n",enable);
		fclose(fpm);
		return -1;
	}

	fwrite(&data,1,1,fpe);
	num = fread((void *)(&data),1,1,fpm);

	while( num == 1 )
	{
		fwrite(&data,1,1,fpe);
		num = fread((void *)(&data),1,1,fpm);
	}

	if ( feof(fpm) )
	{
		fclose(fpe);
		fclose(fpm);
		return 0;
	}

	fclose(fpm);
	return -1;
}

	static
int get_file_length(const char*file,size_t *length)
{
	FILE* fpd = fopen(file,"r");
	if ( fpd == NULL )
	{
		MESG1S ( "open file: %s fail\n",file);
		return -1;
	}
	if ( fseek(fpd,0,SEEK_END) == 0 )
	{
		*length = ftell(fpd);
		fclose(fpd);
		return 0;
	}
	fclose(fpd);
	return -1;
}

	static
int add_2_files(const char* first,const char* second,const char* mergefile)
{
	FILE* fpf = fopen(first,"r");
	if ( fpf == NULL )
	{
		MESG1S ( "open file: %s fail\n",first);
		return -1;
	}

	FILE* fps = fopen(second,"r");
	if ( fps == NULL )
	{
		MESG1S ( "open file: %s fail\n",second);
		fclose(fpf);
		return -1;
	}

	FILE* fpm = fopen(mergefile,"w");
	if ( fpm == NULL )
	{
		MESG1S ( "open file: %s fail\n",mergefile);
		fclose(fpf);
		fclose(fps);
		return -1;
	}

	char data;
	size_t num = fread((void *)(&data),1,1,fpf);
	while( num == 1 )
	{
		fwrite(&data,1,1,fpm);
		num = fread((void *)(&data),1,1,fpf);
	}

	if ( feof(fpf) )
	{
		num = fread((void *)(&data),1,1,fps);
		while( num == 1 )
		{
			fwrite(&data,1,1,fpm);
			num = fread((void *)(&data),1,1,fps);
		}

		if ( feof(fps) )
		{
			fclose(fpf);
			fclose(fps);
			fclose(fpm);
			return 0;
		}
	}

	fclose(fpf);
	fclose(fps);
	fclose(fpm);
	return -1;
}

	static
int merge_files(const char* disable,const char* enable,const char* mergefile)
{
	size_t length = 0;
	if ( get_file_length(disable,&length) == 0 )
	{
		if ( attach_sum_value(disable,".merge.tmp",length) == 0 )
		{
			if ( add_2_files(".merge.tmp",enable,mergefile) == 0 )
			{
				MESG1S("%s\n","Merge file OK\n");
			}
		}

		unlink(".merge.tmp");
		return 0;
	}
	unlink(".merge.tmp");
	return -1;
}

	static
int restore_file(const char* raw,const char* file)
{
	if ( check_sum_value(raw) == 0 )
	{
		FILE* fpr = fopen(raw,"r");
		if ( fpr == NULL )
		{
			MESG1S ( "open file: %s fail\n",raw);
			return -1;
		}

		FILE* fpf = fopen(file,"w");
		if ( fpf == NULL )
		{
			fclose(fpr);
			return -1;
		}

		fseek(fpr,8,SEEK_SET);  
		char data;
		size_t num = fread((void *)(&data),1,1,fpr);
		while( num == 1 )
		{
			fwrite(&data,1,1,fpf);
			num = fread((void *)(&data),1,1,fpr);
		}

		if ( feof(fpr) )
		{

			fclose(fpf);
			fclose(fpr);
			return 0;
		}
	}

	return -1;
}

static void test()
{
	int value;
	if ( calculate_sum_value("data/emmc_appsboot_disable.mbn",&value) == 0 )
	{
		MESG1S ( "sum value = %08x\n",value );
		//MESG1S ( "new sum value = %08lx\n",strtol("ff",NULL,16) );

		if ( attach_sum_value("data/emmc_appsboot_disable.mbn","1.data",value) == 0 )
		{
			if ( check_sum_value("1.data") == 0 )
			{
				MESG1S("%s\n","OK");
				if ( merge_files("data/emmc_appsboot_disable.mbn","data/emmc_appsboot_enable.mbn","merge.data") == 0 )
				{
					if ( dispatch_file("merge.data","new/disable","new/enable") == 0 )
					{
						MESG1S("%s\n","dispach OK");
						if (restore_file("1.data","data/newdisable") == 0)
							MESG1S("%s\n","restore file");
					}
				}
			}
		}
	}
}



	static
int create_sum_file(const char* file,const char* newfile)
{
	int value;
	if ( calculate_sum_value(file,&value) == 0 )
	{
		if ( attach_sum_value(file,newfile,value) == 0 )
		{
			return 0;
		}
	}

	return -1;
}

	static 
void create_merge_files(const char* disable,const char* enable,const char* merge)
{
	if ( create_sum_file(disable,".disable.tmp") == -1 )
	{
		MESG1S("%s\n","create disable fail");
		unlink(".disable.tmp");
		return;
	}

	if ( create_sum_file(enable,".enable.tmp") == -1 )
	{
		MESG1S("%s\n","create enable fail");
		unlink(".enable.tmp");
		return;
	}

	if ( merge_files(".disable.tmp",".enable.tmp",merge) == -1 )
		MESG1S("%s\n","create merge fail");

	unlink(".disable.tmp");
	unlink(".enable.tmp");
}

	static
void	restore_merge_file(const char* merge,const char* disable,const char* enable)
{
	if ( dispatch_file(merge,".tmp.disable",".tmp.enable") == 0 )
	{
		if ( restore_file(".tmp.disable",disable) == 0 && restore_file(".tmp.enable",enable) == 0 )
		{
			MESG1S("%s\n","restore merge file OK");
		}
	}
	unlink(".tmp.disable");
	unlink(".tmp.enable");
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	MESG1S("%s\n","mergetool v1.0.0");
	// test();

	create_merge_files("data/emmc_appsboot_disable.mbn","data/emmc_appsboot_enable.mbn","merge.data");
	restore_merge_file("merge.data","data/disable","data/enable");
	unlink("merge.data");

	return 0;
}				/* ----------  end of function main  ---------- */
