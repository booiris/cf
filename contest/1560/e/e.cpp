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
char ini[500005];
set<char> key;
vector<char> del_ans;
int cnt[50];
int ans[50];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        key.clear();
        del_ans.clear();
        for (int i = 0; i < 26; i++)
            cnt[i] = 0, ans[i] = 0;
        cin >> ini;
        int len = strlen(ini);
        for (int i = len - 1; i >= 0; i--) {
            cnt[ini[i] - 'a']++;
            if (key.count(ini[i]) == 0) {
                del_ans.push_back(ini[i]);
                key.insert(ini[i]);
            }
        }
        int max_time = (int)del_ans.size();
        bool flag = 0;
        for (int i = 0; i < (int)del_ans.size(); i++) {
            int temp = max_time - i;
            if (cnt[del_ans[i] - 'a'] % temp != 0) {
                flag = 1;
                break;
            } else
                ans[del_ans[i] - 'a'] = cnt[del_ans[i] - 'a'] / temp;
        }
        string res = "";
        for (int i = 0; i < len; i++) {
            if (ans[ini[i] - 'a'] != 0) {
                res.push_back(ini[i]);
                ans[ini[i] - 'a']--;
            } else
                break;
        }
        for (int i = 0; i < 26; i++) {
            if (ans[i] != 0) {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "-1\n";
        else {
            string temp = res;
            string check = temp;
            for (int i = max_time - 1; i >= 0; i--) {
                temp.erase(remove(temp.begin(), temp.end(), del_ans[i]), temp.end());
                check += temp;
            }
            if (strcmp(ini, check.c_str()) != 0) {
                cout << "-1\n";
            } else {
                cout << res << " ";
                for (int i = del_ans.size() - 1; i >= 0; i--) {
                    cout << del_ans[i];
                }
                cout << "\n";
            }
        }
    }
}
