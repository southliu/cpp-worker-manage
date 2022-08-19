#include <iostream>
using namespace std;
#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {
	int choice = -1;
	while (choice != 0) {
		WorkerManage wm;
		wm.showMenu();

		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		// 0���˳�ְ��ϵͳ
		case 0:
			wm.exitSystem();
			break;
		// 1�����ְ����Ϣ
		case 1:
			wm.addEmp();
			break;
		// 2����ʾְ����Ϣ
		case 2:
			wm.showEmp();
			break;
		// 3���޸�ְ����Ϣ
		case 3:
			wm.updateEmp();
			break;
		// 4��ɾ��ְ����Ϣ
		case 4:
			wm.deleteEmp();
			break;
		// 5������ְ����Ϣ
		case 5:
			wm.findEmp();
			break;
		// 6�����ձ������
		case 6:
			wm.sortEmp();
			break;
		// 7�����ְ��ϵͳ
		case 7:
			wm.clearEmp();
			break;
		default:
			break;
		}
	};

	return 0;
}