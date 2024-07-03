#include <bits/stdc++.h>

using namespace std;

// 8! = 40320

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
}

bool valid(const vector<int> &perm) {
    if (*min_element(perm.begin(), perm.end()) > 1) return false; // largest month = 12
    int day = perm[6] * 10 + perm[7]; // day last
    int month = perm[4] * 10 + perm[5];
    int year = perm[0] * 1000 + perm[1] * 100 + perm[2] * 10 + perm[3]; // year in front
    if (day > 31 || month > 12 || day == 0 || month == 0) return false;
    if (year < 2000) return false;
    if (month == 2) {
        if (isLeapYear(year)) return day <= 29;
        return day <= 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) return day <= 30;
    return true;
}

void myPrint(const vector<int> &perm) {
    for (int i = 6; i < 8; ++i) cout << perm[i];
    cout << ' ';
    for (int i = 4; i < 6; ++i) cout << perm[i];
    cout << ' ';
    for (int i = 0; i < 4; ++i) cout << perm[i];
    cout << '\n';
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string s;
        vector<int> perm;
        for (int i = 0; i < 3; ++i) {
            cin >> s;
            for (char c : s) perm.push_back(c - '0');
        }
        sort(perm.begin(), perm.end());
        int ans = 0, flag = 0;
        vector<int> bestPerm = perm;
        do {
            if (valid(perm)) {
                if (!flag) bestPerm = perm, // first valid permutation
                flag = 1;
                ans++;
            }
        } while (next_permutation(perm.begin(), perm.end()));
        if (flag) {
            cout << ans << ' ';
            myPrint(bestPerm);
        }
        if (!flag) cout << "0\n";
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
