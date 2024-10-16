/*
처음에 O(N^3) = 1,000,000,000 (10억) 실패
정답은 O(N^2logN) = 10,000,000 (1천만)

bool binary_search(v.begin(), v.end(), want)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int a[1004];
vector<int> sum;

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            sum.push_back(a[i] + a[j]);
    sort(sum.begin(), sum.end());

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            int want = a[i] - a[j];
            if (binary_search(sum.begin(), sum.end(), want)) {
                cout << a[i];
                return 0;
            }
        }
    }
    return 0;
}