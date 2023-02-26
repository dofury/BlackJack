#include "Rule.h"
#include "Utility.h"
#define TITLE 4
using namespace std;
Utility utilR;

void Rule::ruleDraw()//타이틀표현 함수
{
	system("cls");//콘솔화면 초기화
	utilR.printGraphic("시작 화면:ESC", 105, 1);
	utilR.printGraphic("[게임 방법]", 1, 2);
	utilR.printGraphic("돈을 걸고 카드게임을 통한 승패에 따라 돈을 잃거나 배로 받는다", 1, 4);
	utilR.printGraphic("블랙잭은 플레이어가 턴의 우선권을 가진다", 1, 5);
	utilR.printGraphic("플레이어는 게임 패배 조건을 달성하지 않는 선에서 계속 카드를 뽑을 수 있다", 1, 6);
	utilR.printGraphic("플레이어는 무작위로 카드를 뽑고 카드의 고유의 값에 따라 카드의 합에 누적된다", 1, 7);
	utilR.printGraphic("플레이어는 21이 되면 바로 승리를 하며 21이 넘어가면 패배 21보다 낮으면 딜러과 승부를 하게된다", 1, 8);
	utilR.printGraphic("딜러와 승부시 서로 21에 가까운 사람이 승리한다", 1, 9);
	utilR.printGraphic("플레이어는 먼저 패배할 우선권을 가지는 대신 후에 딜러턴에 딜러가 21을 넘을시 플레이어가 승리하게된다", 1, 10);
	utilR.printGraphic("플레이어가 승리시 번돈을 받지않고 걸어서 더높은 배수로 게임을 할 수 있다", 1, 11);
	utilR.printGraphic("21 OVER: 버스트, 21:블랙잭", 1, 13);
	utilR.printGraphic("2~9는 보이는 숫자의 값을 지니며 T,Q,K,J 는 10의 값을 지닌다", 1, 14);
	utilR.printGraphic("플레이어는 기준 A는 1과 11중 나중에 선택할수 있고 딜러는 1로만 본다", 1, 15);
	utilR.printGraphic("선택: <- , -> (방향키) 액션: 스페이스바", 1, 17);
}
int Rule::keyDraw()
{
	while (1) {
		int n = keyControl();
		if (n == TITLE)
			return TITLE;
	}	
}
int Rule::keyControl()
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

