#include "stdafx.h"
#include "Node.h"
extern int listDocNum;
extern Node<std::string,int> *listDoc[200000];
#ifndef _Check_
#define _Check_

class check
{
public:
	static bool if_exist(std::string &s, int &DocNum);//判断关键词是否存在
	static void insert(std::string &s,int &DocNum);//插入新关键词
	static int find(std::string &s);//查找关键词位置
//	static void add(int &DocNum);
};
#endif