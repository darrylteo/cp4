#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vvi v;
    vi temp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        temp.push_back(x);
    }
    v.push_back(temp);
    int depth = 1;
    while (true) {
        vi tmp;
        for (int i = 0; i < n - depth; i++) {
            tmp.push_back(v[depth - 1][i + 1] - v[depth - 1][i]);
        }
        v.push_back(tmp);
        depth++;

        // check if all same
        bool same = true;
        for (int i = 0; i < tmp.size() - 1; i++) {
            if (tmp[i] != tmp[i + 1]) {
                same = false;
                break;
            }
        }
        if (same) break;
    }
    // sum the last digit of each row
    ll sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i].back();
    }
    cout << depth - 1 << " " << sum << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

