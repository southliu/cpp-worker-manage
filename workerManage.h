#pragma once
#include <iostream>
#include <fstream>
#include<string>
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
	// ��ȡ�ļ�����
	int getEmpNum();
	// ��ʼ��ְ��
	void initEmp();
	// ��ʾְ��
	void showEmp();
	// id�Ƿ���ڣ����ڷ����±꣬���򷵻�-1
	int isExist(int id);
	// ɾ��ְ��
	void deleteEmp();

	// �ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	// ��¼ְ������
	int empNum;
	// ְ������ָ��
	Worker** empArray;
};