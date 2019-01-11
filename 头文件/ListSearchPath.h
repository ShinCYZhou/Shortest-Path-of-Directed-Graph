#pragma once
#include"GetAdjList.h"

class LISTSEARCHPATH {
private:
	virtual void ListSearchPath(L list, int source, int target) = 0;
};

//寻找next[i][j]
int findl(L l, int i, int j) {
	if (i == j)
		return 0;

	E *p = l.vex[i].first_edge;
	while (p != NULL) {
		if (p->val == j)
			return p->w;
		else
			p = p->next_edge;
	}
	return MAX;
}


//DIJ算法计算最短路径并输出路径
void ListSearchPath(L l, int s, int t){
	//-----------初始化------------------
	int n = l.v;//顶点数
	int len[MAX];//记录路径长度
	int pre[MAX];//记录前置节点,无：-1
	int ISread[MAX] = { 0 };//记录是否已经经过该节点,1表示已访问过，0表示未访问过

	//len[]初始化
	for (int it = 0; it < n; it++) {
		if (it == s)
			len[it] = 0;
		else
			len[it] = MAX;
	}

	E *p = l.vex[s].first_edge;
	while (p != NULL) {
		len[p->val] = p->w;
		pre[p->val] = s;
		p = p->next_edge;	
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
			int tmp = findl(l, i, j);
			if (len[i] + tmp < len[j]) {
				len[j] = len[i] + tmp;
				pre[j] = i;
			}
		}
	}
	/*
	if (len[t] == MAX)//两点之间不可达
		return -1;
	return len[t];//两点之间可达，返回最短路径
	*/


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
		cout << "节点" << s << "与节点" << t << "之间的最短距离为：" << len[t] << ".    最短路径为：";
		while (!tmps.empty()) {
			cout << tmps.top();
			tmps.pop();
			if (!tmps.empty())
				cout << "--->";
		}
		cout << endl;
	}

}