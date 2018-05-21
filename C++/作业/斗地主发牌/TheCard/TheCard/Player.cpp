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
	int cardNum;	//��������
	Card tem;		//��ʱ���濨��
	int cardNum_A = 0;	// A������
	int cardNum_2 = 0;	// 2������
	int cardNum_A_2 = 0;	//A��2���ܺ�
	bool queen = false;		//�Ƿ���С��
	bool king = false;		//�Ƿ��Ǵ���
	int cardKingSub = 0;	//��С��������ŵ�Ԫ�ص��±�
	int card2Sub = 0;		//3��������ŵ��±�
	bool cardKingSubOnlyOnce = true;	//�жϴ�С������λ�õ��±�ʱ�����ж�һ��
	bool card2SubOnlyOnce = true;		//�ж�A��2��ʼλ�õ��±�ʱ�����ж�һ��
	Card temArray[8];		//��ʱ����A��2�Ŀ���


	//��ֹ����Ϊ�� 
	if (_Cards == nullptr)
	{
		cout << "�Բ���������в�û���ƣ�" << endl;
		return;
	}

	//��������
	if (_IsBanker)
	{
		cardNum = 20;
	}
	else
	{
		cardNum = 17;
	}
	
	//ͳ�ƴ�С��A2����
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

	//�������ֵ�˳���ɴ�С����
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

	//��ȡ����A�Ϳ���2Ŀ��λ�õ��±ꡢ��ǰλ�õ��±�
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

	//���ն������ƵĴ�С˳������
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
		cout << "��ݣ�����" << endl;
	}
	else
	{
		cardNum = 17;
		cout << "��ݣ�ũ��" << endl;
	}

	for (int i = 0; i < cardNum; i++)
	{
		cout << _Cards[i]._Name << "  " << _Cards[i]._Number << endl;
	}
	
	
}
