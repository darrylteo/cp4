#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d, cases = 1;
    while (cin >> a >> b >> c >> d) {
        int det = a * d - b * c;
        cout << "Case " << cases++ << ":\n";
        cout << d / det << " " << -b / det << '\n';
        cout << -c / det << " " << a / det << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

