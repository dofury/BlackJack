#include "Game.h"
#include<Windows.h>
#include<iostream>
#include<conio.h>
#define TITLE 4
using namespace std;
Game::Game()
{
	player.setMoney(1000);
	card[0] = 'A';

}
Game::~Game()
{
	
}
void Game::betting()
{
	gotoxy(15, 27);
	cout << "얼마를 베팅 하시겠습니까?: ";
	gotoxy(50, 27);
	cin >> call;
	player.subMoney(call);
}
void Game::gameDraw()
{
	system("cls");//콘솔화면 초기화
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t         타이틀화면:esc" << endl;	                                                             
	cout << "                                                                           	 \n";
	cout << "                             .MBBb .5U                                     	 \n";
	cout << "                            1BBMMBQBBBBB5                                  	 \n";
	cout << "                            BBr  SB2  KQBB:                                	 \n";
	cout << "                            BB   IBb    2BBS                               	 \n";
	cout << "                            BB    QBI     BQI                              	 \n";
	cout << "                            JBE    BBE     BBi                             	 \n";
	cout << "                            rQBBBBBBBBBBBBQQBB7                            	 \n";
	cout << "                        SQQBBBQQgbXUYjUXqEgRQBBBBQ5                        	 \n";
	cout << "                     5BBBBQ5.                 :XQBBBBX                     	 \n";
	cout << "                   bBBBd.                          dBBBD                   	 \n";
	cout << "                 IBQB7                               rQBBd                 	 \n";
	cout << "                QBBr                                   .QBBI               	 \n";
	cout << "              .BBP                                       rBBM              	 \n";
	cout << "             .BBu                                          gBB             	 \n";
	cout << "             BBj              BZ                            XBB            	 \n";
	cout << "            EBK    .          BB         :gBP                IBB           	 \n";
	cout << "            BQ   IBBBK     .BBBBBB7      QBBBI:vJr            qBQ          	 \n";
	cout << "           PBS uiKBBBP      SJ  .:       igBPvLJsUU            QQK         	 \n";
	gotoxy(0, 24);
	cout << "------------------------------------------------------------------------------------------------------------------------";
	gotoxy(3, 27);
	cout << "메세지";
	gotoxy(12, 25);
	cout << "|";
	gotoxy(12, 26);
	cout << "|";
	gotoxy(12, 27);
	cout << "|";
	gotoxy(12, 28);
	cout << "|";
	gotoxy(12, 29);
	cout << "|";
	gotoxy(90, 27);
	cout << "보유 금액: " << player.getMoney();
}
int Game::keyDraw()
{
	while (1) {
		int n = keyControl();
		if (n == TITLE)
			return TITLE;
	}
}
void Game::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//콘솔 핸들가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
int Game::keyControl()
{
	int temp;
	if (_kbhit())
	{
		temp = _getch();
		if (temp == 27)
		{
			return TITLE;
		}
	}
}
void Game::playerWin()
{

}
void Game::dealerWin()
{

}