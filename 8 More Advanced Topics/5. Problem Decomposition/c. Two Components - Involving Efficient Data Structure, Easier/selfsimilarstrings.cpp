#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> s) {
        int i;
        for (i = 1; i < s.size(); i++) {
            unordered_map<string, int> mp;
            for (int j = 0; j < s.size() - i + 1; j++) {
                string sub = s.substr(j, i);
                mp[sub]++;
            }
            int ok  = 1;
            for (const auto& it : mp) {
                if (it.second < 2) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }
        cout << i - 1 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
