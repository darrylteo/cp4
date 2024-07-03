#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<pair<string, string>> v; // sorted, unsorted
    string s;
    while (cin >> s) {
        if (s == "#") break;
        string tmp = s;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        sort(tmp.begin(), tmp.end());
        v.emplace_back(tmp, s);
    }
    sort(v.begin(), v.end());
    vector<string> ans;
    // for the middle elements
    for (int i = 1; i < v.size() - 1; i++) {
        if (v[i].first != v[i - 1].first && v[i].first != v[i + 1].first) {
            ans.push_back(v[i].second);
        }
    }
    // for the first element
    if (v[0].first != v[1].first) {
        ans.push_back(v[0].second);
    }
    // for the last element
    if (v[v.size() - 1].first != v[v.size() - 2].first) {
        ans.push_back(v[v.size() - 1].second);
    }
    sort(ans.begin(), ans.end());
    for (const auto &i : ans) {
        cout << i << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
