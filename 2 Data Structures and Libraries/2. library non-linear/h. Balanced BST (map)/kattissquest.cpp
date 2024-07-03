#include <bits/stdc++.h>

using namespace std;

// unsure why set<pair<int, int>> gave wrong answer

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    map<int, priority_queue<int>> st;
    while (N--) {
        string s;
        cin >> s;
        if (s == "add") {
            int x, y;
            cin >> x >> y;
            st[x].push(y);
        } else {
            int x;
            long long reward = 0;
            cin >> x; // energy
            while (x > 0 && !st.empty()) {
                auto it = st.lower_bound(x);
                if(it == st.end()) it--; // because if all smaller u end up here
                while(it != st.begin() && it->first > x) {
                    it--;
                }
                if (it->first > x) {
                    break;
                }
                x -= it->first;
                reward += it->second.top();
                it->second.pop();
                if (it->second.empty()) {
                    st.erase(it);
                }
            }
            cout << reward << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
