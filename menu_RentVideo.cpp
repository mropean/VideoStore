// '�뿩' �޴�
#include "videoStore.h"

void
videoStore::Rent_Video() {
	system("cls");
	cout << "���� �뿩 �޴�" << endl;
	cout << "===============================================================" << endl;
	string Video, Member; Node* Rent_v, * Rent_m; int check, how = 0;

	// �뿩�ϴ� ȸ���� ������ �˻��Ѵ�
	cout << "�뿩�Ͻô� ȸ���� ������ �˻��� ����� �Է����ּ���." << endl;
	cout << "1.�̸�" << endl;
	cout << "2.��ȭ��ȣ" << endl;
	cout << ">> "; cin >> how;
	cout << "===============================================================" << endl;
	
	// �Է°��� ���� �˻������ ���� ���ǹ�
	if (how == 1) { cout << "ȸ���� �̸��� �Է��� �ּ���: "; cin >> Member; }
	else if (how == 2) { cout << "ȸ���� ��ȭ��ȣ�� �Է��� �ּ���: "; cin >> Member; }
	else{	// �Է°��� ����ó���� ���ǹ�
		cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		clear_buffer();
		system("pause"); return;
	}
	
	Rent_m = Explore_Member(Member, how);		// Ž���Ǿ� ���� ȸ�� ����� �ּҸ� ����Ű�� Rent_m ����
	// ȸ���� �̹� �뿩�ϰ��ִ� ������ �ִٸ�
	if (Rent_m->Rent_Link->v_Data.v_Video_Id[0] != 0) {
		cout << "���� " << Rent_m->m_Data.m_Name << " ȸ���� ���� " << Rent_m->Rent_Link->v_Data.v_Title << " ��(��) �뿩�ϰ� �ֽ��ϴ�." << endl;
		cout << "�ٽ� �õ��Ͽ� �ֽñ� �ٶ��ϴ�." << endl;
		system("pause"); return;
	}
	
	// �뿩�ϴ� ������ ������ ���
	cout << "===============================================================" << endl;
	cout << "�뿩�Ͻ� ������ ������ �Է����ּ���: "; cin >> Video;
	cout << "�Է��Ͻ� ������ ������ \"" << Video << "\" �� �½��ϱ�? " << endl;
	cout << "1.�� " << endl;
	cout << "2.�ƴϿ�" << endl;
	cout << ">> "; cin >> check;
	cout << "===============================================================" << endl;
	if (!(check == 1)) {
		if (check == 2) {
			cout << "�ٽ� ������ �˻����ֽñ� �ٶ��ϴ�. �޴��� ���ư��ϴ�" << endl;
			system("pause"); return;
		}
		cout << "�� �� �Է��ϼ̽��ϴ�. �ٽ� �õ����ֽñ� �ٶ��ϴ�." << endl;
		system("pause"); return;
	}

	cout << "===============================================================" << endl;
	Rent_v = Explore_Video(Video);				// Ž���Ǿ� ���� ���� ����� �ּҸ� ����Ű�� Rent_v ����
	if (Rent_v->v_Data.v_Number == Rent_v->v_Data.v_State) {						// ������ ������ ���� �뿩�� �� �� �뿩 �Ұ�
		cout << "�ش� ������ ���� �뿩���Դϴ�. �뿩�� �Ұ����մϴ�." << endl;
		cout << "�޴��� ���ư��ϴ�...." << endl; system("pause"); return;
	}

	if (Rent_v->v_Data.v_Video_Id[0] == 2 || Rent_v->v_Data.v_Video_Id[0] == 3) {	// ������ �������� ���ǹ�
		if (Rent_m->m_Data.m_Age < 20) {	// �뿩�Ϸ��� ȸ���� ���̰� 20�� �̸��̸� �Ұ�
			cout << "�ش� ������ �̼����� �����Ұ��Դϴ�. �뿩�� �Ұ����մϴ�." << endl;
			cout << "�޴��� ���ư��ϴ�...." << endl; system("pause"); return;
		}
		// �װ� �ƴ϶�� �뿩�� �����ϴ�.
	}
	// ���� �� ���׵��� �ƴ϶��
	Rent_m->Rent_Link = Rent_v;
	Rent_v->v_Data.v_State++;

	cout << "===============================================================" << endl;
	cout << Rent_m->m_Data.m_Name << " ȸ������ ";
	cout << Rent_v->v_Data.v_Title << "�� ������ �뿩�Ǿ����ϴ�." << endl;
	File_log(Rent_m, Rent_v, 1);
	system("pause");
	return;
}