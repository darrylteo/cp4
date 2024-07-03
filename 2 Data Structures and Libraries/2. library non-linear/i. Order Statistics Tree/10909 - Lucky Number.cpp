#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// note should use splay_tree_tag instead of rb_tree_tag. i think this can just test test which faster
#define ordered_set tree<int, null_type,less<int>, splay_tree_tag,tree_order_statistics_node_update>

// generate all lucky numbers up to 2e6
// need 4 lines to use pbds ._.
// hard qn for entry level !
// ref: https://github.com/Hikari9/UVa/blob/master/10909%20-%20Lucky%20Number.cpp

int lucky_numbers[2000001];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // make lucky numbers
    ordered_set lucky;
    // start with odd
    for (int i = 1; i < 2000001; i += 2) {
        lucky.insert(i);
    }
    for (auto it = ++lucky.begin(); it != lucky.end(); ++it) {
        int strike = *it;
        if (strike > lucky.size()) break;
        // 1st -1 is to account for 0 indexing
        // 2nd -1 is to account for removing the number so next 1 is -1 away.
        // e.g. remove every 3rd number we remove no. 3 so no. 6 is now 5th number
        for (int j = strike - 1; j < lucky.size(); j += strike - 1) {
            lucky.erase(lucky.find_by_order(j));
        }
    }
    // put in array easier access
    for (auto it = lucky.begin(); it != lucky.end(); ++it) {
        lucky_numbers[*it] = 1;
    }

    // read input
    int n;
    while (cin >> n) {
        // add 2 odd numbers cannot be odd
        if (n % 2 == 1) {
                cout << n << " is not the sum of two luckies!" << endl;
                continue;
        }
        int L1 = -1, L2 = -1;
        // L2 will always be the larger number
        // start from mid as we want to minimize diff between L1 and L2
        for (int i = n / 2; i >= 1; --i) {
            if (lucky_numbers[i] && lucky_numbers[n - i]) {
                L1 = i;
                L2 = n - i;
                break;
            }
        }
        if (L1 == -1) {
            cout << n << " is not the sum of two luckies!" << endl;
        } else {
            cout << n << " is the sum of " << L1 << " and " << L2 << "." << endl;
        }
    }




    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
