#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        unordered_map<int, int> nums;
        int k, l;
        cin >> k >> l;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            nums[x]++;
        }
        int matches = 0;
        for (int i = 0; i < l; ++i) {
            int x;
            cin >> x;
            if (nums[x] > 0) {
                matches++;
                nums[x]--;
            }
        }
        cout << k + l - 2 * matches << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
