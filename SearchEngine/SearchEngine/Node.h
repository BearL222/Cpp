#include "stdafx.h"

#ifndef _Node_
#define _Node_

template<class T,class K>
struct Node
{
	T s;
	Node<K,K> *next;
};
#endif