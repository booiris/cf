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
int k, len;
char ini[10005];
int key1, key2;
string ans;
int res;
bool dfs(int depth, bool up)
{
    if (depth >= len) {
        res = min(res, stoi(ans));
        return 1;
    }
    if (k == 1) {
        if (key1 >= ini[depth] - '0' || up) {
            ans += key1 + '0';
            bool temp = up;
            if (key1 != ini[depth] - '0')
                temp = 1;
            bool flag = dfs(depth + 1, temp);
            ans.pop_back();
            return flag;
        }
    } else {
        int c = min(key1, key2);
        if (c >= ini[depth] - '0' || up) {
            ans += c + '0';
            bool temp = up;
            if (c != ini[depth] - '0')
                temp = 1;
            bool flag = dfs(depth + 1, temp);
            ans.pop_back();
            if (flag)
                return 1;
        }
        c = max(key1, key2);
        if (c >= ini[depth] - '0' || up) {
            ans += c + '0';
            bool temp = up;
            if (c != ini[depth] - '0')
                temp = 1;
            bool flag = dfs(depth + 1, temp);
            ans.pop_back();
            return flag;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> ini >> k;
        len = strlen(ini);
        if (len == 10) {
            if (k == 1)
                cout << 1111111111 << "\n";
            else
                cout << 1000000000 << "\n";
            continue;
        }
        res = INF;
        for (int i = ini[0] - '0'; i <= 9; i++) {
            ans.clear();
            ans = i + '0';
            key1 = i;
            bool up = i > (ini[0] - '0') ? 1 : 0;
            if (k == 1) {
                bool up = i > (ini[0] - '0') ? 1 : 0;
                dfs(1, up);
            } else {
                for (int j = 0; j <= 9; j++) {
                    key2 = j;
                    dfs(1, up);
                }
            }
        }
        cout << res << "\n";
    }
}
