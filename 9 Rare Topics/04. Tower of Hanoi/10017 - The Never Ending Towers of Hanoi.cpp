#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ToH(3);
int n, m;

void print() {
    for (int i = 0; i < 3; i++) {
        cout << char('A' + i) << "=>";
        if (!ToH[i].empty()) cout << "  ";
        for (int j: ToH[i]) cout << ' ' << j;
        cout << '\n';
    }
    cout << '\n';
}

void solve(int count, int source, int destination, int intermediate) {
    if (m == 0) return;
    if (count == 1) {
        int top = ToH[source].back();
        ToH[source].pop_back();
        ToH[destination].push_back(top);
        print();
        m--;
    } else {
        solve(count - 1, source, intermediate, destination);
        solve(1, source, destination, intermediate);
        solve(count - 1, intermediate, destination, source);
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    while (cin >> n >> m, n) {
        cout << "Problem #" << cases++ << "\n\n";
        ToH[0].clear();
        ToH[1].clear();
        ToH[2].clear();
        for (int i = n; i >= 1; i--) ToH[0].push_back(i);
        print();
        solve(n, 0, 2, 1);
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}