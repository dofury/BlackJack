#include "Rule.h"
#include "Utility.h"
#define TITLE 4
using namespace std;
Utility utilR;

void Rule::ruleDraw()//Ÿ��Ʋǥ�� �Լ�
{
	system("cls");//�ܼ�ȭ�� �ʱ�ȭ
	utilR.printGraphic("���� ȭ��:ESC", 105, 1);
	utilR.printGraphic("[���� ���]", 1, 2);
	utilR.printGraphic("���� �ɰ� ī������� ���� ���п� ���� ���� �Ұų� ��� �޴´�", 1, 4);
	utilR.printGraphic("������ �÷��̾ ���� �켱���� ������", 1, 5);
	utilR.printGraphic("�÷��̾�� ���� �й� ������ �޼����� �ʴ� ������ ��� ī�带 ���� �� �ִ�", 1, 6);
	utilR.printGraphic("�÷��̾�� �������� ī�带 �̰� ī���� ������ ���� ���� ī���� �տ� �����ȴ�", 1, 7);
	utilR.printGraphic("�÷��̾�� 21�� �Ǹ� �ٷ� �¸��� �ϸ� 21�� �Ѿ�� �й� 21���� ������ ������ �ºθ� �ϰԵȴ�", 1, 8);
	utilR.printGraphic("������ �ºν� ���� 21�� ����� ����� �¸��Ѵ�", 1, 9);
	utilR.printGraphic("�÷��̾�� ���� �й��� �켱���� ������ ��� �Ŀ� �����Ͽ� ������ 21�� ������ �÷��̾ �¸��ϰԵȴ�", 1, 10);
	utilR.printGraphic("�÷��̾ �¸��� ������ �����ʰ� �ɾ ������ ����� ������ �� �� �ִ�", 1, 11);
	utilR.printGraphic("21 OVER: ����Ʈ, 21:����", 1, 13);
	utilR.printGraphic("2~9�� ���̴� ������ ���� ���ϸ� T,Q,K,J �� 10�� ���� ���Ѵ�", 1, 14);
	utilR.printGraphic("�÷��̾�� ���� A�� 1�� 11�� ���߿� �����Ҽ� �ְ� ������ 1�θ� ����", 1, 15);
	utilR.printGraphic("����: <- , -> (����Ű) �׼�: �����̽���", 1, 17);
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

