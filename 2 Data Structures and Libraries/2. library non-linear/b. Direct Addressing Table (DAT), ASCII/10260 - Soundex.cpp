#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // abit dangerous to access s[-1] but the chance of it equal to any of our letters is miniscule

    string s;
    while (cin >> s) {
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] == 'B' || s[i] == 'F' || s[i] == 'P' || s[i] == 'V') && (i == 0 || s[i - 1] != 'B' && s[i - 1] != 'F' && s[i - 1] != 'P' && s[i - 1] != 'V')) ans.push_back('1');
            else if ((s[i] == 'C' || s[i] == 'G' || s[i] == 'J' || s[i] == 'K' || s[i] == 'Q' || s[i] == 'S' || s[i] == 'X' || s[i] == 'Z') && (i == 0 || s[i - 1] != 'C' && s[i - 1] != 'G' && s[i - 1] != 'J' && s[i - 1] != 'K' && s[i - 1] != 'Q' && s[i - 1] != 'S' && s[i - 1] != 'X' && s[i - 1] != 'Z')) ans.push_back('2');
            else if ((s[i] == 'D' || s[i] == 'T') && (i == 0 || s[i - 1] != 'D' && s[i - 1] != 'T')) ans.push_back('3');
            else if (s[i] == 'L' && (i == 0 || s[i - 1] != 'L')) ans.push_back('4');
            else if ((s[i] == 'M' || s[i] == 'N') && (i == 0 || s[i - 1] != 'M' && s[i - 1] != 'N')) ans.push_back('5');
            else if (s[i] == 'R' && (i == 0 || s[i - 1] != 'R')) ans.push_back('6');
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
