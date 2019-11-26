// '추가' 메뉴 회원가입용 회원은 이름순으로 자동 정렬된다.

#include "videoStore.h"

void 
videoStore::Add_Member() {													// 회원을 추가하는 함수
	system("cls");
	cout << "회원 추가 함수" << endl;
	cout << "===============================================================" << endl;
	

	Node* newMemberNode = new Node;											// 새로운 회원 노드 생성
	member* tmp = new member;												// 복사할 용도의 구조체 생성
	int choice = 0;															// 확인용 변수

	cout << "회원의 이름: ";								cin >> tmp->m_Name;
	if (check_name(tmp->m_Name) == false) { delete newMemberNode, tmp; system("pause"); return; }
	// 이름 문자열에 잘못된 이름이 있을시 오류내용을 알려주고 메뉴로 복귀.

	cout << "회원의 전화번호: ";							cin >> tmp->m_Phone_number;
	if (check_number(tmp->m_Phone_number, m_Head, m_Count) == false) { delete newMemberNode, tmp; system("pause"); return; }
	// 번호 문자열에 잘못된 번호가 있거나 회원노드에 동일한 번호가 있을시 오류내용을 알려주고 메뉴로 복귀.

	cout << "회원의 나이: "; cin >> tmp->m_Age;
	if (!(tmp->m_Age > 0 && tmp->m_Age < 150))
	{ cout << "숫자 외에 다른 문자가 입력되었습니다. 다시 시도하여 주십시오" << endl; 
	delete newMemberNode, tmp; system("pause"); return;}	// 회원 나이의 오류 방지

	clear_buffer();

	// 사용자의 입력정보를 확인하여 오타 예방
	cout << "===============================================================" << endl;
	cout << "입력하신 정보를 확인하여 주세요." << endl;						
	cout << "이름: " << tmp->m_Name << endl;
	cout << "전화번호: " << tmp->m_Phone_number << endl;
	cout << "나이: " << tmp->m_Age << "세" << endl;
	cout << "===============================================================" << endl;
	cout << "1.맞다." << endl;
	cout << "2.아니다." << endl;
	cout << ">> "; cin >> choice; 
	cout << "===============================================================" << endl;
	if (!(choice == 1)) {	// 입력값이 다른값 일 때의 예외처리용 조건문
		if (choice == 2) {					// 입력값이 2이면 메뉴로 복귀한다.
			cout << "메뉴로 돌아갑니다. 다시 시도하여 주십시오." << endl;
			clear_buffer();
			delete newMemberNode, tmp; system("pause"); return;
		}									// 잘못된 입력일시 메뉴로 복귀시킨다.
		cout << "잘못입력하셨습니다. 다시 시도하여 주십시오." << endl;
		clear_buffer();
		delete newMemberNode, tmp; system("pause"); return;
	}

	// 연결리스트의 노드에 데이터 대입
	newMemberNode->m_Data.m_Name = tmp->m_Name;
	newMemberNode->m_Data.m_Phone_number = tmp->m_Phone_number;
	newMemberNode->m_Data.m_Age = tmp->m_Age;
	newMemberNode->Rent_Link = z_Head;		// 회원의 대여 비디오 주소값 초기화
	
	// 회원의 고유번호 생성
	srand((unsigned int)time(NULL));										
	for (int i = 0; i < 5;i++) {
		newMemberNode->m_Data.m_Member_Id[i] = rand() % 10;
	}
	
//=========================================================================================================================================================================//

				/* 연결리스트의 주소를 설정해주는 방법 */
																			// 노드의 위치를 결정할 함수
	if (empty(2) == true) {													// 리스트가 비어있다면
		newMemberNode->Llink = m_Head;
		newMemberNode->Rlink = m_Head;
																			// 새로운 노드의 왼쪽 링크와 오른쪽 링크를 m_head의 주소값으로 저장

		m_Head->Llink = newMemberNode;
		m_Head->Rlink = newMemberNode;
																			// 새로운 노드의 왼쪽 링크와 오른쪽 링크를 m_head의 주소값으로 저장
	}
	else if (empty(2) == false) {											// 리스트가 비어있지 않다면
		Node* now;
		now = m_Head;
		for (now = now->Rlink; ; now = now->Rlink) {
			int res = newMemberNode->m_Data.m_Name.compare(now->m_Data.m_Name);
			if (res < 0) {													// 앞에 노드보다 사전순으로 앞에올시
				if (now->Llink == m_Head) {									// 앞노드가 처음노드 일시
					F:
					newMemberNode->Llink = now->Llink;
					newMemberNode->Rlink = now->Llink->Rlink;

					now->Llink->Rlink = newMemberNode;
					now->Llink = newMemberNode;
					break;
				}															// 그게 아니라면
				E:															// 앞에 노드와 뒤의 노드를 새로운 노드에게 연결해준다
				newMemberNode->Rlink = now->Llink->Rlink;
				newMemberNode->Llink = now->Llink;

				now->Llink->Rlink = newMemberNode;
				now->Llink = newMemberNode;
				break;
			}
			else if (res > 0 && now->Rlink == m_Head) {						// 앞에 노드보다 사전순으로 뒤에갈시 무시하면 되지만 그 뒤에가 헤드를 가리킬시
				G:
				newMemberNode->Rlink = now->Rlink;
				newMemberNode->Llink = now->Rlink->Llink;

				now->Rlink->Llink = newMemberNode;
				now->Rlink = newMemberNode;
				break;
			}
			else if (res == 0) {											// 이름이 같을때 나이순으로 정렬한다.
			H:
				if (now->m_Data.m_Age > newMemberNode->m_Data.m_Age) {		// 앞에 노드보다 나이가 작을시 a>b
					if (now->Llink == v_Head) {									// 앞노드가 처음노드 일시
						goto F;
					}
					goto E;
				}
				else if (now->m_Data.m_Age > newMemberNode->m_Data.m_Age) {	// 앞에 노드보다 나이가 클시 a<b
					int day_res = newMemberNode->m_Data.m_Name.compare(now->Rlink->m_Data.m_Name);
					if (day_res == 0) {										// 또 뒤에노드와 이름이 같다면
						now = now->Rlink;
						goto H;
					}
					goto G;
				}
				else if (now->m_Data.m_Age == newMemberNode->m_Data.m_Age) {	// 앞에 노드와 나이가 같을시 회원코드순으로 정렬한다.
					for (int i = 0; i < 4; i++) {
						if (now->m_Data.m_Member_Id[i] > newMemberNode->m_Data.m_Member_Id[i]) { 
							// 현재노드와 새노드의 첫 번째 인덱스를 비교해서 새노드의 코드 더 작은 숫자일 시
							if (now->Llink == v_Head) {									// 앞노드가 처음노드 일시
								goto F;
							}
							goto E;
						}
						// 현재 노드보다 새노드의 인덱스의 숫자가 더 크거나 같을시
					}
					if (now->m_Data.m_Member_Id[4] > newMemberNode->m_Data.m_Member_Id[4]) { 
						// 현재노드와 새노드의 첫 번째 인덱스를 비교해서 새노드의 코드 더 작은 숫자일 시
						if (now->Llink == v_Head) {									// 앞노드가 처음노드 일시
							goto F;
						}
						goto E;
					}
					else if (now->m_Data.m_Member_Id[4] < newMemberNode->m_Data.m_Member_Id[4]) {
						goto G;
					}
					else if (now->m_Data.m_Member_Id[4] == newMemberNode->m_Data.m_Member_Id[4]) {		//  불가능에 가깝지만 혹시 몰라 코드를 만들었다.
						cout << "축하드립니다! 1/100000의 확률로 똑같은 난수가 생겨났습니다." << endl;
						cout << "처음부터 다시 시도하여 주시기 바랍니다..." << endl;
						delete newMemberNode, tmp; system("pause"); return;
					}
				}
			}
		}
	}
	File_log(newMemberNode, 1);		// 로그파일 실행
delete tmp;				// 동적메모리 해제
m_count_increase();		// 회원 변수의 증가를위한 함수
system("pause");
return;
}