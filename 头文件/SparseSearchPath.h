#pragma once
#include "GetSparseMatrix.h"
#include"GetMatrix.h"//MAX,stack
#include<algorithm>//sort()



class SPARSESEARCHPATH {

public:
	//������ͼ�����ڵ�֮�����̾���---ϡ�����
	virtual void SparseSearchPath(SPARSE sp, int source, int target) = 0;//sourceΪԴ�ڵ㣬targetΪĿ��ڵ�
};

//��������
bool compare_row(const THREE &g1,const THREE &g2) {//const &���βΣ�ֵ��仯
	return g1.row < g2.row;
}


//Ѱ��next[i][j],v�Ѿ���������
int finds(vector<THREE> v,int i,int j) {
	if (i == j)
		return 0;
	for (int it = 0; it < v.size(); it++) {//Ѱ��row==s����ʼ��
		if (v[it].row < i);
		else if (v[it].row == i){
			if (v[it].col == j)
				return v[it].val;
			
		}
		else
			return MAX;
	}
}


//DIJ�㷨�������·�������·��
void  SparseSearchPath(SPARSE sp, int s, int t) {
	//-----------��ʼ��------------------
	int n = sp.n;//������
	int len[MAX] = {};//��¼·������
	int pre[MAX] = {};//��¼ǰ�ýڵ�,�ޣ�-1

	int next[MAX] = {};//Ѱ��col==t���൱��next[k][t]
	int ISread[MAX] = { };//��¼�Ƿ��Ѿ������ýڵ�,1��ʾ�ѷ��ʹ���0��ʾδ���ʹ�

	//��������
	sort(sp.vec.begin(), sp.vec.end(), compare_row);

	//len[]��pre[]��ʼ��
	for (int it = 0; it < n; it++) {

		pre[it] = -1;

		if (it == s) 
			len[it] = 0;	
		else
			len[it] = MAX;
		
	}


	for (int it = 0; it < sp.vec.size(); it++) {//Ѱ��row==s����ʼ��
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

	//------------����---------------------
	for (int i = 0; i < n; i++) {

		if (ISread[i] == 0 && len[i] < MAX) {//s->i->t;iδ�����ʹ�����s��i֮����·��
			ISread[i] = 1;//i�Ѷ�
		}

		

		
		//���´�s�������Ѿ����ʹ��Ķ�����̾��룬����i�ڵ�or�������ڵ㣬�ȽϾ���˭��
		for (int j = 0; j < n; j++) {
			int tmp = finds(sp.vec, i, j);//g.next[i][j]
			if ( len[i] + tmp < len[j]) {
				len[j] = len[i] + tmp;
				pre[j] = i;
			}
		}
	}
	/*
	if (len[t] == MAX)//����֮�䲻�ɴ�
		return -1;
	return len[t];//����֮��ɴ�������·��
	*/



	//-----------------------   ������    ---------------------------------------
	if (len[t] == MAX) {//����֮�䲻�ɴ�
		//return -1;       //test
		cout << "�ڵ�" << s << "��ڵ�" << t << "֮�䲻�ɴ" << endl;
	}

	else {
		//return len[t];//����֮��ɴ�������·��   //test
		int tmp = t;
		stack<int> tmps;
		//����·�����Ƚ����
		while (tmp != s) {
			tmps.push(tmp);
			tmp = pre[tmp];
		}
		tmps.push(s);


		//���·��
		cout << "�ڵ�" << s << "��ڵ�" << t << "֮�����̾���Ϊ��" << len[t] << ".    ���·��Ϊ��";
		while (!tmps.empty()) {
			cout << tmps.top();
			tmps.pop();
			if (!tmps.empty())
				cout << "--->";
		}
		cout << endl;
	}

}