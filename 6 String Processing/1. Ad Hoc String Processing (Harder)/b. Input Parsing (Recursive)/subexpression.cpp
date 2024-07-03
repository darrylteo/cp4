#include <bits/stdc++.h>

using namespace std;

struct node{
    // hash is to keep track of the node. more natural to use string but it is 2x slower
    int hash, l, r;
    string s;
    bool operator < (const node &a) const{
        if (hash != a.hash) return hash < a.hash;
        if (l != a.l) return l < a.l;
        return r < a.r;
    }
};

node Node[50005];
bool vis[50005];
map<node, int> mp;
int pos, cnt;
string s;

inline int build() {
    int id = cnt++;
    Node[id] = {0, -1, -1, ""};
    // collect the entire node name
    while(s[pos] >= 'a' && s[pos] <= 'z') {
        Node[id].hash = Node[id].hash * 27 + s[pos] - 'a' + 1; // base 27 (26 letters + 1 for empty)
        Node[id].s += s[pos];
        pos++;
    }
    // if start function ()
    if(s[pos] == '(') {
        pos++;
        Node[id].l = build();
        pos++;
        Node[id].r = build();
        pos++;
    }
    // if repeated subsequence don't count it as new subsequence
    if(mp.count(Node[id])) {
        cnt--;
        return mp[Node[id]];
    }
    return mp[Node[id]] = id; // return the id of the node which will be stored in the left and right subtrees
}

inline void print (int id) {
    if (vis[id]) {
        cout << id + 1;
        return;
    }
    vis[id] = true;
    cout << Node[id].s;
    if (Node[id].l != -1) { // if there is left, there is right since it is binary tree
        cout << "(";
        print(Node[id].l);
        cout << ",";
        print(Node[id].r);
        cout << ")";
    }
}

// also available at uva 12219
// ref: https://www.cnblogs.com/fly-white/p/10092712.html

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        memset(vis, 0, sizeof(vis));
        mp.clear();
        cnt = pos = 0;
        cin >> s;
        build();
        print(0);
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


