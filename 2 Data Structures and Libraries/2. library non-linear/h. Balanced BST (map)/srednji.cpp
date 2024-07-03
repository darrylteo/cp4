#include <bits/stdc++.h>

using namespace std;

// ref: https://github.com/mpfeifer1/Kattis/blob/master/srednji.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B;
    cin >> N >> B;
    map<int, int> m;
    vector<int> v;
    int pos, tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        v.push_back(tmp);
        if (tmp == B) pos = i;
    }
    int sum = 0;
    for (int i = pos; i < N; ++i) {
        if (v[i] < B) sum--;
        else if (v[i] > B) sum++;
        // keep track of how many times we encounter a certain sum
        // sum refers to number of elements greater than B - number of elements less than B
        // e.g. if m[1] = 2, 2 situations where we have 1 element on the right that is greater than B
        // when checking on left, if we have 1 element (sum = -1) less than B, we have 2 situations (m[-(-1)] = 2) where we have 1 element greater than B (on the right)
        // so add 2 to ans
        m[sum]++;
    }
    sum = 0;
    int ans = 0;
    for (int i = pos; i >= 0; --i) {
        if (v[i] < B) sum--;
        else if (v[i] > B) sum++;
        ans += m[-sum];
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}