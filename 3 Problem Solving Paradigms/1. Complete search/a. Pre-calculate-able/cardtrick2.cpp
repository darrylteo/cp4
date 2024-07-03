#include <bits/stdc++.h>

using namespace std;

// straightforward after doing 1 example. do reverse of front to back
// 4 	    || 1 2 3 untouched, printing 4 (4 shifts)
// 4 3 	    || 1 2 untouched, printing 3 (3 shifts), starting from 3 4, send 3 elements from back to front
// 4 3 2	|| 1 untouched, printing 2 (2 shifts). i.e. starting from 2 4 3, send 2 elements from back to front
// 2 1 4 3  || print 1 (1 shift). i.e. starting from 1 4 3 2, send 1 element from back to front


int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> v(14);
    for (int i = 1; i <= 13; ++i) {
        queue<int> q;
        for (int j = i; j >= 1; --j) {
            q.push(j); // add to front of queue
            // get from back of queue and put to front of queue j times
            for (int k = 0; k < j; ++k) {
                q.push(q.front());
                q.pop();
            }
        }
        for (int j = 0; j < i; ++j) {
            v[i].push_back(q.front());
            q.pop();
        }
        reverse(v[i].begin(), v[i].end());
    }


    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 0; i < x; ++i) {
            if (i < x - 1) cout << v[x][i] << " ";
            else cout << v[x][i];
        }
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
