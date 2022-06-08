#include "Title.h"
#include "Rule.h"
#include "Game.h"
#include "Utility.h"

int main() {
	bool mainEnd = false;
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
				Game game;
				mainEnd = game.gameStart();

			}break;
			case eMenuSel_Rule: 
			{
				Rule rule;
				rule.ruleDraw();
				select = rule.keyDraw();
			}break;
			case eMenuSel_Exit:
			{
				mainEnd = true;
			}break;
		}
	}while (mainEnd == false);

	return 0;
}
