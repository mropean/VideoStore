// 탐색하는 파일
#include "videoStore.h"

//========================================= 비디오(제목) 탐색 함수 ===================================================================
Node*
videoStore::Explore_Video(string String) {
	Node* find[100];	// find 포인터 배열은 찾는 이름이 겹칠시 각 인덱스 번호로 주소값 저장 0번 인덱스는 생략
	Node* now;
	now = v_Head;
	int index, find_index, find_accept, ask_num, repeat = 0;
	cout << "==============================================================="	 << endl;
	cout << "제목으로 검색을 시작합니다."										 << endl;
	cout << "검색된 제목과 데이터의 목록입니다. 원하는 번호를 선택하여 주세요."  << endl;
	cout << "원하는 번호가 없을시 0번을 입력하시면 프로그램을 종료합니다."		 << endl;
	cout << "==============================================================="	 << endl;
	for (find_index = 1, find_accept = 1, now = now->Rlink; repeat < v_Count; repeat++) {
		index = now->v_Data.v_Title.find(String);
		if (index != -1) {
			find[find_index] = now;
			cout << find_accept << "." << "제목: " << now->v_Data.v_Title << " 년도: " << now->v_Data.v_Day <<
				" 대여갯수: " << now->v_Data.v_Number << "개중 " << now->v_Data.v_State << "개 대여중" << endl;
			find_index++; find_accept++;
		}
		now = now->Rlink;
	}
	cout << ">> "; cin >> ask_num;
	cout << "===============================================================" << endl;
	if (ask_num == 0) {
		cout << "프로그램을 종료합니다." << endl;
		exit(1);
	}
	cout << "==========================================" << endl;
	if ((index = find[ask_num]->v_Data.v_Title.size()) == 0) {		// 제목 문자열이 비어있을 수 가 없으니 오류로 인식한다.
		cout << "잘못된 번호를 입력하셨거나 비디오가 존재하지 않습니다." << endl; system("pause"); exit(1);
	}
	cout << "선택하신 번호의 데이터는 아래와 같습니다." << endl;
	cout << "제목: " << find[ask_num]->v_Data.v_Title << endl;
	cout << "년도: " << find[ask_num]->v_Data.v_Day << endl;
	cout << "비디오 코드: ";
	for (repeat = 0; repeat < 4; repeat++) { cout << find[ask_num]->v_Data.v_Video_Id[repeat]; }
	cout << endl;
	cout << "===============================================================" << endl;
	
	system("pause");
	return find[ask_num];
}

//========================================= 비디오(카테고리) 탐색 함수 ===================================================================
Node*
videoStore::Explore_Video(int num) {
	Node* find[100];	// find 포인터 배열은 찾는 이름이 겹칠시 각 인덱스 번호로 주소값 저장 0번 인덱스는 생략
	Node* now;
	now = v_Head;
	int index, find_index, find_accept, ask_num, repeat = 0;
	cout << "===============================================================" << endl;
	cout << "카테고리로 검색을 시작합니다." << endl;
	cout << "검색된 카테고리의 데이터 목록입니다. 원하는 번호를 선택하여 주세요." << endl;
	cout << "원하는 번호가 없을시 0번을 입력하시면 프로그램을 종료합니다." << endl;
	cout << "===============================================================" << endl;
	for (find_index = 1, find_accept = 1, now = now->Rlink; repeat < v_Count; repeat++) {
		if (now->v_Data.v_Video_Id[0] == num) {		// 비디오 코드의 첫번째 인덱스와 비교한다.
			find[find_index] = now;
			cout << find_accept << "." << "제목: " << now->v_Data.v_Title << " 년도: " << now->v_Data.v_Day << 
				" 대여갯수: " << now->v_Data.v_Number << "개중 " << now->v_Data.v_State << "개 대여중" << endl;
			find_index++; find_accept++;
		}
		now = now->Rlink;
	}
	cout << ">> "; cin >> ask_num;
	cout << "===============================================================" << endl;
	if (ask_num == 0) {
		cout << "프로그램을 종료합니다." << endl;
		exit(1);
	}
	cout << "==========================================" << endl;
	if ((index = find[ask_num]->v_Data.v_Title.size()) == 0) {		// 제목 문자열이 비어있을 수 가 없으니 오류로 인식한다.
		cout << "잘못된 번호를 입력하셨거나 비디오가 존재하지 않습니다." << endl; system("pause"); exit(1);
	}
	cout << "선택하신 번호의 데이터는 아래와 같습니다." << endl;
	cout << "제목: " << find[ask_num]->v_Data.v_Title << endl;
	cout << "년도: " << find[ask_num]->v_Data.v_Day << endl;
	cout << "비디오 코드: ";
	for(repeat = 0; repeat < 4; repeat++) { cout << find[ask_num]->v_Data.v_Video_Id[repeat]; }
	cout << endl;
	cout << "===============================================================" << endl;

	system("pause");
	return find[ask_num];
}

//========================================= 회원 탐색 함수 ===================================================================
Node*
videoStore::Explore_Member(string String, int num) {
	Node* find[100];	// find 포인터 배열은 찾는 이름이 겹칠시 각 인덱스 번호로 주소값 저장 0번 인덱스는 생략
	Node* now;
	now = m_Head;
	int index, find_index, find_accept, ask_num, repeat = 0;

	cout << "===============================================================" << endl;
	cout << "회원 검색을 시작합니다." << endl;
	cout << "검색된 이름의 데이터 목록입니다. 원하는 번호를 선택하여 주세요." << endl;
	cout << "원하는 번호가 없을시 0번을 입력하시면 프로그램을 종료합니다." << endl;
	cout << "===============================================================" << endl;

	// 매개변수로 받은 문자열이 다르기 때문에 세분화 시켜주어야 한다.
	if (num == 1) {	// 이름으로 검색시
		for (find_index = 1, find_accept = 1, now = now->Rlink; repeat < m_Count; repeat++) {
			index = now->m_Data.m_Name.find(String);		// 이름으로 찾는다.
			if (index != -1) {
				find[find_index] = now;
				cout << find_accept << "." << "이름: " << now->m_Data.m_Name << " 전화번호: " << now->m_Data.m_Phone_number << 
					" 나이: " << now->m_Data.m_Age << " 회원코드: ";
				for (int code_repeat = 0; code_repeat < 5; code_repeat++) { cout << now->m_Data.m_Member_Id[code_repeat]; } cout << endl;
				find_index++; find_accept++;
			}
			now = now->Rlink;
		}
	}
	else if(num == 2) {		// 전화번호로 검색시 
		for (find_index = 1, find_accept = 1, now = now->Rlink; repeat < m_Count; repeat++) {
			index = now->m_Data.m_Phone_number.find(String);	// 전화번호로 찾는다.
			if (index != -1) {
				find[find_index] = now;
				cout << find_accept << "." << "이름: " << now->m_Data.m_Name << " 전화번호: " << now->m_Data.m_Phone_number << 
					" 나이: " << now->m_Data.m_Age << " 회원코드: ";
				for (int code_repeat = 0; code_repeat < 5; code_repeat++) { cout << now->m_Data.m_Member_Id[code_repeat]; } cout << endl;
				find_index++; find_accept++;
			}
			now = now->Rlink;
		}
	} 
	cout << ">> "; cin >> ask_num;
	cout << "===============================================================" << endl;
	if (ask_num == 0) {
		cout << "프로그램을 종료합니다." << endl;
		exit(1);
	}
	
	cout << "==========================================" << endl;
	if ((index = find[ask_num]->m_Data.m_Name.size()) == 0) {
		cout << "잘못된 번호를 입력하셨거나 회원이 존재하지 않습니다." << endl; system("pause"); exit(1);
	}
	cout << "선택하신 번호의 데이터는 아래와 같습니다." << endl;
	cout << "이름: " << find[ask_num]->m_Data.m_Name << " " << find[ask_num]->m_Data.m_Age << "세 " << "전화번호: " << find[ask_num]->m_Data.m_Phone_number << endl;
	system("pause");
	return find[ask_num];
}