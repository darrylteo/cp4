#include <bits/stdc++.h>

using namespace std;

// just check from left and right until match

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    int cntL = 0, cntR = 0; // number of letters that did not change (probably)
    for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
        if (s1[i] == s2[i]) {
            cntL++;
        } else {
            break;
        }
    }
    for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
        if (s1[s1.size() - 1 - i] == s2[s2.size() - 1 - i]) {
            cntR++;
        } else {
            break;
        }
    }
    cout << max(max(0, (int) s2.size() - cntL - cntR), (int) s2.size() - (int) s1.size()) << endl;
    // cast int since unsigned long long is dangerous (if negative it becomes a huge number)
    // must max with 0 for example if string both same, s2.size() - cntL - cntR will likely be negative since cntL=cntR=min(s1.size(), s2.size())
    // must max with s2.size() - s1.size() since using test case
    // GTTTGACCACATT
    // GTTTGACCACCATT
    // i just inserted a C but it cause left and right to match more than expected. this also happens if u add a repeat letter at start or end
    // alternative to prevent double count is pop front and back maybe deque

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
