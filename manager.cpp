#include "manager.h"

Manager::Manager(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
};

// ��ʾ������Ϣ
void Manager::showInfo() {
	cout << "ְ����ţ�" << this->id
		<< "\nְ�����ƣ�" << this->name
		<< "\n��λ��" << this->getDeptName()
		<< "\n��λְ�𣺷���Ա������" << endl;
};

// ��ȡ��λ����
string Manager::getDeptName() {
	return string("�ϰ�");
};