// ���� ���� ����
#include "videoStore.h"

void
videoStore::Remove_Video() {
	system("cls");
	cout << "���� ���� �޴�" << endl;
	cout << "===============================================================" << endl;

	int repeat; string what; Node* del, * now;
	cout << "������ ������ ������ �Է��� �ּ���: "; cin >> what;
	del = Explore_Video(what);

	now = m_Head;
	// ���� ������ �ش� ���� ��带 ����Ű�� ȸ�� ��尡 �ִٸ� �� ��带 z_��尪���� �ʱ�ȭ ��Ų��.
	if (del->v_Data.v_State != 0) {
		for (repeat = 0, now = now->Rlink; repeat < m_Count; repeat++) {
			if (now->Rent_Link == del) {	// ȸ���� ������ ������ �����Ϸ��� ������ ���� �ּҰ��̸�
				now->Rent_Link = z_Head;
			}
			now = now->Rlink;
		}
	}

	File_log(del, 4);
	del->Llink->Rlink = del->Rlink;
	del->Rlink->Llink = del->Llink;
	delete del;
	cout << "������ �����Ǿ����ϴ�." << endl;
	v_count_decrease();			// �� ���� ���� ����
	system("pause");
	return;
}