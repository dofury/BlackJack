#include "Game.h"
#include "Utility.h"
using namespace std;
Utility util;
Game::Game()
{
	playerCall = 0;
	cardMaxIndex = 51;
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
bool Game::gameStart()
{
	gameEnd = false;
	while (gameEnd == false)
	{
		system("cls"); // 콘솔 창 청소
		gameReset(); //게임정보 리셋
		gameClear(); //게임 상태창
		menuClear(); //게임 메뉴상태창
		gameEnd = betting(); //베팅
		if (gameEnd == true)
		{
			gameResult = eGameResult_Cancel;
			break;
		}
		gameLoading();
		gameEnd = cardDraw();
		if (gameEnd == true)
		{
			if (gameResult = eGameResult_Cancel)
			{
				return false;
			}
			else if (gameResult = eGameResult_WIn)
			{
				playerWin();
				return false;
			}
			else if (gameResult = eGameResult_Loss)
			{
				playerLoss();
				return false;
			}
		}
	}
	if (gameResult == eGameResult_Cancel)
	{
		menuClear();
		util.printMessage("게임 종료중...",1000);

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
				return "T";
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
		default:
			{
				return "NULL";
			}
	}
}
void Game::gameLoading()
{
	menuClear();
	util.printMessage("곧 게임이 시작 됩니다...",1000);
	menuClear();
	util.printMessage("3...",1000);
	menuClear();
	util.printMessage("2...",1000);
	menuClear();
	util.printMessage("1...",1000);
}
bool Game::betting()
{
	char input[256];
	while (1)
	{
		menuClear();//메뉴 청소
		util.printMessage("얼마를 베팅 하시겠습니까? :");
		util.gotoxy(43, 27);// 입력좌표
		if (util.getUserInput(input, ARRAY_LENGTH(input)) == false)
			return true;
		if (isAllNumber(input, strlen(input)) == 0 || input[0] == '\0') //예외처리
		{
			menuClear();
			util.printMessage("경고: 베팅금액을 제대로 입력해주세요!!!!!( ex: 500 )",1000);
		}
		else
		{
			if (player.subMoney(atoi(input)) == false)//
			{
				menuClear();//메뉴 청소
				util.printMessage("경고: 베팅금액이 부족합니다!!!!!",1000);
			}
			else//정상 작동
			{
				playerCall = atoi(input);
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
	util.gotoxy(x, y++);
	cout << "┌    ┐";
	util.gotoxy(x, y++);
	cout << " " << player.getMark();
	util.gotoxy(x, y++);
	cout << "   " << getDrawCNum() << "    ";
	util.gotoxy(x, y++);
	cout << "    " << player.getMark();
	util.gotoxy(x, y++);
	cout << "└    ┘";
	util.gotoxy(50, 1);
	cout << "카드의합: " << player.getCardSum();
}
void Game::gameClear()
{
	cout << "                                                                                                                          ";
	util.gotoxy(105,1);
	cout << "타이틀화면:esc";
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
void Game::menuClear()
{
	util.gotoxy(0, 24);
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	util.printGrahphic("메세지", 3, 27);
	util.printGrahphic("|", 12, 25);
	util.printGrahphic("|", 12, 26);
	util.printGrahphic("|", 12, 27);
	util.printGrahphic("|", 12, 28);
	util.printGrahphic("|", 12, 29);
	util.gotoxy(90, 27);
	cout << "보유 금액: " << player.getMoney();
}
void Game::menuDraw()
{
	util.gotoxy(0, 24);
	cout << "------------------------------------------------------------------------------------------------------------------------";
	util.gotoxy(3, 27);
	cout << "메세지";
	util.gotoxy(12, 25);
	cout << "|";
	util.gotoxy(12, 26);
	cout << "|";
	util.gotoxy(12, 27);
	cout << "|";
	util.gotoxy(12, 28);
	cout << "|";
	util.gotoxy(12, 29);
	cout << "|";
	util.gotoxy(90, 27);
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
			if (randomCard() == true)
			{
				int tempCard;
				if (player.getCard() > 10)//10이 넘는 카드는 10으로 제한하는 함수
					tempCard = 10;
				else
					tempCard = player.getCard();
				player.setCardSum(player.getCardSum() + tempCard);
				gameDraw(1, 1);
				if (cardACheck() == false)//A 값 판별 함수
					return eGameProgress_Exit;
				if (resultCheck() == false)//버스트 체크 함수
					break;
				drawRepeat = false;
				count++;
			}
			else if (randomCard() == false)
			{
				util.printMessage("경고 드로우 할 수 있는 카드가 없습니다!!!",1000);
				break;
			}
		}
		else
		{
			util.printMessage("카드를 더 드로우 하시겠습니까? : <- [yes] -> [no] ",0);
			progress = util.getUserInput_s();
			if (progress == eGameProgress_Exit)
				return eGameResult_Exit;
			else if (progress == eGameProgress_Select1)
				drawRepeat = true;
			else if (progress == eGameProgress_Select2)
				return false;
		}
		//esc true 반환 <- 반복, -> fasle 반환
		gameDraw(1, 1);//그리기
	}while(1);
	return false;
}
bool Game::randomCard()
{
	srand(time(NULL));
	if (cardMaxIndex == 0) // 카드를 전부 드로우할시 예외처리
	{
		return false;
	}
	else
	{
		int random = rand() % (cardMaxIndex+1);//card 배열의 인덱스가 될 수를 무작위로 뽑는다.
		player.setCard(card[random].number);
		player.setMark(card[random].mark);
		gameCard tempNum = card[cardMaxIndex];
		card[cardMaxIndex] = card[random];
		card[random] = tempNum;
		cardMaxIndex--;
		//뽑은 카드는 배열 끝으로 밀어낸다.
		return true;
	}
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
bool Game::cardACheck()
{
	menuClear();
	if (player.getCard() == 1) //A -> 1 or 10 판별 함수
	{
		util.printMessage("번째 A의 값을 1과 11중 선택해주십시오 <- [1] -> [10]");
		progress = util.getUserInput_s();
		if (progress == eGameProgress_Exit)
			return eGameResult_Exit;
		else if (progress == eGameProgress_Select1)//1을 선택시
			player.setCardSum(player.getCardSum());//그대로
		else if (progress == eGameProgress_Select2)//11을 선택시
		{
			if ((player.getCardSum() + 10) > 21)
			{
				menuClear();
				util.printMessage("선택시 버스트가 되므로 자동으로 1로 선택됩니다", 1000);
			}
			else
				player.setCardSum(player.getCardSum() + 10);//11로한다
		}
		return eGameProgress_Default;
	}
}
bool Game::resultCheck()
{
	if (player.getCardSum() > 21)
	{
		gameEnd = true;
		playerResult = eGameResult_Loss;
		util.printMessage("버스트가 되셨습니다!!!",2000);
		return false;
	}
	else if (player.getCardSum() == 21)
	{
		gameEnd = true;
		playerResult = eGameResult_WIn;
		util.printMessage("21이 되어 승리하셨습니다 2배 payback 됩니다", 2000);
		return false;
	}
	else
		return true;
}
void Game::playerWin()
{

}
void Game::playerLoss()
{

}
void Game::gameReset()
{
	player.setCardSum(0);
}