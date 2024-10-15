/*
소수점 n자리
cout << fixed;
cout.precision(n);
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> mp;
int total;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	
	cout << fixed;
	cout.precision(4);
	string s;
	while (getline(cin, s)) {
		mp[s]++;
		total++;
	}
	
	for (auto i : mp) {
		cout << i.first << ' ' << 100 * i.second / (double)total << '\n';
	}
	return 0;
}