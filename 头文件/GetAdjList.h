#pragma once
#include<iostream>

#define MAX 99



//边表
typedef struct EDGE {
	
	int val;//邻接顶点编号
	int w;//边上权值
	EDGE *next_edge;//不能用E
}E;

//顶点
typedef struct VERTEX {
	int e;//边数
	int val;//顶点编号
	EDGE *first_edge;//指向边表的头
}V;



//邻接表
typedef struct ADJ_LIST {
	int v;//顶点个数
	V vex[MAX];//顶点表
}L;



class GETADJLIST {
public:
	virtual L GetAdjList() = 0;//直接输入邻接表
};

//直接输入并建立邻接表
L GetAdjList() {
	L l;

	cout << "请先根据以下提示输入有向图！" << endl << "请输入顶点个数：" << endl;
	cin >> l.v;
	for (int i = 0; i < l.v; i++) {
		cout << "请输入顶点" << i << "的出边条数：" << endl;
		cin >> l.vex[i].e;
		l.vex[i].val = i;
		//cout << l.vex[i].val << endl;//test

		if (l.vex[i].e == 0) {
			l.vex[i].first_edge = NULL;//
		}
		else {
			int flag = 0;//判断边表的头
			E *p = new E();//指针

			for (int j = 0; j < l.vex[i].e; j++) {
				if (flag == 0) {
					flag = 1;
					l.vex[i].first_edge = new E();//注意！一定要初始化

					cout << "请输入出边" << j << "指向的顶点：" << endl;
					cin >> l.vex[i].first_edge->val;
					
					cout << "请输入出边" << j << "上的权值：" << endl;
					cin >> l.vex[i].first_edge->w;
					
					p = l.vex[i].first_edge;
					//cout << p->val << endl;//test
					//cout << p->w << endl;//test
				}
				else {
					p->next_edge = new E();//注意！一定要初始化
					p = p->next_edge;

					cout << "请输入出边" << j << "指向的顶点：" << endl;
					cin >> p->val;
					cout << "请输入出边" << j << "上的权值：" << endl;
					cin >> p->w;

					//cout << p->val << endl;//test
					//cout << p->w << endl;//test
				}

			}
		}
		
	}
	return l;
}