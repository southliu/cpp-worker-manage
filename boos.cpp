#include "boss.h"

Boss::Boss(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
};

// ��ʾ������Ϣ
void Boss::showInfo() {
	cout << "ְ����ţ�" << this->id
		<< "\nְ�����ƣ�" << this->name
		<< "\n��λ��" << this->getDeptName()
		<< "\n��λְ�𣺷��侭������" << endl;
};

// ��ȡ��λ����
string Boss::getDeptName() {
	return string("�ϰ�");
};