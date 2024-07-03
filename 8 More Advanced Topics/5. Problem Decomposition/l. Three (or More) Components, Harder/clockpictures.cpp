#include <bits/stdc++.h>

using namespace std;

int least_rotation(vector<int> &s) {
    int n = s.size();
    vector<int> f(2 * n, -1);
    int k = 0;
    for (int j = 1; j < 2 * n; j++) {
        int i = f[j - k - 1];
        while (i != -1 && s[j % n] != s[(k + i + 1) % n]) {
            if (s[j % n] < s[(k + i + 1) % n]) k = j - i - 1;
            i = f[i];
        }
        if (i == -1 && s[j % n] != s[(k + i + 1) % n]) {
            if (s[j % n] < s[(k + i + 1) % n]) k = j;
            f[j - k] = -1;
        } else f[j - k] = i + 1;
    }
    return k;
}

// sort, get differences and see if differences match (lexicographic min rotation. new algorithm)
// slightly modified from https://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation#Booth's_Algorithm

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> diffA(n), diffB(n);
    for (int i = 0; i < n - 1; i++) {
        diffA[i] = a[i + 1] - a[i];
        diffB[i] = b[i + 1] - b[i];
    }
    diffA[n - 1] = a[0] + 360000 - a[n - 1];
    diffB[n - 1] = b[0] + 360000 - b[n - 1];
    int k1 = least_rotation(diffA);
    int k2 = least_rotation(diffB);
    rotate(diffA.begin(), diffA.begin() + k1, diffA.end());
    rotate(diffB.begin(), diffB.begin() + k2, diffB.end());
    if (diffA == diffB) cout << "possible" << endl;
    else cout << "impossible" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
