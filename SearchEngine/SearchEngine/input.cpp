#include "stdafx.h"
#include "input.h"
extern int Doc_building_finish_at;
const int inputSize = 40;
void SearchInput()
{
	Node<int, int> *tmp=new Node<int,int>;
	Bool_retrieval retrieval;
	while (1)
	{
		std::cout << "Input the key words" << std::endl;
		std::string s="", stringlist[inputSize];
		for (int i = 0; i < inputSize; ++i)
		{
			std::cin >> stringlist[i];
			if (stringlist[i] == "_finish_")//��_finish_��ʾ�������
			{
				stringlist[i] = "";
				break;
			}
			std::transform(stringlist[i].begin(), stringlist[i].end(), stringlist[i].begin(), tolower);
			if (i == inputSize - 1)
			{
				std::cout << "Words limit" << std::endl;//��֪�ؼ���������������
			}
		}
		if (stringlist[1] == "")//ֻ��һ����������
		{
			if (retrieval.AND(stringlist[0], stringlist[0]) == NULL) continue;
			else Display(retrieval.AND(stringlist[0], stringlist[0]));
		}
		else
		{
			if (stringlist[1] == "and")//������
			{
				int j = 1, k = 0;
				std::string sample1 = "_doc_special_", sample3;
				char sample2[2];
				sample3 = stringlist[0];
				do
				{
					tmp = retrieval.AND(sample3, stringlist[2 * j]);
					if (tmp == NULL) break;
					listDoc[listDocNum] = new Node < std::string, int > ;
					_itoa_s(k, sample2, 10);
					listDoc[listDocNum]->s = sample1.append(sample2);
					sample3 = listDoc[listDocNum]->s;
					sample1 = "_doc_special_";
					listDoc[listDocNum]->next = tmp;
					++j;
					++k;
					++listDocNum;
				} while (stringlist[2 * j] != "");
			}
			else if (stringlist[1] == "or")//������
			{
				int j = 1, k = 0;
				std::string sample1 = "_doc_special_", sample3;
				char sample2[2];
				sample3 = stringlist[0];
				do
				{
					tmp = retrieval.OR(sample3, stringlist[2 * j]);
					if (tmp == NULL) break;
					listDoc[listDocNum] = new Node < std::string, int > ;
					_itoa_s(k, sample2, 10);
					listDoc[listDocNum]->s = sample1.append(sample2);
					sample3 = listDoc[listDocNum]->s;
					sample1 = "_doc_special_";
					listDoc[listDocNum]->next = tmp;
					++j;
					++k;
					++listDocNum;
				} while (stringlist[2 * j] != "");
			}
			else if (stringlist[1] != "and"&&stringlist[1] != "or")//Ҳ����������ֻ�ǲ�����and
			{
				int j = 1, k = 0;
				std::string sample1 = "_doc_special_", sample3;
				char sample2[2];
				sample3 = stringlist[0];
				do
				{
					tmp = retrieval.AND(sample3, stringlist[j]);
					if (tmp == NULL) break;
					listDoc[listDocNum] = new Node < std::string, int > ;
					_itoa_s(k, sample2, 10);
					listDoc[listDocNum]->s = sample1.append(sample2);
					sample3 = listDoc[listDocNum]->s;
					sample1 = "_doc_special_";
					listDoc[listDocNum]->next = tmp;
					++j;
					++k;
					++listDocNum;
				} while (stringlist[j] != "");
			}
			if (tmp != NULL) Display(listDoc[listDocNum - 1]->next);
		}
		while (1)//�Ƿ����
		{
			std::string choice;
			std::cout << "More search? 1:Yes 0: Quit" << std::endl;
			std::cin >> choice;
			if (choice == "0") return;
			else if (choice == "1")
			{
				listDocNum = Doc_building_finish_at;
				break;
			}
/*			else
			{
				std::cout << "Wrong Input, input 1 or 0" << std::endl;
			}*/
		}
	}
}