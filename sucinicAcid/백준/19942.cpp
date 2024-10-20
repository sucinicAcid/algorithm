/*

비트필드의 사전순 cmp() 만드는게 오래거림

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct A {
    int p;
    int f;
    int s;
    int v;
    int cost;
};

A a[19];
int N;
int mp, mf, ms, mv;
int p, f, s, v, cost;
int ret = 1e9;
vector<int> vect;

bool cmp(int& a, int& b)
{
    for (int i = 0; i < N; i++) {
        if (((a >> i) & 1) == ((b >> i) & 1)) continue;
        if ((a >> i) & 1) {
            if ((b >> i) == 0) return 0;
            else return 1;
        }
        else {
            if ((a >> i) == 0) return 1;
            else return 0;
        }
    }
    return 0;
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++)
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].cost;

    for (int i = 0; i < (1 << N); i++) {

        p = f = s = v = cost = 0;

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                p += a[j].p;
                f += a[j].f;
                s += a[j].s;
                v += a[j].v;
                cost += a[j].cost;
            }
        }

        if (p < mp || f < mf || s < ms || v < mv) continue;

        if (cost < ret) {
            vect.clear();
            vect.push_back(i);
            ret = cost;
        }
        else if (cost == ret) vect.push_back(i);
    }

    if (ret == 1e9) cout << -1;
    else {
        cout << ret << '\n';
        sort(vect.begin(), vect.end(), cmp);

        //cout << "size: " << vect.size() << '\n';
        //for (int j : vect) {
        //    for (int i = 0; i < N; i++)
        //        if (j & (1 << i))
        //            cout << i + 1 << ' ';
        //    cout << endl;
        //}

        for (int i = 0; i < N; i++)
            if (vect[0] & (1 << i))
                cout << i + 1 << ' ';
    }
    return 0;
}