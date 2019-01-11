#include<iostream>
#include "main.h"

using namespace std;

int main(){
	choose();
	/*-------------测试用例--------
	1：
	C:\\Users\\lenovo\\Desktop\\test.csv
	C:\\Users\\lenovo\\Desktop\\test3.csv

	2：
	C:\\Users\\lenovo\\Desktop\\test2.csv

	3：
	3
	2
	1
	5
	2
	3
	0
	1
	1
	1
	------------------------------*/


	/*
	//---------------------邻接矩阵---------------------------
	//图的邻接矩阵文件读取 测试
	GRAPH g = GetMatrix("C:\\Users\\lenovo\\Desktop\\test.csv");
	cout << g.Vs << endl;
	for (int p = 0; p < g.Vs; p++) {
		for (int q = 0; q < g.Vs; q++)
			cout << g.next[p][q] << "  ";
		cout << endl;
	}

	//Dij最短路径 测试
	for (int p = 0; p < g.Vs; p++) {
		for (int q = 0; q < g.Vs; q++)
			//cout << searchPath(g, p, q)<< "  ";
			searchPath(g, p, q);
		//cout << endl;
	}

	//-----------------------------------------------------------


	
	//-------------------稀疏矩阵--------------------------------
	//图的稀疏矩阵文件读取 测试
	SPARSE sp = GetSparseMatrix("C:\\Users\\lenovo\\Desktop\\test2.csv");
	cout << sp.n << endl;
	for (int i = 0; i < sp.vec.size(); i++)
		cout << sp.vec[i].row << "  " << sp.vec[i].col << "  " << sp.vec[i].val << endl;

	//Dij最短路径 测试
	for (int p = 0; p < sp.n; p++) {
		for (int q = 0; q < sp.n; q++)
			//cout << SparseSearchPath(sp, p, q) << "  ";
			SparseSearchPath(sp, p, q);
		//cout << endl;
	}
	//---------------------------------------------------------------
	

	//--------------------邻接表-------------------------------------
	//图的邻接表直接输入 测试
	L l = GetAdjList();
	cout << "共" << l.v << "个节点" << endl;

	for (int i = 0; i < l.v; i++) {
		E *p = l.vex[i].first_edge;
		if (p == NULL) {
			cout << "顶点" <<i << "无出边" << endl;
		}
		else {
			while (p != NULL) {
				cout << "顶点" << i << "：" << p->val << " " << p->w << endl;
				p = p->next_edge;
			}
		}
		
	}


	//Dij最短路径 测试
	for (int p = 0; p < l.v; p++) {
		for (int q = 0; q < l.v; q++)
			//cout << ListSearchPath(l, p, q) << "  ";
			ListSearchPath(l, p, q);
		//cout << endl;
	}
	//---------------------------------------------------------------
	*/
	return 0;
}