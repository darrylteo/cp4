#include <bits/stdc++.h>

using namespace std;

// just draw last test case easy to see

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n >> n;
    if (n % 2 == 0) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}