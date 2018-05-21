#pragma once
#include "Player.h"
class Player;
class Dealer
{
public:
	Dealer();
	~Dealer();

	//È¡ÅÆ
	void GetCard();
	//Ï´ÅÆ
	void Shuffle();
	//·¢ÅÆ
	void Deal(Player &Player1, Player &Player2, Player &Player3);
private:
	int _Zero = 0;
	Card _Cards[54];
};