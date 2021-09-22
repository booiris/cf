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
ll key[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll now = 1;
    for (int i = 1; i <= 1000; i++) {
        while ((now % 10 == 3) || (now % 3 == 0))
            now++;
        key[i] = now++;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << key[n] << "\n";
    }
}
