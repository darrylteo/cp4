#include <bits/stdc++.h>

using namespace std;

//vector<int> v(6);
//int total; // see if can get this exact value
//
//inline bool canGet(int i, int sum) {
//    if (sum == 0) return true; // found the sum
//    if (i == 6) return false; // no more type of marbles
//    if (i + 1 > sum) return false; // can't get to sum
//    if (v[i] == 0) return canGet(i + 1, sum); // no marbles of this value, try next
//    // else try put 1 of this marble and don't put 1 of this marble
//    v[i]--;
//    if (canGet(i, sum - (i + 1))) {
//        v[i]++;
//        return true;
//    } else {
//        v[i]++;
//        return canGet(i + 1, sum);
//    }
//}


// did top down but TLE. seems uva doesn't like top down although topdown was faster on all udebug test cases ...
// bottom up then... ref: https://blog.csdn.net/mobius_strip/article/details/44033851

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1, total;
    vector<int> v(6);
    vector<int> sums(60000), ok(60000);
    while (cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5]) {
        total = 0;
        for (int i = 0; i < 6; ++i) {
            total += v[i] * (i + 1);
        }
        if (total == 0) {
            break;
        }
        cout << "Collection #" << cases++ << ":\n";
        if (total % 2) {
            cout << "Can't be divided.\n\n";
            continue;
        }
        total /= 2;

        // base 2 representation
        int cnt = 0;
        for (int i = 0; i < 6; ++i) {
            int k = 1, vv = v[i]; // store the sums we can achieve in the sums vector
            while (k < vv) {
                sums[cnt++] = (i + 1) * k;
                vv -= k;
                k <<= 1;
            }
            if (vv) sums[cnt++] = (i + 1) * vv;
        }
        ok.assign(total + 1, 0);
        ok[0] = 1; // base case
        for (int i = 0; i < cnt; ++i) {
            for (int j = total; j >= sums[i]; --j) {
                if (ok[j - sums[i]]) {
                    ok[j] = 1;
                }
            }
        }
        if (ok[total]) {
            cout << "Can be divided.\n\n";
        } else {
            cout << "Can't be divided.\n\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}