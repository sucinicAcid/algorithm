/*
행만 정하면 열은 자동으로 정해짐

*/

#include <iostream>

using namespace std;

int N;
char a[24][24];
int ans = 1e9;

void go(int rowIdx, int row)
{
    if (rowIdx == N) {
        int ret = 0;
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                int temp = (a[i][j] == 'T') ? 1 : 0;
                if (row & (1 << i)) temp ^= 1;
                cnt += temp;
            }
            ret += min(cnt, N - cnt);
        }
        ans = min(ans, ret);
        return;
    }

    go(rowIdx + 1, row);
    go(rowIdx + 1, row | (1 << rowIdx));
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            a[i][j] = s[j];
        }
    }
    go(0, 0);
    cout << ans;
    return 0;
}