#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        double area = 0; // area covered by houses
        string s;
        int l;
        vector<pair<string, int>> v;
        // get area covered 1st
        for (int i = 0; i < n; i++) {
            cin >> s >> l;
            v.emplace_back(s, l);
            if (s == "T") {
                area += l * l * sqrt(3) / 4;
            } else {
                area += l * l;
            }
        }
        // find sides of town
        int s1 = v[0].second, s2 = 0;
        int i = 1;
        while (i < n) {
            s1 += v[i].second;
            if (v[i].first == "C") {
                s2 = v[i].second;
                break;
            }
            i++;
        }
        i++;
        while (i < n) {
            if (v[i].first == "C") {
                s2 += v[i].second;
                break;
            } else {
                s2 += v[i].second;
            }
            i++;
        }
        // find area
        cout << fixed << setprecision(4) << s1 * s2 - area << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}