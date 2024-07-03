#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    for (int i = 1; i <= s.size() / 2; ++i) {
        if (s.size() % i == 0) {
            string start = s.substr(0, i);
            string tmp = start;
            sort(start.begin(), start.end());
            bool flag = true;
            for (int j = i; j < s.size(); j += i) {
                string test = s.substr(j, i);
                sort(test.begin(), test.end());
                if (start != test) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << tmp << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
