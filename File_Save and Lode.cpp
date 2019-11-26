// 텍스트 파일 관련 파일
#include "videoStore.h"

long
file_size(ifstream& file) {
	file.seekg(0, ios::end);
	long length = file.tellg();
	return length;
}

void
videoStore::File_Video_Load() {
	const char* File_v = "videoFile.txt";
	ifstream Read_V(File_v);
	Node* now, * newVideoNode;

	now = v_Head;
	if (file_size(Read_V) <= 0) {
		cout << "불러올 비디오 파일이 없습니다. 새로 작성합니다." << endl;
		system("pause");
		return;
	}

	Read_V.seekg(0, ios::beg);	// 비디오 파일 불러오는 순서 연도/제목/개수/대여상태/비디오코드
	while (!Read_V.eof()) {
		newVideoNode = new Node;		// 새로운 노드의 메모리를 할당해준다.
		now->Rlink = newVideoNode;		// 현재 노드가 다음 노드를 가리킬 수 있게 주솟값을 할당한다.
		newVideoNode->Llink = now;		// 새로운 노드가 이전 노드를 가리킬 수 있게 주솟값을 할당한다.

		Read_V >> newVideoNode->v_Data.v_Day;		// 비디오의 개봉연도를 읽어들인다.
		Read_V.seekg(1, ios::cur);		// 연도와 제목 사이의 빈공간을 무시하여 제목만 읽어들인다.
		getline(Read_V, newVideoNode->v_Data.v_Title,'\n');	// 비디오의 제목을 한줄 전체로 읽어들인다.
		Read_V >> newVideoNode->v_Data.v_Number;		// 비디오의 수량을 읽어들인다.
		Read_V >> newVideoNode->v_Data.v_State;			// 비디오의 대여 수량을 읽어들인다.
		for (int repeat = 0; repeat < 4; repeat++) {	// 비디오 코드를 한 개 씩 읽어들여 배열에 저장한다.
			Read_V >> newVideoNode->v_Data.v_Video_Id[repeat];
		}
		now = now->Rlink;			// 다음 노드로 넘어간다.
		v_count_increase();			// 총 비디오 개수를 1 증가시킨다.
	}
	now->Rlink = v_Head;
	cout << "비디오 파일을 불러왔습니다." << endl;
	cout << "비디오 출력을 실행해 확인해 주시기 바랍니다." << endl;
	system("pause");
	Read_V.close();
}

void
videoStore::File_Video_Save() {				// 비디오 파일 작성 순서 연도/제목/개수/대여상태/비디오코드
	ofstream save_V("videoFile.txt");
	Node* now, * before;
	int repeat = 0;
	now = v_Head;							// now는 비디오 헤드부터 시작하는데
	now = now->Rlink;						// 바로 다음 노드로 넘어가서 작업을 시작한다.
	save_V << endl;							// 파일의 첫 줄을 한칸 띄어서 저장한다.
	cout << "데이터들이 \"videoFile.txt\" 파일에 저장되었습니다." << endl;

	for (repeat = 0; repeat < v_Count; repeat++) {
		if (repeat == (v_Count - 1)) {		// 마지막 노드라면 커서 위치를 다음줄로 넘기지 않는다.
			save_V << now->v_Data.v_Day << " " << now->v_Data.v_Title << endl;	// 개봉연도와 제목을 파일에 저장한다.
			save_V << now->v_Data.v_Number << endl;		// 파일에 개수를 저장한다.
			save_V << now->v_Data.v_State << endl;		// 파일에 대여 개수를 저장한다.
			for (int i = 0; i < 4; i++) {				// 파일에 비디오 코드를 저장한다. 
				if (i == 3) {							// 마지막 인덱스이면 " " 없이 저장한다.
					save_V << now->v_Data.v_Video_Id[i];
					break;
				}
				save_V << now->v_Data.v_Video_Id[i] << " ";	// " " 로 띄어서 저장하여 불러올때 한개씩 불러오게 저장한다.
			}
			before = now;
			now = now->Rlink;
			delete before;
			return;
		}
		// 마지막 노드가 아니라면 커서 위치를 다음줄로 넘긴다.
		save_V << now->v_Data.v_Day << " " << now->v_Data.v_Title << endl;	// 개봉연도와 제목을 파일에 저장한다.
		save_V << now->v_Data.v_Number << endl;			// 파일에 개수를 저장한다.
		save_V << now->v_Data.v_State << endl;			// 파일에 대여 개수를 저장한다.
		for (int i = 0; i < 4; i++) {		// 파일에 비디오 코드를 저장한다. 
			if (i == 3) {							// 마지막 인덱스이면 " " 없이 저장한다.
				save_V << now->v_Data.v_Video_Id[i];
				break;
			}
			save_V << now->v_Data.v_Video_Id[i] << " ";		// " " 로 띄어서 저장하여 불러올때 한개씩 불러오게 저장한다.
		}
		save_V << endl;					// 비디오 입력이 다 되면 다음 비디오를 입력하기 위해 다음줄로 넘어간다.
		before = now;
		now = now->Rlink;
		delete before;
	}
	system("pause");
	save_V.close();
}

void
videoStore::File_Member_Load() {
	const char* File_m = "memberFile.txt";
	ifstream Read_M(File_m);
	Node* now, * newMemberNode;
	Node* video_now;
	int videoCode[4];		// 비디오 코드를 저장하는 정수형 배열

	now = m_Head;
	if (file_size(Read_M) <= 0) {
		cout << "불러올 회원 파일이 없습니다. 새로 작성합니다." << endl;
		system("pause");
		return;
	}

	Read_M.seekg(0, ios::beg);	// 회원 파일 불러오는 순서 이름/전화번호/나이/회원코드/비디오코드
	while (!Read_M.eof()) {
		newMemberNode = new Node;			// 회원 노드가될 노드에 메모리를 할당한다.
		now->Rlink = newMemberNode;			// 지금 노드가 새로 생성된 회원 노드를 가리킬 수 있게 한다.
		newMemberNode->Llink = now;			// 새로 생성된 노드가 지금 노드를 가리킬 수 있게 한다.

		Read_M >> newMemberNode->m_Data.m_Name;			// 회원의 이름을 불러온다.
		Read_M >> newMemberNode->m_Data.m_Phone_number;	// 회원의 전화번호를 불러온다.
		Read_M >> newMemberNode->m_Data.m_Age;			// 회원의 나이를 불러온다.
		for (int repeat = 0; repeat < 5; repeat++) {	// 회원의 고유 코드를 불러온다.
			Read_M >> newMemberNode->m_Data.m_Member_Id[repeat];
		}
		for (int repeat = 0; repeat < 4; repeat++) {	// 파일에 저장되있던 비디오 코드를 불러온다.
			Read_M >> videoCode[repeat];
		}

		// 비디오 코드의 0번 인덱스가 0 이라면 대여중이지 않은 사람이고 0이 아니라면 대여중이던 사람이다
		// 0번 인덱스는 비디오의 카테고리이기 때문이다 (0번 인덱스가 0인 카테고리는 zero_헤드 뿐이다)
		if (videoCode[0] == 0) {			// 대여중이던 사람이 아니라면 zero_헤드의 주소값을 가진다
			newMemberNode->Rent_Link = z_Head;
		}
		else if (videoCode[0] != 0) {		// 대여중이던 사람이라면 비디오의 주소값을 가진다
			video_now = v_Head;				// 비디오 헤드부터 시작하여
			for (int repeat = 0; repeat < v_Count; repeat++) {
				int count = 0;				// 코드의 숫자가 동일할지 판단하는 변수 4자리가 전부 같다면 대여하는 비디오이다.
				video_now = video_now->Rlink;	// 비디오 노드의 다음 노드로 넘어간다.
				for (int array_repeat = 0; array_repeat < 4; array_repeat++) {
					if (videoCode[array_repeat] == video_now->v_Data.v_Video_Id[array_repeat]) 
						count++;		// 비디오 코드와 현재 비디오노드의 코드가 같다면 count 증가
				}
				if (count == 4) {		// 4자리가 전부 동일하다면 현재 멤버는 비디오를 대여하고 있었다는뜻
					newMemberNode->Rent_Link = video_now;			// 새로 생성된 회원 노드의 대여 주솟값을 비디오 주솟값으로 대입
				}
			}
		}
		
		now = now->Rlink;
		m_count_increase();		// 총 회원수 증가.
	}
	now->Rlink = m_Head;
	cout << "회원 파일을 불러왔습니다." << endl;
	cout << "회원 출력을 실행해 확인해 주시기 바랍니다." << endl;
	system("pause");
	Read_M.close();
}

void
videoStore::File_Member_Save() {		// 회원 파일 작성 순서 이름/전화번호/나이/회원코드/비디오코드
	ofstream save_M("memberFile.txt");
	Node* now, * before;
	int repeat = 0;
	now = m_Head;						// 회원 노드의 헤드를 가르킨다.
	now = now->Rlink;					// 헤드의 다음 노드로 넘어간다.
	save_M << endl;						// 파일 첫 줄을 띄고 시작한다.

	cout << "데이터들이 \"memberFile.txt\" 파일에 저장되었습니다." << endl;
	for (repeat = 0; repeat < m_Count; repeat++) {
		if (repeat == (m_Count - 1)) {			// 마지막 노드라면 커서 위치를 다음줄로 넘기지 않는다.
			// 비디오와는 다르게 회원의 정보는 한칸씩 띄어서 파일에 저장한다.
			save_M << now->m_Data.m_Name << " " << now->m_Data.m_Phone_number << " " << now->m_Data.m_Age << " ";
			for (int i = 0; i < 5; i++) {		// 회원코드를 한칸씩 저장한다.
				save_M << now->m_Data.m_Member_Id[i] << " ";
			}									// 비디오 코드도 한칸씩 저장하지만 마지막꺼는 한칸 띄지 않는다.
			for (int i = 0; i < 4; i++) {
				if (i == 3) {
					save_M << now->Rent_Link->v_Data.v_Video_Id[i];
					break;
				}
				save_M << now->Rent_Link->v_Data.v_Video_Id[i] << " ";
			}
			before = now;
			now = now->Rlink;
			delete before;
			return;
		}
		// 마지막 노드가 아니라면 커서 위치를 다음줄로 넘긴다.
		save_M << now->m_Data.m_Name << " " << now->m_Data.m_Phone_number << " " << now->m_Data.m_Age << " ";
		for (int i = 0; i < 5; i++) {
			save_M << now->m_Data.m_Member_Id[i] << " ";			// 회원코드를 한칸씩 저장한다.
		}										// 비디오 코드도 한칸씩 저장하지만 마지막꺼는 한칸 띄지 않는다.
		for (int i = 0; i < 4; i++) {
			if (i == 3) {					
				save_M << now->Rent_Link->v_Data.v_Video_Id[i];
				break;
			}
			save_M << now->Rent_Link->v_Data.v_Video_Id[i] << " ";
		}
		save_M << endl;
		before = now;
		now = now->Rlink;
		delete before;
	}
	system("pause");
	save_M.close();
}

void
videoStore::File_log(int Case) {
	ofstream save_L("logFile.txt", ios::app);

	time_t curr_time;					// 헤더 파일에 가보면 'typedef long time_t'로 되어 있습니다. 즉, long과 동일하다고 보면 됩니다.
	tm curr_tm;							// 시간 표시를 위한 구조체를 선언합니다.
	curr_time = time(NULL);				// time 함수는 1970년 1월 1일 이후 몇초가 지났는지를 계산합니다. NULL을 인자로 사용합니다.
	localtime_s(&curr_tm, &curr_time);	// 지역 시간을 기준으로 변환 및 출력 편의를 위하여 tm 구조체에 저장합니다.(포맷팅)

	if (Case == 1) { save_L << "비디오가게 프로그램 시작시간: " << curr_tm.tm_year + 1900 << "년 " << curr_tm.tm_mon + 1 << "월 " << curr_tm.tm_mday << "일" << endl; }
	else if(Case == 0) { 
		save_L << "비디오가게 프로그램 종료시간: " << curr_tm.tm_hour << "시 " << curr_tm.tm_min << "분 " << curr_tm.tm_sec << "초" << endl;
		save_L << "===========================================================================" << endl;
	}

	save_L.close();
}

void
videoStore::File_log(Node* data,int Case) {
	ofstream save_L("logFile.txt", ios::app);
	time_t curr_time;					// 헤더 파일에 가보면 'typedef long time_t'로 되어 있습니다. 즉, long과 동일하다고 보면 됩니다.
	tm curr_tm;							// 시간 표시를 위한 구조체를 선언합니다.
	curr_time = time(NULL);				// time 함수는 1970년 1월 1일 이후 몇초가 지났는지를 계산합니다. NULL을 인자로 사용합니다.
	localtime_s(&curr_tm, &curr_time);	// 지역 시간을 기준으로 변환 및 출력 편의를 위하여 tm 구조체에 저장합니다.(포맷팅)

	if (Case == 1) {
		save_L << "이름: " << data->m_Data.m_Name << " 전화번호: " << data->m_Data.m_Phone_number << " 나이: " << data->m_Data.m_Age << "세 이(가) "
			<< curr_tm.tm_hour << "시 " << curr_tm.tm_min << "분 " << curr_tm.tm_sec << "초에 가입되었습니다." << endl;
		save_L << "회원코드: ";
		for (int i = 0; i < 5; i++) {
			save_L << data->m_Data.m_Member_Id[i];
		}
		save_L << endl;
	}
	else if (Case == 2) {
		save_L << "제목: " << data->v_Data.v_Title << " 개봉연도: " << data->v_Data.v_Day << "년 작품 이 "
			<< curr_tm.tm_hour << "시 " << curr_tm.tm_min << "분 " << curr_tm.tm_sec << "초에 " << data->v_Data.v_Number << "개 이(가) 입고되었습니다." << endl;
		save_L << "비디오 코드: ";
		for (int i = 0; i < 4; i++) {
			save_L << data->v_Data.v_Video_Id[i];
		}
		save_L << endl;
	}
	else if (Case == 3) {
		save_L << "회원(이름: " << data->m_Data.m_Name << "회원코드: ";
		for (int i = 0; i < 5; i++) {
			save_L << data->m_Data.m_Member_Id[i];
		}
		save_L << ") 이(가) " << curr_tm.tm_hour << "시 " << curr_tm.tm_min << "분 " << curr_tm.tm_sec << "초에 삭제되었습니다." << endl;
	}
	else if (Case == 4) {
		save_L << "비디오(제목: " << data->v_Data.v_Title << "비디오코드: ";
		for (int i = 0; i < 4; i++) {
			save_L << data->v_Data.v_Video_Id[i];
		}
		save_L << ") 이(가) " << curr_tm.tm_hour << "시 " << curr_tm.tm_min << "분 " << curr_tm.tm_sec << "초에 삭제되었습니다." << endl;
	}

	save_L.close();
}

void
videoStore::File_log(Node* m_data, Node* v_data, int Case) {
	ofstream save_L("logFile.txt", ios::app);
	time_t curr_time;					// 헤더 파일에 가보면 'typedef long time_t'로 되어 있습니다. 즉, long과 동일하다고 보면 됩니다.
	tm curr_tm;							// 시간 표시를 위한 구조체를 선언합니다.
	curr_time = time(NULL);				// time 함수는 1970년 1월 1일 이후 몇초가 지났는지를 계산합니다. NULL을 인자로 사용합니다.
	localtime_s(&curr_tm, &curr_time);	// 지역 시간을 기준으로 변환 및 출력 편의를 위하여 tm 구조체에 저장합니다.(포맷팅)

	
		save_L << "회원(이름: " << m_data->m_Data.m_Name << ", 회원코드: ";
		for (int i = 0; i < 5; i++) {
			save_L << m_data->m_Data.m_Member_Id[i];
		}
		save_L << ") 이(가)" << curr_tm.tm_hour << "시 " << curr_tm.tm_min << "분 " << curr_tm.tm_sec << "초에 " << endl;
		save_L << "비디오(제목: " << v_data->v_Data.v_Title << ", 비디오코드: ";
		for (int i = 0; i < 4; i++) {
			save_L << v_data->v_Data.v_Video_Id[i];
		}
		if (Case == 1) { save_L << ") 를 대여했습니다." << endl; }			// 비디오 대여 로그
		else if (Case == 2) { save_L << ") 를 반납했습니다." << endl; }		// 비디오 반납 로그

		save_L.close();
}

void
clear_buffer() {
	cin.clear();	// 입력버퍼 비우기
	cin.ignore(INT_MAX, '\n');	// 잘못된 입력이 들어왔어도 숫자만 들어가고 나머지는 버린다.
	return;
}