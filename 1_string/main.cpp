/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年03月23日 13时44分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  LiLin-Tech
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  segment_ip 
 *  Description:  将一个IP地址分成4个部分
 *  		  分别存储在NIP当中
 * =====================================================================================
 */
void segment_ip(std::string IP)
{
	const static int LENGTH = 4;
	std::string dot(".");
	std::string NIP[LENGTH];
	size_t dotp = 0;
	size_t lp   = 0;
	for ( int i=0;i<LENGTH;i++ )
	{ 	
		dotp = IP.find(dot,dotp+1);
		if ( dotp != std::string::npos )
		{
			NIP[i] = IP.substr(lp,dotp-lp);
			lp = dotp + 1;
		}
		else
			NIP[i] = IP.substr(lp);
		std::cout<<NIP[i]<<std::endl;
	}
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
	/* 
	 *	string 初始化 
	 */
	std::string PRO_VERSION("V1.0.0");
	std::cout<<"string C++ programe"<<std::endl;	
	std::cout<<"Ver: "<<PRO_VERSION<<std::endl;	

	/* 
	 *	substr 截取部分字符串	
	 *	下标从0开始
	 */
	std::string IP("192.168.1.205");
	std::string LastIP = IP.substr(4,3);
	std::cout<<"LastIP: "<<LastIP<<std::endl;

	/* 
	 *	c_str  进行字符串到c字符的转换	
	 */
	printf("IP: %s\n",IP.c_str());

	/* 
	 *	length\at() 过滤每个字符串的字符 
	 */
	int length = IP.length();
	for ( int i=0;i<length;i++ )
		printf("%c\n",IP.at(i));

	/* 
	 *	find 查找某个字符的位置	
	 */
	size_t position = IP.find("168"); 
	printf("position = %ld\n",position);

	/* 
	 *	替换某个字符串	
	 */
	std::string NewIP("166");
	IP.replace(position,3,NewIP);
	printf("IP: %s\n",IP.c_str());

	/* 
	 *	判断字符串是否为空的函数	
	 */
	std::string BlankStr("fff");
	BlankStr.clear();
	if ( BlankStr.empty() )
		printf("BlankStr is empty\n");

	/* 
	 *	分割IP地址
	 */
	segment_ip(IP);

	/* 
	 *	反向查找	
	 */
	std::size_t po = IP.rfind(".");
	printf("rfind po = %ld",po);

	/* 
	 *	部分查找,找到最先查找到字符首位置
	 *	192.166.1.205
	 */
	po = IP.find_first_of("26");
	printf("find first of po = %ld",po);	




	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
