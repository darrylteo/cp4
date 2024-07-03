#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<string, null_type,less<string>, rb_tree_tag,tree_order_statistics_node_update>

// just looking at problem. most likely using order_of_key.
// 6 star qn but direct application of ordered_set

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ordered_set male, female;
    while (cin >> n, n) {
        if (n == 1) {
            int gender;
            string name;
            cin >> name >> gender;
            if (gender == 1) {
                male.insert(name);
            } else {
                female.insert(name);
            }
        } else if (n == 2) {
            string name;
            cin >> name;
            male.erase(name);
            female.erase(name);
        } else {
            int gender, maleCnt, femaleCnt;
            string start, end;
            cin >> start >> end >> gender;
            maleCnt = male.order_of_key(end) - male.order_of_key(start);
            femaleCnt = female.order_of_key(end) - female.order_of_key(start);
            if (gender == 0) {
                cout << maleCnt + femaleCnt << '\n';
            } else if (gender == 1) {
                cout << maleCnt << '\n';
            } else {
                cout << femaleCnt << '\n';
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
