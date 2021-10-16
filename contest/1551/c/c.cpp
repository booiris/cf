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
int n;
char s[400005];
struct node {
    int a, b, c, d, e, len;
    int v;
} ini[200005];
bool cmp(const node& x, const node& y) { return x.v > y.v; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            ini[i].a = ini[i].b = ini[i].c = ini[i].d = ini[i].e = 0;
            for (int j = 0; s[j] != 0; j++) {
                if (s[j] == 'a')
                    ini[i].a++;
                else if (s[j] == 'b')
                    ini[i].b++;
                else if (s[j] == 'c')
                    ini[i].c++;
                else if (s[j] == 'd')
                    ini[i].d++;
                else if (s[j] == 'e')
                    ini[i].e++;
            }
            ini[i].len = strlen(s);
        }
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < n; j++) {
                int now;
                if (i == 0)
                    now = ini[j].a;
                else if (i == 1)
                    now = ini[j].b;
                else if (i == 2)
                    now = ini[j].c;
                else if (i == 3)
                    now = ini[j].d;
                else if (i == 4)
                    now = ini[j].e;
                ini[j].v = (now * 2) - ini[j].len;
            }
            sort(ini, ini + n, cmp);
            // for (int j = 0; j < n; j++)
            //     cout << ini[j].v << " ";
            // cout << "\n";
            int sum = 0, temp = 0;
            for (int j = 0; j < n; j++) {
                if (ini[j].v > 0) {
                    temp++;
                    sum += ini[j].v;
                } else {
                    sum += ini[j].v;
                    if (sum <= 0)
                        break;
                    temp++;
                }
            }
            ans = max(ans, temp);
        }
        cout << ans << "\n";
    }
}