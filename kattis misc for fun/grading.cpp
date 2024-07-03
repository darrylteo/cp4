#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d, e, res;
    cin >> a >> b >> c >> d >> e >> res;
    if (res >= a) cout << 'A';
    else if (res >= b) cout << 'B';
    else if (res >= c) cout << 'C';
    else if (res >= d) cout << 'D';
    else if (res >= e) cout << 'E';
    else cout << 'F';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
