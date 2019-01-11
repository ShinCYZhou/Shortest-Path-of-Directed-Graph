#pragma once
#include<string>
#include<sstream>//stringstream
#include<fstream>
#include<vector>

#define MAXN 999
using namespace std;

typedef struct THREE {//��Ԫ
	int row, col, val;//�У��У�ֵ
}THREE;

typedef struct SPARSE {
	vector<THREE> vec;//��Ԫ��;�ڽӾ�����0��MAX�������棬��Ԫ����ϡ�����
	int n;//�ڵ����
};



class GETSPARSEMATRIX {
public:
	virtual SPARSE GetSparseMatrix(string FileName) = 0;//��ȡϡ����󣬴洢��ʽΪ.csv�ļ�,ÿ�����ݼ䶺�ŷָ�
														//��һ��Ϊ�ڵ�����֮��Ϊϡ�������Ԫ��
};




SPARSE GetSparseMatrix(string f) {
	ifstream fin(f);
	string s, token;
	THREE t;
	SPARSE sp;

	//��ȡ�ڵ����
	getline(fin, s);
	sp.n= atoi(s.c_str());

	while (getline(fin, s)) {
		stringstream ss(s);
		int flag = 0;
		while (getline(ss, token, ',')) {
			switch (flag)//ע�⣺˳��ִ�У����break
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