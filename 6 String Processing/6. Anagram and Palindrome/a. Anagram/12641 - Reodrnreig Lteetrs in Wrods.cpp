#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T >> ws;
    while (T--) {
        string buf, s;
        getline(cin, buf);
        stringstream ss(buf);
        vector<string> dict;
        while (ss >> s) {
            dict.push_back(s);
        }
        getline(cin, buf);
        ss = stringstream(buf);
        int start = 1;
        while (ss >> s) {
            if (start) start = 0;
            else cout << " ";
            int found = 0;
            for (string &s1: dict) {
                if (s1.size() == s.size() && s1.front() == s.front() && s1.back() == s.back()) {
                    string tmp = s1, tmp1 = s;
                    sort(tmp.begin(), tmp.end());
                    sort(tmp1.begin(), tmp1.end());
                    if (tmp == tmp1) {
                        cout << s1;
                        found = 1;
                        break;
                    }
                }
            }
            if (!found) cout << s;
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
