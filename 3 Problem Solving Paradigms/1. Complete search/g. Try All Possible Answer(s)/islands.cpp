#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // start by getting possible contiguous subsets of 10 islands
    // we save as ints, although we use as bitsets
    // if encounter 1 when started == 0, make started = 1
    // if encounter 0 when started == 1, make ended = 1
    // if encounter 1 when ended == 1, make flag = false
    vector<int> subsets;
    for (int i = 1; i < 1 << 10; ++i) {
        bool flag = true;
        int started = 0, ended = 0;
        for (int j = 0; j < 10; ++j) {
            if (i & (1 << j)) {
                if (started == 0) {
                    started = 1;
                } else if (ended == 1) {
                    flag = false;
                    break;
                }
            } else {
                if (started == 1) {
                    ended = 1;
                }
            }
        }
        if (flag) {
            subsets.push_back(i);
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << x << " ";
        vector<int> wholeIsland;
        cin >> x;
        for (int i = 0; i < 10; ++i) {
            cin >> x;
            wholeIsland.push_back(x);
        }
        cin >> x;

        int cnt = 0;
        for (int i: subsets) {
            bitset<10> subset(i);
            bool flag = true;
            // beforeAfter is the larger of the two values directly to the right or left of the subset
            int beforeAfter, leftIdx = 100, rightIdx = 0;
            for (int j = 0; j < 10; ++j) {
                if (subset[j]) {
                    leftIdx = min(j, leftIdx);
                    rightIdx = max(j, rightIdx);
                }
            }
            if (leftIdx == 0 && rightIdx == 9) {
                beforeAfter = 0;
            } else if (rightIdx == 9) {
                beforeAfter = wholeIsland[leftIdx - 1];
            } else if (leftIdx == 0) {
                beforeAfter = wholeIsland[rightIdx + 1];
            } else {
                beforeAfter = max(wholeIsland[leftIdx - 1], wholeIsland[rightIdx + 1]);
            }

            // ensure everything in subset is larger than beforeAfter
            for (int j = 0; j < 10; ++j) {
                if (subset[j]) {
                    if (wholeIsland[j] <= beforeAfter) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}