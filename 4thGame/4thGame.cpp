// thirdgame: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
#include <windows.h>

char cTileMap[100] = {
	1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,4,1,
	1,0,0,1,1,1,0,1,0,1,
	1,0,0,1,1,1,0,1,0,1,
	1,1,1,1,1,1,0,1,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,1,1,1,1,1,1,1,
	1,5,1,1,1,1,0,0,0,3,
	1,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1
};

const char *Tileset[] = {
	"  ", //0
	"■", //1
	"∫", //2
	"□", //3
	"♀", //4
	"▥", //5
	"  ", //6
	"  ", //7
	"  ", //8
	"♠", //9
};

// 플레이어 오브젝트
int g_nPlayerPosX, g_nPlayerPosY;

void dump() {
	cTileMap[g_nPlayerPosX + g_nPlayerPosY * 10] = 9;

	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			printf("%s", Tileset[cTileMap[x + y * 10]]);
		}
		printf("\n");
	}

}


int main()
{
	g_nPlayerPosX = 1;
	g_nPlayerPosY = 3;
	char szCmd[32];
	char a;

	dump();

	while (1) {
		int last;
		int key = 0;
		int bl = 0;
		int getkey = 0;
		int door = 0;
		printf("명령어 : ");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) {
			printf_s("프로그램을 종료합니다. \n");
			break;
		}
		else if (strcmp("reset", szCmd) == 0) {
			g_nPlayerPosX = 1;
			g_nPlayerPosY = 3;
			cTileMap[18] = 4;
			cTileMap[71] = 5;
			cTileMap[79] = 3;
			system("cls");
			cTileMap[last] = 0;
			dump();
		}
		else if (strcmp("move", szCmd) == 0) {
			system("cls");
			while (1) {
				int res = g_nPlayerPosX + g_nPlayerPosY * 10;
				int xres = g_nPlayerPosX;
				int yres = g_nPlayerPosY;
				char tr;

				dump();
				if (bl== 1) {
					system("cls");
					dump();
					printf("벽에 막혀 지나갈수 없습니다. \n");
					bl = 0;
				}
				if (key == 1) {
					system("cls");
					dump();
					printf("열쇠를 얻었습니다. \n");
					key = 0;
					getkey = 1;
				}
				if (door == 1) {
					system("cls");
					dump();
					if (getkey == 0) {
						printf("열쇠가 필요합니다. \n");
						door = 0;
					}
					if (getkey == 1) {
						printf("문이 열렸습니다. \n");
						door = 0;
					}
				}

				printf("입력시작 : ");
				scanf_s("%c", &tr, 1);

				scanf_s("%c", &a, 1);

				if (a == '`') {
					printf("move 종료 \n");
					last = res;
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
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 10] == 1) {
					g_nPlayerPosX = xres;
					g_nPlayerPosY = yres;
					bl = 1;
					continue;
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 10] == 4) {
					key = 1;
					cTileMap[res] = 0;
					continue;
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 10] == 5) {
					if (getkey == 0) {
						g_nPlayerPosX = xres;
						g_nPlayerPosY = yres;
						door = 1;
						continue;
					}
					else if (getkey == 1) {
						door = 1;
						cTileMap[res] = 0;
						continue;
					}
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 10] == 3) {
					cTileMap[res] = 0;
					dump();
					printf("탈출했습니다. \n");
					last = res;
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
			printf_s("%s는 잘못된 명령입니다. \n", szCmd);
		}

	}
	return 0;
}

