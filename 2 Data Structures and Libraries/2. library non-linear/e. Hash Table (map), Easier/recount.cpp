#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    unordered_map<string, int> mp;
    while (getline(cin, buf)) {
        mp[buf]++;
    }
    mp.erase("***");
    int mx=0;
    for (auto &i : mp) {
        mx = max(mx, i.second);
    }
    string ans;
    for (auto &i : mp) {
        if (i.second == mx) {
            if (ans.empty()) ans = i.first;
            else {
                cout << "Runoff!" << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
