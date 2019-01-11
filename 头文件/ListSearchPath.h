#pragma once
#include"GetAdjList.h"

class LISTSEARCHPATH {
private:
	virtual void ListSearchPath(L list, int source, int target) = 0;
};

//Ѱ��next[i][j]
int findl(L l, int i, int j) {
	if (i == j)
		return 0;

	E *p = l.vex[i].first_edge;
	while (p != NULL) {
		if (p->val == j)
			return p->w;
		else
			p = p->next_edge;
	}
	return MAX;
}


//DIJ�㷨�������·�������·��
void ListSearchPath(L l, int s, int t){
	//-----------��ʼ��------------------
	int n = l.v;//������
	int len[MAX];//��¼·������
	int pre[MAX];//��¼ǰ�ýڵ�,�ޣ�-1
	int ISread[MAX] = { 0 };//��¼�Ƿ��Ѿ������ýڵ�,1��ʾ�ѷ��ʹ���0��ʾδ���ʹ�

	//len[]��ʼ��
	for (int it = 0; it < n; it++) {
		if (it == s)
			len[it] = 0;
		else
			len[it] = MAX;
	}

	E *p = l.vex[s].first_edge;
	while (p != NULL) {
		len[p->val] = p->w;
		pre[p->val] = s;
		p = p->next_edge;	
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
			int tmp = findl(l, i, j);
			if (len[i] + tmp < len[j]) {
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