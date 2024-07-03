#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<string, vector<int>> mp; // country and what years he visited it
    for (int i = 0; i < n; ++i) {
        string country;
        int year;
        cin >> country >> year;
        mp[country].push_back(year);
    }
    for (auto &i : mp) {
        sort(i.second.begin(), i.second.end());
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string country;
        int k;
        cin >> country >> k;
        cout << mp[country][k - 1] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
