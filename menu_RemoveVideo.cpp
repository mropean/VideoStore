// 비디오 삭제 파일
#include "videoStore.h"

void
videoStore::Remove_Video() {
	system("cls");
	cout << "비디오 삭제 메뉴" << endl;
	cout << "===============================================================" << endl;

	int repeat; string what; Node* del, * now;
	cout << "삭제할 비디오의 제목을 입력해 주세요: "; cin >> what;
	del = Explore_Video(what);

	now = m_Head;
	// 비디오 삭제시 해당 비디오 노드를 가리키는 회원 노드가 있다면 그 노드를 z_헤드값으로 초기화 시킨다.
	if (del->v_Data.v_State != 0) {
		for (repeat = 0, now = now->Rlink; repeat < m_Count; repeat++) {
			if (now->Rent_Link == del) {	// 회원이 빌려간 비디오와 삭제하려는 비디오가 같은 주소값이면
				now->Rent_Link = z_Head;
			}
			now = now->Rlink;
		}
	}

	File_log(del, 4);
	del->Llink->Rlink = del->Rlink;
	del->Rlink->Llink = del->Llink;
	delete del;
	cout << "비디오가 삭제되었습니다." << endl;
	v_count_decrease();			// 총 비디오 개수 감소
	system("pause");
	return;
}