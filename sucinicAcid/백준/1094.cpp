#include <iostream>
using namespace std;

int X;

int main(void)
{
    cin >> X;
    int ret = 0;
    while (X) {
        ret += X & 1;
        X >>= 1;
    }
    cout << ret;
    return 0;
}