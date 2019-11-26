// 회원 삭제 파일
#include "videoStore.h"

void
videoStore::Remove_Member() {
	system("cls");
	cout << "회원 삭제 메뉴" << endl;
	cout << "===============================================================" << endl;

	int how; string what; Node* del, * v_Data;
	cout << "삭제할 회원을 찾는 방법을 선택하여 주세요." << endl;
	cout << "1. 회원 이름" << endl;
	cout << "2. 회원 전화번호 " << endl;
	cout << ">> "; cin >> how; 
	cout << "===============================================================" << endl;
	if (how == 1) { cout << "회원의 이름을 입력해 주세요: "; cin >> what; check_name(what); }
	else if (how == 2) { cout << "회원의 전화번호를 입력해 주세요: "; cin >> what; check_number(what); }
	else { cout << "잘못입력하셨습니다." << endl; 
	clear_buffer();
	system("pause"); return; }

	// 삭제하려는 회원노드의 대여 주소값이 z_헤드가 아니면 해당 비디오를 강제로 반납시킨다.
	del = Explore_Member(what, how);
	if (del->Rent_Link->v_Data.v_Video_Id[0] != 0) {
		v_Data = del->Rent_Link;
		v_Data->v_Data.v_State--;
		cout << del->m_Data.m_Name << " 회원이 빌려간 " << del->v_Data.v_Title << " 비디오가 반납되었습니다." << endl;
	}

	File_log(del, 3);
	del->Llink->Rlink = del->Rlink;
	del->Rlink->Llink = del->Llink;
	delete del;
	cout << "회원이 삭제되었습니다." << endl;
	m_count_decrease();			// 총 회원 수 감소
	system("pause");
	return;
}
