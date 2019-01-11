#pragma once
#include "GetSparseMatrix.h"
#include"GetMatrix.h"//MAX,stack
#include<algorithm>//sort()



class SPARSESEARCHPATH {

public:
	//求有向图中两节点之间的最短距离---稀疏矩阵
	virtual void SparseSearchPath(SPARSE sp, int source, int target) = 0;//source为源节点，target为目标节点
};

//按行排序
bool compare_row(const THREE &g1,const THREE &g2) {//const &：形参，值会变化
	return g1.row < g2.row;
}


//寻找next[i][j],v已经按行排序
int finds(vector<THREE> v,int i,int j) {
	if (i == j)
		return 0;
	for (int it = 0; it < v.size(); it++) {//寻找row==s，初始化
		if (v[it].row < i);
		else if (v[it].row == i){
			if (v[it].col == j)
				return v[it].val;
			
		}
		else
			return MAX;
	}
}


//DIJ算法计算最短路径并输出路径
void  SparseSearchPath(SPARSE sp, int s, int t) {
	//-----------初始化------------------
	int n = sp.n;//顶点数
	int len[MAX] = {};//记录路径长度
	int pre[MAX] = {};//记录前置节点,无：-1

	int next[MAX] = {};//寻找col==t，相当于next[k][t]
	int ISread[MAX] = { };//记录是否已经经过该节点,1表示已访问过，0表示未访问过

	//按行排序
	sort(sp.vec.begin(), sp.vec.end(), compare_row);

	//len[]和pre[]初始化
	for (int it = 0; it < n; it++) {

		pre[it] = -1;

		if (it == s) 
			len[it] = 0;	
		else
			len[it] = MAX;
		
	}


	for (int it = 0; it < sp.vec.size(); it++) {//寻找row==s，初始化
		if (sp.vec[it].row < s);
		else if (sp.vec[it].row > s)
			break;
		else {
			len[sp.vec[it].col] = sp.vec[it].val;
			pre[sp.vec[it].col] = s;
		}
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
			int tmp = finds(sp.vec, i, j);//g.next[i][j]
			if ( len[i] + tmp < len[j]) {
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