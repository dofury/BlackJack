#include "Game.h"
#include "Utility.h"
using namespace std;
Utility util;
Game::Game()
{
	player.setMoney(1000);
	player.setCard(0);
	player.setCardSum(0);
	cardSetAmount = 13; // 같은문양세트 카드 갯수
	for (int i = 0; i < 52; i++) {
		card[i].number = (i%cardSetAmount)+1;
	}
	for (int i = 0; i < 52; i++) {
		if(i<13)
			card[i].mark = "♠";
		else if(i < 26)
			card[i].mark = "◆";
		else if (i < 39)
			card[i].mark = "♥";
		else if (i < 52)
			card[i].mark = "♣";
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
		system("cls"); // 콘솔 창 청소
		gameClear(); //게임 상태창
		menuClear(); //게임 메뉴상태창
		gameend = betting(); //베팅
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
		cout << "게임 종료중...";
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
	cout << "곧 게임이 시작 됩니다...";
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
		menuClear();//메뉴 청소
		gotoxy(15, 27);
		cout << "얼마를 베팅 하시겠습니까? : ";
		gotoxy(43, 27);
		if (util.getUserInput(input, ARRAY_LENGTH(input)) == false)
			return true;
		if (isAllNumber(input, strlen(input)) == 0) //예외처리
		{
			menuClear();
			gotoxy(15, 27);
			cout << "경고: 베팅금액을 제대로 입력해주세요!!!!!( ex: 500 )";
			Sleep(1000);
		}
		else
		{
			if (player.subMoney(atoi(input)) == false)//
			{
				menuClear();//메뉴 청소
				gotoxy(15, 27);
				cout << "경고: 베팅금액이 부족합니다!!!!!";
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
	cout << "┌    ┐";
	gotoxy(x, y++);
	cout << " " << player.getMark();
	gotoxy(x, y++);
	cout << "   " << getDrawCNum() << "    ";
	gotoxy(x, y++);
	cout << "    " << player.getMark();
	gotoxy(x, y);
	cout << "└    ┘";
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
			cout << "카드를 더 드로우 하시겠습니까? : <- [yes] -> [no] ";
			gotoxy(60, 27);
			progress = util.getUserInput_s();
			if (progress == eGameProgress_Exit)
				return eGameResult_Exit;
			else if (progress == eGameProgress_Select1)
				drawRepeat = true;
			else if (progress == eGameProgress_Select2)
				return false;
		}
		//esc true 반환 <- 반복, -> fasle 반환
		count++;
	}while(1);
	return false;
}
gameCard Game::randomCard(int turn)
{
	srand(time(NULL));
	int random = rand() % (52 - turn);//card 배열의 인덱스가 될 수를 무작위로 뽑는다.

	//뽑은 카드는 배열 끝으로 밀어낸다.
	for (int j = random; j < 52; j++) {
		if (j + 1 < 52) {
			gameCard tempNum = card[j];
			card[j] = card[j + 1];
			card[j + 1] = tempNum;
		}
	}
	return card[random];// 랜덤 카드를 리턴한다
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