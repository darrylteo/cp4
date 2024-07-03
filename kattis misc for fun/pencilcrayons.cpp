#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    set<string> s;
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    while (N--) {
        s.clear();
        for (int i = 0; i < K; ++i) {
            string str;
            cin >> str;
            s.insert(str);

        }
        cnt += K - (int) s.size();
    }
    cout << cnt << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}