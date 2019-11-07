// 三壶谜题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 定义三个壶的最大容量
#define MaxFirst 3
#define MaxSecond 5
#define MaxThird 8


// 状态类
class State
{
public:
	int num[3];						// 记录第三个水壶某个时刻，有多少水
	int MaxCanPull[3];				// 存储每个水壶最大的容量
	State* preState;				// 指向前一个状态的指针
 
public:
	State(int first,int second,int third)
	{
		num[0]=first;
		num[1]=second;
		num[2]=third;	
	}

	void init()
	{		
		MaxCanPull[0] = MaxFirst;
		MaxCanPull[1] = MaxSecond;
		MaxCanPull[2] = MaxThird;
	}
 
	//判断是否可以从from水壶中倒水到to水壶中
	bool canPour(int from,int to)
	{
		//不允许自己给自己倒
		if (from == to)
		{
			return false;
		}

		//源壶为空
		if (num[from]==0)
		{
			return false;
		}
		//目标壶满
		if (num[to] == MaxCanPull[to])
		{
			return false;
		}
		else 
		{
			return true;
		}
	}

	//倒水过程，从from水壶中倒水到to水壶中
	void pour(int from,int to)//倒水过程
	{
		//目标壶还能倒入多少水
		int nCanPull = MaxCanPull[to] - num[to];
		//源壶太多了，只倒部分说
		if (num[from] > nCanPull)
		{
			num[from] = num[from] - nCanPull;
			num[to] = MaxCanPull[to];
		}
		//否则全倒进去
		else
		{
			num[to]=num[to]+num[from];
			num[from]=0;
		}
	}

	//计算hash值
	int CalcuHash()
	{
		return num[0]*100 + num[1]*10 + num[2];
	}
 
};

int _tmain(int argc, _TCHAR* argv[])
{
	//记录下各个状态的hashMap
	//例如，0壶a，1壶b，2壶c，则haspMap[a*100+b*10+c]=true;
	map<int,bool> haspMap;

	State *start=new State(0,0,8);
	start->init();
	State *endState=new State(8,8,8);//只有获得解endState才会改变，赋值全为8为了方便判断是否获得最终解

	//保存所有状态对象
	vector<State> action;
	//把初始状态先加入队列中
	action.push_back(*start);
	
	int n=0;
	//当前状态
	State *Currentstate = start;
	do{
		//双层循环为从i水壶中倒水入j水壶中
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if (Currentstate->canPour(i, j))
					{
						Currentstate->pour(i, j);
						//计算哈希值
						int NumHash = Currentstate->CalcuHash();
						//如果该状态不在hash表中，即为第一次出现该状态
						if (!haspMap[NumHash])
						{
							haspMap[NumHash] = true;
							(Currentstate->preState) = new State(action[n]);
							action.push_back(*Currentstate);

							//找到了则停止遍历
							if (Currentstate->num[0] == 4 || Currentstate->num[1] == 4 || Currentstate->num[2] == 4)
							{
								
								endState = Currentstate;
								i=4;
								break;	
							}
					    }
					}
		
				*Currentstate = action[n];
			}			
		}
		n++;
	}
	while(endState->num[0]==8&&endState->num[1]==8&& n<action.size());

	//输出结果
	cout << endState->num[0] << " " << endState->num[1] << " " << endState->num[2] << endl;
	Currentstate = endState;
	do
	{
		Currentstate = Currentstate->preState;
		cout << Currentstate->num[0] << " " << Currentstate->num[1] << " " << Currentstate->num[2] << endl;
		
	} 
	while (Currentstate->preState != NULL);

	return 0;
}

