// 피라미드 모양.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int i = 1;
	int j = 1;
	int k = 5;
	int b = 0;
	for (i; i <= 11; i++) {
		if (i % 2 != 0)
			printf("\n");

		j = 1;
		k = 10;
		for (k; k >= (i / 2); k--)
			printf(" ");

		for (j; j <= i; j++) {
			if ((i % 2) != 0)
				printf("*");
		}
	}
	printf("\n");

	for (b; b <= 2; b++) {
		printf("          ***\n");
	}

	printf("\n");
	return 0;
}


