///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

class RandomUtil
{
public:
	RandomUtil();
	~RandomUtil();

	static int getRandomInteger(int min, int max);		//�����������
	static bool getProbabilityResult(int probability);	//ĳ�¼��Ƿ�����ɹ�
private:
	static bool flag;		//�Ƿ�������������
};
