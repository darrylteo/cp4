#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> s1(10001), s2(10001), s3(10001);
    for (int i = 1; i <= 10000; ++i) {
        s1[i] += s1[i - 1];
        s2[i] += s2[i - 1];
        s3[i] += s3[i - 1];
        s1[i] += i;
        s2[i] += 2 * i - 1;
        s3[i] += 2 * i;
    }
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << a << ' ';
        cout << s1[b] << ' ' << s2[b] << ' ' << s3[b] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}