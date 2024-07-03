#include <bits/stdc++.h>

using namespace std;

// hard problem. had to read A Postage Stamp Problem and some online solns
// clearest explanation https://www.pinghenotes.com/UVa-165-Stamps/ (google translate)

int h, k, maxval;
map<int, int> stamp;
map<int, int> maxstamp;
map<int, int> ans;
vector<bool> check;

void dfs(int cur, int index, int sum) {
    cout << sum << "\n";
    if (cur == h) {
        check[sum] = true;
        return;
    }
    check[sum] = true;
    // this is the part that is hard to wrap my head around
    // say h = 3, k = 2
    // the first call uses sum = 0, index = 1 which means up to 1 stamp can be used
    // for i = 0 below, it used stamp 1, none, none, marks check[1] = true and internally recurses
    // 1, 1, none -> check[2] = true, 1, 1, 1 -> check[3] = true, 1, 1, 2 -> check[4] = true, 1, 2, none -> check[3] = true
    // 1, 2, 1 -> check[4] = true, 1, 2, 2 -> check[5] = true, 2, none, none -> check[2] = true, 2, 1, none -> check[3] = true
    // 2, 1, 1 -> check[4] = true, 2, 1, 2 -> check[5] = true, 2, 2, none -> check[4] = true, 2, 2, 1 -> check[5] = true, 2, 2, 2 -> check[6] = true
    // for easier viewing:
    /*
    0 000
    1 100
    2 110
    3 111
    4 112
    3 120
    4 121
    5 122
    2 200
    3 210
    4 211
    5 212
    4 220
    5 221
    6 222
     */
    for (int i = 0; i <= index; ++i) dfs(cur + 1, index, sum + stamp[i]);
}

void search(int index) {
    if (index == k) {
        if (maxstamp[index - 1] > maxval) {
            maxval = maxstamp[index - 1];
            ans = stamp;
        }
        return;
    }
    for (int i = stamp[index - 1] + 1; i <= maxstamp[index - 1] + 1; ++i) {
        check.assign(200, false);
        stamp[index] = i; // insert a new stamp
        dfs(0, index, 0); // check all possible sums with new stamp
        int j = 0, num = 0;
        while (check[++j]) ++num; // find the max number of consecutive sums
        maxstamp[index] = num;
        search(index + 1);
    }
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> h >> k, h && k) {
        stamp.clear();
        maxstamp.clear();
        maxval = 0;
        stamp[0] = 1;
        maxstamp[0] = h;

        search(1);
        for (auto &x: ans) cout << setw(3) << x.second;
        cout << " ->" << setw(3) << maxval << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
