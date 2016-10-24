#include "stdafx.h"
#include "Check.h"

void check::insert(std::string &s,int &DocNum)
{
	listDoc[listDocNum] = new Node<std::string,int>;
	listDoc[listDocNum]->s = s;
	listDoc[listDocNum]->next = new Node < int, int > ;
	listDoc[listDocNum]->next->s = DocNum;
	listDoc[listDocNum]->next->next = new Node < int, int > ;
	listDoc[listDocNum]->next->next->s = -1;
	++listDocNum;
}

bool check::if_exist(std::string &s,int &DocNum)
{
	for (int i = 0; i < listDocNum; ++i)
	{
		if (listDoc[i]->s == s)
		{
			if (listDoc[i]->next->s == DocNum)//避免是同一个文献中的重复关键词
			{
				return true;
			}
			Node<int, int>*tmp1 = new Node < int, int > ;
			tmp1->next = listDoc[i]->next;
			listDoc[i]->next = tmp1;
			tmp1->s = DocNum;
			return true;
		}
	}
	return false;
}

int check::find(std::string &s)
{
	for (int i = listDocNum-1; i >=0; --i)//从最后往前找
	{
		if (s == listDoc[i]->s)
		{
			return i;
		}
	}
	return -1;
}