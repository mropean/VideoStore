// 프로그램의 각 메뉴의 번호 선택 파일
#include "videoStore.h"

void 
videoStore::Choice_Add() {
	system("cls");
	cout << "===============================================================" << endl;
	cout << "추가 선택 메뉴" << endl;
	int choose_Number;
	cout << "1. 회원 가입" << endl;
	cout << "2. 비디오 입고" << endl;
	cout << "실행하실 항목을 입력해 주세요. >> "; cin >> choose_Number; 
	if (choose_Number == 1) {
		Add_Member();
	}
	else if (choose_Number == 2) {
		Add_Video();
	}
	else {
		cout << "잘 못 입력하셨습니다. 메인메뉴로 돌아갑니다." << endl;
		clear_buffer();
		system("pause"); return;
	}
}

void
videoStore::Choice_Search() {
	system("cls");
	cout << "===============================================================" << endl;
	cout << "검색 선택 메뉴" << endl;
	int choose_Number;
	cout << "1. 회원 검색" << endl;
	cout << "2. 비디오 검색" << endl;
	cout << "실행하실 항목을 입력해 주세요. >> "; cin >> choose_Number;
	if (choose_Number == 1) {
		Search_Member();
	}
	else if (choose_Number == 2) {
		Search_Video();
	}
	else {
		cout << "잘 못 입력하셨습니다. 메인메뉴로 돌아갑니다." << endl;
		clear_buffer();
		system("pause"); return;
	}
}

void
videoStore::choice_Print() {
	system("cls");
	cout << "===============================================================" << endl;
	cout << "출력 선택 메뉴" << endl;
	int choose_Number;
	cout << "1. 회원 목록 출력" << endl;
	cout << "2. 비디오 목록 출력" << endl;
	cout << "실행하실 항목을 입력해 주세요. >> "; cin >> choose_Number;
	if (choose_Number == 1) {
		Print_Member();
	}
	else if (choose_Number == 2) {
		Print_Video();
	}
	else {
		cout << "잘 못 입력하셨습니다. 메인메뉴로 돌아갑니다." << endl;
		clear_buffer();
		system("pause"); return;
	}
}

void
videoStore::choice_Remove() {
	system("cls");
	cout << "===============================================================" << endl;
	cout << "삭제 선택 메뉴" << endl;
	int choose_Number;
	cout << "1. 회원 삭제" << endl;
	cout << "2. 비디오 삭제" << endl;
	cout << "실행하실 항목을 입력해 주세요. >> "; cin >> choose_Number;
	if (choose_Number == 1) {
		Remove_Member();
	}
	else if (choose_Number == 2) {
		Remove_Video();
	}
	else {
		cout << "잘 못 입력하셨습니다. 메인메뉴로 돌아갑니다." << endl;
		clear_buffer();
		system("pause"); return;
	}
}