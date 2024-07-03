#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int bCount = 0, kCount = 0;
    for (char c : s) {
        if (c == 'b') bCount++;
        else if (c == 'k') kCount++;
    }

    if (bCount == 0 && kCount == 0) cout << "none" << endl;
    else if (bCount > kCount) cout << "boba" << endl;
    else if (kCount > bCount) cout << "kiki" << endl;
    else cout << "boki" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
