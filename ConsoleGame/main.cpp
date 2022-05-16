#include "Title.h"
#include "Rule.h"
#include "Game.h"
#include<Windows.h>
#define START 1
#define RULE 2
#define EXIT 3
#define TITLE 4
int main() {
	int select;
	Title title;
	title.init();
	title.titleDraw();
	select = title.keyDraw();
	while (1)
	{
		if (select == START)
		{
			Game game;
			game.gameDraw();
			game.betting();
			select = game.keyDraw();
			game.gameDraw();

		}
		else if (select == RULE)
		{
			Rule rule;
			rule.ruleDraw();
			select = rule.keyDraw();
		}
		else if (select == EXIT)
		{
			exit(0);
		}
		else if (select == TITLE)
		{
			title.titleDraw();
			select = title.keyDraw();
		}

	}



	return 0;
}
