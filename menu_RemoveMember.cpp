// ȸ�� ���� ����
#include "videoStore.h"

void
videoStore::Remove_Member() {
	system("cls");
	cout << "ȸ�� ���� �޴�" << endl;
	cout << "===============================================================" << endl;

	int how; string what; Node* del, * v_Data;
	cout << "������ ȸ���� ã�� ����� �����Ͽ� �ּ���." << endl;
	cout << "1. ȸ�� �̸�" << endl;
	cout << "2. ȸ�� ��ȭ��ȣ " << endl;
	cout << ">> "; cin >> how; 
	cout << "===============================================================" << endl;
	if (how == 1) { cout << "ȸ���� �̸��� �Է��� �ּ���: "; cin >> what; check_name(what); }
	else if (how == 2) { cout << "ȸ���� ��ȭ��ȣ�� �Է��� �ּ���: "; cin >> what; check_number(what); }
	else { cout << "�߸��Է��ϼ̽��ϴ�." << endl; 
	clear_buffer();
	system("pause"); return; }

	// �����Ϸ��� ȸ������� �뿩 �ּҰ��� z_��尡 �ƴϸ� �ش� ������ ������ �ݳ���Ų��.
	del = Explore_Member(what, how);
	if (del->Rent_Link->v_Data.v_Video_Id[0] != 0) {
		v_Data = del->Rent_Link;
		v_Data->v_Data.v_State--;
		cout << del->m_Data.m_Name << " ȸ���� ������ " << del->v_Data.v_Title << " ������ �ݳ��Ǿ����ϴ�." << endl;
	}

	File_log(del, 3);
	del->Llink->Rlink = del->Rlink;
	del->Rlink->Llink = del->Llink;
	delete del;
	cout << "ȸ���� �����Ǿ����ϴ�." << endl;
	m_count_decrease();			// �� ȸ�� �� ����
	system("pause");
	return;
}
