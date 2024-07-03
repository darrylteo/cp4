#include <bits/stdc++.h>

using namespace std;

// note: getline seems not to work here

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string buf;
    while (cin >> n) {
        unordered_map<string, int> mp;
        string s;
        cin >> s;
        if (n > s.size()) {
            cout << endl;
            continue;
        }
        for (int i = 0; i < s.size() - n + 1; i++) {
            string t = s.substr(i, n);
            mp[t]++;
        }
        int mx = 0;
        string ans;
        for (auto &i : mp) {
            if (i.second > mx) {
                mx = i.second;
                ans = i.first;
            }
        }
        cout << ans << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
