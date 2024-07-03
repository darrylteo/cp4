#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int currX = 0, currY = 0;
    for (int i = 0; i < n; i++) {
        int toAdd = pow(2, s.size() - 1); // e.g. in zoom 3, to we add 4 to x, y or none based on curr quadkey
        if (s.back() == '1') {
            currX += toAdd;
        } else if (s.back() == '2') {
            currY += toAdd;
        } else if (s.back() == '3') {
            currX += toAdd;
            currY += toAdd;
        }
        s.pop_back();
    }
    cout << n << " " << currX << " " << currY << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

