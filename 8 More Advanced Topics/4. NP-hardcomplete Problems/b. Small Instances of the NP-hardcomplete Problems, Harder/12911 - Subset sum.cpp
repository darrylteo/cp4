#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll > vll;



vll getSubsetSums(vll &arr) {
    vll subsetSums;
    for (int i = 0; i < (1 << arr.size()); i++) {
        ll sum = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        subsetSums.push_back(sum);
    }
    return subsetSums;
}

// weird example: https://cplusplus.com/reference/algorithm/upper_bound/
// see the little carets. can be used in place of .count() for O(logn) instead of O(n)
// meet in the middle by getting ALL subset sums of first and 2nd half. then sort and count
// probably weak test cases in uva. since on udebug dibery test case took more than 3s.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    while (cin >> n >> x) {
        vll arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vll v1(arr.begin(), arr.begin() + n / 2);
        vll v2(arr.begin() + n / 2, arr.end());

        v1 = getSubsetSums(v1);
        v2 = getSubsetSums(v2);

        sort(v2.begin(), v2.end());

        ll count = 0;
        for (ll sum : v1) {
            ll target = x - sum;
            auto l = lower_bound(v2.begin(), v2.end(), target);
            auto r = upper_bound(v2.begin(), v2.end(), target);
            count += r - l;
        }
        if (x == 0) count--; // empty subset for both halves would fulfil equal to 0
        cout << count << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
