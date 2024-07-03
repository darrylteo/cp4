#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (isdigit(s2[0])) {
            v[i] = {stoi(s2), s1};
        } else {
            v[i] = {stoi(s1)/2, s2};
        }
    }
    sort(v.begin(), v.end());
    for (auto &i : v) {
        cout << i.second << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}