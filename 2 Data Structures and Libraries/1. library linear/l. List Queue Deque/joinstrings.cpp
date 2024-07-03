#include <bits/stdc++.h>

using namespace std;

// weird run time error .... (ok after add a = 1)
// VERY IMPORTANT TO DO BY REFERENCE!!!!

void printAll (vector<string> &v, vector<vector<int>>& indexes, int curr) {
    cout << v[curr];
    for (int i : indexes[curr]) {
        printAll(v, indexes, i);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> v(n);
    vector<vector<int>> indexes;
    indexes.assign(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int a = 1, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        indexes[a - 1].push_back(b - 1);
    }
    // print curr item, and for each item inside it, print it then check if anymore inside
    printAll(v, indexes, a - 1);


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
