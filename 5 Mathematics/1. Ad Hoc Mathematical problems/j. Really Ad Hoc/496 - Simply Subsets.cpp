#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    while (getline(cin, buf)) {
        set<int> A, B;
        stringstream ss(buf);
        int x;
        while (ss >> x) {
            A.insert(x);
        }
        getline(cin, buf);
        stringstream ss2(buf);
        while (ss2 >> x) {
            B.insert(x);
        }
        // equals
        if (A == B) {
            cout << "A equals B\n";
            continue;
        }
        // disjoint
        bool disjoint = true;
        for (int i : A) {
            if (B.count(i)) {
                disjoint = false;
                break;
            }
        }
        if (disjoint) {
            cout << "A and B are disjoint\n";
            continue;
        }
        // A is a proper subset of B
        bool properSubset = true;
        for (int i : A) {
            if (!B.count(i)) {
                properSubset = false;
                break;
            }
        }
        if (properSubset) {
            cout << "A is a proper subset of B\n";
            continue;
        }
        // B is a proper subset of A
        properSubset = true;
        for (int i : B) {
            if (!A.count(i)) {
                properSubset = false;
                break;
            }
        }
        if (properSubset) {
            cout << "B is a proper subset of A\n";
            continue;
        }
        // confused
        cout << "I'm confused!\n";

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

