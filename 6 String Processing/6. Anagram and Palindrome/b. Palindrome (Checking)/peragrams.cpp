#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2) {
            odd++;
        }
    }
    cout << max(0, odd - 1) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
