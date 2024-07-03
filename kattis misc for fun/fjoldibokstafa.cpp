#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    int cnt = 0;
    for (char i : s) {
        if (isalpha(i)) cnt++;
    }
    cout << cnt << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}