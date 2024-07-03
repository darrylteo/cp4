#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll base2ToBase10(const string& s) {
    ll n = 0;
    for (char i : s) {
        n = n * 2 + (i - '0');
    }
    return n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    set<ll> s;
    s.insert(1);
    int curr = 1;
    while (s.size() < 70000) {
        string s1 = bitset<25>(curr).to_string();
        while (s1[0] == '0')  s1.erase(s1.begin());
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        s.insert(base2ToBase10(s1 + s2));
        s.insert(base2ToBase10(s1 + "0" + s2));
        s.insert(base2ToBase10(s1 + "1" + s2));
        curr++;
    }
    vector<ll> v(s.begin(), s.end());
    int M;
    cin >> M;
    cout << v[M - 1] << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
