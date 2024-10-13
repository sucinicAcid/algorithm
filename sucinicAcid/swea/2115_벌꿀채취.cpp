#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int N;
int MM=3; // N과 헷갈리지 않게 M 2개
int C=13;
int maxPrice = -1;
int map[10][10];
int ret = -1;

void input()
{
	ret = -1;

	cin >> N >> MM >> C;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
}

// 백트래킹
// nC1 + nC2 + ... + nCn은 아래처럼 구현
// idx 기준으로 선택하거나 선택안하거나
void getHoney(vector<int>& tong, int idx, int sum, int price)
{
	if (sum > C) return; // 가지치기
	if (maxPrice < price) maxPrice = price;

	if (idx >= MM) return;
	getHoney(tong, idx + 1, sum + tong[idx], price + (tong[idx] * tong[idx])); // idx 선택
	getHoney(tong, idx + 1, sum, price); // idx 선택안함
}

int getValue(int y, int x)
{
	maxPrice = -1;
	vector<int> tong;
	for (int i = 0; i < MM; i++) {
		tong.push_back(map[y][x + i]);
	}
	getHoney(tong, 0, 0, 0);
	return maxPrice;
}

int main(void)
{
	//freopen("input.txt", "r", stdin);

	int tcCnt;
	cin >> tcCnt;

	for (int tc=1; tc<=tcCnt; tc++) {
		input();

		for (int y1 = 0; y1 < N; y1++) {
			for (int x1 = 0; x1 <= N - MM; x1++) {
				int ret1 = getValue(y1, x1);

				int start = x1 + MM; // 길이가 긴 2개의 for문을 하나로 줄이는 방법
				for (int y2 = y1; y2 < N; y2++) {
					for (int x2 = start; x2 <= N - MM; x2++) {
						int ret2 = getValue(y2, x2);

						if (ret < ret1 + ret2) ret = ret1 + ret2;
					}
					start = 0;
				}
			}
		}

		cout << '#' << tc << ' ' << ret << '\n';
	}

	return 0;
}