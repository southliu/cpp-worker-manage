#include "employee.h"

Employee::Employee(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
};

// ��ʾ������Ϣ
void Employee::showInfo() {
	cout << "ְ����ţ�" << this->id
		<< "\nְ�����ƣ�" << this->name
		<< "\n��λ��" << this->getDeptName()
		<< "\n��λְ����ɾ�����������" << endl;
};

// ��ȡ��λ����
string Employee::getDeptName() {
	return string("Ա��");
};