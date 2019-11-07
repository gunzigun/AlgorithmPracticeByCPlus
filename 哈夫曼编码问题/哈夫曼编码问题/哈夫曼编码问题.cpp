// ��������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;


//����ַ��������鳤��
#define MAXCODELEN 100
//���������ڵ�ṹ���������
#define MAXHAFF 100
//������������ṹ������ĸ���
#define MAXCODE 100
#define MAXWEIGHT  10000;


typedef struct Haffman
{
	//Ȩ��
	int weight;
	//�ַ�
	string ch;
	//���ڵ�
	int parent;
	//����ӽڵ�
	int leftChild;
	//�Ҷ��ӽڵ�
	int rightChild;
}HaffmaNode;

typedef struct Code
{
	//�ַ��Ĺ���������Ĵ洢
	int code[MAXCODELEN];
	//���ĸ�λ�ÿ�ʼ
	int start;
}HaffmaCode;


//�����������
HaffmaNode haffman[MAXHAFF];
//�������������
HaffmaCode code[MAXCODE];
//������뵽�ַ���ӳ��
map<string, string> mapCodeChar;
//�����ַ��������ӳ��
map<string, string> mapCharCode;


//�����������
void buildHaffman(int all)
{
	//�������ڵ�ĳ�ʼ��֮ǰ�Ĺ���, weightΪ0,parent,leftChile,rightChile��Ϊ-1
	for (int i = 0; i < all * 2 - 1; ++i)
	{
		haffman[i].weight = 0;
		haffman[i].parent = -1;
		haffman[i].leftChild = -1;
		haffman[i].rightChild = -1;
	}
	std::cout << "��������Ҫ������������ַ���Ȩ�ش�С" << std::endl;
	for (int i = 0; i < all; i++)
	{
		std::cout << "��ֱ�����ڸ�" << i << "�������ַ���Ȩ��" << std::endl;
		std::cin >> haffman[i].ch;
		std::cin >> haffman[i].weight;
	}
	//ÿ���ҳ���С��Ȩ�صĽڵ�,�����µĽڵ�,��Ҫall - 1 �κϲ�
	int x1, x2, w1, w2;
	for (int i = 0; i < all - 1; ++i)
	{
		x1 = x2 = -1;
		w1 = w2 = MAXWEIGHT;
		//ע������ÿ����all + i���������
		for (int j = 0; j < all + i; ++j)
		{
			//�õ���СȨ�صĽڵ�
			if (haffman[j].parent == -1 && haffman[j].weight < w1)
			{
				//���ÿ����С�ĸ����ˣ���ô��Ҫ���ϴ���С�ĸ��ڶ�����С��
				w2 = w1;
				x2 = x1;
				x1 = j;
				w1 = haffman[j].weight;
			}
			//������else if������if,����Ϊ����ÿ��ֻѡ1���Ϳ����ˡ�
			else if (haffman[j].parent == -1 && haffman[j].weight < w2)
			{
				x2 = j;
				w2 = haffman[j].weight;
			}
		}
		//ô���ҵ���С�������ڵ��Ҫ�ǵúϲ���һ���µĽڵ�
		haffman[all + i].leftChild = x1;
		haffman[all + i].rightChild = x2;
		haffman[all + i].weight = w1 + w2;
		haffman[x1].parent = all + i;
		haffman[x2].parent = all + i;
	}
}


//Ϊ�����ַ�ȷ������
void buildCode(int all)
{
	//���浱ǰҶ�ӽڵ���ַ�����
	HaffmaCode hCode;
	//��ǰ���ڵ�
	int curParent;
	//�±��Ҷ�ӽڵ�ı��
	int c;
	//�������ܴ���
	for (int i = 0; i < all; ++i)
	{
		hCode.start = all - 1;
		c = i;
		curParent = haffman[i].parent;
		//�����������Ǹ��ڵ㲻����-1
		while (curParent != -1)
		{
			//�������õ����ڵ㣬Ȼ���ж���ڵ��Ƿ�Ϊ��ǰֵ�������ȡ�ڵ�0
			//����ȡ�ڵ�1,�����c��䶯�����Բ�Ҫ��i��ʾ��������c���浱ǰ����i
			if (haffman[curParent].leftChild == c)
			{
				hCode.code[hCode.start] = 0;
			}
			else
			{
				hCode.code[hCode.start] = 1;
			}
			hCode.start--;
			c = curParent;
			curParent = haffman[c].parent;
		}
		//�ѵ�ǰ��Ҷ�ӽڵ���Ϣ���浽����ṹ������
		for (int j = hCode.start + 1; j < all; ++j)
		{
			code[i].code[j] = hCode.code[j];
		}
		code[i].start = hCode.start;
	}
}


//�����ַ�-����������Ķ�Ӧ��ϵ
void SaveCodeCharRelation(int all)
{
	std::cout << "�ַ�-����������ӳ��:" << endl;
	for (int i = 0; i < all; ++i)
	{
		string strsub = "";
		for (int j = code[i].start + 1; j < all; ++j)
		{
			char chcode[255];
			sprintf_s(chcode, "%x", code[i].code[j]);
			strsub.append(chcode);
		}
		mapCharCode[haffman[i].ch] = strsub;
		mapCodeChar[strsub] = haffman[i].ch;
		cout << "�ַ�ת���룺" << haffman[i].ch << ":" << mapCharCode[haffman[i].ch] << endl;
		cout << "����ת�ַ���" << strsub << ":" << mapCodeChar[strsub] << endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	// ��ȡ���빹���������
	std::cout << "�������ж��ٸ��������ַ���" << std::endl;
	int all = 0;
	std::cin >> all;
	if (all <= 0)
	{
		std::cout << "������ĸ�������" << std::endl;
		return -1;
	}

	//�����������
	buildHaffman(all);
	//Ϊ�����ַ�ȷ������
	buildCode(all);
	//�����ַ�-����������Ķ�Ӧ��ϵ
	SaveCodeCharRelation(all);
	
	
	// Ӣ��ת����
	string strchar = "";
	cout << "������Ӣ�ģ�";
	cin >> strchar;
	string strtmpCode;
	for (int i = 0; i < strchar.length(); ++i)
	{
		string temp,strdes;
		temp = strchar[i];
		strdes.append(temp);
		strtmpCode = strtmpCode + mapCharCode[strdes];
	}
	cout << "ת����Ϊ��" << strtmpCode << endl;
	

	// ����תӢ��
	string strCode = "";
	cout << "��������룺";
	cin >> strCode;
	string strtmpChar;
	do 
	{
		for (int len = 1; len <= strCode.length(); ++len)
		{
			string strBefore = strCode.substr(0, len);
			string strAfter = strCode.substr(len, strCode.length() - len);
			string temp = mapCodeChar[strBefore];
			if (temp != "")
			{
				strCode = strAfter;
				strtmpChar.append(temp);
				break;
			}
		}
	} while (strCode.length() > 0);
	cout << "ת����Ϊ��" << strtmpChar << endl;

	return 0;
}

