/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

#include 	<ucl/ucl.h>
#include	"uclmrg.h"

int 
main(int argc, const char *argv[]) {
	std::cout << "ucl test" << std::endl;

	uclmrg uclm;
	if ( uclm.init() ) {
		std::cout << "uclmrg init sccessful" << std::endl;
	}





	uclm.release();


	int r;
	ucl_bytep in;
	ucl_bytep out;
	ucl_uint in_len;
	ucl_uint out_len;
	ucl_uint new_len;
	int level = 5;                  /* compression level (1-10) */



	in_len = 256 * 1024L;

	out_len = in_len + in_len / 8 + 256;

	in = (ucl_bytep) ucl_malloc(in_len);
	out = (ucl_bytep) ucl_malloc(out_len);
	if (in == NULL || out == NULL)
	{
		printf("out of memory\n");
		return 2;
	}

	ucl_memset(in, 0, in_len);

	r = ucl_nrv2b_99_compress(in,in_len,out,&out_len,NULL,level,NULL,NULL);
	if (r == UCL_E_OUT_OF_MEMORY)
	{
		printf("out of memory in compress\n");
		return 3;
	}
	if (r == UCL_E_OK)
		printf("compressed %lu bytes into %lu bytes\n",
				(unsigned long) in_len, (unsigned long) out_len);
	else
	{
		/* this should NEVER happen */
		printf("internal error - compression failed: %d\n", r);
		return 4;
	}
	/* check for an incompressible block */
	if (out_len >= in_len)
	{
		printf("This block contains incompressible data.\n");
		return 0;
	}

	new_len = in_len;
	r = ucl_nrv2b_decompress_8(out,out_len,in,&new_len,NULL);
	if (r == UCL_E_OK && new_len == in_len)
		printf("decompressed %lu bytes back into %lu bytes\n",
				(unsigned long) out_len, (unsigned long) in_len);
	else
	{
		/* this should NEVER happen */
		printf("internal error - decompression failed: %d\n", r);
		return 5;
	}

	ucl_free(out);
	ucl_free(in);


	return EXIT_SUCCESS;
}
