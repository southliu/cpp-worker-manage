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
	// 显示菜单
	void showMenu();
	// 退出程序
	void exitSystem(); 
	// 添加职工
	void addEmp();
	// 保存文件
	void save();

	// 判断文件是否为空
	bool fileIsEmpty;
	// 记录职工人数
	int empNum;
	// 职工数组指针
	Worker** empArray;
};