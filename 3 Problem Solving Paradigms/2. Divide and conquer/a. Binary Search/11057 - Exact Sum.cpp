#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int &i: v) cin >> i;
        sort(v.begin(), v.end());
        int target;
        cin >> target;
        int l = 0, r = n - 1;
        vector<int> targetL, targetR;
        while (l < r) {
            int sum = v[l] + v[r];
            if (sum == target) {
                targetL.push_back(v[l]);
                targetR.push_back(v[r]);
                l++;
                r--;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        cout << "Peter should buy books whose prices are " << targetL.back() << " and " << targetR.back() << ".\n\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

