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
	// 显示菜单
	void showMenu();
	// 退出程序
	void exitSystem(); 
	// 添加职工
	void addEmp();
	// 保存文件
	void save();
	// 获取文件数量
	int getEmpNum();
	// 初始化职工
	void initEmp();
	// 显示职工
	void showEmp();
	// id是否存在，存在返回下标，否则返回-1
	int isExist(int id);
	// 删除职工
	void deleteEmp();

	// 判断文件是否为空
	bool fileIsEmpty;
	// 记录职工人数
	int empNum;
	// 职工数组指针
	Worker** empArray;
};