/*
# Hash Table (unordered_map으로 구현)

*/

#include <iostream>
#include <unordered_map>
using namespace std;

int vect[5] = { 10, 20, 50, 33, 36 };
unordered_map<int, int> mp;

void init()
{
	for (int i = 0; i < 5; i++) {
		mp[vect[i]] = 1;
	}
}

int main(void)
{
	init();

	int n = 10;
	if (mp.find(n) == mp.end()) {
		cout << "not found\n";
	}
	else {
		cout << "found\n";
	}
	return 0;
}