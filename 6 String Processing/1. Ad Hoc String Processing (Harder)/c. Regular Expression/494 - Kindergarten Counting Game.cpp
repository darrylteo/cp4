#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf, s;
    while (getline(cin, buf)) {
        int cnt = 0;
        stringstream ss(buf);
        while (ss >> s) {
            for (int i = 0; i < s.size(); ++i) {
                if (isalpha(s[i]) && (i == 0 || !isalpha(s[i - 1]))) {
                    ++cnt;
                }
            }
        }
        cout << cnt << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

