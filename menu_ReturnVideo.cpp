// 비디오 반납 파일
#include "videoStore.h"

void
videoStore::Return_Video() {
	system("cls");
	cout << "비디오 반납 메뉴" << endl;
	cout << "===============================================================" << endl;

	string Video, Member; Node* Rent_v, * Rent_m; int check, how = 0;
	cout << "반납하시는 회원의 정보를 입력해 주세요" << endl;
	cout << "1.이름" << endl;
	cout << "2.전화번호" << endl;
	cout << ">> "; cin >> how; 
	cout << "===============================================================" << endl;
	if (how == 1) { cout << "회원의 이름을 입력해 주세요: "; cin >> Member; check_name(Member); }
	else if (how == 2) { cout << "회원의 전화번호를 입력해 주세요: "; cin >> Member; check_number(Member); }
	else {	// 입력값의 예외처리용 조건문
		cout << "잘못입력하셨습니다." << endl;
		clear_buffer();
		system("pause"); return;
	}

	Rent_m = Explore_Member(Member, how);

	Rent_v = Rent_m->Rent_Link;
	if (Rent_v->v_Data.v_Video_Id[0] == 0) {		// 만약 회원의 노드가 zero 헤드를 가리킨다면 대여중 상태가 아니다
		cout << "대여중인 비디오가 없습니다. 메뉴로 돌아가겠습니다." << endl;
		system("pause"); return;
	}
	cout << "반납하시는 비디오의 이름이 " << Rent_v->v_Data.v_Title << "이 가 맞으십니까?" << endl;
	cout << "1.예" << endl;
	cout << "2.아니오" << endl;
	cout << ">> "; cin >> how;
	cout << "===============================================================" << endl;
	if (!(how == 1)) {
		if (how == 2) {
			cout << "메뉴로 돌아가 다시 시도해주시기 바랍니다." << endl;
			clear_buffer();
			system("pause"); return;
		}
		cout << "잘못입력하셨습니다." << endl; clear_buffer(); system("pause"); return;
	}

	Rent_m->Rent_Link = z_Head;			// 회원 노드의 빌린 주소값을 null로 초기화
	Rent_v->v_Data.v_State--;			// 해당 비디오의 대여 수량 줄이기
	cout << Rent_m->m_Data.m_Name << " 회원이 빌려간 " << Rent_v->v_Data.v_Title << " 비디오가 반납되었습니다." << endl;
	File_log(Rent_m, Rent_v, 2);
	system("pause");
	return;
}