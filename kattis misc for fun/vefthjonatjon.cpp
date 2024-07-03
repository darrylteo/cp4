#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p[3] = {};
    cin >> n;
    while (n--) {
        char s;
        for (int &i: p) {
            cin >> s;
            if (s == 'J') i++;
        }
    }
    cout << min(p[0], min(p[1], p[2])) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



