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

	// �ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	// ��¼ְ������
	int empNum;
	// ְ������ָ��
	Worker** empArray;
};