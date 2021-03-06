// thirdgame: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
#include <windows.h>

char cTileMap[64] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,0,0,0,0,1,
	1,0,0,0,1,1,1,1,
	1,0,0,0,0,0,0,3,
	1,1,1,1,1,1,1,1
};

const char *Tileset[] = {
	"  ", //0
	"■", //1
	"∫", //2
	"□", //3
	"  ", //4
	"  ", //5
	"  ", //6
	"  ", //7
	"  ", //8
	"♂", //9
};

// 플레이어 오브젝트
int g_nPlayerPosX, g_nPlayerPosY;

void dump() {
	cTileMap[g_nPlayerPosX + g_nPlayerPosY * 8] = 9;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			printf("%s", Tileset[cTileMap[x + y * 8]]);
		}
		printf("\n");
	}

}


int main()
{
	g_nPlayerPosX = 3;
	g_nPlayerPosY = 3;
	char szCmd[32];
	char a;
	
	dump();

	while (1) {

		printf("명령어 : ");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) {
			printf_s("프로그램을 종료합니다. \n");
			break;
		}
		else if (strcmp("push", szCmd) == 0) {

		}
		else if (strcmp("move", szCmd) == 0) {
			system("cls");
			while (1) {
				dump();

				int res = g_nPlayerPosX + g_nPlayerPosY * 8;
				int xres = g_nPlayerPosX;
				int yres = g_nPlayerPosY;
				char tr;
				printf("입력시작 : ");
				scanf_s("%c", &tr, 1);

				scanf_s("%c", &a, 1);

				if (a == '`') {
					printf("move 종료 \n");
					break;
				}
				else if (a == 'w') {
					g_nPlayerPosY--;
					system("cls");
				}
				else if (a == 's') {
					g_nPlayerPosY++;
					system("cls");
				}
				else if (a == 'a') {
					g_nPlayerPosX--;
					system("cls");
				}
				else if (a == 'd') {
					g_nPlayerPosX++;
					system("cls");
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 8] == 1) {
					g_nPlayerPosX = xres;
					g_nPlayerPosY = yres;
					dump();
					printf("벽에 막혀 지나갈수 없습니다. \n");
					break;
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 8] == 3) {
					cTileMap[res] = 0;
					dump();
					printf("탈출했습니다. \n");
					break;
				}
				cTileMap[res] = 0;

			}
		}
		else if (strcmp("dump", szCmd) == 0) {
			system("cls");
			dump();
		}
		else {
			printf_s("입력하신 커맨드는 : %s입니다. \n", szCmd);
		}

	}
	return 0;
}

