#include "Utility.h"
void Utility::getUserOutput(char curValue) {
	if (curValue == KEY_BACKSPACE) {
		_putch(KEY_BACKSPACE);//커서만 뒤로감
		_putch(' '); //공백으로 수정 하면서 복귀
		_putch(KEY_BACKSPACE); //다시 커서만 뒤로감(지우기 구현)
	}
	else {
		_putch(curValue);
	}

}
/**
* 메세지출력 함수
* @param message 입력할 메세지
* @param time 단위:milliSeconds 메세지 출력후 지연시간 초기값:0
*/
void Utility::printMessage(int time,const char*messageFormat,...)
{
	va_list var_list;
	va_start(var_list,messageFormat);
	printMessage(messageFormat, var_list);
	va_end(var_list);
	Sleep(time);
}
void Utility::printMessage(const char* messageFormat,...)
{
	va_list var_list;
	va_start(var_list, messageFormat);
	printMessage(messageFormat, var_list);
	va_end(var_list);
}
void Utility::printMessage(const char* messageFormat, va_list var_list)
{
	menuClear();
	gotoxy(15, 27);
	vprintf(messageFormat, var_list);
}
void Utility::printGrahphic(const char* message, int x,int y)
{
	gotoxy(x, y);
	cout << message;
}
/**
* 입력 함수
* @param destBuffer 문자열 입력받을 버퍼
* @param nDestBufLength 문자열버퍼의 최대길이
* @return true :  입력이 잘 됨 ;  false : ESC눌러 취소 됨
*/
int  Utility::getUserInput(char* destBuffer, int nDestBufLength) {
	char currentInput;
	int i = 0;
	destBuffer[0] = '\0';
	while ((i < nDestBufLength - 1) && (currentInput = _getch())) {
		if (currentInput == KEY_ENTER)        break;
		else if (currentInput == KEY_ESC)  return eGameProgress_Exit;
		else if (currentInput == KEY_BACKSPACE)
		{
			if (i > 0)
			{
				i--;
				if (i == 0)
					getUserOutput(currentInput);
			}
		}
		else if (currentInput == 224)
		{
			currentInput = _getch();
			if (currentInput == 77) {
				return eGameProgress_Select1;
			}
			else if (currentInput == 75)
			{
				return eGameProgress_Select2;
			}
		}
		else
		{
			destBuffer[i] = currentInput;
			i++;
		}
		if (i > 0)
			getUserOutput(currentInput);
	}
	destBuffer[i] = '\0';
	return eGameProgress_Default;
}
int  Utility::getUserInput_s() {
	int currentInput;
	currentInput = _getch();
	if (currentInput == KEY_ESC)  return eGameProgress_Exit;
	else if (currentInput == 224)
	{
		currentInput = _getch();
		if (currentInput == 75) {//Left
			return eGameProgress_Select1;
		}
		else if (currentInput == 77)//Right
		{
			return eGameProgress_Select2;
		}
	}
	return eGameProgress_Default;
}
void Utility::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//콘솔 핸들가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void Utility::menuClear()
{
	printGrahphic("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────", 0, 24);
	cout << "                                                                                          \n";
	cout << "                                                                                          \n";
	cout << "                                                                                          \n";
	cout << "                                                                                          \n";
	cout << "                                                                                          ";
	printGrahphic("메세지", 3, 27);
	printGrahphic("│", 12, 25);
	printGrahphic("│", 12, 26);
	printGrahphic("│", 12, 27);
	printGrahphic("│", 12, 28);
	printGrahphic("│", 12, 29);
	printGrahphic("│", 90, 25);
	printGrahphic("│", 90, 26);
	printGrahphic("│", 90, 27);
	printGrahphic("│", 90, 28);
	printGrahphic("│", 90, 29);
}