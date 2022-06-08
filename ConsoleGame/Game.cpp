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
	while (gameEnd == false)
	{
		system("cls"); // �ܼ� â û��
		gameReset(); //�������� ����
		gameClear(); //���� ����â û��
		util.menuClear(); //���� �޴�����â û��
		valueUpdate(); //���� �������ͽ�â ������Ʈ
		if (invest == false)
		{
			gameEnd = betting(); //����
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
				//a�� ���� �����Ѵ�
				// end false �� ����ī�带 �̴´�
				// ����ī��� �÷��̾� ī�� ���� end
			}

		}
		
		if (gameResult == eGameResult_Cancel)
		{;
			util.printMessage(1000, "���� ������...");
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
	switch (member == eGamePlayer ? player.getCard():dealer.getCard())//�÷��̾��� �÷��̾� ī�� ������� ���� ī��
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
	util.printMessage(1000,"�� ������ ���� �˴ϴ�...");
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
		util.printMessage("�󸶸� ���� �Ͻðڽ��ϱ�? :");
		util.gotoxy(43, 27);// �Է���ǥ
		if (util.getUserInput(input, ARRAY_LENGTH(input)) == false)
			return true;
		if (isAllNumber(input, strlen(input)) == 0 || input[0] == '\0') //����ó��
		{
			util.printMessage(1000,"���: ���ñݾ��� ����� �Է����ּ���!!!!!( ex: 500 )");
		}
		else
		{
			if (player.subMoney(atoi(input)) == false)//
			{
				util.printMessage(1000,"���: ���ñݾ��� �����մϴ�!!!!!");
			}
			else//���� �۵�
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
		cout << "��    ��";
		util.gotoxy(x, y++);
		cout << " " << player.getMark();
		util.gotoxy(x, y++);
		cout << "   " << getDrawCNum(eGamePlayer) << "    ";
		util.gotoxy(x, y++);
		cout << "    " << player.getMark();
		util.gotoxy(x, y++);
		cout << "��    ��";
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
	cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
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
	util.printGrahphic("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", 0, 24);
	cout << "                                                                                          \n";
	cout << "                                                                                          \n";
	cout << "                                                                                          \n";
	cout << "                                                                                          \n";
	cout << "                                                                                          ";
	util.printGrahphic("�޼���", 3, 27);
	util.printGrahphic("��", 12, 25);
	util.printGrahphic("��", 12, 26);
	util.printGrahphic("��", 12, 27);
	util.printGrahphic("��", 12, 28);
	util.printGrahphic("��", 12, 29);
	util.printGrahphic("��", 90, 25);
	util.printGrahphic("��", 90, 26);
	util.printGrahphic("��", 90, 27);
	util.printGrahphic("��", 90, 28);
	util.printGrahphic("��", 90, 29);
}
void Game::valueUpdate()
{
	reward = playerCall * 2;
	util.printGrahphic("                     ", 1, 13);
	util.gotoxy(1, 13);
	cout << "PLAYER ī���� ��: " << player.getCardSum();
	util.printGrahphic("                     ", 1, 1);
	util.gotoxy(1, 1);
	cout << "DEALER ī���� ��: " << dealer.getCardSum();
	util.printGrahphic("                     ", 98, 26);
	util.gotoxy(98, 26);
	cout << "����: " << reward;
	util.printGrahphic("                     ", 98, 28);
	util.gotoxy(98, 28);
	cout << "���� �ݾ�: " << player.getMoney();
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
				if (player.getCard() > 10)//10�� �Ѵ� ī��� 10���� �����ϴ� �Լ�
					tempCard = 10;
				else
					tempCard = player.getCard();
				cardACount();
				player.setCardSum(player.getCardSum() + tempCard);
				valueUpdate();
				gameDraw(eGamePlayer,cardX, cardY);
				drawRepeat = false;
				if (resultCheck(eGamePlayer) == false)//����Ʈ üũ �Լ�
					return true;
				cardX += 7;//ī�� ��ġ ����
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
	bool drawRepeat = true;
	int cardX = 1, cardY = 4;
	menuClear();
	util.printMessage(200, "��");
	util.printMessage(200, "����");
	util.printMessage(200, "������");
	util.printMessage(200, "������ ��");
	util.printMessage(200, "������ ����");
	util.printMessage(200, "������ ����.");
	util.printMessage(200, "������ ����..");
	util.printMessage(200, "������ ����...");
	do
	{
		util.menuClear();
		if (drawRepeat == true)
		{
			if (randomCard(eGameDealer) == true)
			{
				int tempCard;
				if (dealer.getCard() > 10)//10�� �Ѵ� ī��� 10���� �����ϴ� �Լ�
					tempCard = 10;
				else
					tempCard = dealer.getCard();
				//cardACount();������ aCount
				dealer.setCardSum(dealer.getCardSum() + tempCard);
				valueUpdate();
				gameDraw(eGameDealer,cardX, cardY);
				cardX += 7;//ī�� ��ġ ����
				drawRepeat = false;
			}

			else if (randomCard(eGameDealer) == false)
			{
				util.printMessage("���: ������ ��ο� �� �� �ִ� ī�尡 �����ϴ�!!!");
				break;
			}
		}
		else
		{
			util.printMessage(400,"������");
			util.printMessage(400,"������.");
			util.printMessage(400,"������..");
			util.printMessage(400,"������...");
			if (dealer.getCardSum() < 17) //ī������ 17���� �۴ٸ� �ݺ�
			{
				drawRepeat = true;
				Sleep(1000);
			}		
			else// ī������ 17���� ũ�ٸ� stop
			{
				Sleep(1000);
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
		util.printMessage("%d��° A�� ���� 10�� ���Ͻðڽ��ϱ�? <- [NO] [YES] ->",checkCnt);
		progress = util.getUserInput_s();
		if (progress == eGameProgress_Exit)
			return eGameResult_Exit;
		else if (progress == eGameProgress_Select1)//NO�� ���ý�
			player.setCardSum(player.getCardSum());//�״��
		else if (progress == eGameProgress_Select2)//YES�� ���ý�
		{
			if ((player.getCardSum() + 10) > 21)
			{
				util.printMessage(1000,"���ý� ����Ʈ�� �ǹǷ� �ڵ����� NO�� ���õ˴ϴ�");
			}
			else
			{
				player.setCardSum(player.getCardSum() + 10);//11���Ѵ�
				valueUpdate();
			}
		}
		if(resultCheck(eGamePlayer) == true)//10�� ���ҽ� �����Ǻ�
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
bool Game::investment()
{
	util.printMessage(2000, "���� ���ӿ��� �¸��� �� �����Ͻŵ��� 3�踦 ������ �� �ֽ��ϴ�");
	util.printMessage("���� ������ �����ʰ� �����Ͻðڽ��ϱ�? <- [NO] [YES] ->");
	progress = util.getUserInput_s();
	if (progress == eGameProgress_Select1)//NO�� ���ý�
		return false;
	else if (progress == eGameProgress_Select2)//YES�� ���ý�
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
			util.printMessage(2000, "����Ʈ�� �Ǽ̽��ϴ�!!!");
			return false;
		}
		else if (player.getCardSum() == 21)
		{
			gameEnd = true;
			gameResult = eGameResult_WIn;
			util.printMessage(2000, "21�� �Ǿ� �¸��ϼ̽��ϴ�");
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
	if (investment() == false)
	{
		util.printMessage(2000, "�¸� ���ϵ帳�ϴ�");
		player.setMoney(player.getMoney() + (2 * playerCall));
		valueUpdate();
	}
}
void Game::playerLoss()
{
	util.printMessage(2000,"���� ������");
}
void Game::playerDraw()
{
	util.printMessage(2000, "���º�");
	player.setMoney(player.getMoney() + playerCall);
	valueUpdate();
}
void Game::playerInvest()
{;
	util.printMessage(2000, "���ڸ� �����մϴ�");
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