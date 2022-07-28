#include <iostream>
using namespace std;
#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {
	Worker* worker;
	worker = new Employee(1, "张三", 3);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "经理", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "老板", 1);
	worker->showInfo();
	delete worker;

	//int choice = -1;
	//while (choice != 0) {
	//	WorkerManage wm;
	//	wm.showMenu();

	//	cout << "请输入您的选择:" << endl;
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	// 0、退出职工系统
	//	case 0:
	//		wm.exitSystem();
	//		break;
	//	// 1、添加职工信息
	//	case 1:
	//		break;
	//	// 2、显示职工信息
	//	case 2:
	//		break;
	//	// 3、修改职工信息
	//	case 3:
	//		break;
	//	// 4、删除职工信息
	//	case 4:
	//		break;
	//	// 5、查找职工信息
	//	case 5:
	//		break;
	//	// 6、按照编号排序
	//	case 6:
	//		break;
	//	// 7、清空职工系统
	//	case 7:
	//		break;
	//	default:
	//		break;
	//	}
	//};

	return 0;
}