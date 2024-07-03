#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    cin >> m;
    vector<pair<string, vector<int>>> v;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        vector<int> v1;
        if (s == "rectangle") {
            v1.resize(4);
            for (int j = 0; j < 4; j++) cin >> v1[j];
            v.emplace_back(s, v1);
        } else {
            v1.resize(3);
            for (int j = 0; j < 3; j++) cin >> v1[j];
            v.emplace_back(s, v1);
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, cnt = 0;
        cin >> x >> y;
        for (int j = 0; j < m; j++) {
            if (v[j].first == "rectangle") {
                int xx = v[j].second[0], yy = v[j].second[1], xx1 = v[j].second[2], yy1 = v[j].second[3];
                if (x >= xx && x <= xx1 && y >= yy && y <= yy1) {
                    cnt++;
                }
            } else {
                int xx = v[j].second[0], yy = v[j].second[1], r = v[j].second[2];
                if ((x - xx) * (x - xx) + (y - yy) * (y - yy) <= r * r) {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}