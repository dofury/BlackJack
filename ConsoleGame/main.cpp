#include "Title.h"
#include "Rule.h"
#include "Game.h"
#include<Windows.h>
int main() {
	Game game;
	bool gameend = false;
	int select;
	Title title;
	title.init();
	do
	{
		title.titleDraw();
		select = title.keyDraw();
		switch (select) {
			case eMenuSel_Start: 
			{
				game.gameStart();

			}break;
			case eMenuSel_Rule: 
			{
				Rule rule;
				rule.ruleDraw();
				select = rule.keyDraw();
			}break;
			case eMenuSel_Exit:
			{
				gameend = true;
			}break;
		}
		switch (select) {
		case eGameResult_WIn: {

		}break;
		case eGameResult_Loss: {

		}break;
		case eGameResult_Draw: {

		}break;
		}
	}while (gameend == false);

	return 0;
}
