#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vull;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vi v(N+1,1);
    v[0] = v[1] = 0;
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (v[i] == 1) {
            for (int j = i; j <= N; j += i) {
                if (v[j] == 1) {
                    v[j] = 0;
                    cnt++;
                }
                if (cnt == K) {
                    cout << j << endl;
                    return 0;
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}