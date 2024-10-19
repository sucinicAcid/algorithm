/*
dp + bitfield

처음 dp는 정답후보 외로 설정 : -1

*/
#include <iostream>
#include <cstring>
using namespace std;

int N, M, C;
int a[15];
int dp[11][21][1 << 13];

int go(int bag, int left, int bit)
{
    if (bag == M) {
        int cnt = 0;
        while (bit) {
            cnt += bit & 1;
            bit >>= 1;
        }
        return cnt;
    }
    int& ret = dp[bag][left][bit];
    if (~ret) return ret;
    ret = 0;
    for (int i = 0; i < N; i++) {
        if (((bit >> i) & 1) == 1) continue;
        if (left > a[i]) ret = max(ret, go(bag, left - a[i], bit | (1 << i)));
        else if (left == a[i]) ret = max(ret, go(bag + 1, C, bit | (1 << i)));
    }
    ret = max(ret, go(bag + 1, C, bit));
    return ret;
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    cout << go(0, C, 0);
    return 0;
}