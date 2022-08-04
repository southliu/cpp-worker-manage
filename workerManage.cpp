#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManage::WorkerManage() {
	cout << "WorkerManage构造函数" << endl;
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	// 判断文件是否为空
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->fileIsEmpty = true;
		// 初始化配置
		this->empNum = 0;
		this->empArray = NULL;
		// 关闭文件
		ifs.close();
		return;
	};

	// 文件存在，但没数据
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		// 初始化配置
		this->empNum = 0;
		this->empArray = NULL;
		// 关闭文件
		ifs.close();
		return;
	}

	// 文件存在，且有数据
	int num = this->getEmpNum();
	cout << "职工人数：" << num << endl;
	this->empNum = num;
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
			int choice = -1;

			cout << "请输入第" << i + 1 << "个职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工姓名：" << endl;
			cin >> name;
			while (true) {
				if (choice == 1 || choice == 2 || choice == 3) {
					break;
				};
				cout << "输入参数有误" << endl;
				cout << "请输入第" << i + 1 << "个职工岗位："
					<< "\n1、普通职工"
					<< "\n2、经理"
					<< "\n3、老板" << endl;
				cin >> choice;
			};

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
			};

			// 创建职工保存进数组 
			newSpace[this->empNum + i] = worker;
		};

		// 释放空间
		delete[] this->empArray;
		// 更改指针内容
		this->empArray = newSpace;
		// 长度赋值
		this->empNum = newSize;
		// 更新职工不为空情况
		this->fileIsEmpty = false;
		// 完成添加
		cout << "成功添加" << addNum << "个职工";
		// 保存文件
		save();
	}
	else {
		cout << "请输入正确的职工数量" << endl;
	}
	system("pause");
	system("cls");
};

// 保存文件
void WorkerManage::save() {
	ofstream ofs;
	// 打开文件
	ofs.open(FILE_NAME, ios::out);

	for (int i = 0; i < this->empNum; i++) {

		ofs << this->empArray[i]->id << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->deptId << endl;
	};

	// 关闭文件
	ofs.close();
};


// 获取文件数量
int WorkerManage::getEmpNum() {
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	int num = 0;
	int id;
	string name;
	int deptId;

	while (ifs >> id && ifs >> name && ifs >> deptId) {
		// 记录人数
		num++;
	};

	// 关闭文件
	ifs.close();

	return num;
};


// 初始化职工
void WorkerManage::initEmp() {
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	int index = 0;
	int id;
	string name;
	int deptId;

	while (ifs >> id && ifs >> name && ifs >> deptId) {
		Worker* worker = NULL;
		switch (deptId)
		{
		case 1:
			worker = new Employee(id, name, deptId);
			break;
		case 2:
			worker = new Manager(id, name, deptId);
			break;
		case 3:
			worker = new Boss(id, name, deptId);
			break;
		default:
			break;
		};
		// 存放数组中
		this->empArray[index] = worker;
		index++;
	};

	// 关闭文件
	ifs.close();
};