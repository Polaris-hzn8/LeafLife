///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <vector>
#include <string>
#include "GameItem.h"
using namespace std;

class BlackMarket
{
public:
	BlackMarket();
	~BlackMarket();
	void SetId(int id) { m_id = id; }
	int GetId() { return m_id; }
	void SetName(string name) { m_name = name; }
	string GetName() { return m_name; }
	vector<GameItem*>* getItemList() { return &m_itemList; }
public:
	// 通过Id获取商品
	GameItem* GetItemFromMarket(int nGoodsId);
	// 出售商品
	int SellItem(int nGoodsId, int nSellItemNum);
private:
	int					m_id;		// 黑市id
	string				m_name;		// 黑市名称
	vector<GameItem*>	m_itemList;	// 黑市商品列表
};

