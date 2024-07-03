#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A = 0, B = 0;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i += 2) {
        if (s[i-1] == 'A') {
            A += s[i] - '0';
        } else {
            B += s[i] - '0';
        }
        if (A < 10 && B >= 11) {
            cout << "B";
            return 0;
        } else if (B < 10 && A >= 11) {
            cout << "A";
            return 0;
        } else {
            if (A >= 10 && B >= 10) {
                if (A - B >= 2) {
                    cout << "A";
                    return 0;
                } else if (B - A >= 2) {
                    cout << "B";
                    return 0;
                }
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


