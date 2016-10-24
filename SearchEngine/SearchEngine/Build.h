#include "stdafx.h"
#include "Check.h"
#include "Node.h"
extern int listDocNum;
extern Node<std::string, int> *listDoc[200000];
extern int list_sort[16980];
extern Node<int, int> *list[16980];

#ifndef _Build_
#define _Build_

class Build
{
public:
	void BuildDoc(std::ifstream &in_file);
	void BuildLink(std::ifstream &in_file);
};

void Build::BuildLink(std::ifstream &in_file)
{
	Node<int, int> *tmp1, *tmp2;
	int count = 0, i = 0, mpos = 0;
	std::string string1;
	while (getline(in_file, string1))
	{
		list[i] = new Node < int, int > ;
		tmp2 = list[i];
		mpos = string1.find(":", mpos) + 1;
		mpos = string1.find(":", mpos) + 1;
		while (string1.find(" ", mpos) < string1.length())
		{
			tmp1 = new Node < int, int > ;
			tmp2->next = tmp1;
			tmp1->s = atoi(string1.substr(mpos, string1.find(" ", mpos) - mpos).c_str());//记录引用它的文献
			mpos = string1.find(" ", mpos) + 1;
			tmp2 = tmp1;
			++count;//记录引用次数
		}
		tmp2->next = new Node < int, int > ;
		tmp2->next->s = -1;//-1表示末尾
		mpos = 0;
		list[i]->s = count;
		count = 0;
		++i;
	}
	std::cout << "Link buiding finished" << std::endl;
	//记录文献权重
	int weight = 0;
	for (int i = 0; i < 16980; ++i)
	{
		weight = 0;
		Node<int, int>*tmp = list[i]->next;
		while (tmp->s != -1)
		{
			weight += list[tmp->s]->s;//权重和
			tmp = tmp->next;
		}
		list_sort[i] = weight;
	}
}

void Build::BuildDoc(std::ifstream &in_file)
{
	int DocNum = 0;
	//int pos[3];
	int opos;
	std::string beginning, string1, string2;
	while (getline(in_file, string1))
	{
		int mpos = 0, npos = 0;
		beginning = string1.substr(0, 1).c_str();
		if (beginning == "")
		{
			continue;
		}
		else if (beginning == "#")//标记第几个文献的行
		{
			listDoc[listDocNum] = new Node < std::string, int > ;
			DocNum = atoi(string1.substr(2, string1.length() - 2).c_str());
			continue;
		}
		else if (beginning == "A" || beginning == "T")//标题或摘要行
		{
			mpos = string1.find(" ", mpos) + 1;
			while (string1.substr(mpos, 1) != "")
			{
				/*	pos[0] = string1.find(",", mpos);
					pos[1] = string1.find(".", mpos);
					pos[2] = string1.find(":", mpos);
					npos = string1.find(" ", mpos);
					for (int j = 0; j < 3; ++j)
					{
					if (pos[j] == -1)
					{
					pos[j] = npos + 1;
					}
					}*/
				//npos = std::min(std::min(pos[0], pos[1]),std::min(pos[2], npos));
				npos = string1.find(" ", mpos);
				if (npos == -1) break;
				opos = npos - 1;
				while (string1.substr(opos, 1)[0] < 65 || string1.substr(opos, 1)[0] > 122 || (string1.substr(opos, 1)[0] > 90 && string1.substr(opos, 1)[0] < 97))//避免英文句末连接着标点的情况
				{
					opos = opos - 1;
				}
				string2 = string1.substr(mpos, opos + 1 - mpos);//记录关键词
				std::transform(string2.begin(), string2.end(), string2.begin(), tolower);//建立字典，单词变小写
				if (!check::if_exist(string2, DocNum))
				{
					check::insert(string2, DocNum);
					//if (DocNum % 100 == 0) std::cout << "another 100" << std::endl;//每记录100个提示一下
					if (DocNum % 200 == 0) std::cout << "=";//每记录200个提示一下
				}
				//if (npos == pos[0] || npos == pos[1] || npos == pos[2]) mpos = npos + 2;
				//else mpos = npos+1;
				mpos = npos + 1;
			}
		}
	}
	std::cout << std::endl << "Documents building finished" << std::endl;
}
#endif