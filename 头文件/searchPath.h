#pragma once
#include "GetMatrix.h"//˫���ţ�����MAX��GRAPH�ṹ��
#include<stack>

class SEARCHPATH {
	
	public:
		//������ͼ�����ڵ�֮�����̾���
		virtual void searchPath(GRAPH graph,int source,int target) = 0;//sourceΪԴ�ڵ㣬targetΪĿ��ڵ㣬graphΪ����ͼ
};


//DIJ�㷨�������·�������·��
void searchPath(GRAPH g, int s, int t) {
	//-----------��ʼ��------------------
	int n = g.Vs;//������
	int pre[MAX];//��¼ǰ�ýڵ�,�ޣ�-1
	int len[MAX];//��¼·������
	int ISread[MAX] = {0};//��¼�Ƿ��Ѿ������ýڵ�,1��ʾ�ѷ��ʹ���0��ʾδ���ʹ�

	for (int i = 0; i < n; i++) {
		
		if (g.next[s][i] < MAX)
			pre[i] = s;
		else
			pre[i] = -1;
		
		len[i] = g.next[s][i];
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
			if ( len[i] + g.next[i][j] < len[j]) {
				len[j] = len[i] + g.next[i][j];
				pre[j] = i;
			}
		}
	}




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
		cout << "�ڵ�" << s << "��ڵ�" << t << "֮�����̾���Ϊ��" << len[t] << ".    ���·��Ϊ��" ;
		while (!tmps.empty()) {
			cout << tmps.top();
			tmps.pop();
			if(!tmps.empty())
				cout<< "--->";
		}
		cout << endl;
	}
}