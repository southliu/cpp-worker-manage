#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

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
void WorkerManage::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
};

// 添加职工
void WorkerManage::addEmp() {
	// 添加职工数量
	int addNum = 0;
	cout << "请输入添加的职工数量：" << endl;
	cin >> addNum;

	if (addNum > 0) {
		int newSize = this->empNum + addNum;
		Worker** newSpace = new Worker*[newSize];
		
		// 原有数据赋值
		if (this->empArray != NULL) {
			for (int i = 0; i < this->empNum; i++) {
				newSpace[i] = this->empArray[i];
			};
		};

		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int choice;

			cout << "请输入第" << i + 1 << "个职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工姓名：" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个职工岗位："
				<< "\n1、普通职工"
				<< "\n2、经理"
				<< "\n3、老板" << endl;
			cin >> choice;

			Worker* worker = NULL;
			switch (choice)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			default:
				worker = new Boss(id, name, 3);
				break;
			}

			newSpace[this->empNum + i] = worker;
		}

		// 更改指针内容
		this->empArray = newSpace;
		// 长度赋值
		this->empNum = newSize;
		// 释放空间
		delete this->empArray;
		// 完成添加
		cout << "成功添加" << addNum << "个职工";
	}
	else {
		cout << "请输入正确的职工数量" << endl;
	}
	system("pause");
	system("cls");
};