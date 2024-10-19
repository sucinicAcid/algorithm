#include <iostream>
#include <cstring>
using namespace std;

int N,MM;
int a[502][502];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
int dp[502][502];

int go(int y, int x)
{
    if (y==N-1 && x==MM-1) return 1;

    int& ret = dp[y][x];
    if (~ret) return ret;
    ret = 0;

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny<0 || ny>=N || nx<0 || nx>=MM) continue;
        if (a[ny][nx] >= a[y][x]) continue;

        ret += go(ny, nx);
    }

    return ret;
}

int main(void)
{   
    //freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    cin >> N >> MM;
    for (int i=0; i<N; i++)
        for (int j=0; j<MM; j++)
            cin >> a[i][j];
    
    cout << go(0, 0);

    return 0;
}