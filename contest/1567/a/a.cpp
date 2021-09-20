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
char ini[105];
char ans[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int d;
    cin >> t;
    while (t--) {
        cin >> n >> ini;
        for (int i = 0; i < n; i++) {
            if (ini[i] == 'U')
                ans[i] = 'D';
            else if (ini[i] == 'D')
                ans[i] = 'U';
            else
                ans[i] = ini[i];
        }
        for (int i = 0; i < n; i++)
            cout << ans[i];
        cout << "\n";
    }
}
