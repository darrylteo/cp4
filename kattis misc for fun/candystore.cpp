#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    map<string, vector<string>> mp;
    int n, m;
    cin >> n >> m;
    while (n--) {
        string a, b;
        cin >> a >> b;
        string initials = a.substr(0, 1) + b.substr(0, 1);
        string name = a + " " + b;
        mp[initials].push_back(name);
    }
    while (m--) {
        string i;
        cin >> i;
        if (mp[i].size() == 0) cout << "nobody\n";
        else if (mp[i].size() == 1) cout << mp[i][0] << '\n';
        else cout << "ambiguous\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
