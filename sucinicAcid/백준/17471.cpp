#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define RED     0
#define BLUE    1

int N;
int ingu[14];
int redBlue[14];
vector<int> adj[14];
int used[14];
int ret = 1e9;

void input()
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> ingu[i];
    }
    for (int i = 1; i <= N; i++) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int a;
            cin >> a;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
    }
}

int dfs(int here, int color)
{
    int cnt = ingu[here];
    used[here] = 1;

    for (int next : adj[here]) {
        if (used[next]) continue;
        if (redBlue[next] != color) continue;
        cnt += dfs(next, color);
    }

    return cnt;
}

int main(void)
{
    input();

    for (int i = 0; i < (1 << N); i++) {
        memset(used, 0, sizeof(used));
        memset(redBlue, 0, sizeof(redBlue));

        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                redBlue[j + 1] = BLUE;

        int blueCnt;
        for (int j = 1; j <= N; j++) {
            if (redBlue[j] == BLUE) {
                blueCnt = dfs(j, BLUE);
                break;
            }
        }

        int redCnt;
        for (int j = 1; j <= N; j++) {
            if (redBlue[j] == RED) {
                redCnt = dfs(j, RED);
                break;
            }
        }

        int flag = 0;
        for (int j = 1; j <= N; j++) {
            if (used[j] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;

        ret = min(ret, abs(blueCnt - redCnt));
    }
    if (ret == 1e9) cout << -1;
    else cout << ret;
    return 0;
}