#pragma once
class Title
{
public:
	void init();
	void titleDraw();
	int keyDraw();
private:
	int x, y;
	void gotoxy(int x, int y);
	int keyControl();
};

