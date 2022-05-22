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
using namespace std;
class Utility
{
public:
	int x, y;
	int getUserInput(char* destBuffer, int nDestBufLength);
	int getUserInput_s();
	void printMessage(const char* message,int time=0);
	void printGrahphic(const char* message, int x,int y);
	void getUserOutput(char curValue);
	void gotoxy(int x, int y);
};
typedef enum _eGameProgress {
	eGameProgress_Exit = 0,
	eGameProgress_Select1,
	eGameProgress_Select2,
	eGameProgress_Default

}eGameProgress;
#endif


