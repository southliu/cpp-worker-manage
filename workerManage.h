#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "worker.h"
#define FILE_NAME "emp.txt"

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
	// �����ļ�
	void save();

	// ��¼ְ������
	int empNum;
	// ְ������ָ��
	Worker** empArray;
};