#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    while (getline(cin, buf)) {
        int currSpaces = 0, longestSpaces = 0;
        for (char i : buf) {
            if (i == ' ') {
                currSpaces++;
            } else {
                longestSpaces = max(longestSpaces, currSpaces);
                currSpaces = 0;
            }
        }
        cout << ceil(log2(longestSpaces)) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

