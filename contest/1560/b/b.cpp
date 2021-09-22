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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int key = abs(a - b) * 2;
        if (c > key || a > key || b > key)
            cout << "-1\n";
        else {
            int ans = (a + key / 2);
            if (ans > key)
                ans -= key;
            if (ans != b)
                cout << "-1\n";
            else {
                ans = c + key / 2;
                if (ans > key)
                    ans -= key;
                cout << ans << "\n";
            }
        }
    }
}
