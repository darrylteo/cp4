#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

bool isSorted(vi & v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) return false;
    }
    return true;
}

void flip(vi & v, int i) { // i is 0 based. when printing remember to +1
    reverse(v.begin(), v.end() - i + 1);
}

int idx(vi & v, int val) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == val) return i;
    }
    return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (getline(cin, s)) {
        cout << s << endl;
        vi v;
        stringstream ss(s);
        int x;
        while (ss >> x) v.push_back(x);
        map<int, int> mp; // val, sorted index
        vi tmp = v;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size(); i++) mp[tmp[i]] = i;
        for (int & i : v) i = mp[i]; // update v
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] == i) continue; // already in correct position
            int id = idx(v, i);
            if (id == 0) { // id is at top, just flip to appropriate position
                flip(v, v.size() - i);
                cout << v.size() - i << " ";
            } else { // flip id to top, then flip id to i
                flip(v, v.size() - id);
                cout << v.size() - id << " ";
                flip(v, v.size() - i);
                cout << v.size() - i << " ";
            }
            if (isSorted(v)) break;
        }
        cout << "0\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
