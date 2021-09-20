#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int temp()
{
    return 0;
}
int aaa;
ll dp[15][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string n, a, b;
        cin >> n;
        int len = n.length();
        for (int i = 0; i < len; i++) {
            if (i & 1)
                b += n[i];
            else
                a += n[i];
        }
        if (len == 1) {
            cout << stoi(a) - 1 << "\n";
        } else {
            cout << 1LL * (stoi(a) + 1) * (stoi(b) + 1) - 2 << "\n";
        }
    }
}
