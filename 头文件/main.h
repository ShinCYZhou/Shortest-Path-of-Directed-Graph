#pragma once
#include"searchPath.h"
#include"GetSparseMatrix.h"
#include"SparseSearchPath.h"
#include"GetAdjList.h"
#include"ListSearchPath.h"

//�ӿڼ���
class MAIN {
public:
	//����ѡ��
	virtual void choose() = 0;
	
	//����ͼ����
	virtual GRAPH GetMatrix(string FileName) = 0;//�ļ���ȡ�ڽӾ��󣬴洢��ʽΪ.csv�ļ�,ÿ�����ݼ䶺�ŷָ�
	virtual SPARSE GetSparseMatrix(string FileName) = 0;//�ļ���ȡϡ����󣬴洢��ʽΪ.csv�ļ�,ÿ�����ݼ䶺�ŷָ�
														//��һ��Ϊ�ڵ�����֮��Ϊϡ�������Ԫ��
	virtual L GetAdjList() = 0;//ֱ�������������ڽӱ�

	//������ͼ�����ڵ�֮�����̾���
	virtual void searchPath(GRAPH graph, int source, int target) = 0;//�ڽӾ���
	virtual void SparseSearchPath(SPARSE sp, int source, int target) = 0;//ϡ�����
	virtual void ListSearchPath(L list, int source, int target) = 0;//�ڽӱ�
};


void choose() {
	cout << "��ѡ�����뷽ʽ��1���ļ���ȡ�ڽӾ���2���ļ���ȡϡ�����3��ֱ�������������ڽӱ�" << endl;
	int x, s, t;
	string f;
	cin >> x;

	switch (x) {//δ������ϸ�Ĵ�����
	case 1:
		cout << "�������ļ�·������˫б�ܱ�ʾ·���еĵ�б�ܣ�" << endl;
		cin >> f;
		
		cout << "������Դ�ڵ㣡" << endl;
		cin >> s;

		cout << "������Ŀ��ڵ㣡" << endl;
		cin >> t;

		searchPath(GetMatrix(f), s, t);
		break;
	case 2:
		cout << "�������ļ�·������˫б�ܱ�ʾ·���еĵ�б�ܣ�" << endl;
		cin >> f;

		cout << "������Դ�ڵ㣡" << endl;
		cin >> s;

		cout << "������Ŀ��ڵ㣡" << endl;
		cin >> t;

		SparseSearchPath(GetSparseMatrix(f), s, t);
		break;
	case 3:
		L l = GetAdjList();

		cout << "������Դ�ڵ㣡" << endl;
		cin >> s;

		cout << "������Ŀ��ڵ㣡" << endl;
		cin >> t;

		ListSearchPath(l, s, t);
		break;
	default:
		cout << "�����ָ�����" << endl;
		break;
	}


}