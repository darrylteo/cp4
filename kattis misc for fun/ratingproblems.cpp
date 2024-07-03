#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << (sum - 3.0 * (n - k)) / n << " " << (sum + 3.0 * (n - k)) / n << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
