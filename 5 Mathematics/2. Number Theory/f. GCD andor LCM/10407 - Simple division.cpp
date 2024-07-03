#include <bits/stdc++.h>

using namespace std;

// s[0] = a * b + r
// s[1] = a * c + r
// s[2] = a * d + r

// s[1] - s[0] = a * (c - b)
// s[2] - s[0] = a * (d - b)

// find gcd for all values after subtracting the first (or smallest wtv)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    while (getline(cin, buf), buf != "0") {
        vector<int> s;
        stringstream ss(buf);
        int x;
        while (ss >> x) {
            if (x == 0) break;
            s.push_back(x);
        }
        sort(s.begin(), s.end());
        for (int i = 1; i < s.size(); i++) {
            s[i] -= s[0];
        }
        // find gcd for 1 to n
        int g = s[1];
        for (int i = 2; i < s.size(); i++) {
            g = __gcd(g, s[i]);
        }
        cout << g << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}