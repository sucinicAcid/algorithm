/*
V1과 달라진점
head가 Node*가 아니라 Node임
 장점: deleteNode()에서 케이스 나눌 필요 없음
 단점: head관련 연산에서 next가 추가되서 복잡해짐

*/

#include <stdio.h>

struct Node {
	int data;
	Node* next;
};

Node head;

Node buf[11000000];
int bufCnt;

void addNode(int v)
{
	Node* node = &buf[bufCnt++];
	node->data = v;
	node->next = head.next;
	head.next = node;
}

// 맨앞, 맨뒤 예외처리 불필요
void deleteNode(int tar)
{
	Node* p = &head;
	while (p->next) {
		if (p->next->data == tar) p->next = p->next->next;
		else p = p->next;
	}
}

int main(void)
{
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);

	deleteNode(3);
	deleteNode(4);
	deleteNode(8);

	// 탐색
	for (Node* p = head.next; p; p = p->next) {
		printf("%d ", p->data);
	}
	return 0;
}