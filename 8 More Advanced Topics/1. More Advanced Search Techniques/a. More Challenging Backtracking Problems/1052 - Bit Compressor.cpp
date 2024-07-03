#include <bits/stdc++.h>

using namespace std;

int L, N;
string s;
int cnt;

// pos of s, length of original string, number of ones in original string
inline void dfs(int i, int len, int ones) {
    if (i == s.length() && len == L && ones == N) { // found a possible ans
        cnt++;
        return;
    }
    if (i >= s.length() || len > L || ones > N) return; // invalid
    if (s[i] == '0') dfs(i + 1, len + 1, ones); // add a zero
    else { // starting from this 1xxxxx, get all possible binary values of lengths of 1s in original string
        int k = 0; // binary val check
        for (int j = i; j < s.length(); ++j) {
            k <<= 1;
            k += s[j] - '0';
            if (k + len > L || k + ones > N) break; // invalid. stop checking as it will only get bigger
            // add the number of 1s equal to binary value.
            // do not "decompress" if string starts with 10. this is impossible since 11 would not be compressed to 10 since same size
            // also we don't count until reach a 0 as a series of ones would have been compressed
            if (s[j + 1] != '1' && k != 2) dfs(j + 1, len + k, ones + k);
        }
        // the above misses a case where string starts with 11 (since we block 10 start). 11 is fine
        if (s[i + 1] == '1' && s[i + 2] != '1') dfs(i + 2, len + 2, ones + 2);
    }
}

// ref: https://blog.csdn.net/qq_43985303/article/details/105149948
// the corner cases hard to notice...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    while (cin >> L >> N, L) {
        cnt = 0;
        cin >> s;
        dfs(0, 0, 0);
        if (cnt == 0) cout << "Case #" << cases++ << ": NO\n";
        else if (cnt == 1) cout << "Case #" << cases++ << ": YES\n";
        else cout << "Case #" << cases++ << ": NOT UNIQUE\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}