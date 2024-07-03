#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    vector<string> v;
    int cases = 1;
    while (cin >> s) {
        v.push_back(s);
        if (s == "9") {
            bool valid = true;
            for (int i = 0; i < v.size(); i++) {
                for (int j = 0; j < v.size(); j++) {
                    if (i == j) continue;
                    if (v[j].find(v[i]) == 0) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }
            if (valid) cout << "Set " << cases++ << " is immediately decodable\n";
            else cout << "Set " << cases++ << " is not immediately decodable\n";
            v.clear();
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

