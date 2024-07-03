#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, vol = 7;
    cin >> n;
    while (n--) {
        string s;
        cin >> s >> s;
        if (s[0] == 'o') vol = min(vol+1, 10);
        else vol = max(vol-1, 0);
    }
    cout << vol << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


