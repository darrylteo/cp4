#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    map<string, int> mp;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        mp[s] = 0;
    }
    cin >> m;
    while (m--) {
        cin >> k;
        while (k--) {
            string s;
            cin >> s;
            mp[s]++;
        }
    }
    vector<pair<int, string>> v;
    for (auto &i: mp) {
        v.push_back({i.second, i.first});
    }
    sort(v.begin(), v.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    });
    for (auto &i: v) {
        cout << i.first << " " << i.second << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
