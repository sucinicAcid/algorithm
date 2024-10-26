#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, L;
int a[104][104];
int temp[104];
int check[104];
int ret;

void go()
{
    for (int i = 0; i < N - 1; i++) {
        if (temp[i] == temp[i + 1]) continue;
        if (abs(temp[i] - temp[i + 1]) > 1) return;

        if (temp[i] - temp[i + 1] == -1) {
            // 놓을 수 있는지 검사
            if (i + 1 < L) return;
            for (int j = 0; j < L - 1; j++) {
                if (temp[i - j] != temp[i - j - 1]) return;
                if (check[i - j]) return;
            }
            if (check[i - L + 1]) return;

            // 놓기
            for (int j = 0; j < L; j++) {
                check[i - j] = 1;
            }
        }
        else {
            if (i + L >= N) return;
            for (int j = 0; j < L - 1; j++) {
                if (temp[i + 1 + j] != temp[i + 1 + j + 1]) return;
                if (check[i + 1 + j]) return;
            }
            if (check[i + 1 + L - 1]) return;
            for (int j = 0; j < L; j++) {
                check[i + 1 + j] = 1;
            }
            i += L - 1;
        }
    }
    ret++;
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    cin >> N >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    // 행 검사
    for (int i = 0; i < N; i++) {
        memcpy(temp, a[i], sizeof(temp));
        memset(check, 0, sizeof(check));
        go();
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            temp[i] = a[i][j];
        }
        memset(check, 0, sizeof(check));
        go();
    }

    cout << ret;
    return 0;
}