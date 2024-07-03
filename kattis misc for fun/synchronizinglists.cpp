#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vector<int> v1(n), v2(n), sorted_v1(n);
        for (int i = 0; i < n; i++) cin >> v1[i];
        for (int i = 0; i < n; i++) cin >> v2[i];
        sorted_v1 = v1;
        sort(sorted_v1.begin(), sorted_v1.end());
        sort(v2.begin(), v2.end());
        for (int i = 0; i < n; i++) { // pos in original list
            int idx = -1;
            for (int j = 0; j < n; j++) { // find pos in sorted list (this matches the sorted v2 list)
                if (v1[i] == sorted_v1[j]) {
                    idx = j;
                    break;
                }
            }
            cout << v2[idx] << '\n';
        }
        cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
