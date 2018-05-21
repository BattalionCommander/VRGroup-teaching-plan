#pragma once

class Dealer;
class Player
{
	friend class Dealer;

public:
	Player();
	~Player();


	void SetCard(int i,Card card);

	//≈≈–Ú
	void RankCards();
	//’π æ ÷≈∆
	void ShowCards();

private:
	Card _Cards[20];
	bool _IsBanker = false;
};

