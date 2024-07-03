#include <bits/stdc++.h>

using namespace std;

// anything above 100,000 usually cannot O(n^2)
// if add smallest, go to left of current smallest
// if add largest, go to right of current largest
// if add in between, abit harder...
// use set to check what it is in between. if insert y, x<y<z, it goes to the longest branch.
// since if x is above z, y goes to left of z
// if z is above x, y goes to right of x

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> st;
    int heights[300005];
    long long totalDepth = 0;
    // insert 1st element
    int x;
    cin >> x;
    st.insert(x);
    heights[x] = 0;
    cout << totalDepth << endl;
    for (int _ = 0; _ < n - 1; ++_) {
        cin >> x;
        st.insert(x);
        auto it = st.lower_bound(x);
        if (it == --st.end()) {
            --it; // (previously largest)
            totalDepth += heights[*it] + 1;
            heights[x] = heights[*it] + 1;
        } else if (it == st.begin()) {
            ++it; // (previously smallest)
            totalDepth += heights[*it] + 1;
            heights[x] = heights[*it] + 1;
        } else {
            --it;
            int left = heights[*it];
            ++it; ++it;
            int right = heights[*it];
            heights[x] = max(left, right) + 1;
            totalDepth += heights[x];
        }
        cout << totalDepth << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
