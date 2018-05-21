#include "stdafx.h"
#include "Dealer.h"
Dealer::Dealer()
{

}
Dealer::~Dealer()
{

}

//第一层循环控制花色，第二层控制数字，最后再设置大小王
void Dealer::GetCard()
{
	string _Type;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			_Type = "FangPian";
			break;
		case 1:
			_Type = "HeiTao";
			break;
		case 2:
			_Type = "HongTao";
			break;
		case 3:
			_Type = "MeiHua";
			break;
		default:
			break;
		}
		for (int n = 0; n < 13; n++)
		{
			_Cards[i * 13 + n]._Name = _Type;
			_Cards[i * 13 + n]._Number = n+1;
		}
	}
	_Cards[52]._Name = "XiaoWang";
	_Cards[52]._Number = 14;
	_Cards[53]._Name = "DaWang";
	_Cards[53]._Number = 15;
	cout << "取牌完成！" << endl;
}

//54次循环，每次产生随机数，将54张牌依次与随机出的位置交换顺序，保证每张牌都至少移动过一次位置
void Dealer::Shuffle()
{
	int _Random = 0;

	Card _CardTemporary;
	srand((unsigned)time(0));
	//srand()函数产生一个以当前时间开始的随机种子.应该放在for等循环语句前面 不然要等待很长时间

	//洗牌
	for (int i = 0; i < 54; i++)
	{
		_Random = rand() % 54;
		_CardTemporary = _Cards[_Random];
		_Cards[_Random] = _Cards[i];
		_Cards[i] = _CardTemporary;
	}
	cout << "洗牌完成！" << endl;
}


//1.使用友元类，使得可以访问Player中的数据
//2.使用随机数控制地主
//3.使用循环依次发牌，并在最后将剩下的三张牌发给地主。赋值的同时将原数据清空。
void Dealer::Deal(Player &Player1, Player &Player2, Player &Player3)
{
	int _Random = rand() % 3;

	for (size_t i = 0; i < 17; i++)
	{	
		//给玩家发牌
		Player1.SetCard(i, _Cards[i * 3]);
		Player2.SetCard(i, _Cards[i * 3 + 1]);
		Player3.SetCard(i, _Cards[i * 3 + 2]);

		//发牌员已发的牌
		_Cards[i * 3]._Name.clear();
		_Cards[i * 3]._Number = _Zero;
		_Cards[i * 3 + 1]._Name.clear();
		_Cards[i * 3 + 1]._Number = _Zero;
		_Cards[i * 3 + 2]._Name.clear();
		_Cards[i * 3 + 2]._Number = _Zero;
	}

	switch (_Random)
	{
	case 0:
		Player1._IsBanker = true;
		Player1.SetCard(17, _Cards[51]);
		Player1.SetCard(18, _Cards[52]);
		Player1.SetCard(19, _Cards[53]);
		break;
	case 1:
		Player2._IsBanker = true;
		Player2.SetCard(17, _Cards[51]);
		Player2.SetCard(18, _Cards[52]);
		Player2.SetCard(19, _Cards[53]);
		break;
	case 2:
		Player3._IsBanker = true;
		Player3.SetCard(17, _Cards[51]);
		Player3.SetCard(18, _Cards[52]);
		Player3.SetCard(19, _Cards[53]);
		break;
	default:
		break;
	}
	_Cards[51]._Name.clear();
	_Cards[51]._Number = _Zero;
	_Cards[52]._Name.clear();
	_Cards[52]._Number = _Zero;
	_Cards[53]._Name.clear();
	_Cards[53]._Number = _Zero;
	cout << "发牌完成！" << endl;
}