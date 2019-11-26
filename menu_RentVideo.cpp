// '대여' 메뉴
#include "videoStore.h"

void
videoStore::Rent_Video() {
	system("cls");
	cout << "비디오 대여 메뉴" << endl;
	cout << "===============================================================" << endl;
	string Video, Member; Node* Rent_v, * Rent_m; int check, how = 0;

	// 대여하는 회원의 정보를 검색한다
	cout << "대여하시는 회원의 정보를 검색할 방법을 입력해주세요." << endl;
	cout << "1.이름" << endl;
	cout << "2.전화번호" << endl;
	cout << ">> "; cin >> how;
	cout << "===============================================================" << endl;
	
	// 입력값에 따른 검색방법을 위한 조건문
	if (how == 1) { cout << "회원의 이름을 입력해 주세요: "; cin >> Member; }
	else if (how == 2) { cout << "회원의 전화번호를 입력해 주세요: "; cin >> Member; }
	else{	// 입력값의 예외처리용 조건문
		cout << "잘못입력하셨습니다." << endl;
		clear_buffer();
		system("pause"); return;
	}
	
	Rent_m = Explore_Member(Member, how);		// 탐색되어 나온 회원 노드의 주소를 가리키는 Rent_m 변수
	// 회원이 이미 대여하고있는 비디오가 있다면
	if (Rent_m->Rent_Link->v_Data.v_Video_Id[0] != 0) {
		cout << "현재 " << Rent_m->m_Data.m_Name << " 회원은 비디오 " << Rent_m->Rent_Link->v_Data.v_Title << " 을(를) 대여하고 있습니다." << endl;
		cout << "다시 시도하여 주시기 바랍니다." << endl;
		system("pause"); return;
	}
	
	// 대여하는 비디오의 정보를 기록
	cout << "===============================================================" << endl;
	cout << "대여하실 비디오의 제목을 입력해주세요: "; cin >> Video;
	cout << "입력하신 비디오의 제목이 \"" << Video << "\" 가 맞습니까? " << endl;
	cout << "1.예 " << endl;
	cout << "2.아니요" << endl;
	cout << ">> "; cin >> check;
	cout << "===============================================================" << endl;
	if (!(check == 1)) {
		if (check == 2) {
			cout << "다시 비디오를 검색해주시기 바랍니다. 메뉴로 돌아갑니다" << endl;
			system("pause"); return;
		}
		cout << "잘 못 입력하셨습니다. 다시 시도해주시기 바랍니다." << endl;
		system("pause"); return;
	}

	cout << "===============================================================" << endl;
	Rent_v = Explore_Video(Video);				// 탐색되어 나온 비디오 노드의 주소를 가리키는 Rent_v 변수
	if (Rent_v->v_Data.v_Number == Rent_v->v_Data.v_State) {						// 비디오의 수량이 전부 대여중 일 때 대여 불가
		cout << "해당 비디오는 전부 대여중입니다. 대여가 불가능합니다." << endl;
		cout << "메뉴로 돌아갑니다...." << endl; system("pause"); return;
	}

	if (Rent_v->v_Data.v_Video_Id[0] == 2 || Rent_v->v_Data.v_Video_Id[0] == 3) {	// 비디오의 연령제한 조건문
		if (Rent_m->m_Data.m_Age < 20) {	// 대여하려는 회원의 나이가 20세 미만이면 불가
			cout << "해당 비디오는 미성년자 관람불가입니다. 대여가 불가능합니다." << endl;
			cout << "메뉴로 돌아갑니다...." << endl; system("pause"); return;
		}
		// 그게 아니라면 대여가 가능하다.
	}
	// 만약 위 사항들이 아니라면
	Rent_m->Rent_Link = Rent_v;
	Rent_v->v_Data.v_State++;

	cout << "===============================================================" << endl;
	cout << Rent_m->m_Data.m_Name << " 회원에게 ";
	cout << Rent_v->v_Data.v_Title << "의 비디오가 대여되었습니다." << endl;
	File_log(Rent_m, Rent_v, 1);
	system("pause");
	return;
}