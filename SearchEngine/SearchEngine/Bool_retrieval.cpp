#include "stdafx.h"
#include "Bool_retrieval.h"

Node<int, int> *Bool_retrieval::AND(std::string &string1, std::string &string2)
{
	int s1 = check::find(string1);
	int s2 = check::find(string2);
	if (s1 == -1 || s2 == -1)//其中之一不存在
	{
		return NULL;
	}
	Node<int, int> *tmp1 = listDoc[s1]->next;
	Node<int, int> *tmp2 = listDoc[s2]->next;
	Node<int, int> *sort1 = new Node<int, int>;
	Node<int, int> *sort2;
	Node<int, int> *start = sort1;
	int scount = 0;
	while (tmp1->s != -1)
	{
		while (tmp2->s != -1)
		{
			if (tmp1->s == tmp2->s)//找到两个关键词都存在的文献
			{
				++scount;
				sort1->s = tmp1->s;
				sort2 = sort1;
				sort1->next = new Node<int, int>;
				sort1 = sort1->next;
				break;
			}
			else
			{
				tmp2 = tmp2->next;
			}
		}
		tmp1 = tmp1->next;
		tmp2 = listDoc[s2]->next;
	}
	sort1->s = -1;
	Sort<int> sorting;
	//	sorting.getCount(scount);
	sortcount = scount;
	return sorting.sort(start);//文献排序
}

Node<int, int> *Bool_retrieval::OR(std::string &string1, std::string &string2)
{
	Sort<int> sorting;
	int s1 = check::find(string1);
	int s2 = check::find(string2);
	if (s1 == -1 && s2 != -1)
	{
		return NULL;
	}
	if (s1 != -1 && s2 == -1)
	{
		s2 = s1;
	}
	if (s1 == -1 && s2 != -1)
	{
		s1 = s2;
	}
	Node<int, int> *tmp1 = listDoc[s1]->next;
	Node<int, int> *tmp2 = listDoc[s2]->next;
	Node<int, int> *start = new Node < int, int >;
	Node<int, int> *tmp3 = start;
	int scount = 0;
	//将两者属于的文献链接在一起
	while (tmp1->s != -1)
	{
		tmp3->s = tmp1->s;
		tmp3->next = new Node < int, int >;
		tmp1 = tmp1->next;
		tmp3 = tmp3->next;
		++scount;
	}
	while (tmp2->s != -1)
	{
		tmp3->s = tmp2->s;
		tmp3->next = new Node < int, int >;
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;
		++scount;
	}
	tmp3->s = -1;
	tmp3 = start;
	Node<int, int> *tmp4;
	Node<int, int> *tmp5;
	while (tmp3->s != -1)
	{
		if (tmp3->next->s == -1) break;//只有一篇
		if (tmp3->next->next->s == -1)//只有两篇
		{
			if (tmp3->next->s == tmp3->s)
			{
				tmp4 = tmp3->next;
				tmp3->next = tmp3->next->next;
				delete tmp4;
				break;
			}
		}
		if (tmp3->next->s == tmp3->s)//当前与下一篇相同
		{
			tmp4 = tmp3->next;
			tmp3->next = tmp3->next->next;
			delete tmp4;
			continue;
		}
		//其他
		tmp4 = tmp3->next;
		tmp5 = tmp4->next;
		while (tmp5->s != -1)
		{
			if (tmp5->s == tmp3->s)//将相同的文献删除
			{
				--scount;
				tmp4->next = tmp5->next;
				delete tmp5;
				tmp5 = tmp4->next;
			}
			else
			{
				tmp4 = tmp4->next;
				tmp5 = tmp5->next;
			}
		}
		tmp3 = tmp3->next;
	}
	//	sorting.getCount(scount);
	sortcount = scount;
	return sorting.sort(start);
}