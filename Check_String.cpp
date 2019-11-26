// 문자열의 예외처리용 파일
#include "videoStore.h"

bool 
check_name(string String) {
	int size = String.length();		// 문자열의 길이로 초기화
	for (int repeat = 0, ask_num = 0; repeat < size; repeat++) {	// 이름에 영어가 들어가있을시 사용자에게 물어보고 결과 입력을 기다림
																	// 영어로 들어가 있을시 일일이 물어봐야하는 어려움, 그러므로 한글만 입력바람
		if (String[repeat] >= (char)65 && String[repeat] <= (char)90 || String[repeat] >= (char)97 && String[repeat] <= (char)122) {
			cout << "이름에 영어가 들어가 있습니다. 그대로 진행 합니까?" << endl;
			cout << "들어간 문자 : " << String[repeat] << endl;
			cout << "1. 예" << " 2. 아니오(메뉴로)" << endl;
			cout << ">> "; cin >> ask_num;
			if (ask_num == 2) {	system("pause"); return false; }
		}
	}
	for (int repeat = 0, ask_num = 0; repeat < size; repeat++) {	// 숫자와 특수문자가 들어가 있을시 false리턴하여 전화번호부 종료
		if (String[repeat] >= (char)33 && String[repeat] <= 64 || String[repeat] >= 91 && String[repeat] <= 96 || String[repeat] >= 123 && String[repeat] <= 126) {
			cout << "문자열에 숫자 또는 특수문자가 들어가있습니다." << endl;
			system("pause");
			return false;
		}
	}
	return true;
}

bool 
check_number(string String,Node* head,int count) {
	Node* now;
	now = head;
	int size = String.length();
	for (int repeat = 0, ask_num = 0; repeat < size; repeat++) {
		if (!(String[repeat] >= (char)48 && String[repeat] <= (char)57)) {	// 
			cout << "전화번호에 숫자가아닌 다른문자가 입력되었습니다 다시 시도해 주세요." << endl;
			system("pause");
			return false;
		}
	}
	for (int i = 0, index = 0; i < count; i++) {
		if ((index = now->m_Data.m_Phone_number.find(String)) != -1) {
			cout << "전화번호부 안에 동일한 전화번호가 있습니다. 다시 시도해 주세요." << endl;
			system("pause");
			return false;
		}
		now = now->Rlink;
	}
	return true;
}

bool 
check_number(string String) {
	int size = String.length();
	for (int repeat = 0, ask_num = 0; repeat < size; repeat++) {
		if (!(String[repeat] >= (char)48 && String[repeat] <= (char)57)) {	// 
			cout << "전화번호에 숫자가아닌 다른문자가 입력되었습니다 다시 시도해 주세요." << endl;
			system("pause");
			return false;
		}
	}
}