#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int drK[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dcK[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0, currSize = 1;
    while (n > 0) {
        n -= currSize * currSize;
        ans++;
        currSize += 2;
    }
    if (n < 0) ans--;
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}