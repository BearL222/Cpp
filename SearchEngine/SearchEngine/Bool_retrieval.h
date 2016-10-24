#include "stdafx.h"
#include "Node.h"
#include "check.h"
#include "Sort.h"

extern int sortcount;
#ifndef _Bool_retrieval_
#define _Bool_retrieval_

class Bool_retrieval
{
public:
	Node<int,int> *AND(std::string &s1, std::string &s2);
	Node<int,int> *OR(std::string &s1, std::string &s2);
};


#endif