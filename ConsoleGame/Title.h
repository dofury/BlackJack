#pragma once
typedef enum _eMenuSelect {
	eMenuSel_Start = 1,
	eMenuSel_Rule,
	eMenuSel_Exit,
}eMenuSelect;
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


