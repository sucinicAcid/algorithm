/*
그냥 완탐은 2^100 경우로 불가능 -> DP
1000만, 1억 배열은 안되는 경우가 많지만 이 경우는 가능

*/

#include <iostream>
using namespace std;

int N, K;
int walk[104][2];
int bicy[104][2];
int dp[104][100002];

int go(int idx, int time) {
	if (time < 0) return -1e9;
	if (idx == N) return 0;

	int& ret = dp[idx][time];
	if (ret) return ret;

	ret = go(idx + 1, time - walk[idx][0]) + walk[idx][1];
	ret = max(ret, go(idx + 1, time - bicy[idx][0]) + bicy[idx][1]);

	return ret;
}

int main(void)
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> walk[i][0] >> walk[i][1] >> bicy[i][0] >> bicy[i][1];
	
	cout << go(0, K);
	return 0;
}