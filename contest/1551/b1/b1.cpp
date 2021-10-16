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
char s[1005];
int key[500];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 499; i++)
            key[i] = 0;
        cin >> s;
        int len = strlen(s);
        int now = 0;
        for (int i = 0; i < len; i++) {
            key[s[i]]++;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 499; i++) {
            if (key[i] == 1)
                cnt1++;
            else if (key[i] > 1)
                cnt2++;
        }
        cout << cnt1 / 2 + cnt2 << "\n";
    }
}