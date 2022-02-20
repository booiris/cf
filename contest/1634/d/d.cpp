#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        int last = 0;
        cout << "? 1 2 3\n";
        cout.flush();
        cin >> last;
        cout << "? 1 2 4\n";
        cout.flush();
        int res;
        while (1)
        {
            cin >> res;
            if (res < last)
            {
            }
            else if (res > last)
            {
            }
            else
            {
            }
        }
    }
}