
#include "stdafx.h"


int main()
{
	char ary[100];
	int i = 0;
	int j = 0;
	printf("문자를 입력하세요 => ");
	scanf_s("%s", ary, sizeof(ary));
	printf("원 문자열 : %s \n", ary);

	int chsize = 0;

	int arysize = sizeof(ary) / sizeof(ary[0]);

	for (i; i < arysize; i++) {
		if (ary[i] == 0x00)
			break;
		chsize++;
	}
	int d = chsize / 2;
	int k = chsize - 1;
	char tp;

	for (j; j < d; j++) {
		tp = ary[j];
		ary[j] = ary[k];
		ary[k] = tp;
		k--;
	}
	printf("바뀐문자열 : %s \n", ary);


	return 0;
}