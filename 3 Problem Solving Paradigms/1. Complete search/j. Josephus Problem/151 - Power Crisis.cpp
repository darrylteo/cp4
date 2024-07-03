#include <bits/stdc++.h>

using namespace std;

// josephus problem
int F(int n, int k) {
    if (n == 1) return 0;

    return (F(n-1, k) + k) % n;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        int k = 0;
        while (true) {
            k++;
            // + 2 to 1 index AND because we removed 1st person
            if (F(n-1, k) + 2 == 13) {
                cout << k << '\n';
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

