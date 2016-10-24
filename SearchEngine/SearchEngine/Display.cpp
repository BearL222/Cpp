#include "stdafx.h"
#include "Display.h"

void Display(Node<int, int> *start)
{
	std::cout << std::endl;
	int count = 0,temp;
	Node<int, int> *tmp = start;
	std::string string1;
	while (tmp->s != -1)
	{
		std::ifstream in_file("D:\\NJU\\Data Structure\\dataset\\test\\doctest2.txt", std::ios::in);
		in_file.clear();
		while (getline(in_file, string1))
		{
			if (count > 0)
			{
				std::cout << string1 << std:: endl;
				--count;
				if (count == 0)
				{
					std::cout << std::endl;
					break;
				}
			}
			else
			{
				std::string beginning = string1.substr(0, 1);
				if (beginning == "") continue;
				temp = atoi(string1.substr(2, string1.length() - 2).c_str());
				if (beginning == "#"&&temp == tmp->s)//找到文献
				{
					count = 2;//一次输出标题，一次输出摘要
				}
			}
		}
		tmp = tmp->next;
	}
	std::cout << std::endl;
	std::cout << "Display finished" << std::endl;
}