#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // messy but we just get different numbers. left col should have 2 of each type, right col also
    vector<int> left, right;
    int a, b, no1L, no2L, no1R, no2R;
    cin >> a >> b;
    left.push_back(a);
    right.push_back(b);
    no1L = a;
    no1R = b;
    cin >> a >> b;
    left.push_back(a);
    right.push_back(b);
    if (a != no1L) no2L = a;
    if (b != no1R) no2R = b;
    cin >> a >> b;
    left.push_back(a);
    right.push_back(b);
    if (a != no1L) no2L = a;
    if (b != no1R) no2R = b;

    int no1CntLeft = 0, no2CntLeft = 0, no1CntRight = 0, no2CntRight = 0;
    for (int i = 0; i < 3; i++) {
        if (left[i] == no1L) no1CntLeft++;
        else no2CntLeft++;
        if (right[i] == no1R) no1CntRight++;
        else no2CntRight++;
    }

    if (no1CntLeft == 1) cout << no1L << ' ';
    if (no2CntLeft == 1) cout << no2L << ' ';
    if (no1CntRight == 1) cout << no1R << ' ';
    if (no2CntRight == 1) cout << no2R << ' ';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



