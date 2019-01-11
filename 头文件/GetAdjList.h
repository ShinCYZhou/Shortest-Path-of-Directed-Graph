#pragma once
#include<iostream>

#define MAX 99



//�߱�
typedef struct EDGE {
	
	int val;//�ڽӶ�����
	int w;//����Ȩֵ
	EDGE *next_edge;//������E
}E;

//����
typedef struct VERTEX {
	int e;//����
	int val;//������
	EDGE *first_edge;//ָ��߱��ͷ
}V;



//�ڽӱ�
typedef struct ADJ_LIST {
	int v;//�������
	V vex[MAX];//�����
}L;



class GETADJLIST {
public:
	virtual L GetAdjList() = 0;//ֱ�������ڽӱ�
};

//ֱ�����벢�����ڽӱ�
L GetAdjList() {
	L l;

	cout << "���ȸ���������ʾ��������ͼ��" << endl << "�����붥�������" << endl;
	cin >> l.v;
	for (int i = 0; i < l.v; i++) {
		cout << "�����붥��" << i << "�ĳ���������" << endl;
		cin >> l.vex[i].e;
		l.vex[i].val = i;
		//cout << l.vex[i].val << endl;//test

		if (l.vex[i].e == 0) {
			l.vex[i].first_edge = NULL;//
		}
		else {
			int flag = 0;//�жϱ߱��ͷ
			E *p = new E();//ָ��

			for (int j = 0; j < l.vex[i].e; j++) {
				if (flag == 0) {
					flag = 1;
					l.vex[i].first_edge = new E();//ע�⣡һ��Ҫ��ʼ��

					cout << "���������" << j << "ָ��Ķ��㣺" << endl;
					cin >> l.vex[i].first_edge->val;
					
					cout << "���������" << j << "�ϵ�Ȩֵ��" << endl;
					cin >> l.vex[i].first_edge->w;
					
					p = l.vex[i].first_edge;
					//cout << p->val << endl;//test
					//cout << p->w << endl;//test
				}
				else {
					p->next_edge = new E();//ע�⣡һ��Ҫ��ʼ��
					p = p->next_edge;

					cout << "���������" << j << "ָ��Ķ��㣺" << endl;
					cin >> p->val;
					cout << "���������" << j << "�ϵ�Ȩֵ��" << endl;
					cin >> p->w;

					//cout << p->val << endl;//test
					//cout << p->w << endl;//test
				}

			}
		}
		
	}
	return l;
}