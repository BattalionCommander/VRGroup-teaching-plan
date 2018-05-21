
#include "stdafx.h"
#include "Dealer.h"
#include "Player.h"

int main()
{
	Dealer Dealer;
	Player Player_1;
	Player Player_2;
	Player Player_3;

	Dealer.GetCard();
	Dealer.Shuffle();
	Dealer.Deal(Player_1, Player_2, Player_3);

	Player_1.RankCards();
	cout << "玩家1" << endl;
	Player_1.ShowCards();

	Player_2.RankCards();
	cout << "\n\n玩家2" << endl;
	Player_2.ShowCards();

	Player_3.RankCards();
	cout << "\n\n玩家3" << endl;
	Player_3.ShowCards();

	system("PAUSE");
    return 0;
}

