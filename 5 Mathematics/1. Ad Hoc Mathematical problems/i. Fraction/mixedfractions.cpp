#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b, a) {
        cout << a / b << " " << a % b << " / " << b << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

