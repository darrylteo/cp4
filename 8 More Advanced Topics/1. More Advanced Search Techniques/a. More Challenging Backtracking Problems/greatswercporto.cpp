#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    map<char, int> mp; // letter and idx. just for initialization
    int idx = 0;
    string s;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (char c : s) {
            if (mp.find(c) == mp.end()) mp[c] = idx++; // new letter
            v[i].push_back(mp[c]); // store each letter into idx
        }
    }
    unordered_set<int> firsts;
    for (int i = 0; i < n; ++i) firsts.insert(v[i][0]);
    vector<int> perm(10);
    for (int i = 0; i < 10; ++i) perm[i] = i;
    int ans = 0;
    do {
        // check no first letter is 0
        bool ok = true;
        for (int first : firsts) {
            if (perm[first] == 0) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        // check if first n-1 numbers sum to the last number
        int sum = 0; // sum of first n-1 numbers
        for (int i = 0; i < n - 1; ++i) {
            int num = 0;
            for (int j : v[i]) {
                num = num * 10 + perm[j];
            }
            sum += num;
        }
        int num = 0; // last number
        for (int j : v[n - 1]) {
            num = num * 10 + perm[j];
        }
        if (sum == num) {
            ++ans;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans / factorial(10 - idx) << endl; // divide by the number of unused digits

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}