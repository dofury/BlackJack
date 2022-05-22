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
		util.printMessage("���� ������...",1000);

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
	util.printMessage("�� ������ ���� �˴ϴ�...",1000);
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
		menuClear();//�޴� û��
		util.printMessage("�󸶸� ���� �Ͻðڽ��ϱ�? :");
		util.gotoxy(43, 27);// �Է���ǥ
		if (util.getUserInput(input, ARRAY_LENGTH(input)) == false)
			return true;
		if (isAllNumber(input, strlen(input)) == 0 || input[0] == '\0') //����ó��
		{
			menuClear();
			util.printMessage("���: ���ñݾ��� ����� �Է����ּ���!!!!!( ex: 500 )",1000);
		}
		else
		{
			if (player.subMoney(atoi(input)) == false)//
			{
				menuClear();//�޴� û��
				util.printMessage("���: ���ñݾ��� �����մϴ�!!!!!",1000);
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
void Game::gameDraw(int x,int y)
{
	util.gotoxy(x, y++);
	cout << "��    ��";
	util.gotoxy(x, y++);
	cout << " " << player.getMark();
	util.gotoxy(x, y++);
	cout << "   " << getDrawCNum() << "    ";
	util.gotoxy(x, y++);
	cout << "    " << player.getMark();
	util.gotoxy(x, y++);
	cout << "��    ��";
	util.gotoxy(50, 1);
	cout << "ī������: " << player.getCardSum();
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
				if (player.getCard() > 10)//10�� �Ѵ� ī��� 10���� �����ϴ� �Լ�
					tempCard = 10;
				else
					tempCard = player.getCard();
				player.setCardSum(player.getCardSum() + tempCard);
				gameDraw(1, 1);
				if (cardACheck() == false)//A �� �Ǻ� �Լ�
					return eGameProgress_Exit;
				if (resultCheck() == false)//����Ʈ üũ �Լ�
					break;
				drawRepeat = false;
				count++;
			}
			else if (randomCard() == false)
			{
				util.printMessage("��� ��ο� �� �� �ִ� ī�尡 �����ϴ�!!!",1000);
				break;
			}
		}
		else
		{
			util.printMessage("ī�带 �� ��ο� �Ͻðڽ��ϱ�? : <- [yes] -> [no] ",0);
			progress = util.getUserInput_s();
			if (progress == eGameProgress_Exit)
				return eGameResult_Exit;
			else if (progress == eGameProgress_Select1)
				drawRepeat = true;
			else if (progress == eGameProgress_Select2)
				return false;
		}
		//esc true ��ȯ <- �ݺ�, -> fasle ��ȯ
		gameDraw(1, 1);//�׸���
	}while(1);
	return false;
}
bool Game::randomCard()
{
	srand(time(NULL));
	if (cardMaxIndex == 0) // ī�带 ���� ��ο��ҽ� ����ó��
	{
		return false;
	}
	else
	{
		int random = rand() % (cardMaxIndex+1);//card �迭�� �ε����� �� ���� �������� �̴´�.
		player.setCard(card[random].number);
		player.setMark(card[random].mark);
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
	menuClear();
	if (player.getCard() == 1) //A -> 1 or 10 �Ǻ� �Լ�
	{
		util.printMessage("��° A�� ���� 1�� 11�� �������ֽʽÿ� <- [1] -> [10]");
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
				util.printMessage("���ý� ����Ʈ�� �ǹǷ� �ڵ����� 1�� ���õ˴ϴ�", 1000);
			}
			else
				player.setCardSum(player.getCardSum() + 10);//11���Ѵ�
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
		util.printMessage("����Ʈ�� �Ǽ̽��ϴ�!!!",2000);
		return false;
	}
	else if (player.getCardSum() == 21)
	{
		gameEnd = true;
		playerResult = eGameResult_WIn;
		util.printMessage("21�� �Ǿ� �¸��ϼ̽��ϴ� 2�� payback �˴ϴ�", 2000);
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