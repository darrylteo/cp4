#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<string, int> mp;
    string s;
    while (n--) {
        cin >> s;
        cout << mp[s] << endl;
        // add all prefixes of s
        for (int i = 1; i <= s.size(); i++) mp[s.substr(0, i)]++;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
