#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class WorkerManage {
public:
	WorkerManage();
	~WorkerManage();
	// ��ʾ�˵�
	void showMenu();
	// �˳�����
	void exitSystem(); 
	// ���ְ��
	void addEmp();

	// ��¼ְ������
	int empNum;
	// ְ������ָ��
	Worker** empArray;
};