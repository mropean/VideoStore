// �ؽ�Ʈ ���� ���� ����
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
		cout << "�ҷ��� ���� ������ �����ϴ�. ���� �ۼ��մϴ�." << endl;
		system("pause");
		return;
	}

	Read_V.seekg(0, ios::beg);	// ���� ���� �ҷ����� ���� ����/����/����/�뿩����/�����ڵ�
	while (!Read_V.eof()) {
		newVideoNode = new Node;		// ���ο� ����� �޸𸮸� �Ҵ����ش�.
		now->Rlink = newVideoNode;		// ���� ��尡 ���� ��带 ����ų �� �ְ� �ּڰ��� �Ҵ��Ѵ�.
		newVideoNode->Llink = now;		// ���ο� ��尡 ���� ��带 ����ų �� �ְ� �ּڰ��� �Ҵ��Ѵ�.

		Read_V >> newVideoNode->v_Data.v_Day;		// ������ ���������� �о���δ�.
		Read_V.seekg(1, ios::cur);		// ������ ���� ������ ������� �����Ͽ� ���� �о���δ�.
		getline(Read_V, newVideoNode->v_Data.v_Title,'\n');	// ������ ������ ���� ��ü�� �о���δ�.
		Read_V >> newVideoNode->v_Data.v_Number;		// ������ ������ �о���δ�.
		Read_V >> newVideoNode->v_Data.v_State;			// ������ �뿩 ������ �о���δ�.
		for (int repeat = 0; repeat < 4; repeat++) {	// ���� �ڵ带 �� �� �� �о�鿩 �迭�� �����Ѵ�.
			Read_V >> newVideoNode->v_Data.v_Video_Id[repeat];
		}
		now = now->Rlink;			// ���� ���� �Ѿ��.
		v_count_increase();			// �� ���� ������ 1 ������Ų��.
	}
	now->Rlink = v_Head;
	cout << "���� ������ �ҷ��Խ��ϴ�." << endl;
	cout << "���� ����� ������ Ȯ���� �ֽñ� �ٶ��ϴ�." << endl;
	system("pause");
	Read_V.close();
}

void
videoStore::File_Video_Save() {				// ���� ���� �ۼ� ���� ����/����/����/�뿩����/�����ڵ�
	ofstream save_V("videoFile.txt");
	Node* now, * before;
	int repeat = 0;
	now = v_Head;							// now�� ���� ������ �����ϴµ�
	now = now->Rlink;						// �ٷ� ���� ���� �Ѿ�� �۾��� �����Ѵ�.
	save_V << endl;							// ������ ù ���� ��ĭ �� �����Ѵ�.
	cout << "�����͵��� \"videoFile.txt\" ���Ͽ� ����Ǿ����ϴ�." << endl;

	for (repeat = 0; repeat < v_Count; repeat++) {
		if (repeat == (v_Count - 1)) {		// ������ ����� Ŀ�� ��ġ�� �����ٷ� �ѱ��� �ʴ´�.
			save_V << now->v_Data.v_Day << " " << now->v_Data.v_Title << endl;	// ���������� ������ ���Ͽ� �����Ѵ�.
			save_V << now->v_Data.v_Number << endl;		// ���Ͽ� ������ �����Ѵ�.
			save_V << now->v_Data.v_State << endl;		// ���Ͽ� �뿩 ������ �����Ѵ�.
			for (int i = 0; i < 4; i++) {				// ���Ͽ� ���� �ڵ带 �����Ѵ�. 
				if (i == 3) {							// ������ �ε����̸� " " ���� �����Ѵ�.
					save_V << now->v_Data.v_Video_Id[i];
					break;
				}
				save_V << now->v_Data.v_Video_Id[i] << " ";	// " " �� �� �����Ͽ� �ҷ��ö� �Ѱ��� �ҷ����� �����Ѵ�.
			}
			before = now;
			now = now->Rlink;
			delete before;
			return;
		}
		// ������ ��尡 �ƴ϶�� Ŀ�� ��ġ�� �����ٷ� �ѱ��.
		save_V << now->v_Data.v_Day << " " << now->v_Data.v_Title << endl;	// ���������� ������ ���Ͽ� �����Ѵ�.
		save_V << now->v_Data.v_Number << endl;			// ���Ͽ� ������ �����Ѵ�.
		save_V << now->v_Data.v_State << endl;			// ���Ͽ� �뿩 ������ �����Ѵ�.
		for (int i = 0; i < 4; i++) {		// ���Ͽ� ���� �ڵ带 �����Ѵ�. 
			if (i == 3) {							// ������ �ε����̸� " " ���� �����Ѵ�.
				save_V << now->v_Data.v_Video_Id[i];
				break;
			}
			save_V << now->v_Data.v_Video_Id[i] << " ";		// " " �� �� �����Ͽ� �ҷ��ö� �Ѱ��� �ҷ����� �����Ѵ�.
		}
		save_V << endl;					// ���� �Է��� �� �Ǹ� ���� ������ �Է��ϱ� ���� �����ٷ� �Ѿ��.
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
	int videoCode[4];		// ���� �ڵ带 �����ϴ� ������ �迭

	now = m_Head;
	if (file_size(Read_M) <= 0) {
		cout << "�ҷ��� ȸ�� ������ �����ϴ�. ���� �ۼ��մϴ�." << endl;
		system("pause");
		return;
	}

	Read_M.seekg(0, ios::beg);	// ȸ�� ���� �ҷ����� ���� �̸�/��ȭ��ȣ/����/ȸ���ڵ�/�����ڵ�
	while (!Read_M.eof()) {
		newMemberNode = new Node;			// ȸ�� ��尡�� ��忡 �޸𸮸� �Ҵ��Ѵ�.
		now->Rlink = newMemberNode;			// ���� ��尡 ���� ������ ȸ�� ��带 ����ų �� �ְ� �Ѵ�.
		newMemberNode->Llink = now;			// ���� ������ ��尡 ���� ��带 ����ų �� �ְ� �Ѵ�.

		Read_M >> newMemberNode->m_Data.m_Name;			// ȸ���� �̸��� �ҷ��´�.
		Read_M >> newMemberNode->m_Data.m_Phone_number;	// ȸ���� ��ȭ��ȣ�� �ҷ��´�.
		Read_M >> newMemberNode->m_Data.m_Age;			// ȸ���� ���̸� �ҷ��´�.
		for (int repeat = 0; repeat < 5; repeat++) {	// ȸ���� ���� �ڵ带 �ҷ��´�.
			Read_M >> newMemberNode->m_Data.m_Member_Id[repeat];
		}
		for (int repeat = 0; repeat < 4; repeat++) {	// ���Ͽ� ������ִ� ���� �ڵ带 �ҷ��´�.
			Read_M >> videoCode[repeat];
		}

		// ���� �ڵ��� 0�� �ε����� 0 �̶�� �뿩������ ���� ����̰� 0�� �ƴ϶�� �뿩���̴� ����̴�
		// 0�� �ε����� ������ ī�װ��̱� �����̴� (0�� �ε����� 0�� ī�װ��� zero_��� ���̴�)
		if (videoCode[0] == 0) {			// �뿩���̴� ����� �ƴ϶�� zero_����� �ּҰ��� ������
			newMemberNode->Rent_Link = z_Head;
		}
		else if (videoCode[0] != 0) {		// �뿩���̴� ����̶�� ������ �ּҰ��� ������
			video_now = v_Head;				// ���� ������ �����Ͽ�
			for (int repeat = 0; repeat < v_Count; repeat++) {
				int count = 0;				// �ڵ��� ���ڰ� �������� �Ǵ��ϴ� ���� 4�ڸ��� ���� ���ٸ� �뿩�ϴ� �����̴�.
				video_now = video_now->Rlink;	// ���� ����� ���� ���� �Ѿ��.
				for (int array_repeat = 0; array_repeat < 4; array_repeat++) {
					if (videoCode[array_repeat] == video_now->v_Data.v_Video_Id[array_repeat]) 
						count++;		// ���� �ڵ�� ���� ��������� �ڵ尡 ���ٸ� count ����
				}
				if (count == 4) {		// 4�ڸ��� ���� �����ϴٸ� ���� ����� ������ �뿩�ϰ� �־��ٴ¶�
					newMemberNode->Rent_Link = video_now;			// ���� ������ ȸ�� ����� �뿩 �ּڰ��� ���� �ּڰ����� ����
				}
			}
		}
		
		now = now->Rlink;
		m_count_increase();		// �� ȸ���� ����.
	}
	now->Rlink = m_Head;
	cout << "ȸ�� ������ �ҷ��Խ��ϴ�." << endl;
	cout << "ȸ�� ����� ������ Ȯ���� �ֽñ� �ٶ��ϴ�." << endl;
	system("pause");
	Read_M.close();
}

void
videoStore::File_Member_Save() {		// ȸ�� ���� �ۼ� ���� �̸�/��ȭ��ȣ/����/ȸ���ڵ�/�����ڵ�
	ofstream save_M("memberFile.txt");
	Node* now, * before;
	int repeat = 0;
	now = m_Head;						// ȸ�� ����� ��带 ����Ų��.
	now = now->Rlink;					// ����� ���� ���� �Ѿ��.
	save_M << endl;						// ���� ù ���� ��� �����Ѵ�.

	cout << "�����͵��� \"memberFile.txt\" ���Ͽ� ����Ǿ����ϴ�." << endl;
	for (repeat = 0; repeat < m_Count; repeat++) {
		if (repeat == (m_Count - 1)) {			// ������ ����� Ŀ�� ��ġ�� �����ٷ� �ѱ��� �ʴ´�.
			// �����ʹ� �ٸ��� ȸ���� ������ ��ĭ�� �� ���Ͽ� �����Ѵ�.
			save_M << now->m_Data.m_Name << " " << now->m_Data.m_Phone_number << " " << now->m_Data.m_Age << " ";
			for (int i = 0; i < 5; i++) {		// ȸ���ڵ带 ��ĭ�� �����Ѵ�.
				save_M << now->m_Data.m_Member_Id[i] << " ";
			}									// ���� �ڵ嵵 ��ĭ�� ���������� ���������� ��ĭ ���� �ʴ´�.
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
		// ������ ��尡 �ƴ϶�� Ŀ�� ��ġ�� �����ٷ� �ѱ��.
		save_M << now->m_Data.m_Name << " " << now->m_Data.m_Phone_number << " " << now->m_Data.m_Age << " ";
		for (int i = 0; i < 5; i++) {
			save_M << now->m_Data.m_Member_Id[i] << " ";			// ȸ���ڵ带 ��ĭ�� �����Ѵ�.
		}										// ���� �ڵ嵵 ��ĭ�� ���������� ���������� ��ĭ ���� �ʴ´�.
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

	time_t curr_time;					// ��� ���Ͽ� ������ 'typedef long time_t'�� �Ǿ� �ֽ��ϴ�. ��, long�� �����ϴٰ� ���� �˴ϴ�.
	tm curr_tm;							// �ð� ǥ�ø� ���� ����ü�� �����մϴ�.
	curr_time = time(NULL);				// time �Լ��� 1970�� 1�� 1�� ���� ���ʰ� ���������� ����մϴ�. NULL�� ���ڷ� ����մϴ�.
	localtime_s(&curr_tm, &curr_time);	// ���� �ð��� �������� ��ȯ �� ��� ���Ǹ� ���Ͽ� tm ����ü�� �����մϴ�.(������)

	if (Case == 1) { save_L << "�������� ���α׷� ���۽ð�: " << curr_tm.tm_year + 1900 << "�� " << curr_tm.tm_mon + 1 << "�� " << curr_tm.tm_mday << "��" << endl; }
	else if(Case == 0) { 
		save_L << "�������� ���α׷� ����ð�: " << curr_tm.tm_hour << "�� " << curr_tm.tm_min << "�� " << curr_tm.tm_sec << "��" << endl;
		save_L << "===========================================================================" << endl;
	}

	save_L.close();
}

void
videoStore::File_log(Node* data,int Case) {
	ofstream save_L("logFile.txt", ios::app);
	time_t curr_time;					// ��� ���Ͽ� ������ 'typedef long time_t'�� �Ǿ� �ֽ��ϴ�. ��, long�� �����ϴٰ� ���� �˴ϴ�.
	tm curr_tm;							// �ð� ǥ�ø� ���� ����ü�� �����մϴ�.
	curr_time = time(NULL);				// time �Լ��� 1970�� 1�� 1�� ���� ���ʰ� ���������� ����մϴ�. NULL�� ���ڷ� ����մϴ�.
	localtime_s(&curr_tm, &curr_time);	// ���� �ð��� �������� ��ȯ �� ��� ���Ǹ� ���Ͽ� tm ����ü�� �����մϴ�.(������)

	if (Case == 1) {
		save_L << "�̸�: " << data->m_Data.m_Name << " ��ȭ��ȣ: " << data->m_Data.m_Phone_number << " ����: " << data->m_Data.m_Age << "�� ��(��) "
			<< curr_tm.tm_hour << "�� " << curr_tm.tm_min << "�� " << curr_tm.tm_sec << "�ʿ� ���ԵǾ����ϴ�." << endl;
		save_L << "ȸ���ڵ�: ";
		for (int i = 0; i < 5; i++) {
			save_L << data->m_Data.m_Member_Id[i];
		}
		save_L << endl;
	}
	else if (Case == 2) {
		save_L << "����: " << data->v_Data.v_Title << " ��������: " << data->v_Data.v_Day << "�� ��ǰ �� "
			<< curr_tm.tm_hour << "�� " << curr_tm.tm_min << "�� " << curr_tm.tm_sec << "�ʿ� " << data->v_Data.v_Number << "�� ��(��) �԰�Ǿ����ϴ�." << endl;
		save_L << "���� �ڵ�: ";
		for (int i = 0; i < 4; i++) {
			save_L << data->v_Data.v_Video_Id[i];
		}
		save_L << endl;
	}
	else if (Case == 3) {
		save_L << "ȸ��(�̸�: " << data->m_Data.m_Name << "ȸ���ڵ�: ";
		for (int i = 0; i < 5; i++) {
			save_L << data->m_Data.m_Member_Id[i];
		}
		save_L << ") ��(��) " << curr_tm.tm_hour << "�� " << curr_tm.tm_min << "�� " << curr_tm.tm_sec << "�ʿ� �����Ǿ����ϴ�." << endl;
	}
	else if (Case == 4) {
		save_L << "����(����: " << data->v_Data.v_Title << "�����ڵ�: ";
		for (int i = 0; i < 4; i++) {
			save_L << data->v_Data.v_Video_Id[i];
		}
		save_L << ") ��(��) " << curr_tm.tm_hour << "�� " << curr_tm.tm_min << "�� " << curr_tm.tm_sec << "�ʿ� �����Ǿ����ϴ�." << endl;
	}

	save_L.close();
}

void
videoStore::File_log(Node* m_data, Node* v_data, int Case) {
	ofstream save_L("logFile.txt", ios::app);
	time_t curr_time;					// ��� ���Ͽ� ������ 'typedef long time_t'�� �Ǿ� �ֽ��ϴ�. ��, long�� �����ϴٰ� ���� �˴ϴ�.
	tm curr_tm;							// �ð� ǥ�ø� ���� ����ü�� �����մϴ�.
	curr_time = time(NULL);				// time �Լ��� 1970�� 1�� 1�� ���� ���ʰ� ���������� ����մϴ�. NULL�� ���ڷ� ����մϴ�.
	localtime_s(&curr_tm, &curr_time);	// ���� �ð��� �������� ��ȯ �� ��� ���Ǹ� ���Ͽ� tm ����ü�� �����մϴ�.(������)

	
		save_L << "ȸ��(�̸�: " << m_data->m_Data.m_Name << ", ȸ���ڵ�: ";
		for (int i = 0; i < 5; i++) {
			save_L << m_data->m_Data.m_Member_Id[i];
		}
		save_L << ") ��(��)" << curr_tm.tm_hour << "�� " << curr_tm.tm_min << "�� " << curr_tm.tm_sec << "�ʿ� " << endl;
		save_L << "����(����: " << v_data->v_Data.v_Title << ", �����ڵ�: ";
		for (int i = 0; i < 4; i++) {
			save_L << v_data->v_Data.v_Video_Id[i];
		}
		if (Case == 1) { save_L << ") �� �뿩�߽��ϴ�." << endl; }			// ���� �뿩 �α�
		else if (Case == 2) { save_L << ") �� �ݳ��߽��ϴ�." << endl; }		// ���� �ݳ� �α�

		save_L.close();
}

void
clear_buffer() {
	cin.clear();	// �Է¹��� ����
	cin.ignore(INT_MAX, '\n');	// �߸��� �Է��� ���Ծ ���ڸ� ���� �������� ������.
	return;
}