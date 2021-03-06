// firstgame(last): 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
#include <windows.h>

char cTileMap[225] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,
	1,0,0,1,1,1,0,0,7,0,0,0,1,0,1,
	1,0,0,1,1,1,0,0,1,0,0,6,1,0,1,
	1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,8,0,0,1,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,7,0,0,1,
	1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,1,0,0,10,0,0,0,0,1,1,0,0,1,
	1,10,0,0,0,10,0,1,0,0,1,1,0,0,1,
	1,0,1,0,0,1,0,1,1,0,0,2,1,0,1,
	1,1,1,1,1,1,0,0,1,0,0,2,1,0,1,
	1,0,0,0,0,7,0,0,1,1,1,1,1,0,3,
	1,0,0,0,0,1,0,0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const char *Tileset[] = {
	"  ", //0
	"■", //1
	"Ⅰ", //2
	"□", //3
	"♀", //4
	"▩", //5
	"☎", //6
	"▣", //7
	"⊙", //8
	"♠", //9
	"▥", //10
	"￥", //11
	"＃", //12
	"♨"  //13
};

// 플레이어 오브젝트
int g_nPlayerPosX, g_nPlayerPosY;

void dump() {
	cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] = 9;

	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++) {
			printf("%s", Tileset[cTileMap[x + y * 15]]);
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
		int getItem = 0;
		int noReset = 0;
		int swDoor = 0;
		int sw = 1;
		int swBl = 0;
		int box = 0;
		int boxEn = 0;
		int fire = 0;
		int getfire = 0;
		int boom = 0;
		int sel = 0;
		int yes = 0;
		int ash = 0;

		printf("명령어 : ");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) {
			printf_s("프로그램을 종료합니다. \n");
			break;
		}
		else if (strcmp("reset", szCmd) == 0) {
			g_nPlayerPosX = 1;
			g_nPlayerPosY = 3;
			cTileMap[194] = 3;
			cTileMap[176] = 2;
			cTileMap[161] = 2;
			cTileMap[146] = 1;
			cTileMap[145] = 1;
			cTileMap[131] = 1;
			cTileMap[130] = 1;

			system("cls");
			dump();
		}
		else if (strcmp("start", szCmd) == 0) {
			system("cls");
			while (1) {
				int res = g_nPlayerPosX + g_nPlayerPosY * 15;
				int xres = g_nPlayerPosX;
				int yres = g_nPlayerPosY;
				char tr;

				dump();
				if (bl == 1) {
					system("cls");
					dump();
					printf("벽에 막혀 지나갈 수 없다. \n");
					bl = 0;
				}
				if (key == 1) {
					system("cls");
					dump();
					printf("열쇠를 얻었다. \n");
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
				if (getItem == 1) {
					system("cls");
					dump();
					if (noReset == 0) {
						noReset = 1;
						getItem = 0;
						printf("아이템의 위치가 확인 되었습니다. \n");
					}
					else if (noReset == 1) {
						getItem = 0;
						printf("아이템의 위치가 이미 확인 되었습니다. 탈출해보세요 \n");
					}
				}
				if (swDoor == 1) {
					system("cls");
					dump();
					printf("문이 닫혀있어서 지나갈 수 없다. 열 방법을 찾아보자. \n");
					swDoor = 0;
				}
				if (swBl == 1) {
					system("cls");
					dump();
					printf("스위치를 눌렀다. \n");
					printf("어딘가 문이 열린것 같다. \n");
					swBl = 0;
				}
				if (box == 1) {
					system("cls");
					dump();
					if (boxEn == 0) {
						box = 0;
						printf("박스를 밀었다. \n");
					}
					else if (boxEn == 1) {
						box = 0;
						boxEn = 0;
						printf("박스를 밀 수 없다. \n");
					}
				}
				if (fire == 1) {
					system("cls");
					dump();
					printf("라이터를 얻었다. \n");
					fire = 0;
					getfire = 1;
				}
				if (boom == 1) {
					system("cls");
					dump();
					if (getfire == 0) {
						printf("도화선인 것 같다. \n");
						boom = 0;
					}
					else if (getfire == 1) {
						char b;
						printf("도화선에 불을 붙일까? (y, n)");
						scanf_s("%c", &b, 1 );
						scanf_s("%c", &b, 1 );
						boom = 0;
						if (b == 'n') {
							sel = 1;
							yes = 0;
						}
						else if (b == 'y') {
							sel = 1;
							yes = 1;
						}
						else printf("잘못된 입력입니다. \n");

					}
				}
				if (sel == 1) {
					system("cls");
					dump();
					if (yes == 0) {
						printf("조금 더 생각해보기로 했다. \n");
						sel = 0;
						Sleep(1000);
						system("cls");
					}
					else if (yes == 1) {
						sel = 0;
						printf("도화선에 불을 붙였다. \n");
						cTileMap[205] = 0;
						Sleep(1000);
						system("cls");
						dump();

						cTileMap[176] = 0;
						Sleep(1000);
						system("cls");
						dump();

						cTileMap[161] = 0;
						Sleep(1000);
						system("cls");
						dump();

						cTileMap[146] = 13;
						cTileMap[145] = 13;
						cTileMap[131] = 13;
						cTileMap[130] = 13;
						Sleep(1000);
						system("cls");
						dump();

						printf("폭탄이 터지는 소리가 났다. \n");
						Sleep(1000);
						system("cls");
					}
					continue;
				}
				if (ash == 1) {
					system("cls");
					dump();
					ash = 0;
					printf("밟으면 안될것 같다. \n");
				}

				printf("이동 : ");
				scanf_s("%c", &tr, 1);

				scanf_s("%c", &a, 1);

				if (a == 'q') {
					printf("게임 종료 \n");
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
				else {
					system("cls");
					continue;
				}

				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 1) { // 벽 막힘
					g_nPlayerPosX = xres;
					g_nPlayerPosY = yres;
					bl = 1;
					continue;
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 4) { // 열쇠
					key = 1;
					cTileMap[res] = 0;
					continue;
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 5) { // 문
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
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 6) { //아이템 확인
					if (noReset == 0) {
						g_nPlayerPosX = xres;
						g_nPlayerPosY = yres;
						cTileMap[28] = 4;
						cTileMap[196] = 11;
						cTileMap[205] = 12;
						getItem = 1;
						continue;
					}
					else if (noReset == 1) {
						g_nPlayerPosX = xres;
						g_nPlayerPosY = yres;
						getItem = 1;
						continue;
					}
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 7) { // swDoor 막힘
					g_nPlayerPosX = xres;
					g_nPlayerPosY = yres;
					swDoor = 1;
					continue;
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 8) { // 스위치
					if (sw == 1) {
						g_nPlayerPosX = xres;
						g_nPlayerPosY = yres;
						cTileMap[38] = 0;
						cTileMap[101] = 7;
						cTileMap[185] = 7;
						sw = 2;
						swBl = 1;
						continue;
					}
					else if (sw == 2) {
						g_nPlayerPosX = xres;
						g_nPlayerPosY = yres;
						cTileMap[38] = 7;
						cTileMap[101] = 0;
						cTileMap[185] = 7;
						sw = 3;
						swBl = 1;
						continue;
					}
					else if (sw == 3) {
						g_nPlayerPosX = xres;
						g_nPlayerPosY = yres;
						cTileMap[38] = 7;
						cTileMap[101] = 7;
						cTileMap[185] = 0;
						sw = 1;
						swBl = 1;
						continue;
					}
					else if (sw == 3) {
						g_nPlayerPosX = xres;
						g_nPlayerPosY = yres;
						sw = 1;
						continue;
					}
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 10) { // 박스 밀기
					cTileMap[res] = 0;
					box = 1;
					switch (a) {
					case 'w':
						if (cTileMap[g_nPlayerPosX + (g_nPlayerPosY - 1) * 15] == 0
							|| cTileMap[g_nPlayerPosX + (g_nPlayerPosY - 1) * 15] == 13 ) {
							cTileMap[g_nPlayerPosX + (g_nPlayerPosY - 1) * 15] = 10;
							break;
						}
						else {
							g_nPlayerPosX = xres;
							g_nPlayerPosY = yres;
							boxEn = 1;
							break;
						}
					case 's':
						if (cTileMap[g_nPlayerPosX + (g_nPlayerPosY + 1) * 15] == 0
							|| cTileMap[g_nPlayerPosX + (g_nPlayerPosY + 1) * 15] == 13 ) {
							cTileMap[g_nPlayerPosX + (g_nPlayerPosY + 1) * 15] = 10;
							break;
						}
						else {
							g_nPlayerPosX = xres;
							g_nPlayerPosY = yres;
							boxEn = 1;
							break;
						}
					case 'a' :
						if (cTileMap[(g_nPlayerPosX - 1) + g_nPlayerPosY * 15] == 0
							|| cTileMap[(g_nPlayerPosX - 1) + g_nPlayerPosY * 15] == 13 ) {
							cTileMap[(g_nPlayerPosX - 1) + g_nPlayerPosY * 15] = 10;
							break;
						}
						else {
							g_nPlayerPosX = xres;
							g_nPlayerPosY = yres;
							boxEn = 1;
							break;
						}
					case 'd' :
						if (cTileMap[(g_nPlayerPosX + 1) + g_nPlayerPosY * 15] == 0
							|| cTileMap[(g_nPlayerPosX + 1) + g_nPlayerPosY * 15] == 13 ) {
							cTileMap[(g_nPlayerPosX + 1) + g_nPlayerPosY * 15] = 10;
							break;
						}
						else {
							g_nPlayerPosX = xres;
							g_nPlayerPosY = yres;
							boxEn = 1;
							break;
						}
					}
					continue;
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 11) { // 점화도구
					fire = 1;
					cTileMap[res] = 0;
					continue;
				}

				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 12) { // 점화
					g_nPlayerPosX = xres;
					g_nPlayerPosY = yres;
					boom = 1;
					continue;
				}
				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 13) { // 재
					g_nPlayerPosX = xres;
					g_nPlayerPosY = yres;
					ash = 1;
					continue;
				}

				if (cTileMap[g_nPlayerPosX + g_nPlayerPosY * 15] == 3) { // 탈출
					cTileMap[res] = 0;
					dump();
					printf("탈출했습니다. \n");
					last = res;
					break;
				}

				cTileMap[res] = 0; // 잔상 처리

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

