#include <iostream>
using namespace std;

int N, K;
int idx[130];
int a[54];
int ret = -1;

void input()
{
    //freopen("input.txt", "r", stdin);
    int i = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') continue;
        idx[c] = i++;
    }

    cin >> N >> K;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 4; j < s.size() - 4; j++) {
            int c = s[j];
            if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') continue;
            a[i] |= (1 << idx[c]);
        }

    }
}

int getCnt(int i)
{
    int sum = 0;
    for (int j = 0; j < N; j++) {
        if ((a[j] & i) == a[j]) sum += 1;
    }
    return sum;
}

void go(int idx, int bit, int cnt)
{
    if (cnt == K - 5) {
        ret = max(ret, getCnt(bit));
        return;
    }
    if (idx == 21) return;

    go(idx + 1, bit, cnt);
    go(idx + 1, bit | (1 << idx), cnt + 1);
}

int main(void)
{
    input();
    if (K < 5) {
        cout << 0;
        return 0;
    }

    go(0, 0, 0);
    cout << ret;
    return 0;
}