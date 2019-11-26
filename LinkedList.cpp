#include "videoStore.h"

videoStore::videoStore() {
	v_Head = new Node;
	m_Head = new Node;
	z_Head = new Node;
	Init_list(m_Head); 
	Init_list(v_Head);
	z_head_init(z_Head);
	File_log(1);
	File_Video_Load();
	File_Member_Load();
}

void videoStore::m_count_increase() { m_Count++; }
void videoStore::v_count_increase() { v_Count++; }

void videoStore::m_count_decrease() { m_Count--; }
void videoStore::v_count_decrease() { v_Count--; }


void
videoStore::z_head_init(Node* phead) {
	phead->Llink = phead;
	phead->Rlink = phead;
	for (int i = 0; i < 4; i++) {
		phead->v_Data.v_Video_Id[i] = 0;
	}

}
void 
videoStore::Init_list(Node* phead) {
	phead->Llink = phead;
	phead->Rlink = phead;
}

bool 
videoStore::empty(int a) {
	switch (a) {
	case 1: {
		if (v_Count == 0) return true;
		return false;
		break;
	}
	case 2: {
		if (m_Count == 0) return true;
		return false;
		break;
	}
	}

}

videoStore::~videoStore() {
	File_Member_Save();
	File_Video_Save();
	delete v_Head, m_Head, z_Head;
	File_log(0);
}