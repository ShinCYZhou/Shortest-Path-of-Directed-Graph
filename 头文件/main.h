#pragma once
#include"searchPath.h"
#include"GetSparseMatrix.h"
#include"SparseSearchPath.h"
#include"GetAdjList.h"
#include"ListSearchPath.h"

//接口集合
class MAIN {
public:
	//输入选择
	virtual void choose() = 0;
	
	//有向图输入
	virtual GRAPH GetMatrix(string FileName) = 0;//文件读取邻接矩阵，存储格式为.csv文件,每行数据间逗号分隔
	virtual SPARSE GetSparseMatrix(string FileName) = 0;//文件读取稀疏矩阵，存储格式为.csv文件,每行数据间逗号分隔
														//第一行为节点数，之后为稀疏矩阵三元表
	virtual L GetAdjList() = 0;//直接命令行输入邻接表

	//求有向图中两节点之间的最短距离
	virtual void searchPath(GRAPH graph, int source, int target) = 0;//邻接矩阵
	virtual void SparseSearchPath(SPARSE sp, int source, int target) = 0;//稀疏矩阵
	virtual void ListSearchPath(L list, int source, int target) = 0;//邻接表
};


void choose() {
	cout << "请选择输入方式！1：文件读取邻接矩阵；2：文件读取稀疏矩阵；3：直接命令行输入邻接表" << endl;
	int x, s, t;
	string f;
	cin >> x;

	switch (x) {//未进行详细的错误处理！
	case 1:
		cout << "请输入文件路径！用双斜杠表示路径中的单斜杠！" << endl;
		cin >> f;
		
		cout << "请输入源节点！" << endl;
		cin >> s;

		cout << "请输入目标节点！" << endl;
		cin >> t;

		searchPath(GetMatrix(f), s, t);
		break;
	case 2:
		cout << "请输入文件路径！用双斜杠表示路径中的单斜杠！" << endl;
		cin >> f;

		cout << "请输入源节点！" << endl;
		cin >> s;

		cout << "请输入目标节点！" << endl;
		cin >> t;

		SparseSearchPath(GetSparseMatrix(f), s, t);
		break;
	case 3:
		L l = GetAdjList();

		cout << "请输入源节点！" << endl;
		cin >> s;

		cout << "请输入目标节点！" << endl;
		cin >> t;

		ListSearchPath(l, s, t);
		break;
	default:
		cout << "输入的指令错误！" << endl;
		break;
	}


}