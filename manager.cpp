#include "manager.h"

Manager::Manager(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
};

// 显示个人信息
void Manager::showInfo() {
	cout << "职工编号：" << this->id
		<< "\n职工名称：" << this->name
		<< "\n岗位：" << this->getDeptName()
		<< "\n岗位职责：分配员工任务" << endl;
};

// 获取岗位名称
string Manager::getDeptName() {
	return string("老板");
};