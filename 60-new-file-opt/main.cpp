/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年09月04日 
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
#include	<cstring>
#include 	<iostream>

#include	<vector>

#include	"fileopt.h"

int 
main(int argc, const char *argv[]) {
	std::cout << "File Opt" << std::endl;	

	/*
	WFile *wf = new WFile("README");
	ZFile::this_string msg = "hello the world 我进行的测试 abc";
	wf->Write(msg);
	msg = " 春眠不觉晓，处处闻啼鸟";
	wf->Write(msg);
	delete wf;
	wf = NULL;

	RFile *zf = new RFile("README");
	std::cout << "File Length = " << zf->GetFileLength() << std::endl;
	std::cout << "File Path = " << zf->GetPath() << std::endl;

	msg = "";
	zf->Read(msg,10,20);
	std::cout << msg << std::endl;

	std::cout << "---------" << std::endl;

	std::vector<char> buf;
	zf->ReadAll(buf);
	for (auto a : buf) {
		std::cout << a;
	}

	delete zf;
	zf = NULL;
	*/

	RFile *zf = new RFile("README");
	std::cout << "File Length = " << zf->GetFileLength() << std::endl;
	std::cout << "File Path = " << zf->GetPath() << std::endl;
	std::vector<char> buf;
	zf->ReadAll(buf);
	for (auto a : buf) {
		std::cout << a;
	}
	delete zf;
	zf = NULL;

	return EXIT_SUCCESS;
}
