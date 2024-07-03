#include <bits/stdc++.h>

using namespace std;

// just buy and sell on next day if it is better

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    long long total = 100, numShares = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (prices[i] < prices[i + 1]) {
            // note need convert to long long. cannot make total/prices to int since total may be very big and price small
            numShares = min((long long) 100000, total / prices[i]);
            total -= numShares * prices[i];
            total += numShares * prices[i + 1];
            numShares = 0;
        }
    }
    cout << total << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
