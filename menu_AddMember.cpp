// '�߰�' �޴� ȸ�����Կ� ȸ���� �̸������� �ڵ� ���ĵȴ�.

#include "videoStore.h"

void 
videoStore::Add_Member() {													// ȸ���� �߰��ϴ� �Լ�
	system("cls");
	cout << "ȸ�� �߰� �Լ�" << endl;
	cout << "===============================================================" << endl;
	

	Node* newMemberNode = new Node;											// ���ο� ȸ�� ��� ����
	member* tmp = new member;												// ������ �뵵�� ����ü ����
	int choice = 0;															// Ȯ�ο� ����

	cout << "ȸ���� �̸�: ";								cin >> tmp->m_Name;
	if (check_name(tmp->m_Name) == false) { delete newMemberNode, tmp; system("pause"); return; }
	// �̸� ���ڿ��� �߸��� �̸��� ������ ���������� �˷��ְ� �޴��� ����.

	cout << "ȸ���� ��ȭ��ȣ: ";							cin >> tmp->m_Phone_number;
	if (check_number(tmp->m_Phone_number, m_Head, m_Count) == false) { delete newMemberNode, tmp; system("pause"); return; }
	// ��ȣ ���ڿ��� �߸��� ��ȣ�� �ְų� ȸ����忡 ������ ��ȣ�� ������ ���������� �˷��ְ� �޴��� ����.

	cout << "ȸ���� ����: "; cin >> tmp->m_Age;
	if (!(tmp->m_Age > 0 && tmp->m_Age < 150))
	{ cout << "���� �ܿ� �ٸ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �õ��Ͽ� �ֽʽÿ�" << endl; 
	delete newMemberNode, tmp; system("pause"); return;}	// ȸ�� ������ ���� ����

	clear_buffer();

	// ������� �Է������� Ȯ���Ͽ� ��Ÿ ����
	cout << "===============================================================" << endl;
	cout << "�Է��Ͻ� ������ Ȯ���Ͽ� �ּ���." << endl;						
	cout << "�̸�: " << tmp->m_Name << endl;
	cout << "��ȭ��ȣ: " << tmp->m_Phone_number << endl;
	cout << "����: " << tmp->m_Age << "��" << endl;
	cout << "===============================================================" << endl;
	cout << "1.�´�." << endl;
	cout << "2.�ƴϴ�." << endl;
	cout << ">> "; cin >> choice; 
	cout << "===============================================================" << endl;
	if (!(choice == 1)) {	// �Է°��� �ٸ��� �� ���� ����ó���� ���ǹ�
		if (choice == 2) {					// �Է°��� 2�̸� �޴��� �����Ѵ�.
			cout << "�޴��� ���ư��ϴ�. �ٽ� �õ��Ͽ� �ֽʽÿ�." << endl;
			clear_buffer();
			delete newMemberNode, tmp; system("pause"); return;
		}									// �߸��� �Է��Ͻ� �޴��� ���ͽ�Ų��.
		cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �õ��Ͽ� �ֽʽÿ�." << endl;
		clear_buffer();
		delete newMemberNode, tmp; system("pause"); return;
	}

	// ���Ḯ��Ʈ�� ��忡 ������ ����
	newMemberNode->m_Data.m_Name = tmp->m_Name;
	newMemberNode->m_Data.m_Phone_number = tmp->m_Phone_number;
	newMemberNode->m_Data.m_Age = tmp->m_Age;
	newMemberNode->Rent_Link = z_Head;		// ȸ���� �뿩 ���� �ּҰ� �ʱ�ȭ
	
	// ȸ���� ������ȣ ����
	srand((unsigned int)time(NULL));										
	for (int i = 0; i < 5;i++) {
		newMemberNode->m_Data.m_Member_Id[i] = rand() % 10;
	}
	
//=========================================================================================================================================================================//

				/* ���Ḯ��Ʈ�� �ּҸ� �������ִ� ��� */
																			// ����� ��ġ�� ������ �Լ�
	if (empty(2) == true) {													// ����Ʈ�� ����ִٸ�
		newMemberNode->Llink = m_Head;
		newMemberNode->Rlink = m_Head;
																			// ���ο� ����� ���� ��ũ�� ������ ��ũ�� m_head�� �ּҰ����� ����

		m_Head->Llink = newMemberNode;
		m_Head->Rlink = newMemberNode;
																			// ���ο� ����� ���� ��ũ�� ������ ��ũ�� m_head�� �ּҰ����� ����
	}
	else if (empty(2) == false) {											// ����Ʈ�� ������� �ʴٸ�
		Node* now;
		now = m_Head;
		for (now = now->Rlink; ; now = now->Rlink) {
			int res = newMemberNode->m_Data.m_Name.compare(now->m_Data.m_Name);
			if (res < 0) {													// �տ� ��庸�� ���������� �տ��ý�
				if (now->Llink == m_Head) {									// �ճ�尡 ó����� �Ͻ�
					F:
					newMemberNode->Llink = now->Llink;
					newMemberNode->Rlink = now->Llink->Rlink;

					now->Llink->Rlink = newMemberNode;
					now->Llink = newMemberNode;
					break;
				}															// �װ� �ƴ϶��
				E:															// �տ� ���� ���� ��带 ���ο� ��忡�� �������ش�
				newMemberNode->Rlink = now->Llink->Rlink;
				newMemberNode->Llink = now->Llink;

				now->Llink->Rlink = newMemberNode;
				now->Llink = newMemberNode;
				break;
			}
			else if (res > 0 && now->Rlink == m_Head) {						// �տ� ��庸�� ���������� �ڿ����� �����ϸ� ������ �� �ڿ��� ��带 ����ų��
				G:
				newMemberNode->Rlink = now->Rlink;
				newMemberNode->Llink = now->Rlink->Llink;

				now->Rlink->Llink = newMemberNode;
				now->Rlink = newMemberNode;
				break;
			}
			else if (res == 0) {											// �̸��� ������ ���̼����� �����Ѵ�.
			H:
				if (now->m_Data.m_Age > newMemberNode->m_Data.m_Age) {		// �տ� ��庸�� ���̰� ������ a>b
					if (now->Llink == v_Head) {									// �ճ�尡 ó����� �Ͻ�
						goto F;
					}
					goto E;
				}
				else if (now->m_Data.m_Age > newMemberNode->m_Data.m_Age) {	// �տ� ��庸�� ���̰� Ŭ�� a<b
					int day_res = newMemberNode->m_Data.m_Name.compare(now->Rlink->m_Data.m_Name);
					if (day_res == 0) {										// �� �ڿ����� �̸��� ���ٸ�
						now = now->Rlink;
						goto H;
					}
					goto G;
				}
				else if (now->m_Data.m_Age == newMemberNode->m_Data.m_Age) {	// �տ� ���� ���̰� ������ ȸ���ڵ������ �����Ѵ�.
					for (int i = 0; i < 4; i++) {
						if (now->m_Data.m_Member_Id[i] > newMemberNode->m_Data.m_Member_Id[i]) { 
							// ������� ������� ù ��° �ε����� ���ؼ� ������� �ڵ� �� ���� ������ ��
							if (now->Llink == v_Head) {									// �ճ�尡 ó����� �Ͻ�
								goto F;
							}
							goto E;
						}
						// ���� ��庸�� ������� �ε����� ���ڰ� �� ũ�ų� ������
					}
					if (now->m_Data.m_Member_Id[4] > newMemberNode->m_Data.m_Member_Id[4]) { 
						// ������� ������� ù ��° �ε����� ���ؼ� ������� �ڵ� �� ���� ������ ��
						if (now->Llink == v_Head) {									// �ճ�尡 ó����� �Ͻ�
							goto F;
						}
						goto E;
					}
					else if (now->m_Data.m_Member_Id[4] < newMemberNode->m_Data.m_Member_Id[4]) {
						goto G;
					}
					else if (now->m_Data.m_Member_Id[4] == newMemberNode->m_Data.m_Member_Id[4]) {		//  �Ұ��ɿ� �������� Ȥ�� ���� �ڵ带 �������.
						cout << "���ϵ帳�ϴ�! 1/100000�� Ȯ���� �Ȱ��� ������ ���ܳ����ϴ�." << endl;
						cout << "ó������ �ٽ� �õ��Ͽ� �ֽñ� �ٶ��ϴ�..." << endl;
						delete newMemberNode, tmp; system("pause"); return;
					}
				}
			}
		}
	}
	File_log(newMemberNode, 1);		// �α����� ����
delete tmp;				// �����޸� ����
m_count_increase();		// ȸ�� ������ ���������� �Լ�
system("pause");
return;
}