// Ž���ϴ� ����
#include "videoStore.h"

//========================================= ����(����) Ž�� �Լ� ===================================================================
Node*
videoStore::Explore_Video(string String) {
	Node* find[100];	// find ������ �迭�� ã�� �̸��� ��ĥ�� �� �ε��� ��ȣ�� �ּҰ� ���� 0�� �ε����� ����
	Node* now;
	now = v_Head;
	int index, find_index, find_accept, ask_num, repeat = 0;
	cout << "==============================================================="	 << endl;
	cout << "�������� �˻��� �����մϴ�."										 << endl;
	cout << "�˻��� ����� �������� ����Դϴ�. ���ϴ� ��ȣ�� �����Ͽ� �ּ���."  << endl;
	cout << "���ϴ� ��ȣ�� ������ 0���� �Է��Ͻø� ���α׷��� �����մϴ�."		 << endl;
	cout << "==============================================================="	 << endl;
	for (find_index = 1, find_accept = 1, now = now->Rlink; repeat < v_Count; repeat++) {
		index = now->v_Data.v_Title.find(String);
		if (index != -1) {
			find[find_index] = now;
			cout << find_accept << "." << "����: " << now->v_Data.v_Title << " �⵵: " << now->v_Data.v_Day <<
				" �뿩����: " << now->v_Data.v_Number << "���� " << now->v_Data.v_State << "�� �뿩��" << endl;
			find_index++; find_accept++;
		}
		now = now->Rlink;
	}
	cout << ">> "; cin >> ask_num;
	cout << "===============================================================" << endl;
	if (ask_num == 0) {
		cout << "���α׷��� �����մϴ�." << endl;
		exit(1);
	}
	cout << "==========================================" << endl;
	if ((index = find[ask_num]->v_Data.v_Title.size()) == 0) {		// ���� ���ڿ��� ������� �� �� ������ ������ �ν��Ѵ�.
		cout << "�߸��� ��ȣ�� �Է��ϼ̰ų� ������ �������� �ʽ��ϴ�." << endl; system("pause"); exit(1);
	}
	cout << "�����Ͻ� ��ȣ�� �����ʹ� �Ʒ��� �����ϴ�." << endl;
	cout << "����: " << find[ask_num]->v_Data.v_Title << endl;
	cout << "�⵵: " << find[ask_num]->v_Data.v_Day << endl;
	cout << "���� �ڵ�: ";
	for (repeat = 0; repeat < 4; repeat++) { cout << find[ask_num]->v_Data.v_Video_Id[repeat]; }
	cout << endl;
	cout << "===============================================================" << endl;
	
	system("pause");
	return find[ask_num];
}

//========================================= ����(ī�װ�) Ž�� �Լ� ===================================================================
Node*
videoStore::Explore_Video(int num) {
	Node* find[100];	// find ������ �迭�� ã�� �̸��� ��ĥ�� �� �ε��� ��ȣ�� �ּҰ� ���� 0�� �ε����� ����
	Node* now;
	now = v_Head;
	int index, find_index, find_accept, ask_num, repeat = 0;
	cout << "===============================================================" << endl;
	cout << "ī�װ��� �˻��� �����մϴ�." << endl;
	cout << "�˻��� ī�װ��� ������ ����Դϴ�. ���ϴ� ��ȣ�� �����Ͽ� �ּ���." << endl;
	cout << "���ϴ� ��ȣ�� ������ 0���� �Է��Ͻø� ���α׷��� �����մϴ�." << endl;
	cout << "===============================================================" << endl;
	for (find_index = 1, find_accept = 1, now = now->Rlink; repeat < v_Count; repeat++) {
		if (now->v_Data.v_Video_Id[0] == num) {		// ���� �ڵ��� ù��° �ε����� ���Ѵ�.
			find[find_index] = now;
			cout << find_accept << "." << "����: " << now->v_Data.v_Title << " �⵵: " << now->v_Data.v_Day << 
				" �뿩����: " << now->v_Data.v_Number << "���� " << now->v_Data.v_State << "�� �뿩��" << endl;
			find_index++; find_accept++;
		}
		now = now->Rlink;
	}
	cout << ">> "; cin >> ask_num;
	cout << "===============================================================" << endl;
	if (ask_num == 0) {
		cout << "���α׷��� �����մϴ�." << endl;
		exit(1);
	}
	cout << "==========================================" << endl;
	if ((index = find[ask_num]->v_Data.v_Title.size()) == 0) {		// ���� ���ڿ��� ������� �� �� ������ ������ �ν��Ѵ�.
		cout << "�߸��� ��ȣ�� �Է��ϼ̰ų� ������ �������� �ʽ��ϴ�." << endl; system("pause"); exit(1);
	}
	cout << "�����Ͻ� ��ȣ�� �����ʹ� �Ʒ��� �����ϴ�." << endl;
	cout << "����: " << find[ask_num]->v_Data.v_Title << endl;
	cout << "�⵵: " << find[ask_num]->v_Data.v_Day << endl;
	cout << "���� �ڵ�: ";
	for(repeat = 0; repeat < 4; repeat++) { cout << find[ask_num]->v_Data.v_Video_Id[repeat]; }
	cout << endl;
	cout << "===============================================================" << endl;

	system("pause");
	return find[ask_num];
}

//========================================= ȸ�� Ž�� �Լ� ===================================================================
Node*
videoStore::Explore_Member(string String, int num) {
	Node* find[100];	// find ������ �迭�� ã�� �̸��� ��ĥ�� �� �ε��� ��ȣ�� �ּҰ� ���� 0�� �ε����� ����
	Node* now;
	now = m_Head;
	int index, find_index, find_accept, ask_num, repeat = 0;

	cout << "===============================================================" << endl;
	cout << "ȸ�� �˻��� �����մϴ�." << endl;
	cout << "�˻��� �̸��� ������ ����Դϴ�. ���ϴ� ��ȣ�� �����Ͽ� �ּ���." << endl;
	cout << "���ϴ� ��ȣ�� ������ 0���� �Է��Ͻø� ���α׷��� �����մϴ�." << endl;
	cout << "===============================================================" << endl;

	// �Ű������� ���� ���ڿ��� �ٸ��� ������ ����ȭ �����־�� �Ѵ�.
	if (num == 1) {	// �̸����� �˻���
		for (find_index = 1, find_accept = 1, now = now->Rlink; repeat < m_Count; repeat++) {
			index = now->m_Data.m_Name.find(String);		// �̸����� ã�´�.
			if (index != -1) {
				find[find_index] = now;
				cout << find_accept << "." << "�̸�: " << now->m_Data.m_Name << " ��ȭ��ȣ: " << now->m_Data.m_Phone_number << 
					" ����: " << now->m_Data.m_Age << " ȸ���ڵ�: ";
				for (int code_repeat = 0; code_repeat < 5; code_repeat++) { cout << now->m_Data.m_Member_Id[code_repeat]; } cout << endl;
				find_index++; find_accept++;
			}
			now = now->Rlink;
		}
	}
	else if(num == 2) {		// ��ȭ��ȣ�� �˻��� 
		for (find_index = 1, find_accept = 1, now = now->Rlink; repeat < m_Count; repeat++) {
			index = now->m_Data.m_Phone_number.find(String);	// ��ȭ��ȣ�� ã�´�.
			if (index != -1) {
				find[find_index] = now;
				cout << find_accept << "." << "�̸�: " << now->m_Data.m_Name << " ��ȭ��ȣ: " << now->m_Data.m_Phone_number << 
					" ����: " << now->m_Data.m_Age << " ȸ���ڵ�: ";
				for (int code_repeat = 0; code_repeat < 5; code_repeat++) { cout << now->m_Data.m_Member_Id[code_repeat]; } cout << endl;
				find_index++; find_accept++;
			}
			now = now->Rlink;
		}
	} 
	cout << ">> "; cin >> ask_num;
	cout << "===============================================================" << endl;
	if (ask_num == 0) {
		cout << "���α׷��� �����մϴ�." << endl;
		exit(1);
	}
	
	cout << "==========================================" << endl;
	if ((index = find[ask_num]->m_Data.m_Name.size()) == 0) {
		cout << "�߸��� ��ȣ�� �Է��ϼ̰ų� ȸ���� �������� �ʽ��ϴ�." << endl; system("pause"); exit(1);
	}
	cout << "�����Ͻ� ��ȣ�� �����ʹ� �Ʒ��� �����ϴ�." << endl;
	cout << "�̸�: " << find[ask_num]->m_Data.m_Name << " " << find[ask_num]->m_Data.m_Age << "�� " << "��ȭ��ȣ: " << find[ask_num]->m_Data.m_Phone_number << endl;
	system("pause");
	return find[ask_num];
}