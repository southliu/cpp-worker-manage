#include "workerManage.h"

WorkerManage::WorkerManage() {
	cout << "WorkerManage构造函数" << endl;
}

WorkerManage::~WorkerManage() {
	cout << "WorkerManage析构函数" << endl;
}

// 显示菜单
void WorkerManage::showMenu() {
	cout << endl
		<< "**********************" << endl
		<< "**** 0-退出职工系统 ****" << endl
		<< "**** 1-添加职工信息 ****" << endl
		<< "**** 2-显示职工信息 ****" << endl
		<< "**** 3-修改职工信息 ****" << endl
		<< "**** 4-删除职工信息 ****" << endl
		<< "**** 5-查找职工信息 ****" << endl
		<< "**** 6-按照编号排序 ****" << endl
		<< "**** 7-清空职工系统 ****" << endl
		<< "**********************" << endl
		<< endl;
}


// 退出程序
void exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
};