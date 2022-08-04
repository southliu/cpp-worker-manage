#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManage::WorkerManage() {
	cout << "WorkerManage���캯��" << endl;
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	// �ж��ļ��Ƿ�Ϊ��
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->fileIsEmpty = true;
		// ��ʼ������
		this->empNum = 0;
		this->empArray = NULL;
		// �ر��ļ�
		ifs.close();
		return;
	};

	// �ļ����ڣ���û����
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		// ��ʼ������
		this->empNum = 0;
		this->empArray = NULL;
		// �ر��ļ�
		ifs.close();
		return;
	}

	// �ļ����ڣ���������
	int num = this->getEmpNum();
	cout << "ְ��������" << num << endl;
	this->empNum = num;
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
			int choice = -1;

			cout << "�������" << i + 1 << "��ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;
			while (true) {
				if (choice == 1 || choice == 2 || choice == 3) {
					break;
				};
				cout << "�����������" << endl;
				cout << "�������" << i + 1 << "��ְ����λ��"
					<< "\n1����ְͨ��"
					<< "\n2������"
					<< "\n3���ϰ�" << endl;
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

			// ����ְ����������� 
			newSpace[this->empNum + i] = worker;
		};

		// �ͷſռ�
		delete[] this->empArray;
		// ����ָ������
		this->empArray = newSpace;
		// ���ȸ�ֵ
		this->empNum = newSize;
		// ����ְ����Ϊ�����
		this->fileIsEmpty = false;
		// ������
		cout << "�ɹ����" << addNum << "��ְ��";
		// �����ļ�
		save();
	}
	else {
		cout << "��������ȷ��ְ������" << endl;
	}
	system("pause");
	system("cls");
};

// �����ļ�
void WorkerManage::save() {
	ofstream ofs;
	// ���ļ�
	ofs.open(FILE_NAME, ios::out);

	for (int i = 0; i < this->empNum; i++) {

		ofs << this->empArray[i]->id << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->deptId << endl;
	};

	// �ر��ļ�
	ofs.close();
};


// ��ȡ�ļ�����
int WorkerManage::getEmpNum() {
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	int num = 0;
	int id;
	string name;
	int deptId;

	while (ifs >> id && ifs >> name && ifs >> deptId) {
		// ��¼����
		num++;
	};

	// �ر��ļ�
	ifs.close();

	return num;
};


// ��ʼ��ְ��
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
		// ���������
		this->empArray[index] = worker;
		index++;
	};

	// �ر��ļ�
	ifs.close();
};