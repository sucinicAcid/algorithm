/*
# Hash Table

1. key -> (hashFunc) -> hashCode 변환
2. bucket[hashCode] = key;


링크드 리스트의 구현을 위해 메모리풀 필요

hashFunc 내용에 모듈러: 매우 큰수 처리 가능
hashFunc 파라미터로 "unsigned int": 음수를 양수로 변경

권장 bucket 사이즈: Node 개수 이상
*/

#include <iostream>
using namespace std;

int vect[5] = { 1, 34, 65, 25, 77 };

struct Node {
	int x;
	Node* next;
};

Node buf[100];
int bufCnt;

Node* bucket[3];

Node* myAlloc(int x, Node* next)
{
	buf[bufCnt] = { x, next };
	return &buf[bufCnt++];
}

void addNode(int from, int x)
{
	bucket[from] = myAlloc(x, bucket[from]);
}

int hashFunc(unsigned int key)
{
	return key % 3;
}

void init()
{
	for (int i = 0; i < 5; i++) {
		int hashCode = hashFunc(vect[i]);
		addNode(hashCode, vect[i]);
	}
}

int main(void)
{
	init();

	int n = 77;
	int code = hashFunc(n);
	for (Node* p = bucket[code]; p != NULL; p = p->next) {
		if (p->x == n) {
			cout << "found\n";
			return 0;
		}
	}
	cout << "not found\n";
	return 0;
}