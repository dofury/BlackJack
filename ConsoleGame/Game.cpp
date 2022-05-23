#include "Game.h"
#include "Utility.h"
using namespace std;
Utility util;
Game::Game()
{
	aCount = 0;
	playerCall = 0;
	cardMaxIndex = 51;
	player.setMoney(1000);
	player.setCard(0);
	player.setCardSum(0);
	dealer.setCard(0);
	dealer.setCardSum(0);
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
bool Game::gameStart()
{
	gameEnd = false;
	while (gameEnd == false)
	{
		system("cls"); // �ܼ� â û��
		gameReset(); //�������� ����
		gameClear(); //���� ����â
		menuClear(); //���� �޴�����â
		gameEnd = betting(); //����
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
				//a�� ���� �����Ѵ�
				// end false �� ����ī�带 �̴´�
				// ����ī��� �÷��̾� ī�� ���� end
			}
			
		}
		if (gameResult == eGameResult_Cancel)
		{
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
	}
	if (gameResult == eGameResult_Cancel)
	{
		menuClear();
		util.printMessage(1000,"���� ������...");

	}
	return false;
}
eGameResult Game::getGameResult()
{
	return gameResult;
}
string Game::getDrawCNum(eMember member)
{
	if (member == eGamePlayer)
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
	else if (member == eGameDealer)
	{ 
		switch (dealer.getCard())
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
	
}
void Game::gameLoading()
{
	menuClear();
	util.printMessage(1000,"�� ������ ���� �˴ϴ�...");
	menuClear();
	util.printMessage(1000,"3...");
	menuClear();
	util.printMessage(1000,"2...");
	menuClear();
	util.printMessage(1000,"1...");
}
bool Game::betting()
{
	char input[256];
	while (1)
	{
		menuClear();//�޴� û��
		util.printMessage("�󸶸� ���� �Ͻðڽ��ϱ�? :");
		util.gotoxy(43, 27);// �Է���ǥ
		if (util.getUserInput(input, ARRAY_LENGTH(input)) == false)
			return true;
		if (isAllNumber(input, strlen(input)) == 0 || input[0] == '\0') //����ó��
		{
			menuClear();
			util.printMessage(1000,"���: ���ñݾ��� ����� �Է����ּ���!!!!!( ex: 500 )");
		}
		else
		{
			if (player.subMoney(atoi(input)) == false)//
			{
				menuClear();//�޴� û��
				util.printMessage(1000,"���: ���ñݾ��� �����մϴ�!!!!!");
			}
			else//���� �۵�
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
void Game::gameDraw(eMember member,int x,int y)
{
	if (member == eGamePlayer)
	{
		util.gotoxy(x, y++);
		cout << "��    ��";
		util.gotoxy(x, y++);
		cout << " " << player.getMark();
		util.gotoxy(x, y++);
		cout << "   " << getDrawCNum(eGamePlayer) << "    ";
		util.gotoxy(x, y++);
		cout << "    " << player.getMark();
		util.gotoxy(x, y++);
		cout << "��    ��";
		util.gotoxy(50, 1);
		cout << "player ī������: " << player.getCardSum();
	}
	else if (member == eGameDealer)
	{
		util.gotoxy(x, y++);
		cout << "��    ��";
		util.gotoxy(x, y++);
		cout << " " << dealer.getMark();
		util.gotoxy(x, y++);
		cout << "   " << getDrawCNum(eGameDealer) << "    ";
		util.gotoxy(x, y++);
		cout << "    " << dealer.getMark();
		util.gotoxy(x, y++);
		cout << "��    ��";
		util.gotoxy(70, 1);
		cout << "dealer ī������: " << dealer.getCardSum();
	}
}
void Game::gameClear()
{
	cout << "                                                                                                                          ";
	util.gotoxy(105,1);
	cout << "Ÿ��Ʋȭ��:esc";
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
	util.printGrahphic("�޼���", 3, 27);
	util.printGrahphic("|", 12, 25);
	util.printGrahphic("|", 12, 26);
	util.printGrahphic("|", 12, 27);
	util.printGrahphic("|", 12, 28);
	util.printGrahphic("|", 12, 29);
	util.gotoxy(90, 27);
	cout << "���� �ݾ�: " << player.getMoney();
}
void Game::menuDraw()
{
	util.gotoxy(0, 24);
	cout << "------------------------------------------------------------------------------------------------------------------------";
	util.gotoxy(3, 27);
	cout << "�޼���";
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
	cout << "���� �ݾ�: " << player.getMoney();
}
bool Game::playerCardDraw()
{
	int count = 0;
	bool drawRepeat = true;
	char input[256];
	do
	{
		menuClear();
		if (drawRepeat == true)
		{
			if (randomCard(eGamePlayer) == true)
			{
				int tempCard;
				if (player.getCard() > 10)//10�� �Ѵ� ī��� 10���� �����ϴ� �Լ�
					tempCard = 10;
				else
					tempCard = player.getCard();
				cardACount();
				player.setCardSum(player.getCardSum() + tempCard);
				gameDraw(eGamePlayer,1, 1);
				drawRepeat = false;
				count++;
				if (resultCheck(eGamePlayer) == false)//����Ʈ üũ �Լ�
					return true;
			}

			else if (randomCard(eGamePlayer) == false)
			{
				util.printMessage("���: ��ο� �� �� �ִ� ī�尡 �����ϴ�!!!");
				break;
			}
		}
		else
		{
			util.printMessage("ī�带 �� ��ο� �Ͻðڽ��ϱ�? : <- [yes] -> [no] ");
			progress = util.getUserInput_s();
			if (progress == eGameProgress_Exit)
				return true;
			else if (progress == eGameProgress_Select1)
				drawRepeat = true;
			else if (progress == eGameProgress_Select2)
				return false;
		}
		//esc true ��ȯ <- �ݺ�, -> fasle ��ȯ
	}while(1);
	return false;
}
bool Game::dealerCardDraw()//ai
{
	int count = 0;
	bool drawRepeat = true;
	char input[256];
	do
	{
		menuClear();
		if (drawRepeat == true)
		{
			if (randomCard(eGameDealer) == true)
			{
				int tempCard;
				if (dealer.getCard() > 10)//10�� �Ѵ� ī��� 10���� �����ϴ� �Լ�
					tempCard = 10;
				else
					tempCard = dealer.getCard();
				cardACount();
				dealer.setCardSum(dealer.getCardSum() + tempCard);
				gameDraw(eGameDealer,10, 1);
				drawRepeat = false;
				count++;
			}

			else if (randomCard(eGameDealer) == false)
			{
				util.printMessage("���: ������ ��ο� �� �� �ִ� ī�尡 �����ϴ�!!!");
				break;
			}
		}
		else
		{
			util.printMessage("������ �Ǵ���...");
			if (dealer.getCardSum() < 17) //ī������ 17���� �۴ٸ� �ݺ�
			{
				drawRepeat = true;
				Sleep(3000);
			}		
			else// ī������ 17���� ũ�ٸ� stop
			{
				if (resultCheck(eGameDealer) == false)
					break;
			}
		}
	} while (1);
	if (resultCheck(eGameDealer) == false)//����Ʈ üũ �Լ�
		return true;
	return false;
}
bool Game::randomCard(eMember member)
{
	srand(time(NULL));
	if (cardMaxIndex == 0) // ī�带 ���� ��ο��ҽ� ����ó��
	{
		return false;
	}
	else
	{
		int random = rand() % (cardMaxIndex+1);//card �迭�� �ε����� �� ���� �������� �̴´�.
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
		//���� ī��� �迭 ������ �о��.
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
		util.printMessage("%d��° A�� ���� 1�� 11�� �������ֽʽÿ� <- [1] -> [10]",checkCnt);
		progress = util.getUserInput_s();
		if (progress == eGameProgress_Exit)
			return eGameResult_Exit;
		else if (progress == eGameProgress_Select1)//1�� ���ý�
			player.setCardSum(player.getCardSum());//�״��
		else if (progress == eGameProgress_Select2)//11�� ���ý�
		{
			if ((player.getCardSum() + 10) > 21)
			{
				menuClear();
				util.printMessage(1000,"���ý� ����Ʈ�� �ǹǷ� �ڵ����� 1�� ���õ˴ϴ�");
			}
			else
				player.setCardSum(player.getCardSum() + 10);//11���Ѵ�
		}
		checkCnt++;
	}
	return false;
}
void Game::cardACount()
{
	if (player.getCard() == 1) //A -> 1 or 10 �Ǻ� �Լ�
	{
		aCount++;
	}
}
bool Game::resultCheck(eMember member)
{
	menuClear();
	if (member == eGamePlayer)
	{
		if (player.getCardSum() > 21)
		{
			gameEnd = true;
			gameResult = eGameResult_Loss;
			util.printMessage(2000, "����Ʈ�� �Ǽ̽��ϴ�!!!");
			return false;
		}
		else if (player.getCardSum() == 21)
		{
			gameEnd = true;
			gameResult = eGameResult_WIn;
			util.printMessage(2000, "21�� �Ǿ� �¸��ϼ̽��ϴ� 2�� payback �˴ϴ�");
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
			util.printMessage(2000, "������ ����Ʈ�� �����Ƿ� �¸��ϼ̽��ϴ�");
		}
		else if (dealer.getCardSum() == 21)
		{
			gameResult = eGameResult_Loss;
			util.printMessage(2000, "������ 21�� �����Ƿ� �й��ϼ̽��ϴ�");
		}
		else
		{
			dealer.setCardScore(21 - (dealer.getCardSum()));
			if (dealer.getCardScore() == player.getCardScore())
			{
				gameResult = eGameResult_Draw;
				util.printMessage("���º�");
			}
			else if (dealer.getCardScore() > player.getCardScore())
			{
				gameResult = eGameResult_WIn;
				util.printMessage("�������� 21�� �����Ƿ� �¸��ϼ̽��ϴ�");
			}
			else if (dealer.getCardScore() < player.getCardScore())
			{
				gameResult = eGameResult_Loss;
				util.printMessage("������ 21�� �� �����Ƿ� �й��ϼ̽��ϴ�");
			}
		}		
		gameEnd = true;//�׻� ���� ����
		return false;
	}
	return true;

}
void Game::playerWin()
{
	menuClear();
	util.printMessage(2000,"�¸� ����");
	player.setMoney(player.getMoney() + (2 * playerCall));
}
void Game::playerLoss()
{
	menuClear();
	util.printMessage(2000,"���� ������");
}
void Game::gameReset()
{
	player.setCardSum(0);
	dealer.setCardSum(0);
	aCount = 0;
	cardMaxIndex = 51;
	player.setCardScore(0);
	dealer.setCardScore(0);
	gameResult = eGameResult_Default;
}