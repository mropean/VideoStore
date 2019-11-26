// '검색' 메뉴 중 비디오가게 회원을 검색
#include "videoStore.h"

void
videoStore::Search_Member() {
	system("cls");
	cout << "회원 검색 메뉴" << endl;
	cout << "===============================================================" << endl;

	int how; string what;
	cout << "검색방법을 선택하여 주세요." << endl;
	cout << "1. 회원 이름 " << endl;
	cout << "2. 회원 전화번호 " << endl;
	cout << "===============================================================" << endl;
	cout << ">> "; cin >> how;

	switch (how) {
	case 1:		{
					cout << "검색하실 회원의 이름을 입력해주세요: "; cin >> what;
					check_name(what);
					Explore_Member(what, how);
					break;
																					}
	case 2:		{
					cout << "검색하실 회원의 전화번호를 입력해주세요: "; cin >> what;
					check_number(what);
					Explore_Member(what, how);
					break;
																					}
	default:	{
					cout << "잘못 입력하셨습니다." << endl;
					clear_buffer();
					system("pause"); return;
																					}
	}
	system("pause");
}