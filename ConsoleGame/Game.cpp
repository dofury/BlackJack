#include "Game.h"
#include "Utility.h"
using namespace std;
Utility util;
Game::Game()
{
	player.setMoney(1000);
	player.setCard(0);
	player.setCardSum(0);
	cardSetAmount = 13; // �������缼Ʈ ī�� ����
	for (int i = 0; i < 52; i++) {
		card[i].number = (i%cardSetAmount)+1;
	}
	for (int i = 0; i < 52; i++) {
		if(i<13)
			card[i].mark = "��";
		else if(i < 26)
			card[i].mark = "��";
		else if (i < 39)
			card[i].mark = "��";
		else if (i < 52)
			card[i].mark = "��";
	}
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
		gameClear(); //���� ����â
		menuClear(); //���� �޴�����â
		gameend = betting(); //����
		if (gameend == true)
		{
			gameResult = eGameResult_Cancel;
			break;
		}
		gameLoading();
		gameend = cardDraw();
		if (gameend == true)
		{
			gameResult = eGameResult_Cancel;
			break;
		}
	}
	if (gameResult == eGameResult_Cancel)
	{
		menuClear();
		gotoxy(15, 27);
		cout << "���� ������...";
		Sleep(1000);

	}
}
eGameResult Game::getGameResult()
{
	return gameResult;
}
string Game::getDrawCNum()
{
	switch (player.getCard())
	{
		case 1:
			{
				return "A";
			}break;
		case 2:
			{
				return "2";
			}break;
		case 3:
			{
				return "3";
			}break;
		case 4:
			{
				return "4";
			}break;
		case 5:
			{
				return "5";
			}break;
		case 6:
			{
				return "6";
			}break;
		case 7:
			{
				return "7";
			}break;
		case 8:
			{
				return "8";
			}break;
		case 9:
			{
				return "9";
			}break;
		case 10:
			{
				return "10";
			}break;
		case 11:
			{
				return "J";
			}break;
		case 12:
			{
				return "Q";
			}break;
		case 13:
			{
				return "K";
			}break;
	}
}
void Game::gameLoading()
{
	menuClear();
	gotoxy(15, 27);
	cout << "�� ������ ���� �˴ϴ�...";
	Sleep(1000);
	menuClear();
	gotoxy(15, 27);
	cout << "3...";
	Sleep(1000);
	menuClear();
	gotoxy(15, 27);
	cout << "2...";
	Sleep(1000);
	menuClear();
	gotoxy(15, 27);
	cout << "1...";
	Sleep(1000);
}
bool Game::betting()
{
	char input[256];
	while (1)
	{
		menuClear();//�޴� û��
		gotoxy(15, 27);
		cout << "�󸶸� ���� �Ͻðڽ��ϱ�? : ";
		gotoxy(43, 27);
		if (util.getUserInput(input, ARRAY_LENGTH(input)) == false)
			return true;
		if (isAllNumber(input, strlen(input)) == 0) //����ó��
		{
			menuClear();
			gotoxy(15, 27);
			cout << "���: ���ñݾ��� ����� �Է����ּ���!!!!!( ex: 500 )";
			Sleep(1000);
		}
		else
		{
			if (player.subMoney(atoi(input)) == false)//
			{
				menuClear();//�޴� û��
				gotoxy(15, 27);
				cout << "���: ���ñݾ��� �����մϴ�!!!!!";
				Sleep(1000);
			}
			else
			{
				break;
			}
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
void Game::gameDraw(int x,int y)
{
	gotoxy(x, y++);
	cout << "��    ��";
	gotoxy(x, y++);
	cout << " " << player.getMark();
	gotoxy(x, y++);
	cout << "   " << getDrawCNum() << "    ";
	gotoxy(x, y++);
	cout << "    " << player.getMark();
	gotoxy(x, y);
	cout << "��    ��";
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
bool Game::cardDraw()
{
	int count = 0;
	int progress = 0;
	bool drawRepeat = true;
	char input[256];
	do
	{
		menuClear();
		if (drawRepeat == true)
		{
			gameCard randomTemp = randomCard(count);
			player.setCard(randomTemp.number);
			player.setMark(randomTemp.mark);
			player.setCardSum(player.getCardSum() + player.getCard());
			gameDraw(1,1);
			drawRepeat = false;
		}
		else
		{
			gotoxy(15, 27);
			cout << "ī�带 �� ��ο� �Ͻðڽ��ϱ�? : <- [yes] -> [no] ";
			gotoxy(60, 27);
			progress = util.getUserInput_s();
			if (progress == eGameProgress_Exit)
				return eGameResult_Exit;
			else if (progress == eGameProgress_Select1)
				drawRepeat = true;
			else if (progress == eGameProgress_Select2)
				return false;
		}
		//esc true ��ȯ <- �ݺ�, -> fasle ��ȯ
		count++;
	}while(1);
	return false;
}
gameCard Game::randomCard(int turn)
{
	srand(time(NULL));
	int random = rand() % (52 - turn);//card �迭�� �ε����� �� ���� �������� �̴´�.

	//���� ī��� �迭 ������ �о��.
	for (int j = random; j < 52; j++) {
		if (j + 1 < 52) {
			gameCard tempNum = card[j];
			card[j] = card[j + 1];
			card[j + 1] = tempNum;
		}
	}
	return card[random];// ���� ī�带 �����Ѵ�
}
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