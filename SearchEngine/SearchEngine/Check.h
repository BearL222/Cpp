#include "stdafx.h"
#include "Node.h"
extern int listDocNum;
extern Node<std::string,int> *listDoc[200000];
#ifndef _Check_
#define _Check_

class check
{
public:
	static bool if_exist(std::string &s, int &DocNum);//�жϹؼ����Ƿ����
	static void insert(std::string &s,int &DocNum);//�����¹ؼ���
	static int find(std::string &s);//���ҹؼ���λ��
//	static void add(int &DocNum);
};
#endif