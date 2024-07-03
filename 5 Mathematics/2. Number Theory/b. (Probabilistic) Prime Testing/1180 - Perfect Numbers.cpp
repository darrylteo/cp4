#include <bits/stdc++.h>

using namespace std;

// quick google search show that there are only 6 perfect numbers less than 2^33
// could use sumDiv function in book but ahh well let's shortcut

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T >> ws;
    string buf, s;
    getline(cin, buf);
    istringstream iss(buf);
    while (getline(iss, s, ',')) {
        int n = stoi(s);
        if (n == 2 || n == 3 || n == 5 || n == 7 || n == 13 || n == 17) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}