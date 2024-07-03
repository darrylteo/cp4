#include <bits/stdc++.h>

using namespace std;

// O(nlogn) for inserting into set
// O(n) if check all same elements

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    // find largest unique element
    int largestUnique = -1;
    auto it = --s.end();
    for (int i = 0; i < s.size(); ++i) {
        if (count(a.begin(), a.end(), *it) == 1) {
            largestUnique = *it;
            break;
        }
        it--;
    }
    // find position of this element if exists
    if (largestUnique == -1) {
        cout << "none" << endl;
    } else {
        cout << find(a.begin(), a.end(), largestUnique) - a.begin() + 1 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
