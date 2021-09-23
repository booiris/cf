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
string n;
vector<string> key;
int solve(string& x, string y)
{
    int ans = 0;
    int x_i = 0, y_i = 0;
    while (x_i < (int)x.length() && y_i < (int)y.length()) {
        if (x[x_i] == y[y_i]) {
            x_i++;
            y_i++;
            ans++;
        } else
            x_i++;
    }
    return x.length() - ans + y.length() - ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll now = 1;
    while (now < 2e18) {
        key.push_back(to_string(now));
        now <<= 1;
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int res = INF;
        for (int i = 0; i < (int)key.size(); i++) {
            res = min(res, solve(n, key[i]));
        }
        cout << res << "\n";
    }
}
