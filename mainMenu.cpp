// ���� �޴�
#include "videoStore.h"

int main() {
	videoStore vs; int select_Number = 0;
	cout << "���� ����" << endl;

	while (select_Number != 7) {
		system("cls");
		cout << "===============================================================" << endl;
		cout << "�������� ���� �޴�"				<< endl;
		cout << "1. ȸ�� ���� �� ���� �԰�. "		<< endl; 
		cout << "2. ȸ�� ��� �� ���� ���. "		<< endl; 
		cout << "3. ���� �뿩. "					<< endl; 
		cout << "4. ȸ�� �˻� �� ���� �˻�. "		<< endl;
		cout << "5. ���� �ݳ�. "					<< endl;
		cout << "6. ȸ�� ���� �� ���� ����. "		<< endl;
		cout << "7. ���� �� ���α׷� ����"			<< endl;
		cout << "���Ͻô� �޴��� ������ �ּ��� >> "; cin >> select_Number;

		switch (select_Number) {
		case 1: { vs.Choice_Add();		break; }
		case 2: { vs.choice_Print();	break; }
		case 3: { vs.Rent_Video();		break; }
		case 4: { vs.Choice_Search();	break; }
		case 5: { vs.Return_Video();	break; }
		case 6: { vs.choice_Remove();	break; }
		case 7: {
			break;
		}

		default: {
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			cin.clear();	// �Է¹��� ����
			cin.ignore(INT_MAX, '\n');	// �߸��� �Է��� ��� ���۸� ��� ���ѹݺ��� �����Ѵ�.
		}
		}
		

	}
	return 0;
}