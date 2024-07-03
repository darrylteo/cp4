#include <bits/stdc++.h>

using namespace std;

// ref:https://reponroy.wordpress.com/2016/05/13/uva-307-sticks/
// goal is length of original sticks. n is total no. of tiny sticks
int goal, n;
vector<int> sticks, used;

bool dfs(int idx, int sum, int cnt) {
    // done
    if (cnt == n) {
        return true;
    }
    // try to add sticks to current stick
    for(int i = idx; i < n; ++i) {
        if (used[i] || sum + sticks[i] > goal) {
            continue;
        }
        if (sum + sticks[i] < goal) {
            used[i] = 1;
            if (dfs(i + 1, sum + sticks[i], cnt + 1)) {
                return true;
            }
            used[i] = 0;
            // if sum is 0, u should have been able to start with any stick
            // but since u couldn't, this current combination is not possible
            // if returning false in a for loop, better to add condition so can try other combinations since break is quite a strong statement
            if (sum == 0) {
                return false;
            }
            // skip so u don't run the loop with same parameters
            while(i + 1 < n && sticks[i] == sticks[i + 1]) {
                ++i;
            }
        }
        if (sum + sticks[i] == goal) {
            used[i] = 1;
            if (dfs(0, 0, cnt + 1)) {
                return true;
            }
            used[i] = 0;
            return false;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n, n) {
        sticks.clear();
        sticks.assign(n, 0);
        used.clear();
        used.assign(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> sticks[i];
        }
        sort(sticks.begin(), sticks.end(), greater<int>());
        int sum = accumulate(sticks.begin(), sticks.end(), 0);
        // check for each length
        for(int i = sticks[0]; i <= sum; ++i) {
            if (sum % i == 0) {
                goal = i;
                if (dfs(0, 0, 0)) {
                    cout << goal << '\n';
                    break;
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

