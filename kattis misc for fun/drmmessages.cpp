#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s, s1, s2;
    cin >> s;
    s1 = s.substr(0, s.size() / 2);
    s2 = s.substr(s.size() / 2, s.size() / 2);
    vector<int> v1, v2;
    for (char c: s1) {
        v1.push_back(c - 'A');
    }
    for (char c: s2) {
        v2.push_back(c - 'A');
    }
    int rotation1 = 0, rotation2 = 0;
    for (int i = 0; i < v1.size(); i++) {
        rotation1 += v1[i];
        rotation2 += v2[i];
    }
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = (v1[i] + rotation1) % 26;
        v2[i] = (v2[i] + rotation2) % 26;
    }
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = (v1[i] + v2[i]) % 26;
    }
    for (int i = 0; i < v1.size(); i++) {
        cout << (char) (v1[i] + 'A');
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}