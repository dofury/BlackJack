#include "Rule.h"
#include "Utility.h"
#define TITLE 4
using namespace std;

void Rule::ruleDraw()//Ÿ��Ʋǥ�� �Լ�
{
	system("cls");//�ܼ�ȭ�� �ʱ�ȭ
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t   ����ȭ��:esc" << endl;
	cout << "\t\t\t\t\t\t\t[���ӹ��]" << endl;
	cout << "\t\t\t\t\t�����̶� �����̴�" << endl;
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

