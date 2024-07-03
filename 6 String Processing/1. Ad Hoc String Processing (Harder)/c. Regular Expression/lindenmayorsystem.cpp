#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string map[100];
    while (n--) {
        char x;
        string y;
        cin >> x >> y >> y;
        map[x] = y;
    }
    string prev;
    cin >> prev;
    while (m--) {
        string tmp;
        for (char c: prev) {
            if (map[c].size() > 0) {
                tmp += map[c];
            } else {
                tmp += c;
            }
        }
        prev = tmp;
    }
    cout << prev << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

