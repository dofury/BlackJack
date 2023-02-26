#ifndef __UNTILITY_H__
#define __UNTILITY_H__
#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_BACKSPACE 8
#define ARRAY_LENGTH(array)  (sizeof(array)/sizeof(array[0]))
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<stdarg.h>
using namespace std;
class Utility
{
public:
	int x, y;
	int getUserInput(char* destBuffer, int nDestBufLength);
	int getUserInput_s();
	void printMessage(int time, const char* messageFormat, ...);
	void printMessage(const char* messageFormat,...);
	void printGraphic(const char* message, int x,int y);
	void getUserOutput(char curValue);
	void gotoxy(int x, int y);
	void menuClear();
private:
	void printMessage(const char* message, va_list var_list);
};
typedef enum _eGameProgress {
	eGameProgress_Exit = 0,
	eGameProgress_Select1,
	eGameProgress_Select2,
	eGameProgress_Default

}eGameProgress;
#endif


