#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    cin >> s;

    // policy 1
    int ans1 = 0;
    if (s[0] == 'D') ans1++; // if first seat down, second guy MUST lift it
    if (s[0] == 'U' && s[1] == 'D') ans1 += 2; // the standard usage
    for (int i = 2; i < s.size(); i++) {
        if (s[i] == 'D') ans1 += 2; // if 'D', he must put down to use, and lift after
    }
    cout << ans1 << endl;

    // policy 2
    int ans2 = 0;
    if (s[0] == 'U') ans2++; // if first seat up, second guy MUST put it down
    if (s[0] == 'D' && s[1] == 'U') ans2 += 2; // the standard usage
    for (int i = 2; i < s.size(); i++) {
        if (s[i] == 'U') ans2 += 2; // if 'U', he must put up to use, and put down after
    }
    cout << ans2 << endl;

    // policy 3
    int ans3 = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i+1]) ans3++; // if different he change it once to suit himself
    }
    cout << ans3 << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
