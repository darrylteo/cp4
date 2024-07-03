#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    map<string, int> m;
    while (n--) {
        string s;
        int x;
        cin >> s >> x;
        m[s] += x;
    }
    int best = 0;
    string bestname;
    for (auto &i : m) {
        if (i.second > best) {
            best = i.second;
            bestname = i.first;
        }
    }
    cout << bestname << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
