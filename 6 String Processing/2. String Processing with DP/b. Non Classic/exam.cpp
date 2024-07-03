#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    cin >> k;
    string s1, s2;
    cin >> s1 >> s2;
    int match = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) {
            match++;
        }
    }
    int notMatch = s1.size() - match;
    int correctMatch = min(match, k);
    int correctNotMatch = min(notMatch, (int) s1.size() - k);
    cout << correctMatch + correctNotMatch << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}