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
		system("cls"); // �ܼ� â û��
		this->gameClear(); //���� ����â
		this->menuClear(); //���� �޴�����â
		gameend = this->betting(); //����
		if (gameend == true)
		{
			gameResult == eGameResult_Cancel;
			break;
		}
		this->cardDraw();
	}
	if (gameResult == eGameResult_Cancel)
	{
		cout << "���� ����";
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
* �Է� �Լ�
* @param destBuffer ���ڿ� �Է¹��� ����
* @param nDestBufLength ���ڿ������� �ִ����
* @return true :  �Է��� �� �� ;  false : ESC���� ��� ��
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
		cout << "�󸶸� ���� �Ͻðڽ��ϱ�? : ";
		gotoxy(43, 27);
		if (getUserInput(a, ARRAY_LENGTH(a)) == false)
			return true;
		gotoxy(43, 27);
		cout << a;
		gotoxy(50, 27);
		cout << "                                     ";
		if (isAllNumber(a, strlen(a)) == 0) //����ó��
		{
			menuClear();
			gotoxy(15, 27);
			cout << "���: ���ñݾ��� ����� �Է����ּ���!!!!!( ex: 500 )";
			Sleep(1000);
			menuClear();
		}
		else
		{
			player.subMoney(atoi(a));
			menuClear();//�޴� ������Ʈ
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
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t         Ÿ��Ʋȭ��:esc" << endl;	                                                             
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
	cout << "                                                                                                         Ÿ��Ʋȭ��:esc \n";
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
	cout << "�޼���";
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
	cout << "���� �ݾ�: " << player.getMoney();
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
	cout << "�޼���";
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
	cout << "���� �ݾ�: " << player.getMoney();
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
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ鰡������
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