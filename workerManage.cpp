#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManage::WorkerManage() {
	cout << "WorkerManage���캯��" << endl;
}

WorkerManage::~WorkerManage() {
	cout << "WorkerManage��������" << endl;
}

// ��ʾ�˵�
void WorkerManage::showMenu() {
	cout << endl
		<< "**********************" << endl
		<< "**** 0-�˳�ְ��ϵͳ ****" << endl
		<< "**** 1-���ְ����Ϣ ****" << endl
		<< "**** 2-��ʾְ����Ϣ ****" << endl
		<< "**** 3-�޸�ְ����Ϣ ****" << endl
		<< "**** 4-ɾ��ְ����Ϣ ****" << endl
		<< "**** 5-����ְ����Ϣ ****" << endl
		<< "**** 6-���ձ������ ****" << endl
		<< "**** 7-���ְ��ϵͳ ****" << endl
		<< "**********************" << endl
		<< endl;
}


// �˳�����
void WorkerManage::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
};

// ���ְ��
void WorkerManage::addEmp() {
	// ���ְ������
	int addNum = 0;
	cout << "��������ӵ�ְ��������" << endl;
	cin >> addNum;

	if (addNum > 0) {
		int newSize = this->empNum + addNum;
		Worker** newSpace = new Worker*[newSize];
		
		// ԭ�����ݸ�ֵ
		if (this->empArray != NULL) {
			for (int i = 0; i < this->empNum; i++) {
				newSpace[i] = this->empArray[i];
			};
		};

		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int choice;

			cout << "�������" << i + 1 << "��ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "��ְ����λ��"
				<< "\n1����ְͨ��"
				<< "\n2������"
				<< "\n3���ϰ�" << endl;
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

		// ����ָ������
		this->empArray = newSpace;
		// ���ȸ�ֵ
		this->empNum = newSize;
		// �ͷſռ�
		delete this->empArray;
		// ������
		cout << "�ɹ����" << addNum << "��ְ��";
	}
	else {
		cout << "��������ȷ��ְ������" << endl;
	}
	system("pause");
	system("cls");
};