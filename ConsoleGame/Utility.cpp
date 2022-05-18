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