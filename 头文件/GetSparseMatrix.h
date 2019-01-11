#pragma once
#include<string>
#include<sstream>//stringstream
#include<fstream>
#include<vector>

#define MAXN 999
using namespace std;

typedef struct THREE {//三元
	int row, col, val;//行，列，值
}THREE;

typedef struct SPARSE {
	vector<THREE> vec;//三元表;邻接矩阵中0和MAX均不储存，三元表保存稀疏矩阵
	int n;//节点个数
};



class GETSPARSEMATRIX {
public:
	virtual SPARSE GetSparseMatrix(string FileName) = 0;//读取稀疏矩阵，存储格式为.csv文件,每行数据间逗号分隔
														//第一行为节点数，之后为稀疏矩阵三元表
};




SPARSE GetSparseMatrix(string f) {
	ifstream fin(f);
	string s, token;
	THREE t;
	SPARSE sp;

	//获取节点个数
	getline(fin, s);
	sp.n= atoi(s.c_str());

	while (getline(fin, s)) {
		stringstream ss(s);
		int flag = 0;
		while (getline(ss, token, ',')) {
			switch (flag)//注意：顺序执行，需加break
			{
			case 0:
				t.row = atoi(token.c_str());
				flag++;
				break;
			case 1:
				t.col = atoi(token.c_str());
				flag++;
				break;
			case 2:
				t.val = atoi(token.c_str());
				flag++;
				break;
			default:
				break;

			}
			
		}
		sp.vec.push_back(t);
	}
	return sp;
}