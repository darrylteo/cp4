#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc, start = 1;
    cin >> tc;
    while (tc--) {
        if (start) start = 0;
        else cout << '\n';
        string T;
        cin >> T;
        for (int i = 1; i <= T.size(); i++) {
            if (i == T.size()) {
                cout << i << '\n';
                break;
            }
            if (T.size() % i == 0) {
                string sub = T.substr(0, i);
                string tmp;
                for (int j = 0; j < T.size() / i; j++) {
                    tmp += sub;
                }
                if (tmp == T) {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


