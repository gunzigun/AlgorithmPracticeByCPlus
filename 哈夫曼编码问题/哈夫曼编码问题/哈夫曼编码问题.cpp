// 哈夫曼编码问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;


//最大字符编码数组长度
#define MAXCODELEN 100
//最大哈夫曼节点结构体数组个数
#define MAXHAFF 100
//最大哈夫曼编码结构体数组的个数
#define MAXCODE 100
#define MAXWEIGHT  10000;


typedef struct Haffman
{
	//权重
	int weight;
	//字符
	string ch;
	//父节点
	int parent;
	//左儿子节点
	int leftChild;
	//右儿子节点
	int rightChild;
}HaffmaNode;

typedef struct Code
{
	//字符的哈夫曼编码的存储
	int code[MAXCODELEN];
	//从哪个位置开始
	int start;
}HaffmaCode;


//保存哈夫曼树
HaffmaNode haffman[MAXHAFF];
//保存哈夫曼编码
HaffmaCode code[MAXCODE];
//保存编码到字符的映射
map<string, string> mapCodeChar;
//保存字符到编码的映射
map<string, string> mapCharCode;


//构造哈夫曼树
void buildHaffman(int all)
{
	//哈夫曼节点的初始化之前的工作, weight为0,parent,leftChile,rightChile都为-1
	for (int i = 0; i < all * 2 - 1; ++i)
	{
		haffman[i].weight = 0;
		haffman[i].parent = -1;
		haffman[i].leftChild = -1;
		haffman[i].rightChild = -1;
	}
	std::cout << "请输入需要哈夫曼编码的字符和权重大小" << std::endl;
	for (int i = 0; i < all; i++)
	{
		std::cout << "请分别输入第个" << i << "哈夫曼字符和权重" << std::endl;
		std::cin >> haffman[i].ch;
		std::cin >> haffman[i].weight;
	}
	//每次找出最小的权重的节点,生成新的节点,需要all - 1 次合并
	int x1, x2, w1, w2;
	for (int i = 0; i < all - 1; ++i)
	{
		x1 = x2 = -1;
		w1 = w2 = MAXWEIGHT;
		//注意这里每次是all + i次里面便利
		for (int j = 0; j < all + i; ++j)
		{
			//得到最小权重的节点
			if (haffman[j].parent == -1 && haffman[j].weight < w1)
			{
				//如果每次最小的更新了，那么需要把上次最小的给第二个最小的
				w2 = w1;
				x2 = x1;
				x1 = j;
				w1 = haffman[j].weight;
			}
			//这里用else if而不是if,是因为它们每次只选1个就可以了。
			else if (haffman[j].parent == -1 && haffman[j].weight < w2)
			{
				x2 = j;
				w2 = haffman[j].weight;
			}
		}
		//么次找到最小的两个节点后要记得合并成一个新的节点
		haffman[all + i].leftChild = x1;
		haffman[all + i].rightChild = x2;
		haffman[all + i].weight = w1 + w2;
		haffman[x1].parent = all + i;
		haffman[x2].parent = all + i;
	}
}


//为各个字符确定编码
void buildCode(int all)
{
	//保存当前叶子节点的字符编码
	HaffmaCode hCode;
	//当前父节点
	int curParent;
	//下标和叶子节点的编号
	int c;
	//遍历的总次数
	for (int i = 0; i < all; ++i)
	{
		hCode.start = all - 1;
		c = i;
		curParent = haffman[i].parent;
		//遍历的条件是父节点不等于-1
		while (curParent != -1)
		{
			//我们先拿到父节点，然后判断左节点是否为当前值，如果是取节点0
			//否则取节点1,这里的c会变动，所以不要用i表示，我们用c保存当前变量i
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
		//把当前的叶子节点信息保存到编码结构体里面
		for (int j = hCode.start + 1; j < all; ++j)
		{
			code[i].code[j] = hCode.code[j];
		}
		code[i].start = hCode.start;
	}
}


//保存字符-哈夫曼编码的对应关系
void SaveCodeCharRelation(int all)
{
	std::cout << "字符-哈夫曼编码映射:" << endl;
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
		cout << "字符转编码：" << haffman[i].ch << ":" << mapCharCode[haffman[i].ch] << endl;
		cout << "编码转字符：" << strsub << ":" << mapCodeChar[strsub] << endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	// 获取输入构造哈夫曼树
	std::cout << "请输入有多少个哈夫曼字符：" << std::endl;
	int all = 0;
	std::cin >> all;
	if (all <= 0)
	{
		std::cout << "您输入的个数有误" << std::endl;
		return -1;
	}

	//构造哈夫曼树
	buildHaffman(all);
	//为各个字符确定编码
	buildCode(all);
	//保存字符-哈夫曼编码的对应关系
	SaveCodeCharRelation(all);
	
	
	// 英文转编码
	string strchar = "";
	cout << "请输入英文：";
	cin >> strchar;
	string strtmpCode;
	for (int i = 0; i < strchar.length(); ++i)
	{
		string temp,strdes;
		temp = strchar[i];
		strdes.append(temp);
		strtmpCode = strtmpCode + mapCharCode[strdes];
	}
	cout << "转换后为：" << strtmpCode << endl;
	

	// 编码转英文
	string strCode = "";
	cout << "请输入编码：";
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
	cout << "转换后为：" << strtmpChar << endl;

	return 0;
}

