#include "Game.h"
#include "Utility.h"
using namespace std;
Utility util;
Game::Game()
{
	invest = false;
	gameEnd = false;
	aCount = 0;
	playerCall = 0;
	cardMaxIndex = 51;
	player.setMoney(1000);
	player.setCard(0);
	player.setCardSum(0);
	dealer.setCard(0);
	dealer.setCardSum(0);
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
	while (gameEnd == false)
	{
		system("cls"); // 콘솔 창 청소
		gameReset(); //게임정보 리셋
		gameClear(); //게임 상태창 청소
		util.menuClear(); //게임 메뉴상태창 청소
		valueUpdate(); //게임 스테이터스창 업데이트
		if (invest == false)
		{
			gameEnd = betting(); //베팅
		}
		invest = false;
		if (gameEnd == false)
		{
			gameLoading();
			gameEnd = playerCardDraw();
			if (gameEnd == false)
			{
				gameEnd = cardACheck();
				if (gameEnd == false)
				{
					gameEnd = dealerCardDraw();

				}
				//a의 값을 선택한다
				// end false 시 딜러카드를 뽑는다
				// 딜러카드와 플레이어 카드 비교후 end
			}

		}
		
		if (gameResult == eGameResult_Cancel)
		{;
			util.printMessage(1000, "게임 종료중...");
			break;
		}
		else if (gameResult == eGameResult_WIn)
		{
			playerWin();
			gameEnd = false;
		}
		else if (gameResult == eGameResult_Loss)
		{
			playerLoss();
			gameEnd = false;
		}
		else if (gameResult == eGameResult_Draw)
		{
			playerDraw();
			gameEnd = false;
		}
	}
	return false;
}
eGameResult Game::getGameResult()
{
	return gameResult;
}
string Game::getDrawCNum(eMember member)
{
	switch (member == eGamePlayer ? player.getCard():dealer.getCard())//플레이어라면 플레이어 카드 딜러라면 딜러 카드
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
	util.printMessage(1000,"곧 게임이 시작 됩니다...");
	util.printMessage(1000,"3...");
	util.printMessage(1000,"2...");
	util.printMessage(1000,"1...");
}
bool Game::betting()
{
	char input[256];
	playerCall = 0;
	valueUpdate();
	while (1)
	{
		util.printMessage("얼마를 베팅 하시겠습니까? :");
		util.gotoxy(43, 27);// 입력좌표
		if (util.getUserInput(input, ARRAY_LENGTH(input)) == false)
			return true;
		if (isAllNumber(input, strlen(input)) == 0 || input[0] == '\0') //예외처리
		{
			util.printMessage(1000,"경고: 베팅금액을 제대로 입력해주세요!!!!!( ex: 500 )");
		}
		else
		{
			if (player.subMoney(atoi(input)) == false)//
			{
				util.printMessage(1000,"경고: 베팅금액이 부족합니다!!!!!");
			}
			else//정상 작동
			{
				playerCall = atoi(input);
				valueUpdate();
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
void Game::gameDraw(eMember member,int x,int y)
{
	if (member == eGamePlayer)
	{
		util.gotoxy(x, y++);
		cout << "┌    ┐";
		util.gotoxy(x, y++);
		cout << " " << player.getMark();
		util.gotoxy(x, y++);
		cout << "   " << getDrawCNum(eGamePlayer) << "    ";
		util.gotoxy(x, y++);
		cout << "    " << player.getMark();
		util.gotoxy(x, y++);
		cout << "└    ┘";
	}
	else if (member == eGameDealer)
	{
		util.gotoxy(x, y++);
		cout << "┌    ┐";
		util.gotoxy(x, y++);
		cout << " " << dealer.getMark();
		util.gotoxy(x, y++);
		cout << "   " << getDrawCNum(eGameDealer) << "    ";
		util.gotoxy(x, y++);
		cout << "    " << dealer.getMark();
		util.gotoxy(x, y++);
		cout << "└    ┘";
	}
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
	cout << "───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────";
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
	util.printGrahphic("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────", 0, 24);
	cout << "                                                                                          \n";
	cout << "                                                                                          \n";
	cout << "                                                                                          \n";
	cout << "                                                                                          \n";
	cout << "                                                                                          ";
	util.printGrahphic("메세지", 3, 27);
	util.printGrahphic("│", 12, 25);
	util.printGrahphic("│", 12, 26);
	util.printGrahphic("│", 12, 27);
	util.printGrahphic("│", 12, 28);
	util.printGrahphic("│", 12, 29);
	util.printGrahphic("│", 90, 25);
	util.printGrahphic("│", 90, 26);
	util.printGrahphic("│", 90, 27);
	util.printGrahphic("│", 90, 28);
	util.printGrahphic("│", 90, 29);
}
void Game::valueUpdate()
{
	reward = playerCall * 2;
	util.printGrahphic("                     ", 1, 13);
	util.gotoxy(1, 13);
	cout << "PLAYER 카드의 합: " << player.getCardSum();
	util.printGrahphic("                     ", 1, 1);
	util.gotoxy(1, 1);
	cout << "DEALER 카드의 합: " << dealer.getCardSum();
	util.printGrahphic("                     ", 98, 26);
	util.gotoxy(98, 26);
	cout << "보상: " << reward;
	util.printGrahphic("                     ", 98, 28);
	util.gotoxy(98, 28);
	cout << "보유 금액: " << player.getMoney();
}
bool Game::playerCardDraw()
{
	int cardX = 1, cardY = 16;
	bool drawRepeat = true;
	char input[256];
	do
	{
		util.menuClear();
		if (drawRepeat == true)
		{
			if (randomCard(eGamePlayer) == true)
			{
				int tempCard;
				if (player.getCard() > 10)//10이 넘는 카드는 10으로 제한하는 함수
					tempCard = 10;
				else
					tempCard = player.getCard();
				cardACount();
				player.setCardSum(player.getCardSum() + tempCard);
				valueUpdate();
				gameDraw(eGamePlayer,cardX, cardY);
				drawRepeat = false;
				if (resultCheck(eGamePlayer) == false)//버스트 체크 함수
					return true;
				cardX += 7;//카드 위치 변경
			}

			else if (randomCard(eGamePlayer) == false)
			{
				util.printMessage("경고: 드로우 할 수 있는 카드가 없습니다!!!");
				break;
			}
		}
		else
		{
			util.printMessage("카드를 더 드로우 하시겠습니까? : <- [yes] -> [no] ");
			progress = util.getUserInput_s();
			if (progress == eGameProgress_Exit)
				return true;
			else if (progress == eGameProgress_Select1)
				drawRepeat = true;
			else if (progress == eGameProgress_Select2)
				return false;
		}
		//esc true 반환 <- 반복, -> fasle 반환
	}while(1);
	return false;
}
bool Game::dealerCardDraw()//ai
{
	bool drawRepeat = true;
	int cardX = 1, cardY = 4;
	menuClear();
	util.printMessage(200, "딜");
	util.printMessage(200, "딜러");
	util.printMessage(200, "딜러의");
	util.printMessage(200, "딜러의 차");
	util.printMessage(200, "딜러의 차례");
	util.printMessage(200, "딜러의 차례.");
	util.printMessage(200, "딜러의 차례..");
	util.printMessage(200, "딜러의 차례...");
	do
	{
		util.menuClear();
		if (drawRepeat == true)
		{
			if (randomCard(eGameDealer) == true)
			{
				int tempCard;
				if (dealer.getCard() > 10)//10이 넘는 카드는 10으로 제한하는 함수
					tempCard = 10;
				else
					tempCard = dealer.getCard();
				//cardACount();딜러의 aCount
				dealer.setCardSum(dealer.getCardSum() + tempCard);
				valueUpdate();
				gameDraw(eGameDealer,cardX, cardY);
				cardX += 7;//카드 위치 변경
				drawRepeat = false;
			}

			else if (randomCard(eGameDealer) == false)
			{
				util.printMessage("경고: 딜러가 드로우 할 수 있는 카드가 없습니다!!!");
				break;
			}
		}
		else
		{
			util.printMessage(400,"진행중");
			util.printMessage(400,"진행중.");
			util.printMessage(400,"진행중..");
			util.printMessage(400,"진행중...");
			if (dealer.getCardSum() < 17) //카드합이 17보다 작다면 반복
			{
				drawRepeat = true;
				Sleep(1000);
			}		
			else// 카드합이 17보다 크다면 stop
			{
				Sleep(1000);
				if (resultCheck(eGameDealer) == false)
					break;
			}
		}
	} while (1);
	if (resultCheck(eGameDealer) == false)//버스트 체크 함수
		return true;
	return false;
}
bool Game::randomCard(eMember member)
{
	srand(time(NULL));
	if (cardMaxIndex == 0) // 카드를 전부 드로우할시 예외처리
	{
		return false;
	}
	else
	{
		int random = rand() % (cardMaxIndex+1);//card 배열의 인덱스가 될 수를 무작위로 뽑는다.
		if (member == eGamePlayer)
		{
			player.setCard(card[random].number);
			player.setMark(card[random].mark);
		}
		else if (member == eGameDealer)
		{
			dealer.setCard(card[random].number);
			dealer.setMark(card[random].mark);
		}
		
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
	int checkCnt = 1;
	while (checkCnt<=aCount)
	{
		util.printMessage("%d번째 A의 값에 10을 더하시겠습니까? <- [NO] [YES] ->",checkCnt);
		progress = util.getUserInput_s();
		if (progress == eGameProgress_Exit)
			return eGameResult_Exit;
		else if (progress == eGameProgress_Select1)//NO를 선택시
			player.setCardSum(player.getCardSum());//그대로
		else if (progress == eGameProgress_Select2)//YES를 선택시
		{
			if ((player.getCardSum() + 10) > 21)
			{
				util.printMessage(1000,"선택시 버스트가 되므로 자동으로 NO로 선택됩니다");
			}
			else
			{
				player.setCardSum(player.getCardSum() + 10);//11로한다
				valueUpdate();
			}
		}
		if(resultCheck(eGamePlayer) == true)//10을 더할시 조건판별
		checkCnt++;
	}
	return false;
}
void Game::cardACount()
{
	if (player.getCard() == 1) //A -> 1 or 10 판별 함수
	{
		aCount++;
	}
}
bool Game::investment()
{
	util.printMessage(2000, "다음 게임에서 승리할 시 투자하신돈의 3배를 받으실 수 있습니다");
	util.printMessage("지금 보상을 받지않고 투자하시겠습니까? <- [NO] [YES] ->");
	progress = util.getUserInput_s();
	if (progress == eGameProgress_Select1)//NO를 선택시
		return false;
	else if (progress == eGameProgress_Select2)//YES를 선택시
	{
		playerCall *= 3;
		invest = true;
		return true;
	}
}
bool Game::resultCheck(eMember member)
{
	if (member == eGamePlayer)
	{
		if (player.getCardSum() > 21)
		{
			gameEnd = true;
			gameResult = eGameResult_Loss;
			util.printMessage(2000, "버스트가 되셨습니다!!!");
			return false;
		}
		else if (player.getCardSum() == 21)
		{
			gameEnd = true;
			gameResult = eGameResult_WIn;
			util.printMessage(2000, "21이 되어 승리하셨습니다");
			return false;
		}
		else
		{
			player.setCardScore(21 - (player.getCardSum()));
		}
	}
	else if (member == eGameDealer)
	{
		if (dealer.getCardSum() > 21)
		{
			gameResult = eGameResult_WIn;
			util.printMessage(2000, "딜러가 버스트가 됬으므로 승리하셨습니다");
		}
		else if (dealer.getCardSum() == 21)
		{
			gameResult = eGameResult_Loss;
			util.printMessage(2000, "딜러가 21이 됬으므로 패배하셨습니다");
		}
		else
		{
			dealer.setCardScore(21 - (dealer.getCardSum()));
			if (dealer.getCardScore() == player.getCardScore())
			{
				gameResult = eGameResult_Draw;
				util.printMessage("무승부");
			}
			else if (dealer.getCardScore() > player.getCardScore())
			{
				gameResult = eGameResult_WIn;
				util.printMessage("딜러보다 21에 가까우므로 승리하셨습니다");
			}
			else if (dealer.getCardScore() < player.getCardScore())
			{
				gameResult = eGameResult_Loss;
				util.printMessage("딜러가 21에 더 가까우므로 패배하셨습니다");
			}
		}		
		gameEnd = true;//항상 게임 종료
		return false;
	}
	return true;

}
void Game::playerWin()
{
	if (investment() == false)
	{
		util.printMessage(2000, "승리 축하드립니다");
		player.setMoney(player.getMoney() + (2 * playerCall));
		valueUpdate();
	}
}
void Game::playerLoss()
{
	util.printMessage(2000,"ㅉㅉ 돈잃음");
}
void Game::playerDraw()
{
	util.printMessage(2000, "무승부");
	player.setMoney(player.getMoney() + playerCall);
	valueUpdate();
}
void Game::playerInvest()
{;
	util.printMessage(2000, "투자를 시작합니다");
	invest = true;
}
void Game::gameReset()
{
	reward = 0;
	player.setCardSum(0);
	dealer.setCardSum(0);
	aCount = 0;
	cardMaxIndex = 51;
	player.setCardScore(0);
	dealer.setCardScore(0);
	gameResult = eGameResult_Default;
}