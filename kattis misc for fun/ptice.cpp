#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<string> v(3);
    for (int i = 0; i < 50; i++) v[0] += "ABC";
    for (int i = 0; i < 50; i++) v[1] += "BABC";
    for (int i = 0; i < 50; i++) v[2] += "CCAABB";
    string s;
    cin >> s >> s;
    vector<int> cnt(3);
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (s[i] == v[j][i]) cnt[j]++;
        }
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    cout << mx << endl;
    for (int i = 0; i < 3; i++) {
        if (cnt[i] == mx) {
            if (i == 0) cout << "Adrian\n";
            if (i == 1) cout << "Bruno\n";
            if (i == 2) cout << "Goran\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
