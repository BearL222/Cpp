#include "stdafx.h"
#include "Node.h"
#include "Display.h"
#ifndef _Sort_
#define _Sort_

extern Node<int, int> *list[16980];
extern int list_sort[16980];
extern int sortcount;
template<class T>
class Sort
{
public:
	void getCount(int i)
	{
		count = i;
	}
	Node<T,T> *sort(Node<T,T> *start);
private:
	int count;
};
	
template<class T>
Node<T,T> *Sort<T>::sort(Node<T,T> *start)
{
#if 0
	Node<T, T> *tmp1 = start;

	Node<T, T> *tmp2 = start->next;
	int exchange;
	for (int i = 0; i < Sort::count; ++i)
	{
		int j = Sort::count - i - 1;
		while (tmp2->s != -1&&j!=-1)
		{
			if (list[tmp1->s - 1] < list[tmp2->s - 1])
			{
				exchange = tmp1->s;
				tmp1->s = tmp2->s;
				tmp2->s = exchange;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			--j;
		}
		tmp1 = start;
		tmp2 = tmp1->next;
}
#endif
#if 1
	Node<T, T> *tmp1 = start;
	Node<T, T> *tmp2 = start->next;
	int exchange,j;
/*	for (int i = Sort::count - 1; i > -1; --i)
	{
		j = i;*/
	for (int i = 0; i < sortcount; ++i)
	{
		j = sortcount - i - 1;
		while (tmp2->s != -1&&j!=-1)
		{
			if (list_sort[tmp1->s - 1] < list_sort[tmp2->s - 1])//将权重小的移到后面
			{
				exchange = tmp1->s;
				tmp1->s = tmp2->s;
				tmp2->s = exchange;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			--j;
		}
		tmp1 = start;
		tmp2 = tmp1->next;
	}
#endif
	return start;
}
#endif