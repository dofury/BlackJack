#include "Title.h"
#include<Windows.h>
#include<iostream>
#include<conio.h>
#define UP 1
#define DOWN 2
#define SUBMIT 3
using namespace std;
void Title::init()//âũ�� ���� �Լ�
{
	system("mode con cols=120 lines=30 | title BLACK JACK");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ鰡������
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false �Ǵ� 0: �����
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void Title::titleDraw()//Ÿ��Ʋǥ�� �Լ�
{
	system("cls");//�ܼ�ȭ�� �ʱ�ȭ
	cout << "\n\n\n\n";
	cout << "                                           .                                   .                     \n";
	cout << "                        RBBBBBi vBB      :BBB.   2BBBg  :Bq  QBq     BBBBQ1  BBBB   .BBBB7  BB  IBB  \n";
	cout << "                        BB. QBb LBB      BBjBB  .BBPBBQ .BBEBBv      . MBg   BggB7  BBQZBBr BBIBBZ   \n";
	cout << "                        BBBMBB. iQQ      BB BB  BBb     .BBQr          7BE  ZQ: BB .BB      BBBg     \n";
	cout << "                        BB: 2BQ .Bg     EBBBBBs QBB YBQ .BBBBv       . JBQ  BBBBBB  BBv gBr BBBBP    \n";
	cout << "                        BBBBBBB .BBBBBB BB. .QB  BBBBBX :BB KBBu    YBBBB: SBM  dB2 rBBBBQ  BB :BBB  \n";
	cout << "                         :..      .i:r: P.   :1    :.    g    v.     .r:   r2    ji   .:.   IL   rr  \n";
}
int Title::keyDraw()
{
	x = 60;
	y = 20;
	gotoxy(x - 2, y);
	cout << "> ���ӽ���";
	gotoxy(x, y + 1);
	cout << "��������";
	gotoxy(x, y + 2);
	cout << "����";
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 20) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 22) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		case SUBMIT: {
			return y - 19;
		}


		}
		}
	}
}
void Title::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ鰡������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
int Title::keyControl()
{
	int temp;
	temp = _getch();
	if (temp == 224)
	{
		temp = _getch();
		if (temp == 72) {
			return UP;
		}
		else if (temp == 80) {
			return DOWN;
		}
	}
	else if (temp == 32) {
		return SUBMIT;
	}
}
