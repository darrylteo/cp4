#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> s) {
        int total = s.size(), danger = 0, safe = 0, rotateDanger = 0;
        if (s.back() == '1') danger++;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '1') danger++;
            if (s[i] == '0') {
                safe++;
                if (s[i + 1] == '1') rotateDanger++;
            }
        }
        if (s.back() == '0') {
            safe++;
            if (s.front() == '1') rotateDanger++;
        }

        double rotateDie = (double) danger / total;
        double stayDie = (double) rotateDanger / safe;

        if (fabs(stayDie - rotateDie) < 1e-9 || danger == total || danger == 0) cout << "EQUAL\n";
        else if (stayDie > rotateDie) cout << "ROTATE\n";
        else cout << "SHOOT\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


