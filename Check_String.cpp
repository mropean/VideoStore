// ���ڿ��� ����ó���� ����
#include "videoStore.h"

bool 
check_name(string String) {
	int size = String.length();		// ���ڿ��� ���̷� �ʱ�ȭ
	for (int repeat = 0, ask_num = 0; repeat < size; repeat++) {	// �̸��� ��� �������� ����ڿ��� ����� ��� �Է��� ��ٸ�
																	// ����� �� ������ ������ ��������ϴ� �����, �׷��Ƿ� �ѱ۸� �Է¹ٶ�
		if (String[repeat] >= (char)65 && String[repeat] <= (char)90 || String[repeat] >= (char)97 && String[repeat] <= (char)122) {
			cout << "�̸��� ��� �� �ֽ��ϴ�. �״�� ���� �մϱ�?" << endl;
			cout << "�� ���� : " << String[repeat] << endl;
			cout << "1. ��" << " 2. �ƴϿ�(�޴���)" << endl;
			cout << ">> "; cin >> ask_num;
			if (ask_num == 2) {	system("pause"); return false; }
		}
	}
	for (int repeat = 0, ask_num = 0; repeat < size; repeat++) {	// ���ڿ� Ư�����ڰ� �� ������ false�����Ͽ� ��ȭ��ȣ�� ����
		if (String[repeat] >= (char)33 && String[repeat] <= 64 || String[repeat] >= 91 && String[repeat] <= 96 || String[repeat] >= 123 && String[repeat] <= 126) {
			cout << "���ڿ��� ���� �Ǵ� Ư�����ڰ� ���ֽ��ϴ�." << endl;
			system("pause");
			return false;
		}
	}
	return true;
}

bool 
check_number(string String,Node* head,int count) {
	Node* now;
	now = head;
	int size = String.length();
	for (int repeat = 0, ask_num = 0; repeat < size; repeat++) {
		if (!(String[repeat] >= (char)48 && String[repeat] <= (char)57)) {	// 
			cout << "��ȭ��ȣ�� ���ڰ��ƴ� �ٸ����ڰ� �ԷµǾ����ϴ� �ٽ� �õ��� �ּ���." << endl;
			system("pause");
			return false;
		}
	}
	for (int i = 0, index = 0; i < count; i++) {
		if ((index = now->m_Data.m_Phone_number.find(String)) != -1) {
			cout << "��ȭ��ȣ�� �ȿ� ������ ��ȭ��ȣ�� �ֽ��ϴ�. �ٽ� �õ��� �ּ���." << endl;
			system("pause");
			return false;
		}
		now = now->Rlink;
	}
	return true;
}

bool 
check_number(string String) {
	int size = String.length();
	for (int repeat = 0, ask_num = 0; repeat < size; repeat++) {
		if (!(String[repeat] >= (char)48 && String[repeat] <= (char)57)) {	// 
			cout << "��ȭ��ȣ�� ���ڰ��ƴ� �ٸ����ڰ� �ԷµǾ����ϴ� �ٽ� �õ��� �ּ���." << endl;
			system("pause");
			return false;
		}
	}
}