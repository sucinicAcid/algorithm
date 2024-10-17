/*
mp[0] = 1 찾느라 오래걸림
결과값은 최대가 20만H2 이므로 long long
*/
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
int N;
int K;
int psum[200004];
unordered_map<int, int> mp;
ll ret;

int main(void)
{
    cin >> N >> K;
    mp[0] = 1;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        psum[i] = psum[i - 1] + a;

        ret += mp[psum[i] - K];
        mp[psum[i]]++;
    }

    cout << ret;
    return 0;
}