// '검색' 메뉴 중 비디오가게 비디오를 검색
#include "videoStore.h"

void
videoStore::Search_Video() {
	system("cls");
	cout << "비디오 검색 메뉴" << endl;
	cout << "===============================================================" << endl;

	int how; string what;
	cout << "검색방법을 선택하여 주세요." << endl;
	cout << "1. 비디오 제목 " << endl;
	cout << "2. 비디오 카테고리 " << endl;
	cout << ">> "; cin >> how;
	cout << "===============================================================" << endl;
	if (!(how == 1 || how == 2)) { cout << "잘못입력하셨습니다." << endl; system("pause"); return; }
	switch (how) {
	case 1: {
		cout << "비디오 제목을 입력해 주세요: "; cin >> what;
		Explore_Video(what);
		break;
	}
	case 2: {
		cout << "액션 = 1, 호러 = 2, 성인 = 3, 공상과학 = 4, 코미디 = 5, 판타지 = 6, 만화 = 7, 로맨스 = 8, 전쟁 = 9" << endl;
		cout << "카테고리를 선택해 주세요: "; cin >> how;
		if (!(how > 0 && how < 10)) { cout << "잘 못 입력하셨습니다. 다시시도해 주세요" << endl; system("pause"); return; }
		Explore_Video(how);
		break;
	}
	default: {
		cout << "잘못 입력하셨습니다." << endl;
		clear_buffer();
		system("pause"); return;
	}

	}
	system("pause");
}