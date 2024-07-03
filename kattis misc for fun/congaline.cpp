#include <bits/stdc++.h>

using namespace std;

// ref: https://github.com/donaldong/kattis/blob/main/solutions/congaline/a.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<string> names(2 * N);
    list<int> l;
    vector<list<int>::iterator> it(2 * N); // store to know where his buddy is
    for (int i = 0; i < 2 * N; i++) {
        cin >> names[i];
        it[i] = l.insert(l.end(), i); // insert idx at end and store iterator (address)
    }
    string s;
    cin >> s;

    auto itr = l.begin();
    for (char c: s) {
        if (c == 'F') itr--; // move mic in front
        else if (c == 'B') itr++; // move mic behind
        else if (c == 'R') {
            int idx = *itr;
            itr = l.erase(itr); // mic automatically moves behind
            if (itr == l.end()) itr = l.begin(); // if end, send mic to start
            it[idx] = l.insert(l.end(), idx); // insert guy behind and record his position
        } else if (c == 'C') {
            int idx = *itr, buddy;
            itr = l.erase(itr); // mic automatically moves behind
            if (itr == l.end()) itr = l.begin(); // if end, send mic to start
            if (idx % 2) {
                buddy = idx - 1;
            } else {
                buddy = idx + 1;
            }
            it[idx] = l.insert(next(it[buddy]), idx); // add him behind his buddy
        } else if (c == 'P') {
            int idx = *itr, buddy;
            if (idx % 2) {
                buddy = idx - 1;
            } else {
                buddy = idx + 1;
            }
            cout << names[buddy] << '\n';
        }
    }
    cout << '\n';
    for (auto i: l) {
        cout << names[i] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}