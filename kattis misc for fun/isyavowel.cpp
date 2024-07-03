#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int vowelCnt = 0, yCnt = 0;
    for (char c: s) {
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u') {
            vowelCnt++;
        } else if (c == 'y') {
            yCnt++;
        }
    }
    cout << vowelCnt << " " << vowelCnt + yCnt << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



