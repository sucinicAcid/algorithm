#include <iostream>
#include <cstring>
using namespace std;

int N;
int MM;
int used[54][54];
int wall[54][54];
int area[2504];
int maxArea;
int totalCnt;
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
int maxArea2;

int dfs(int y, int x)
{
    used[y][x] = 1;
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= MM) continue;
        if (used[ny][nx]) continue;
        if (wall[y][x] & (1 << i)) continue;
        cnt += dfs(ny, nx);
    }

    return cnt;
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    cin >> MM >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < MM; j++)
            cin >> wall[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MM; j++) {
            if (!used[i][j]) {
                maxArea = max(maxArea, dfs(i, j));
                totalCnt += 1;
            }
        }
    }
    cout << totalCnt << '\n';
    cout << maxArea << '\n';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MM; j++) {
            for (int k = 0; k < 4; k++) {
                if (wall[i][j] & (1 << k)) {
                    memset(used, 0, sizeof(used));
                    wall[i][j] &= ~(1 << k);
                    maxArea2 = max(maxArea2, dfs(i, j));
                    wall[i][j] |= (1 << k);
                }
            }
        }
    }
    cout << maxArea2 << '\n';
    return 0;
}