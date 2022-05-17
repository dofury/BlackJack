#include "Game.h"
#include<Windows.h>
#include<iostream>
#include<conio.h>
#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_BACKSPACE 8
#define ARRAY_LENGTH(array)  (sizeof(array)/sizeof(array[0]))
using namespace std;
Game::Game()
{
	player.setMoney(1000);
	card[0] = 'A';

}
Game::~Game()
{
	
}
void Game::gameStart()
{
	bool gameend = false;
	while (gameend == false)
	{
		system("cls"); // 콘솔 창 청소
		this->gameClear(); //게임 상태창
		this->menuClear(); //게임 메뉴상태창
		gameend = this->betting(); //베팅
		if (gameend == true)
		{
			gameResult == eGameResult_Cancel;
			break;
		}
		this->cardDraw();
	}
	if (gameResult == eGameResult_Cancel)
	{
		cout << "게임 종료";
	}
}
eGameResult Game::getGameResult()
{
	return gameResult;
}
void myPutChar(char curValue) {
	if (curValue == KEY_BACKSPACE){
		_putch(KEY_BACKSPACE);
		_putch(' ');
		_putch(KEY_BACKSPACE);
	}
	else {
		_putch(curValue);
	}

}
/**
* 입력 함수
* @param destBuffer 문자열 입력받을 버퍼
* @param nDestBufLength 문자열버퍼의 최대길이
* @return true :  입력이 잘 됨 ;  false : ESC눌러 취소 됨
*/
bool getUserInput(char* destBuffer,int nDestBufLength) {
	char currentInput;
	int i = 0;
	destBuffer[0] = '\0';
	while ((i < nDestBufLength-1) && (currentInput = _getch())) {
		if (currentInput == KEY_ENTER)        break;
		else if (currentInput == KEY_ESC)  return false;
		else if (currentInput == KEY_BACKSPACE)
		{
			if (i > 0)
			{
				i--;
				if(i==0)
					myPutChar(currentInput);
			}
		}
		else
		{
			destBuffer[i] = currentInput;
			i++;
		}
		if (i > 0)
			myPutChar(currentInput);
	}
	destBuffer[i] = '\0';
	return true;
}
bool Game::betting()
{
	char a[256];
	while (1)
	{
		gotoxy(15, 27);
		cout << "얼마를 베팅 하시겠습니까? : ";
		gotoxy(43, 27);
		if (getUserInput(a, ARRAY_LENGTH(a)) == false)
			return true;
		gotoxy(43, 27);
		cout << a;
		gotoxy(50, 27);
		cout << "                                     ";
		if (isAllNumber(a, strlen(a)) == 0) //예외처리
		{
			menuClear();
			gotoxy(15, 27);
			cout << "경고: 베팅금액을 제대로 입력해주세요!!!!!( ex: 500 )";
			Sleep(1000);
			menuClear();
		}
		else
		{
			player.subMoney(atoi(a));
			menuClear();//메뉴 업데이트
			break;
		}
	}
	return false;
}
int Game::isAllNumber(char* input,int length)
{
	for (int i = 0; i < length; i++)
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return 0;
	}
	return 1;
}
void Game::gameDraw()
{
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
}
void Game::gameClear()
{
	cout << "                                                                                                         타이틀화면:esc \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                      	 \n";
	cout << "              	                                                                                                      	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
	cout << "              	                                                                                                     	 \n";
}
void Game::menuDraw()
{
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
void Game::menuClear()
{
	gotoxy(0, 24);
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
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
void Game::cardDraw()
{
	menuClear();
}
//int Game::keyDraw()
//{
//	while (1) {
//		int n = keyControl();
//		if (n == TITLE)
//			return TITLE;
//	}
//}
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
	temp = _getch();
	if (temp == KEY_ESC)
	{
		return 1;
	}
	return 0;
}
void Game::playerWin()
{

}
void Game::dealerWin()
{

}