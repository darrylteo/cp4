#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum / n << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

