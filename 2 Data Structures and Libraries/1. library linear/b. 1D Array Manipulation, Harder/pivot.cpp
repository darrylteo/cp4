#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    vector<long long> a(n), maxFromLeft(n), maxFromRight(n), minFromLeft(n), minFromRight(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    maxFromLeft[0] = a[0];
    minFromLeft[0] = a[0];
    maxFromRight[a.size() - 1] = a[a.size() - 1];
    minFromRight[a.size() - 1] = a[a.size() - 1];
    for (int i = 1; i < a.size(); i++) {
        maxFromLeft[i] = max(maxFromLeft[i - 1], a[i]);
        minFromLeft[i] = min(minFromLeft[i - 1], a[i]);
    }
    for (int i = a.size() - 2; i >= 0; i--) {
        maxFromRight[i] = max(maxFromRight[i + 1], a[i]);
        minFromRight[i] = min(minFromRight[i + 1], a[i]);
    }

    int ans = 0;
    for (int i = 1; i < a.size() - 1; i++) {
        if (maxFromLeft[i-1] <= a[i] && a[i] <= minFromRight[i+1] || // bigger than all the left elements, smaller than all the right elements
                minFromLeft[i-1] >= a[i] && a[i] >= maxFromRight[i+1]) { // smaller than all the left elements, bigger than all the right elements
            ans++;
        }
    }

    // corner cases
    if (a[0] <= minFromRight[1] ||a[0] >= maxFromRight[1]) {
        ans++;
    }
    if (a[a.size() - 1] <= minFromLeft[a.size() - 2] || a[a.size() - 1] >= maxFromLeft[a.size() - 2]) {
        ans++;
    }

    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




