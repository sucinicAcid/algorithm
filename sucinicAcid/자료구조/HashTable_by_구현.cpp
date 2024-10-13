/*
# Hash Table (unordered_map 없이 unordered_map 구현)

*/

#include <iostream>
using namespace std;

struct Node {
	int key;
	int val;
	Node* next;
};

int vect[5] = { 10, 20, 50, 33, 36 };

Node buf[100];
int bufCnt;

Node* bucket[10];

Node* myAlloc(int key, int val, Node* next)
{
	buf[bufCnt] = { key, val, next };
	return &buf[bufCnt++];
}

void addNode(int from, int key, int val)
{
	// 이미 있는 경우엔 val 값만 갱신
	for (Node* p = bucket[from]; p != NULL; p = p->next) {
		if (p->key == key) {
			p->val = val;
			return;
		}
	}
	bucket[from] = myAlloc(key, val, bucket[from]);
}

int hashFunc(unsigned int key)
{
	return key % 97;
}

void insert(int key, int val)
{
	int hashCode = hashFunc(key);
	addNode(hashCode, key, val);
}

int getVal(int key)
{
	int hashCode = hashFunc(key);
	for (Node* p = bucket[hashCode]; p != NULL; p = p->next) {
		if (p->key == key) {
			return p->val;
		}
	}
	return 0; // 없으면 0 리턴
}

void init()
{
	for (int i = 0; i < 5; i++) {
		//mp[vect[i]] = 1;
		insert(vect[i], 1);
	}
}

int main(void)
{
	init();
	// cout << mp[10];
	cout << getVal(10);
	return 0;
}