/*
	   배열 vs 링크드 리스트
추가&삭제  O(n)     O(1)

*추가&삭제 매우 빠름
*/

#include <stdio.h>

struct Node {
	int x;
	Node* next;
};

Node* head;
Node* last;

void addNode(int v)
{
	if (head == NULL) {
		head = new Node();
		head->x = v;
		head->next = NULL;
		last = head;
		return;
	}
	last->next = new Node();
	last = last->next;
	last->x = v;
	last->next = NULL;
}

int main(void)
{
	// 추가
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);

	// 탐색
	for (Node* p = head; p != NULL; p = p->next) {
		printf("%d", p->x);
	}

	// 삭제
	Node* old;
	while (head != NULL) {
		old = head;
		head = head->next;
		delete old;
	}
	return 0;
}