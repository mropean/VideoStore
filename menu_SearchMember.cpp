// '�˻�' �޴� �� �������� ȸ���� �˻�
#include "videoStore.h"

void
videoStore::Search_Member() {
	system("cls");
	cout << "ȸ�� �˻� �޴�" << endl;
	cout << "===============================================================" << endl;

	int how; string what;
	cout << "�˻������ �����Ͽ� �ּ���." << endl;
	cout << "1. ȸ�� �̸� " << endl;
	cout << "2. ȸ�� ��ȭ��ȣ " << endl;
	cout << "===============================================================" << endl;
	cout << ">> "; cin >> how;

	switch (how) {
	case 1:		{
					cout << "�˻��Ͻ� ȸ���� �̸��� �Է����ּ���: "; cin >> what;
					check_name(what);
					Explore_Member(what, how);
					break;
																					}
	case 2:		{
					cout << "�˻��Ͻ� ȸ���� ��ȭ��ȣ�� �Է����ּ���: "; cin >> what;
					check_number(what);
					Explore_Member(what, how);
					break;
																					}
	default:	{
					cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
					clear_buffer();
					system("pause"); return;
																					}
	}
	system("pause");
}