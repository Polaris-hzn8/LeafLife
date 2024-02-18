///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <string>
using namespace std;

class GameScene
{
public:
	GameScene();
	~GameScene();

	int GetId() { return m_id; }
	void SetId(int id) { m_id = id; }
	string GetName() { return m_name; }
	void setName(string name) { m_name = name; }
protected:
	
private:
	int		m_id;		// ����id
	string	m_name;		// ��������
};

