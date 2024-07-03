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
    vector<string> v;
    while (n--) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int m;
    cin >> m;
    while (m--) {
        string a, b, c;
        cin >> a;
        if (a == "cut") {
            cin >> b >> c;
            int pos = std::find(v.begin(), v.end(), c) - v.begin();
            v.insert(v.begin() + pos, b);
        } else if (a == "leave") {
            cin >> b;
            int pos = std::find(v.begin(), v.end(), b) - v.begin();
            v.erase(v.begin() + pos);
        }
    }
    for (auto &i: v) {
        cout << i << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
