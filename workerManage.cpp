#include "workerManage.h"

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
void exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
};