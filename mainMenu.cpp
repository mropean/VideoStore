// 메인 메뉴
#include "videoStore.h"

int main() {
	videoStore vs; int select_Number = 0;
	cout << "비디오 가게" << endl;

	while (select_Number != 7) {
		system("cls");
		cout << "===============================================================" << endl;
		cout << "비디오가게 메인 메뉴"				<< endl;
		cout << "1. 회원 가입 및 비디오 입고. "		<< endl; 
		cout << "2. 회원 목록 및 비디오 목록. "		<< endl; 
		cout << "3. 비디오 대여. "					<< endl; 
		cout << "4. 회원 검색 및 비디오 검색. "		<< endl;
		cout << "5. 비디오 반납. "					<< endl;
		cout << "6. 회원 삭제 및 비디오 삭제. "		<< endl;
		cout << "7. 저장 후 프로그램 종료"			<< endl;
		cout << "원하시는 메뉴를 선택해 주세요 >> "; cin >> select_Number;

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
			cout << "잘못 입력하셨습니다." << endl;
			cin.clear();	// 입력버퍼 비우기
			cin.ignore(INT_MAX, '\n');	// 잘못된 입력일 경우 버퍼를 비워 무한반복을 예방한다.
		}
		}
		

	}
	return 0;
}