#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> lengths;
    string s;
    int longest = 0;
    while (getline(cin, s)) {
        lengths.push_back(s.size());
        longest = max(longest, (int) s.size());
    }
    int raggy = 0;
    for (int i = 0; i < lengths.size() - 1; i++) {
        raggy += (longest - lengths[i]) * (longest - lengths[i]);
    }
    cout << raggy << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

