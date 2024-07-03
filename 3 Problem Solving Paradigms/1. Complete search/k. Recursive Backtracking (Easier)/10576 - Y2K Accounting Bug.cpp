#include <bits/stdc++.h>

using namespace std;

// practice backtracking
// faster than check all permutations of 12 months since backtrack early pruning

int s, d;
vector<int> earnings;

int findEarnings(int month) {
    if (month >= 5) {
        int sum3 = 0;
        for (int i = month - 5; i < month; ++i) {
            sum3 += earnings[i];
        }
        if (sum3 >= 0) {
            return -1; // any number doesn't matter as long deficit
        }
    }

    if (earnings.size() == 12) {
        return accumulate(earnings.begin(), earnings.end(), 0);
    }

    earnings.push_back(s);
    int sum1 = findEarnings(month + 1);
    earnings.pop_back();

    earnings.push_back(-d);
    int sum2 = findEarnings(month + 1);
    earnings.pop_back();

    return max(sum1, sum2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> s >> d) {
        earnings.clear();
        int ans = findEarnings(0);
        if (ans < 0) {
            cout << "Deficit" << endl;
        } else {
            cout << ans << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

