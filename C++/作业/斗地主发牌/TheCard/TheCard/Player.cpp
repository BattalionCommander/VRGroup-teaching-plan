#include "stdafx.h"
#include "Player.h"
#include <math.h>
using std::begin;
using std::end;
using std::abs;

Player::Player()
{
}

Player::~Player()
{
}

void Player::SetCard(int i, Card card)
{
	_Cards[i] = card;
}

void Player::RankCards()
{
	int cardNum;
	Card tem;
	int cardNum_A = 0;
	int cardNum_2 = 0;
	int cardNum_A_2 = 0;
	bool queen = false;
	bool king = false;
	int cardKingSub = 0;
	int card2Sub = 0;
	bool cardKingSubOnlyOnce = true;
	bool card2SubOnlyOnce = true;
	Card temArray[8];


	//防止手牌为空 
	if (_Cards == nullptr)
	{
		cout << "对不起，玩家手中并没有牌！" << endl;
		return;
	}

	//手牌数量
	if (_IsBanker)
	{
		cardNum = 20;
	}
	else
	{
		cardNum = 17;
	}
	
	//统计大小王A2个数
	for (int i = 0; i < cardNum; i++)
	{

		switch (_Cards[i]._Number)
		{
		case 1:
			++cardNum_A;
			break;
		case 2:
			++cardNum_2;
			break;
		case 14:
			queen = true;
			break;
		case 15:
			king = true;
			break;
		default:
			break;
		}
	}
	cardNum_A_2 = cardNum_A + cardNum_2;

	//按照数字的顺序由大到小排列
	for (int i = 0; i < cardNum; i++)
	{
		for (int n = i+1; n < cardNum; n++)
		{
			if (_Cards[i]._Number < _Cards[n]._Number)
			{
				tem._Name = _Cards[n]._Name;
				tem._Number = _Cards[n]._Number;
				_Cards[n]._Name = _Cards[i]._Name;
				_Cards[n]._Number = _Cards[i]._Number;
				_Cards[i]._Name = tem._Name;
				_Cards[i]._Number = tem._Number;
			}
		}
	}

	//获取卡牌A和卡牌2目标位置的下标、当前位置的下标
	for (int i = 0; i < cardNum; i++)
	{
		if ((_Cards[i]._Number!=15)&&(_Cards[i]._Number != 14)&& cardKingSubOnlyOnce)
		{
			cardKingSub = i;
			cardKingSubOnlyOnce = false;
		}
		if ((_Cards[i]._Number <= 2) && card2SubOnlyOnce)
		{
			card2Sub = i;
			card2SubOnlyOnce = false;
		}
	}

	//按照斗地主牌的大小顺序排列
	if (cardNum&&((cardNum_A_2)!=0))
	{
		for (int i = 0; i < cardNum_A_2; i++)
		{
			temArray[i] = _Cards[card2Sub + i];
		}
		for (int i = 0; i < card2Sub- cardKingSub; i++)
		{
			_Cards[card2Sub - i - 1 + cardNum_A_2] = _Cards[card2Sub - i - 1];
		}
		for (int i = 0; i < cardNum_A_2; i++)
		{
			_Cards[cardKingSub + i] = temArray[i];
		}
	}


}



void Player::ShowCards()
{
	int cardNum;

	if (_IsBanker)
	{
		cardNum = 20;
		cout << "身份：地主" << endl;
	}
	else
	{
		cardNum = 17;
		cout << "身份：农民" << endl;
	}

	for (int i = 0; i < cardNum; i++)
	{
		cout << _Cards[i]._Name << "  " << _Cards[i]._Number << endl;
	}
	
	
}
