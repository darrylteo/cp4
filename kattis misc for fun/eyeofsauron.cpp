#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int left = 0, right = 0, flag = 0;
    for (char i : s) {
        if (!flag && i == '|') left++;
        else if (flag && i == '|') right++;
        else flag = 1;
    }

    if (left == right) cout << "correct";
    else cout << "fix";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
