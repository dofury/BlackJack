#include "Rule.h"
#include "Utility.h"
#define TITLE 4
using namespace std;

void Rule::ruleDraw()//타이틀표현 함수
{
	system("cls");//콘솔화면 초기화
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t   시작화면:esc" << endl;
	cout << "\t\t\t\t\t\t\t[게임방법]" << endl;
	cout << "\t\t\t\t\t블랙잭이란 블랙잭이다" << endl;
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

