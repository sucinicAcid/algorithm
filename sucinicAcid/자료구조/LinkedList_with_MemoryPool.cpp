/*
기존의 링크드리스트 문제점: new 연산시 병목현상

해결방법: 메모리풀(전역 배열) 사용

장점
  1. 병목현상 (X)
  2. 지울필요 없음
*/

#include <stdio.h>

struct Node {
	int x;
	Node* next;
};

Node* head;
Node* last;

Node buf[11000000];
int bufCnt;

Node *myAlloc(int v, Node* next)
{
	buf[bufCnt] = { v, next };
	return &buf[bufCnt++];
}

// 뒤에 추가
void addNode(int v)
{
	if (head == NULL) {
		last = head = myAlloc(v, NULL);
		return;
	}
	last = last->next = myAlloc(v, NULL);
}

// 앞에 추가
void addNode2(int v)
{
	head = myAlloc(v, head);
}

int main(void)
{
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode2(5);
	addNode2(6);
	addNode2(7);
	addNode2(8);

	// 탐색
	for (Node* p = head; p != NULL; p = p->next) {
		printf("%d", p->x);
	}

	/* 필요 없음
	Node* old;
	while (head != NULL) {
		old = head;
		head = head->next;
		delete old;
	}
	return 0;
	*/
	return 0;
}