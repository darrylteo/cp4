#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    int T, C, G;
    cin >> s;
    T = count(s.begin(), s.end(), 'T');
    C = count(s.begin(), s.end(), 'C');
    G = count(s.begin(), s.end(), 'G');
    int ans = T * T + C * C + G * G + min({T, C, G}) * 7;
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
