// '추가' 메뉴 비디오 입고 용
#include "videoStore.h"

// 카테고리 고유번호
/*	액션:	 1				호러:		 2
	성인:	 3				공상과학:	 4 
	코미디:	 5				판타지:		 6 
	만화:	 7				로맨스:		 8
	전쟁:	 9								*/

// 호러와 성인은 미성년자 대여 불가

void 
videoStore::Add_Video() {
	system("cls");
	cout << "비디오 추가 함수" << endl;
	cout << "===============================================================" << endl;
	cout << "*비디오의 개봉연도는 숫자만 기입해주시기 바랍니다." << endl;
	cout << "*비디오의 개수는 0개 이상 9개 이하입니다. 꼭 지켜주시길 바랍니다." << endl;
	cout << "===============================================================" << endl;

	Node* newVideoNode = new Node;
	video* tmp = new video;
	int categori, choice;

	cout << "비디오의 개봉연도를 입력해주세요: ";			 cin >> tmp->v_Day;
	if (check_number(tmp->v_Day) == false) { delete newVideoNode, tmp; system("pause"); return; }	// 숫자외에 다른 값방지를 위한 함수실행

	cout << "비디오의 제목을 입력해주세요: ";	
	cin.ignore(100, '\n');				// 이전입력의 \n이 getline으로 인한 입력버퍼에 들어가게 되는걸 방지
	getline(cin, tmp->v_Title);	// 비디오의 제목에는 모든 문자가 들어갈 수 있다.
	

	cout << "비디오의 개수를 입력해주세요: ";				 cin >> tmp->v_Number;	
	if (!(tmp->v_Number > 0 && tmp->v_Number < 10)) 
	{ cout << "숫자 외에 다른 문자가 입력되었습니다. 다시 시도하여 주십시오" << endl; delete newVideoNode, tmp; system("pause"); return; }	// 비디오의 개수 오류 방지
	clear_buffer();
	cout << "===============================================================" << endl;
	cout << "입력하신 정보" << endl;
	cout << "개봉연도: " << tmp->v_Day << "년" << endl;
	cout << "제목: " << tmp->v_Title << endl;
	cout << "개수: " << tmp->v_Number << "개" << endl;
	cout << "===============================================================" << endl;

	cout << "1.맞다." << endl;
	cout << "2.아니다." << endl;
	cout << ">> "; cin >> choice;
	cout << "===============================================================" << endl;
	if (!(choice == 1)) {	// 입력값이 다른값 일 때의 예외처리용 조건문
		if (choice == 2) {					// 입력값이 2이면 메뉴로 복귀한다.
			cout << "메뉴로 돌아갑니다. 다시 시도하여 주십시오." << endl;
			clear_buffer();
			delete newVideoNode, tmp; system("pause"); return;
		}									// 잘못된 입력일시 메뉴로 복귀시킨다.
		cout << "잘못입력하셨습니다. 다시 시도하여 주십시오." << endl;
		clear_buffer();
		delete newVideoNode, tmp; system("pause"); return;
	}

	cout << "===============================================================" << endl;
	// 고유번호의 0번째 인덱스는 카테고리의 확인에 도움이된다.
	while (1) {
		enum Categori { 액션 = 1, 호러 = 2, 성인 = 3, 공상과학 = 4, 코미디 = 5, 판타지 = 6, 만화 = 7, 로맨스 = 8, 전쟁 = 9 };
		cout << "액션 = 1, 호러 = 2, 성인 = 3, 공상과학 = 4, 코미디 = 5, 판타지 = 6, 만화 = 7, 로맨스 = 8, 전쟁 = 9" << endl;
		cout << "카테고리를 선택해 주세요: "; cin >> categori;
		switch (categori) {
			case 액션:				{ tmp->v_Video_Id[0] = 1; break; }
			case 호러:				{ tmp->v_Video_Id[0] = 2; break; }
			case 성인:				{ tmp->v_Video_Id[0] = 3; break; }
			case 공상과학:			{ tmp->v_Video_Id[0] = 4; break; }
			case 코미디:			{ tmp->v_Video_Id[0] = 5; break; }
			case 판타지:			{ tmp->v_Video_Id[0] = 6; break; }
			case 만화:				{ tmp->v_Video_Id[0] = 7; break; }
			case 로맨스:			{ tmp->v_Video_Id[0] = 8; break; }
			case 전쟁:				{ tmp->v_Video_Id[0] = 9; break; }
			default: {
			cout << "잘못 입력하셨습니다." << endl;
			cin.clear();	// 입력버퍼 비우기
			cin.ignore(INT_MAX, '\n');	// 잘못된 입력일 경우 버퍼를 비워 무한반복을 예방한다.
			system("pause");
			return;
			}
		}
		break;
	}
	cout << "===============================================================" << endl;

	// 비디오의 고유번호 배열에 1번째 인덱스부터 마지막 인덱스까지 난수 생성
	srand((unsigned int)time(NULL));
	for (int repeat = 1; repeat < 4; repeat++) { tmp->v_Video_Id[repeat] = rand() % 10;	}

	cout << "비디오의 고유번호는: ";
	for (int repeat = 0; repeat < 4; repeat++) { cout << tmp->v_Video_Id[repeat]; } cout << endl;
	cout << "===============================================================" << endl;

	newVideoNode->v_Data.v_Day = tmp->v_Day;
	newVideoNode->v_Data.v_Number = tmp->v_Number;
	newVideoNode->v_Data.v_Title = tmp->v_Title;
	newVideoNode->v_Data.v_State = 0;
	for (int repeat = 0; repeat < 4; repeat++) {			// 메모리 카피를 써봤으나 잘못사용하여 메모리값이 복사됨.
		newVideoNode->v_Data.v_Video_Id[repeat] = tmp->v_Video_Id[repeat];
	}

	//=========================================================================================================================================================================//
	/* 연결리스트의 주소를 설정해주는 방법 */
																		// 노드의 위치를 결정할 함수
	if (empty(1) == true) {													// 리스트가 비어있다면
		newVideoNode->Llink = v_Head;
		newVideoNode->Rlink = v_Head;
		// 새로운 노드의 왼쪽 링크와 오른쪽 링크를 m_head의 주소값으로 저장

		v_Head->Llink = newVideoNode;
		v_Head->Rlink = newVideoNode;
		// 새로운 노드의 왼쪽 링크와 오른쪽 링크를 m_head의 주소값으로 저장
	}
	else if (empty(1) == false) {											// 리스트가 비어있지 않다면
		Node* now;
		now = v_Head;
		for (now = now->Rlink; ; now = now->Rlink) {
			int res = newVideoNode->v_Data.v_Title.compare(now->v_Data.v_Title);
			if (res < 0) {													// 앞에 노드보다 사전순으로 앞에올시
				if (now->Llink == v_Head) {									// 앞노드가 처음노드 일시
					B:
					newVideoNode->Llink = now->Llink;
					newVideoNode->Rlink = now->Llink->Rlink;

					now->Llink->Rlink = newVideoNode;
					now->Llink = newVideoNode;
					break;
				}															// 그게 아니라면
				A:															// 앞에 노드와 뒤의 노드를 새로운 노드에게 연결해준다
				newVideoNode->Rlink = now->Llink->Rlink;
				newVideoNode->Llink = now->Llink;

				now->Llink->Rlink = newVideoNode;
				now->Llink = newVideoNode;
				break;
			}
			else if (res > 0 && now->Rlink == v_Head) {						// 앞에 노드보다 사전순으로 뒤에갈시 무시하면 되지만 그 뒤에가 헤드를 가리킬시
				C:
				newVideoNode->Rlink = now->Rlink;
				newVideoNode->Llink = now->Rlink->Llink;

				now->Rlink->Llink = newVideoNode;
				now->Rlink = newVideoNode;
				break;
			}
			else if (res == 0) {											// 사전순으로 같을시
				D:
				if (now->v_Data.v_Day > newVideoNode->v_Data.v_Day) {		// 앞에 노드보다 개봉연도가 작을시
					if (now->Llink == v_Head) {									// 앞노드가 처음노드 일시
						goto B;
					}											
					goto A;														
				}
				else if (now->v_Data.v_Day < newVideoNode->v_Data.v_Day) {	// 앞에 노드보다 개봉연도가 클시
					int day_res = newVideoNode->v_Data.v_Title.compare(now->Rlink->v_Data.v_Title);
					if (day_res == 0) {				// 또 뒤에노드와 이름이 같다면
						now = now->Rlink;
						goto D;
					}
					goto C;
				}
				else if (now->v_Data.v_Day == newVideoNode->v_Data.v_Day) {	// 앞에 노드와 개봉연도가 같을시
					cout << "같은 비디오가 입력되었습니다. 목록 확인 후 다시 시작하여 주시기 바랍니다." << endl;
					delete newVideoNode, tmp; system("pause"); return;
				}
			}
		}
	}
	File_log(newVideoNode, 2);			// 비디오 입고 로그 실행
delete tmp;								// 메모리 해제
v_count_increase();						// 총 비디오수 증가
system("pause");
return;
}