#include <bits/stdc++.h>

using namespace std;

// using beiju code keep giving runtime error... redo
// SO MUCH EASIER! same runtime as doubly linked list too sad face

void solve(const string& s) {
    list<char> l;
    auto it = l.begin();
    for (char c: s) {
        if (c == '[') {
            it = l.begin();
        } else if (c == ']') {
            it = l.end();
        } else if (c == '<') {
            if (it != l.begin()) {
                it--;
                it = l.erase(it);
            }
        }
        else {
            l.insert(it, c);
        }
    }
    for (char c: l) {
        cout << c;
    }
    cout << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf;
    getline(cin, buf);
    int n;
    n = stoi(buf);
    for (int i = 0; i < n; i++) {
        getline(cin, buf);
        solve(buf);
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
