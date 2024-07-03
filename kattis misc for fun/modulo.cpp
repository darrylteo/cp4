#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    set<int> s;
    for (int i = 0; i < 10; ++i) {
        int n;
        cin >> n;
        s.insert(n % 42);
    }
    cout << s.size() << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
