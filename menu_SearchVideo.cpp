// '�˻�' �޴� �� �������� ������ �˻�
#include "videoStore.h"

void
videoStore::Search_Video() {
	system("cls");
	cout << "���� �˻� �޴�" << endl;
	cout << "===============================================================" << endl;

	int how; string what;
	cout << "�˻������ �����Ͽ� �ּ���." << endl;
	cout << "1. ���� ���� " << endl;
	cout << "2. ���� ī�װ� " << endl;
	cout << ">> "; cin >> how;
	cout << "===============================================================" << endl;
	if (!(how == 1 || how == 2)) { cout << "�߸��Է��ϼ̽��ϴ�." << endl; system("pause"); return; }
	switch (how) {
	case 1: {
		cout << "���� ������ �Է��� �ּ���: "; cin >> what;
		Explore_Video(what);
		break;
	}
	case 2: {
		cout << "�׼� = 1, ȣ�� = 2, ���� = 3, ������� = 4, �ڹ̵� = 5, ��Ÿ�� = 6, ��ȭ = 7, �θǽ� = 8, ���� = 9" << endl;
		cout << "ī�װ��� ������ �ּ���: "; cin >> how;
		if (!(how > 0 && how < 10)) { cout << "�� �� �Է��ϼ̽��ϴ�. �ٽýõ��� �ּ���" << endl; system("pause"); return; }
		Explore_Video(how);
		break;
	}
	default: {
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		clear_buffer();
		system("pause"); return;
	}

	}
	system("pause");
}