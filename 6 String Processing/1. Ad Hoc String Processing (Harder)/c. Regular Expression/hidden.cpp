#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    int idx = 0;
    vector<char> v;
    for (char c: s1) v.push_back(c);
    reverse(v.begin(), v.end());
    v.pop_back();
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == s1[idx]) {
            idx++;
            v.pop_back();
        } else if (find(v.begin(), v.end(), s2[i]) != v.end()) {
            cout << "FAIL\n";
            return 0;
        }
    }
    if (idx == s1.size()) cout << "PASS\n";
    else cout << "FAIL\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

