// '�߰�' �޴� ���� �԰� ��
#include "videoStore.h"

// ī�װ� ������ȣ
/*	�׼�:	 1				ȣ��:		 2
	����:	 3				�������:	 4 
	�ڹ̵�:	 5				��Ÿ��:		 6 
	��ȭ:	 7				�θǽ�:		 8
	����:	 9								*/

// ȣ���� ������ �̼����� �뿩 �Ұ�

void 
videoStore::Add_Video() {
	system("cls");
	cout << "���� �߰� �Լ�" << endl;
	cout << "===============================================================" << endl;
	cout << "*������ ���������� ���ڸ� �������ֽñ� �ٶ��ϴ�." << endl;
	cout << "*������ ������ 0�� �̻� 9�� �����Դϴ�. �� �����ֽñ� �ٶ��ϴ�." << endl;
	cout << "===============================================================" << endl;

	Node* newVideoNode = new Node;
	video* tmp = new video;
	int categori, choice;

	cout << "������ ���������� �Է����ּ���: ";			 cin >> tmp->v_Day;
	if (check_number(tmp->v_Day) == false) { delete newVideoNode, tmp; system("pause"); return; }	// ���ڿܿ� �ٸ� �������� ���� �Լ�����

	cout << "������ ������ �Է����ּ���: ";	
	cin.ignore(100, '\n');				// �����Է��� \n�� getline���� ���� �Է¹��ۿ� ���� �Ǵ°� ����
	getline(cin, tmp->v_Title);	// ������ ���񿡴� ��� ���ڰ� �� �� �ִ�.
	

	cout << "������ ������ �Է����ּ���: ";				 cin >> tmp->v_Number;	
	if (!(tmp->v_Number > 0 && tmp->v_Number < 10)) 
	{ cout << "���� �ܿ� �ٸ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �õ��Ͽ� �ֽʽÿ�" << endl; delete newVideoNode, tmp; system("pause"); return; }	// ������ ���� ���� ����
	clear_buffer();
	cout << "===============================================================" << endl;
	cout << "�Է��Ͻ� ����" << endl;
	cout << "��������: " << tmp->v_Day << "��" << endl;
	cout << "����: " << tmp->v_Title << endl;
	cout << "����: " << tmp->v_Number << "��" << endl;
	cout << "===============================================================" << endl;

	cout << "1.�´�." << endl;
	cout << "2.�ƴϴ�." << endl;
	cout << ">> "; cin >> choice;
	cout << "===============================================================" << endl;
	if (!(choice == 1)) {	// �Է°��� �ٸ��� �� ���� ����ó���� ���ǹ�
		if (choice == 2) {					// �Է°��� 2�̸� �޴��� �����Ѵ�.
			cout << "�޴��� ���ư��ϴ�. �ٽ� �õ��Ͽ� �ֽʽÿ�." << endl;
			clear_buffer();
			delete newVideoNode, tmp; system("pause"); return;
		}									// �߸��� �Է��Ͻ� �޴��� ���ͽ�Ų��.
		cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �õ��Ͽ� �ֽʽÿ�." << endl;
		clear_buffer();
		delete newVideoNode, tmp; system("pause"); return;
	}

	cout << "===============================================================" << endl;
	// ������ȣ�� 0��° �ε����� ī�װ��� Ȯ�ο� �����̵ȴ�.
	while (1) {
		enum Categori { �׼� = 1, ȣ�� = 2, ���� = 3, ������� = 4, �ڹ̵� = 5, ��Ÿ�� = 6, ��ȭ = 7, �θǽ� = 8, ���� = 9 };
		cout << "�׼� = 1, ȣ�� = 2, ���� = 3, ������� = 4, �ڹ̵� = 5, ��Ÿ�� = 6, ��ȭ = 7, �θǽ� = 8, ���� = 9" << endl;
		cout << "ī�װ��� ������ �ּ���: "; cin >> categori;
		switch (categori) {
			case �׼�:				{ tmp->v_Video_Id[0] = 1; break; }
			case ȣ��:				{ tmp->v_Video_Id[0] = 2; break; }
			case ����:				{ tmp->v_Video_Id[0] = 3; break; }
			case �������:			{ tmp->v_Video_Id[0] = 4; break; }
			case �ڹ̵�:			{ tmp->v_Video_Id[0] = 5; break; }
			case ��Ÿ��:			{ tmp->v_Video_Id[0] = 6; break; }
			case ��ȭ:				{ tmp->v_Video_Id[0] = 7; break; }
			case �θǽ�:			{ tmp->v_Video_Id[0] = 8; break; }
			case ����:				{ tmp->v_Video_Id[0] = 9; break; }
			default: {
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			cin.clear();	// �Է¹��� ����
			cin.ignore(INT_MAX, '\n');	// �߸��� �Է��� ��� ���۸� ��� ���ѹݺ��� �����Ѵ�.
			system("pause");
			return;
			}
		}
		break;
	}
	cout << "===============================================================" << endl;

	// ������ ������ȣ �迭�� 1��° �ε������� ������ �ε������� ���� ����
	srand((unsigned int)time(NULL));
	for (int repeat = 1; repeat < 4; repeat++) { tmp->v_Video_Id[repeat] = rand() % 10;	}

	cout << "������ ������ȣ��: ";
	for (int repeat = 0; repeat < 4; repeat++) { cout << tmp->v_Video_Id[repeat]; } cout << endl;
	cout << "===============================================================" << endl;

	newVideoNode->v_Data.v_Day = tmp->v_Day;
	newVideoNode->v_Data.v_Number = tmp->v_Number;
	newVideoNode->v_Data.v_Title = tmp->v_Title;
	newVideoNode->v_Data.v_State = 0;
	for (int repeat = 0; repeat < 4; repeat++) {			// �޸� ī�Ǹ� ������� �߸�����Ͽ� �޸𸮰��� �����.
		newVideoNode->v_Data.v_Video_Id[repeat] = tmp->v_Video_Id[repeat];
	}

	//=========================================================================================================================================================================//
	/* ���Ḯ��Ʈ�� �ּҸ� �������ִ� ��� */
																		// ����� ��ġ�� ������ �Լ�
	if (empty(1) == true) {													// ����Ʈ�� ����ִٸ�
		newVideoNode->Llink = v_Head;
		newVideoNode->Rlink = v_Head;
		// ���ο� ����� ���� ��ũ�� ������ ��ũ�� m_head�� �ּҰ����� ����

		v_Head->Llink = newVideoNode;
		v_Head->Rlink = newVideoNode;
		// ���ο� ����� ���� ��ũ�� ������ ��ũ�� m_head�� �ּҰ����� ����
	}
	else if (empty(1) == false) {											// ����Ʈ�� ������� �ʴٸ�
		Node* now;
		now = v_Head;
		for (now = now->Rlink; ; now = now->Rlink) {
			int res = newVideoNode->v_Data.v_Title.compare(now->v_Data.v_Title);
			if (res < 0) {													// �տ� ��庸�� ���������� �տ��ý�
				if (now->Llink == v_Head) {									// �ճ�尡 ó����� �Ͻ�
					B:
					newVideoNode->Llink = now->Llink;
					newVideoNode->Rlink = now->Llink->Rlink;

					now->Llink->Rlink = newVideoNode;
					now->Llink = newVideoNode;
					break;
				}															// �װ� �ƴ϶��
				A:															// �տ� ���� ���� ��带 ���ο� ��忡�� �������ش�
				newVideoNode->Rlink = now->Llink->Rlink;
				newVideoNode->Llink = now->Llink;

				now->Llink->Rlink = newVideoNode;
				now->Llink = newVideoNode;
				break;
			}
			else if (res > 0 && now->Rlink == v_Head) {						// �տ� ��庸�� ���������� �ڿ����� �����ϸ� ������ �� �ڿ��� ��带 ����ų��
				C:
				newVideoNode->Rlink = now->Rlink;
				newVideoNode->Llink = now->Rlink->Llink;

				now->Rlink->Llink = newVideoNode;
				now->Rlink = newVideoNode;
				break;
			}
			else if (res == 0) {											// ���������� ������
				D:
				if (now->v_Data.v_Day > newVideoNode->v_Data.v_Day) {		// �տ� ��庸�� ���������� ������
					if (now->Llink == v_Head) {									// �ճ�尡 ó����� �Ͻ�
						goto B;
					}											
					goto A;														
				}
				else if (now->v_Data.v_Day < newVideoNode->v_Data.v_Day) {	// �տ� ��庸�� ���������� Ŭ��
					int day_res = newVideoNode->v_Data.v_Title.compare(now->Rlink->v_Data.v_Title);
					if (day_res == 0) {				// �� �ڿ����� �̸��� ���ٸ�
						now = now->Rlink;
						goto D;
					}
					goto C;
				}
				else if (now->v_Data.v_Day == newVideoNode->v_Data.v_Day) {	// �տ� ���� ���������� ������
					cout << "���� ������ �ԷµǾ����ϴ�. ��� Ȯ�� �� �ٽ� �����Ͽ� �ֽñ� �ٶ��ϴ�." << endl;
					delete newVideoNode, tmp; system("pause"); return;
				}
			}
		}
	}
	File_log(newVideoNode, 2);			// ���� �԰� �α� ����
delete tmp;								// �޸� ����
v_count_increase();						// �� ������ ����
system("pause");
return;
}