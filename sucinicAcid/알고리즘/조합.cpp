/* 조합
1. 기존의 combi()는 파라미터로 vector<int>가 들어감
   이건 전역배열로 조금 더 빠름
2. 다중 for문
*/

#include <iostream>
using namespace std;

int N = 5, MM = 3;
int vect[100];
int arr[5] = { 3, 4, 1, 5, 2 };

void combi(int lev, int start)
{
	if (lev == MM) {
		for (int i = 0; i < MM; i++)
			cout << vect[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i < N; i++) {
		//vect[lev] = i; 인덱스를 넣고 싶을때 (0, 1, 2, ...)
		vect[lev] = arr[i];
		combi(lev + 1, i + 1);
	}
}

int main(void)
{
	//1. 전역배열
	combi(0, 0);

	//2. 다중for문
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			for (int k = 0; k < j; k++)
				cout << i << ' ' << j << ' ' << k << '\n';
	return 0;
}