#pragma once
#include<string>
#include<sstream>//stringstream
#include<fstream>
using namespace std;

#define MAX 99

typedef struct GRAPH {
	//int v[MAX];//顶点集
	int Vs;//顶点数
	//Es;边数
	int next[MAX][MAX];//邻接矩阵

};

class GETMATRIX {
public:
	virtual GRAPH GetMatrix(string FileName) = 0;//读取邻接矩阵，存储格式为.csv文件,每行数据间逗号分隔

};

GRAPH GetMatrix(string f) {
	GRAPH g;
	string token, s;
	ifstream fin(f);

	int i = 0;//行
	while (getline(fin, s)) {
		stringstream ss(s);
		int j = 0;
		while (getline(ss, token, ',')) {
			g.next[i][j] = atoi(token.c_str());
			j++;
		}
		i++;
	}
	g.Vs = i;//顶点数

	return g;
}
