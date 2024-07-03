#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set cookies;

// use less_equal to account for duplicates but weird need iterator to delete instead of just value
// i also did pair<int, int> and it was more readable, but slightly slower (0.62s instead of 0.59s)

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        if (s != "#") {
            int x = stoi(s);
            cookies.insert(x);
        } else {
            int n = cookies.size();
            if (n % 2 == 0) {
                auto it = cookies.find_by_order(n / 2);
                int median = *it;
                cout << median << endl;
                cookies.erase(it);
            } else {
                auto it = cookies.find_by_order((n - 1) / 2);
                int median = *it;
                cout << median << endl;
                cookies.erase(it);
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
