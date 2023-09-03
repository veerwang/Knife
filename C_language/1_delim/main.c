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

/*!
	\brief
	\param[in]
	\param[out]
	\retval
*/
int get_segment(char* source, const char* delim, char segments[][3])
{
	int number = 0;
	char* substr = strtok(source, delim);
	while (substr) {
		strncpy(&(segments[number++][strlen(substr) + 1]), substr, strlen(substr) + 1);
		substr = strtok(NULL, delim);
	}
	return number;
}

int main(void)
{
	char btmac[] = "01:02:03:04:05:06";
	char segments[6][3];
	int num = get_segment(btmac, ":", segments);
	for (int i = 0; i < num; i++) {
		printf("segments[%d]=%s\n", i, &segments[i][3]);
	}
}
