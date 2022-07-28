#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class WorkerManage {
public:
	WorkerManage();
	~WorkerManage();
	// 显示菜单
	void showMenu();
	// 退出程序
	void exitSystem(); 
	// 添加职工
	void addEmp();

	// 记录职工人数
	int empNum;
	// 职工数组指针
	Worker** empArray;
};