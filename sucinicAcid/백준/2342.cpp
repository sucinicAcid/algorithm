#include <iostream>
using namespace std;

int N;
int a[100004];
int dp[100004][5][5];

int move(int from, int to)
{
    if (from == 0) return 2;
    else if (from == to) return 1;
    else if (abs(from - to) == 2) return 4;
    else return 3;
}

int go(int idx, int l, int r)
{
    if (idx == N) return 0;

    int& ret = dp[idx][l][r];
    if (ret) return ret;
    //if (a[idx] == l || a[idx] == r) {
    //    ret = go(idx + 1, l, r) + 1;
    //    return ret;
    //}
    ret = go(idx + 1, a[idx], r) + move(l, a[idx]);
    ret = min(ret, go(idx + 1, l, a[idx]) + move(r, a[idx]));
    return ret;
}

int main(void)
{
   //freopen("input.txt", "r", stdin);

    for (int i = 0; ; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            N = i;
            break;
        }
    }
    cout << go(0, 0, 0);

    return 0;
}