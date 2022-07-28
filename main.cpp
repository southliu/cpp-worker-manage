#include <iostream>
using namespace std;
#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {
	Worker* worker;
	worker = new Employee(1, "����", 3);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "�ϰ�", 1);
	worker->showInfo();
	delete worker;

	//int choice = -1;
	//while (choice != 0) {
	//	WorkerManage wm;
	//	wm.showMenu();

	//	cout << "����������ѡ��:" << endl;
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	// 0���˳�ְ��ϵͳ
	//	case 0:
	//		wm.exitSystem();
	//		break;
	//	// 1�����ְ����Ϣ
	//	case 1:
	//		break;
	//	// 2����ʾְ����Ϣ
	//	case 2:
	//		break;
	//	// 3���޸�ְ����Ϣ
	//	case 3:
	//		break;
	//	// 4��ɾ��ְ����Ϣ
	//	case 4:
	//		break;
	//	// 5������ְ����Ϣ
	//	case 5:
	//		break;
	//	// 6�����ձ������
	//	case 6:
	//		break;
	//	// 7�����ְ��ϵͳ
	//	case 7:
	//		break;
	//	default:
	//		break;
	//	}
	//};

	return 0;
}