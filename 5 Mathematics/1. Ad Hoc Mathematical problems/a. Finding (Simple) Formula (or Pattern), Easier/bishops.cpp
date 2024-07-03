#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        cout << (n - 1) * 2 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


