// '출력' 메뉴 비디오의 데이터를 출력하며 대여 상태를 출력
#include "videoStore.h"

void videoStore::Print_Video() {
	Node* now;
	cout << "===============================================================" << endl;
	cout << "총 개수: " << v_Count << "개" << endl;
	now = v_Head;			// 비디오 헤드로부터 시작하여 모든 비디오 출력
	now = now->Rlink;
	for (int i = 0; i < v_Count; i++) {
		cout << "제목: " << now->v_Data.v_Title << " 년도: " << now->v_Data.v_Day << " 재고/대여갯수: " << now->v_Data.v_Number << "/" << now->v_Data.v_State << " 코드: ";
		for (int repeat = 0; repeat < 4; repeat++) cout << now->v_Data.v_Video_Id[repeat];
		cout << endl;
		now = now->Rlink;
	}
	system("pause");
}

void videoStore::Print_Member() {
	Node* now;
	cout << "===============================================================" << endl;
	cout << "총 인원: " << m_Count << "명" << endl;
	now = m_Head;			// 회원 헤드로부터 시작하여 모든 회원 출력
	now = now->Rlink;
	for (int i = 0; i < m_Count; i++) {
		cout << "이름: " << now->m_Data.m_Name << " 전화번호: " << now->m_Data.m_Phone_number << " 나이: " << now->m_Data.m_Age << "세 " << "회원코드: ";
		for (int repeat = 0; repeat < 5; repeat++) cout << now->m_Data.m_Member_Id[repeat];
		cout << endl;
		cout << now->m_Data.m_Name << " 회원이 대여중인 비디오: " << now->Rent_Link->v_Data.v_Title << endl;
		now = now->Rlink;
	}
	system("pause");
}
