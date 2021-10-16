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
        int n;
        cin >> n;
        int key = n / 3;
        int key1 = n % 3;
        if (key1 == 0) {
            cout << key << " " << key << "\n";
        } else if (key1 == 1) {
            cout << key + 1 << " " << key << "\n";
        } else if (key1 == 2) {
            cout << key << " " << key + 1 << "\n";
        }
    }
}