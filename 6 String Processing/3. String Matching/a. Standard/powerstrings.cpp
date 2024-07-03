#include <bits/stdc++.h>

using namespace std;

// tried kmp but actually it wasn't that tricky :S

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string T;
    while (cin >> T, T != ".") {
        for (int i = 1; i <= T.size(); i++) {
            if (i == T.size()) {
                cout << 1 << '\n';
                break;
            }
            if (T.size() % i) continue;
            string sub = T.substr(0, i);
            bool flag = true;
            for (int j = i; j < T.size(); j += i) {
                if (T.substr(j, i) != sub) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << T.size() / i << '\n';
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


