#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// assume no 2 teams have same solved and penalty
// tree stores {solved, penalty, id} need sort id too if got same all same rank so sort this opposite so we get smallest rank (to be all same)

using namespace std;
using namespace __gnu_pbds;
// greater since we want largest solved is rank 1
#define ordered_set tree<tuple<int, int, int>, null_type, greater<tuple<int, int, int>>, rb_tree_tag, tree_order_statistics_node_update>

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    ordered_set teams;
    pair<int, int> a[n]; // to keep track of solved and penalty so can search tree

    for (int i = 0; i < n; ++i) {
        teams.insert({0, 0, -i});
    }

    for (int i = 0; i < m; ++i) {
        vector<tuple<int, int, int>> v;
        int id, penalty;
        cin >> id >> penalty;
        id--;
        teams.erase({a[id].first, a[id].second, -id - 1});
        a[id].first++;
        a[id].second -= penalty;
        teams.insert({a[id].first, a[id].second, -id - 1});
	// output pos of 1st guy
        cout << teams.order_of_key({a[0].first, a[0].second, 0}) + 1 << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
