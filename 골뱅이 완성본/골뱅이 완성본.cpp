// 골뱅이3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char ary[100];
	printf("문자열 입력 : ");
	scanf_s("%s", ary, sizeof(ary));
	printf("원 문자열 : \n");

	int arysize = sizeof(ary) / sizeof(ary[0]);
	int length = 0;

	for (int i = 0; i < arysize; i++) {
		if (ary[i] == 0x00) break;
		length++;
	}
	int F = 0;
	for (int j = 0; j < length; j++) {
		if (F == 0) {
			if (ary[j] == '@') {
				F = 1;
				printf("%c", '@');
				continue;
			}
			printf("%c", ary[j]);
		}
		else if (F == 1) {
			if (ary[j] == '@') {
				printf("%c", '@');
				F = 0;
				continue;
			}
			printf("%c", '*');
		}
	}
	printf("\n");

	return 0;
}


