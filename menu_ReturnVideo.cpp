// ���� �ݳ� ����
#include "videoStore.h"

void
videoStore::Return_Video() {
	system("cls");
	cout << "���� �ݳ� �޴�" << endl;
	cout << "===============================================================" << endl;

	string Video, Member; Node* Rent_v, * Rent_m; int check, how = 0;
	cout << "�ݳ��Ͻô� ȸ���� ������ �Է��� �ּ���" << endl;
	cout << "1.�̸�" << endl;
	cout << "2.��ȭ��ȣ" << endl;
	cout << ">> "; cin >> how; 
	cout << "===============================================================" << endl;
	if (how == 1) { cout << "ȸ���� �̸��� �Է��� �ּ���: "; cin >> Member; check_name(Member); }
	else if (how == 2) { cout << "ȸ���� ��ȭ��ȣ�� �Է��� �ּ���: "; cin >> Member; check_number(Member); }
	else {	// �Է°��� ����ó���� ���ǹ�
		cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		clear_buffer();
		system("pause"); return;
	}

	Rent_m = Explore_Member(Member, how);

	Rent_v = Rent_m->Rent_Link;
	if (Rent_v->v_Data.v_Video_Id[0] == 0) {		// ���� ȸ���� ��尡 zero ��带 ����Ų�ٸ� �뿩�� ���°� �ƴϴ�
		cout << "�뿩���� ������ �����ϴ�. �޴��� ���ư��ڽ��ϴ�." << endl;
		system("pause"); return;
	}
	cout << "�ݳ��Ͻô� ������ �̸��� " << Rent_v->v_Data.v_Title << "�� �� �����ʴϱ�?" << endl;
	cout << "1.��" << endl;
	cout << "2.�ƴϿ�" << endl;
	cout << ">> "; cin >> how;
	cout << "===============================================================" << endl;
	if (!(how == 1)) {
		if (how == 2) {
			cout << "�޴��� ���ư� �ٽ� �õ����ֽñ� �ٶ��ϴ�." << endl;
			clear_buffer();
			system("pause"); return;
		}
		cout << "�߸��Է��ϼ̽��ϴ�." << endl; clear_buffer(); system("pause"); return;
	}

	Rent_m->Rent_Link = z_Head;			// ȸ�� ����� ���� �ּҰ��� null�� �ʱ�ȭ
	Rent_v->v_Data.v_State--;			// �ش� ������ �뿩 ���� ���̱�
	cout << Rent_m->m_Data.m_Name << " ȸ���� ������ " << Rent_v->v_Data.v_Title << " ������ �ݳ��Ǿ����ϴ�." << endl;
	File_log(Rent_m, Rent_v, 2);
	system("pause");
	return;
}