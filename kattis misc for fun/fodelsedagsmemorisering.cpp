#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    map<string, pair<int, string>> m; // date, (priority, name)
    int n;
    cin >> n;
    while (n--) {
        string name, date;
        int priority;
        cin >> name >> priority >> date;
        if (m.find(date) == m.end()) {
            m[date] = {priority, name};
        } else {
            if (m[date].first < priority) {
                m[date] = {priority, name};
            }
        }
    }
    vector<string> ans;
    for (auto &i : m) {
        ans.push_back(i.second.second);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}