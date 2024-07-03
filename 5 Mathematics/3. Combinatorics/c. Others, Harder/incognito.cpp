#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        map<string, set<string>> m;
        int n;
        cin >> n;
        while (n--) {
            string item, type;
            cin >> item >> type;
            m[type].insert(item);
        }
        ull ans = 1;
        for (auto &i : m) {
            ans *= (i.second.size() + 1);
        }
        cout << ans - 1 << '\n';
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


