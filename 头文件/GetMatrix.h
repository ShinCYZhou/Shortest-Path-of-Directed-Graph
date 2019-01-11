#pragma once
#include<string>
#include<sstream>//stringstream
#include<fstream>
using namespace std;

#define MAX 99

typedef struct GRAPH {
	//int v[MAX];//���㼯
	int Vs;//������
	//Es;����
	int next[MAX][MAX];//�ڽӾ���

};

class GETMATRIX {
public:
	virtual GRAPH GetMatrix(string FileName) = 0;//��ȡ�ڽӾ��󣬴洢��ʽΪ.csv�ļ�,ÿ�����ݼ䶺�ŷָ�

};

GRAPH GetMatrix(string f) {
	GRAPH g;
	string token, s;
	ifstream fin(f);

	int i = 0;//��
	while (getline(fin, s)) {
		stringstream ss(s);
		int j = 0;
		while (getline(ss, token, ',')) {
			g.next[i][j] = atoi(token.c_str());
			j++;
		}
		i++;
	}
	g.Vs = i;//������

	return g;
}
