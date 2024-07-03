#include <bits/stdc++.h>

using namespace std;

// not easy but given easy rating on kattis (or maybe im new to recursion)
// my logic is to check whether passing left or right is better recursively
// return a gets value from return ans. a is top layer.
// on calling recurse(true, 1), we call int a = min(recurse(false, i + 1), recurse(true, i + 1))
// which checks its left and right tree which checks their left and right tree etc until reach bottom level
// then return best ans to top layer

int ans, N, S, R;
vector<int> v;

// i is the current person
int recurse(bool passLeft, int i) {
    // only returned when reach bottom level
    if (i == N + 1) {
        ans = 0;
        for (int j = 0; j < N + 1; ++j) {
            if (v[j] == -1) {
                ans++;
            }
        }
        return ans;
    }

    if (v[i] != 1) // if i has no extra kayak, skip
        return recurse(passLeft, i + 1);

    if (passLeft) {
        if (v[i - 1] == -1) { // if i-1 has missing kayak, pass to i-1
            v[i - 1]++;
            v[i]--;
            int a = min(recurse(false, i + 1), recurse(true, i + 1)); // recurse both cases (top level)
            v[i - 1]--;
            v[i]++;
            return a;
        } else if (v[i + 1] == -1) { // if i+1 has missing kayak, pass to i+1
            v[i + 1]++;
            v[i]--;
            int a = min(recurse(false, i + 1), recurse(true, i + 1));
            v[i + 1]--;
            v[i]++;
            return a;
        } else { // if no one has missing kayak, keep kayaks
            return recurse(passLeft, i + 1);
        }
    } else {
        if (v[i + 1] == -1) { // if i+1 has missing kayak, pass to i+1
            v[i + 1]++;
            v[i]--;
            int a = min(recurse(false, i + 1), recurse(true, i + 1));
            v[i + 1]--;
            v[i]++;
            return a;
        } else if (v[i - 1] == -1) { // if i-1 has missing kayak, pass to i-1
            v[i - 1]++;
            v[i]--;
            int a = min(recurse(false, i + 1), recurse(true, i + 1));
            v[i - 1]--;
            v[i]++;
            return a;
        } else { // if no one has missing kayak, keep kayaks
            return recurse(passLeft, i + 1);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S >> R;
    // record down who has extra kayaks, who has missing kayaks. 0s at ends
    v.assign(N + 2, 0);
    for (int i = 0; i < S; ++i) {
        int x;
        cin >> x;
        v[x]--;
    }
    for (int i = 0; i < R; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }
    cout << min(recurse(true, 1), recurse(false, 1)) << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

