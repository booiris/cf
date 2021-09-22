#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll key[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    key[0] = 1;
    for (int i = 1; i < 100000; i++) {
        key[i] = key[i - 1] + i * 2 - 1;
    }
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int len = -1;
        int x, y = -1;
        for (int i = 1; i < 100000; i++) {
            if (k < key[i]) {
                y = i - 1;
                len = k - key[i - 1];
                break;
            }
        }
        int maxlen = 2 * y + 1;
        if (len <= maxlen / 2)
            x = len;
        else {
            x = y;
            y = maxlen - len - 1;
        }
        cout << x + 1 << " " << y + 1 << "\n";
    }
}
