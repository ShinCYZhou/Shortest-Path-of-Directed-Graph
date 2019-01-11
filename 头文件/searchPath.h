#pragma once
#include "GetMatrix.h"//双引号；包含MAX和GRAPH结构体
#include<stack>

class SEARCHPATH {
	
	public:
		//求有向图中两节点之间的最短距离
		virtual void searchPath(GRAPH graph,int source,int target) = 0;//source为源节点，target为目标节点，graph为有向图
};


//DIJ算法计算最短路径并输出路径
void searchPath(GRAPH g, int s, int t) {
	//-----------初始化------------------
	int n = g.Vs;//顶点数
	int pre[MAX];//记录前置节点,无：-1
	int len[MAX];//记录路径长度
	int ISread[MAX] = {0};//记录是否已经经过该节点,1表示已访问过，0表示未访问过

	for (int i = 0; i < n; i++) {
		
		if (g.next[s][i] < MAX)
			pre[i] = s;
		else
			pre[i] = -1;
		
		len[i] = g.next[s][i];
	}
	ISread[s] = 1;
	//----------------------------------------

	//------------过程---------------------
	for (int i = 0; i < n; i++) {

		if (ISread[i] == 0 && len[i] < MAX) {//s->i->t;i未被访问过，且s到i之间有路径
			ISread[i] = 1;//i已读
		}
		


		//更新从s出发到已经访问过的顶点最短距离，经过i节点or不经过节点，比较距离谁短
		for (int j = 0; j < n; j++) {
			if ( len[i] + g.next[i][j] < len[j]) {
				len[j] = len[i] + g.next[i][j];
				pre[j] = i;
			}
		}
	}




	//-----------------------   输出结果    ---------------------------------------
	if (len[t] == MAX) {//两点之间不可达
		//return -1;       //test
		cout << "节点" << s << "与节点" << t << "之间不可达！" << endl;
	}
	
	else {
		//return len[t];//两点之间可达，返回最短路径   //test
		int tmp = t;
		stack<int> tmps;
		//保存路径，先进后出
		while (tmp != s) {
			tmps.push(tmp);
			tmp = pre[tmp];
		}
		tmps.push(s);


		//输出路径
		cout << "节点" << s << "与节点" << t << "之间的最短距离为：" << len[t] << ".    最短路径为：" ;
		while (!tmps.empty()) {
			cout << tmps.top();
			tmps.pop();
			if(!tmps.empty())
				cout<< "--->";
		}
		cout << endl;
	}
}