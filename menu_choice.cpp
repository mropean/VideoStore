// ���α׷��� �� �޴��� ��ȣ ���� ����
#include "videoStore.h"

void 
videoStore::Choice_Add() {
	system("cls");
	cout << "===============================================================" << endl;
	cout << "�߰� ���� �޴�" << endl;
	int choose_Number;
	cout << "1. ȸ�� ����" << endl;
	cout << "2. ���� �԰�" << endl;
	cout << "�����Ͻ� �׸��� �Է��� �ּ���. >> "; cin >> choose_Number; 
	if (choose_Number == 1) {
		Add_Member();
	}
	else if (choose_Number == 2) {
		Add_Video();
	}
	else {
		cout << "�� �� �Է��ϼ̽��ϴ�. ���θ޴��� ���ư��ϴ�." << endl;
		clear_buffer();
		system("pause"); return;
	}
}

void
videoStore::Choice_Search() {
	system("cls");
	cout << "===============================================================" << endl;
	cout << "�˻� ���� �޴�" << endl;
	int choose_Number;
	cout << "1. ȸ�� �˻�" << endl;
	cout << "2. ���� �˻�" << endl;
	cout << "�����Ͻ� �׸��� �Է��� �ּ���. >> "; cin >> choose_Number;
	if (choose_Number == 1) {
		Search_Member();
	}
	else if (choose_Number == 2) {
		Search_Video();
	}
	else {
		cout << "�� �� �Է��ϼ̽��ϴ�. ���θ޴��� ���ư��ϴ�." << endl;
		clear_buffer();
		system("pause"); return;
	}
}

void
videoStore::choice_Print() {
	system("cls");
	cout << "===============================================================" << endl;
	cout << "��� ���� �޴�" << endl;
	int choose_Number;
	cout << "1. ȸ�� ��� ���" << endl;
	cout << "2. ���� ��� ���" << endl;
	cout << "�����Ͻ� �׸��� �Է��� �ּ���. >> "; cin >> choose_Number;
	if (choose_Number == 1) {
		Print_Member();
	}
	else if (choose_Number == 2) {
		Print_Video();
	}
	else {
		cout << "�� �� �Է��ϼ̽��ϴ�. ���θ޴��� ���ư��ϴ�." << endl;
		clear_buffer();
		system("pause"); return;
	}
}

void
videoStore::choice_Remove() {
	system("cls");
	cout << "===============================================================" << endl;
	cout << "���� ���� �޴�" << endl;
	int choose_Number;
	cout << "1. ȸ�� ����" << endl;
	cout << "2. ���� ����" << endl;
	cout << "�����Ͻ� �׸��� �Է��� �ּ���. >> "; cin >> choose_Number;
	if (choose_Number == 1) {
		Remove_Member();
	}
	else if (choose_Number == 2) {
		Remove_Video();
	}
	else {
		cout << "�� �� �Է��ϼ̽��ϴ�. ���θ޴��� ���ư��ϴ�." << endl;
		clear_buffer();
		system("pause"); return;
	}
}