// '���' �޴� ������ �����͸� ����ϸ� �뿩 ���¸� ���
#include "videoStore.h"

void videoStore::Print_Video() {
	Node* now;
	cout << "===============================================================" << endl;
	cout << "�� ����: " << v_Count << "��" << endl;
	now = v_Head;			// ���� ���κ��� �����Ͽ� ��� ���� ���
	now = now->Rlink;
	for (int i = 0; i < v_Count; i++) {
		cout << "����: " << now->v_Data.v_Title << " �⵵: " << now->v_Data.v_Day << " ���/�뿩����: " << now->v_Data.v_Number << "/" << now->v_Data.v_State << " �ڵ�: ";
		for (int repeat = 0; repeat < 4; repeat++) cout << now->v_Data.v_Video_Id[repeat];
		cout << endl;
		now = now->Rlink;
	}
	system("pause");
}

void videoStore::Print_Member() {
	Node* now;
	cout << "===============================================================" << endl;
	cout << "�� �ο�: " << m_Count << "��" << endl;
	now = m_Head;			// ȸ�� ���κ��� �����Ͽ� ��� ȸ�� ���
	now = now->Rlink;
	for (int i = 0; i < m_Count; i++) {
		cout << "�̸�: " << now->m_Data.m_Name << " ��ȭ��ȣ: " << now->m_Data.m_Phone_number << " ����: " << now->m_Data.m_Age << "�� " << "ȸ���ڵ�: ";
		for (int repeat = 0; repeat < 5; repeat++) cout << now->m_Data.m_Member_Id[repeat];
		cout << endl;
		cout << now->m_Data.m_Name << " ȸ���� �뿩���� ����: " << now->Rent_Link->v_Data.v_Title << endl;
		now = now->Rlink;
	}
	system("pause");
}
