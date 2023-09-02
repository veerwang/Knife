/*!
	\file    main.c
	\brief   学习使用string相关用法

	\version 2023-09-02, V1.0
	\author	 kevin.wang
	\note    none
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char givename[6];
	// 这种初始化是错误的
	// givename = "kevin";

	/// 好似用string.h库文件
	/// 字符串+'\0' = 最少需要的字符个数
	strncpy(givename, "kevin", 6);
	printf("-->%s<--\n", givename);

	/// 这种字符串初始化是OK的
	char familyname[12] = "king ";
	printf("-->%s<--\n", familyname);

	strncat(familyname, givename, strlen(givename));
	/// 注意字符串的长度是不包括 '\0'的
	/// 是5
	printf("length = %ld \n", strlen(givename));
	printf("-->%s<--\n", familyname);

	char thirdname[6] = "kevin";
	if (strncmp(givename, thirdname, strlen(givename)) == 0 ) {
		printf("they are same\n");
	}
	else
		printf("they are different\n");

	/// strndup复制字符串，注意它会自己malloc内存，
	/// 因此使用完之后需要使用free进行释放
	char *npoint = strndup(familyname, 4);
	printf("-->%s<--\n", npoint);
	free(npoint);

	/// 查找substr字符串，如果没有找到则返回空
	char* substr = strstr(familyname, "kegv");
	if (substr != NULL) {
		printf("-->%s<--\n", substr);
	}
}
