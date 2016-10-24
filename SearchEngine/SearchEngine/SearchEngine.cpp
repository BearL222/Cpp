// SearchEngine.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Build.h"
#include "Bool_retrieval.h"
#include "Sort.h"
#include "check.h"
#include "Display.h"
#include "input.h"

Node<int,int> *list[16980];//�洢����֮�������
int listDocNum = 0;//��������
Node<std::string,int> *listDoc[200000];//�洢����
int Doc_building_finish_at = 0;
int list_sort[16980];//���׵�Ȩ��
int sortcount = 0;
std::ifstream in_file1("D:\\NJU\\Data Structure\\dataset\\test\\doctest2.txt", std::ios::in);
std::ifstream in_file2("D:\\NJU\\Data Structure\\dataset\\link.txt", std::ios::in);

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Loading: ";
	Build start;

	start.BuildDoc(in_file1);//���ʿ�
	Doc_building_finish_at = listDocNum;
	start.BuildLink(in_file2);//������
	Node<int, int> *result = NULL;
	std::cout << std::endl << "Search Engine on!" << std::endl;
#if 0
	Bool_retrieval<std::string> retrieval;
	std::string string1, string2;
	int choice;
	while (1)
	{
		std::cout << "Input the Bool Retrieval Type:1.Single 2.AND 3.OR" << std::endl;
		std::cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3)
		{
			std::cout << "Input the key words" << std::endl;
			if (choice == 1)
			{
				std::cin >> string1;
				string2 = string1;
				result = retrieval.AND(string1, string2);//
			}
			else if (choice == 2 || choice == 3)
			{
				std::cin >> string1 >> string2;
				switch (choice)
				{
				case 2:
					result = retrieval.AND(string1, string2);
					break;
				case 3:
					result = retrieval.OR(string1, string2);
					break;
				}
			}
			if (result != NULL)
			{
				Display(result);
			}
			std::cout << "Continue?" << std::endl << "1.More search 0.Quit" << std::endl;
			std::cin >> choice;
			if (choice == 0) break;
		}
		else std::cout << "Choose Again!" << std::endl;
	}
#endif
#if 1
	SearchInput();
#endif
	std::system("pause");
	return 0;
}