/* 순열
1. 기존의 permutation()은 파라미터가 3개에 swap 연산까지 있음
   이건 파라미터가 1개에 swap 연산 없음
   조합과 차이점은 check[], 파라미터 start 없음
2. make_permutation()
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N = 5, MM = 3;
int vect[100];
int arr[5] = { 3, 4, 1, 5, 2 };
bool check[5];

void permu(int lev)
{
	if (lev == MM) {
		for (int i = 0; i < MM; i++)
			cout << vect[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (check[i]) continue;
		check[i] = true;
		//vect[lev] = i; 인덱스를 넣고 싶을때 (0, 1, 2, ...)
		vect[lev] = arr[i];
		permu(lev + 1);
		check[i] = false;
	}
}

int main(void)
{
	//1
	permu(0);

	//2
	sort(arr, arr + 5);
	do {
		for (int i = 0; i < MM; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	} while (next_permutation(arr, arr + 5));
	return 0;
}