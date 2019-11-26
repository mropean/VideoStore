#pragma once
#include <iostream>				// 기본 c++ 헤더			
#include <string>				// 문자열을 입력하기 위한 헤더
#include <fstream>				// 파일 입출력을 위한 헤더
#include <cstdlib>				// system 함수를 사용하고 난수를 생성하기 위한 헤더
#include <ctime>				// 현재 날짜와 시간을 알기위한 헤더

using 
namespace std;

struct 
member {					// 회원용 구조체
	string		m_Name;
	string		m_Phone_number;
	int			m_Age;
	int			m_Member_Id[5];
};

struct
video {						// 비디오용 구조체
	string		v_Day;
	string		v_Title;
	int			v_Number;
	int			v_State;	// 빌려간 갯수
	int			v_Video_Id[4];
};

struct
Node {						// 노드의 구조체
	member		m_Data;
	video		v_Data;
	Node*		Llink;
	Node*		Rlink;
	Node*		Rent_Link;
};

class
videoStore {			// 비디오가게 클래스

private:

	Node* v_Head; 
	Node* m_Head;
	Node* z_Head;
	int v_Count;
	int m_Count;

public:
	videoStore();
	void z_head_init(Node* phead);
	void m_count_increase();
	void v_count_increase();
	void m_count_decrease();
	void v_count_decrease();
	void Init_list(Node* phead);
	bool empty(int a);
	void Choice_Add();
	void Choice_Search();
	void choice_Print();
	void choice_Remove();
	void Add_Member();
	void Add_Video();
	void Search_Member();
	void Search_Video();
	Node* Explore_Video(string String);
	Node* Explore_Video(int num);
	Node* Explore_Member(string String, int num);
	void Rent_Video();
	void Return_Video();
	void Remove_Member();
	void Remove_Video();
	void Print_Video();
	void Print_Member();
	void File_Video_Save();
	void File_Member_Save();
	void File_Video_Load();
	void File_Member_Load();
	void File_log(int Case);
	void File_log(Node* data, int Case);
	void File_log(Node* m_data, Node* v_data, int Case);
	~videoStore();
};

bool check_name(string String);
bool check_number(string String);
bool check_number(string String, Node* head, int count);
long file_size(ifstream& file);
void clear_buffer();