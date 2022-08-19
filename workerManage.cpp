#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManage::WorkerManage() {
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

	// ���ٿռ�
	this->empArray = new Worker * [this->empNum];
	// ���ļ��е����ݣ��浽������
	this->initEmp();
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

// ��ʾְ��
void WorkerManage::showEmp() {
	if (this->fileIsEmpty) {
		cout << "�ļ������ڼ�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->empNum; i++) {
			// ���ö�̬���ýӿ�
			this->empArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
};

// id�Ƿ���ڣ����ڷ����±꣬���򷵻�-1
int WorkerManage::isExistId(int id) {
	int res = -1;

	for (int i = 0; i < this->empNum; i++)
	{
		if (this->empArray[i]->id == id)
		{
			res = i;
			break;
		}
	}

	return res;
};

// name�Ƿ���ڣ����ڷ����±꣬���򷵻�-1
int WorkerManage::isExistName(string name) {
	int res = -1;

	for (int i = 0; i < this->empNum; i++)
	{
		if (this->empArray[i]->name == name)
		{
			res = i;
			break;
		}
	}

	return res;
};

// ɾ��ְ��
void WorkerManage::deleteEmp() {
	if (this->fileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		int id;
		cout << "������Ҫɾ��ְ����ID��" << endl;
		cin >> id;
		int index = this->isExistId(id);
		if (index == -1) {
			cout << "ID������" << endl;
		}
		else {
			for (int i = index; i < this->empNum - 1; i++) {
				this->empArray[i] = this->empArray[i + 1];
			};
			// ���¼�¼����
			this->empNum--;
			// ����ͬ���ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
};

// �޸�ְ��
void WorkerManage::updateEmp() {
	if (this->fileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else {

		cout << "������Ҫ�޸�ְ����ID��" << endl;
		int id;
		cin >> id;
		int index = this->isExistId(id);
		if (index == -1) {
			cout << "ID������" << endl;
		}
		else {
			int id;
			string name;
			int choice = -1;

			cout << "������ְ����ţ�" << endl;
			cin >> id;
			cout << "������ְ��������" << endl;
			cin >> name;
			while (true) {
				if (choice == 1 || choice == 2 || choice == 3) {
					break;
				};
				cout << "�����������" << endl;
				cout << "������ְ����λ��"
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

			// �޸�ְ����������� 
			this->empArray[index] = worker;

			// ����ͬ���ļ���
			this->save();
			cout << "�޸ĳɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
};

// ����ְ��
void WorkerManage::findEmp() {
	if (this->fileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else {
		int select;
		int index; // ����ְ���±�
		while (true) {
			cout << "��ѡ����ҵ�ְ���ķ�ʽ��"
				<< "\n1: ����ID����"
				<< "\n2: �������Ʋ���" << endl;
			cin >> select;
			if (select == 1 || select == 2) {
				break;
			}
		}
		if (select == 1) {
			int id;
			cout << "��������Ҫ���ҵ�ְ��ID��" << endl;
			cin >> id;
			index = this->isExistId(id);
		}
		else {
			string name;
			cout << "��������Ҫ���ҵ�ְ�����ƣ�" << endl;
			cin >> name;
			index = this->isExistName(name);
		}
		if (index == -1) {
			cout << "������Ϣ������" << endl;
		}
		else {
			this->empArray[index]->showInfo();
		}
	}

	system("pause");
	system("cls");
};

// ��ʾ����ְ��
void WorkerManage::showAllEmp() {
	if (this->fileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	} else if (this->empNum == 0) {
		cout << "ְ��Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < empNum; i++)
		{
			this->empArray[i]->showInfo();
		}
	}
};

// ���ձ������
void WorkerManage::sortEmp() {
	if (this->fileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else {
		for (int i = 0; i < this->empNum -1; i++) {
			for (int j = 0; j < this->empNum - i - 1; j++) {
				if (this->empArray[j]->id > this->empArray[j + 1]->id) {
					Worker* temp = this->empArray[j];
					this->empArray[j] = this->empArray[j + 1];
					this->empArray[j + 1] = temp;
				}
			}
		}
		this->showAllEmp();
	}

	system("pause");
	system("cls");
};


// ���ְ��ϵͳ
void WorkerManage::clearEmp() {
	int select;

	while (true) {
		cout << "ȷ����գ�"
			<< "1��ȷ��"
			<< "2������" << endl;
		cin >> select;
		if (select == 1 || select == 2) {
			break;
		}
	}

	if (select == 1) {
		// �������ɾ���ļ������´���
		ofstream ofs(FILE_NAME, ios::trunc);
		ofs.close();

		// �������ÿ������
		if (this->empArray != NULL) {
			for (int i = 0; i < this->empNum; i++)
			{
				if (this->empArray[i] != NULL) {
					delete this->empArray[i];
				}
			}
		}
		this->empNum = 0;
		delete[] this->empArray;
		this->empArray = NULL;
		this->fileIsEmpty = true;

		cout << "����ɹ�!" << endl;
		system("pause");
		system("cls");
	}
	else {
		system("cls");
	}
};

WorkerManage::~WorkerManage() {
	if (this->empArray != NULL) {
		for (int i = 0; i < this->empNum; i++)
		{
			if (this->empArray[i] != NULL) {
				delete this->empArray[i];
			}
		}
		delete[] this->empArray;
		this->empArray = NULL;
	}
}