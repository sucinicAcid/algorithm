/*
dp 초기화는 정답후보 외 : 51자리 이상
*/

#include <iostream>
#include <string>

using namespace std;

int N;
int a[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
const string MAX_STR = "11111111111111111111111111111111111111111111111111";
string dp[104];

string getMin(string a, string b)
{
    if (a.size() < b.size()) return a;
    else if (a.size() > b.size()) return b;
    else return ((a < b) ? a : b);
}

string goMin(int n)
{
    if (n == 0) return "";

    string& ret = dp[n];
    if (ret != MAX_STR) return ret;

    for (int i = 0; i <= 9; i++) {
        if (n - a[i] < 0) continue;
        if (n == N && i == 0) continue;
        ret = getMin(ret, to_string(i) + goMin(n - a[i]));
    }
    return ret;
}

string goMax()
{
    string s = "";
    if (N % 2 == 0) {
        for (int i = 0; i < N / 2; i++) {
            s += "1";
        }
    }
    else {
        s += "7";
        for (int i = 0; i < (N - 3) / 2; i++) {
            s += "1";
        }
    }
    return s;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;
    while (tcCnt--) {
        fill(&dp[0], &dp[0] + 104, MAX_STR);
        cin >> N;
        cout << goMin(N) << ' ' << goMax() << '\n';
    }
    return 0;
}