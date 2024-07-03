#include <bits/stdc++.h>

using namespace std;

// important note: if dont use ios::sync_with_stdio(false); + cin.tie(nullptr);
// then need use scanf printf... else very slow
// so the combo for cin cout need to use ios::sync_with_stdio(false); + cin.tie(nullptr);

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    string s;
    cin >> n;
    deque<int> dqSmall, dqLarge;
    // dqSmall stores the smaller half of the array
    // dqLarge stores the larger half of the array
    // dqSmall.size() == dqLarge.size() or dqSmall.size() == dqLarge.size() + 1
    // push_middle adds the element to the smaller half
    while (n--) {
        cin >> s;
        if (s == "push_back") {
            cin >> x;
            dqLarge.push_back(x);
            if (dqSmall.size() < dqLarge.size()) {
                dqSmall.push_back(dqLarge.front());
                dqLarge.pop_front();
            }
        } else if (s == "push_front") {
            cin >> x;
            dqSmall.push_front(x);
            if (dqSmall.size() > dqLarge.size() + 1) {
                dqLarge.push_front(dqSmall.back());
                dqSmall.pop_back();
            }
        } else if (s == "push_middle") {
            cin >> x;
            dqSmall.push_back(x);
            if (dqSmall.size() > dqLarge.size() + 1) {
                dqLarge.push_front(dqSmall.back());
                dqSmall.pop_back();
            }
        } else {
            cin >> x;
            if (x < dqSmall.size()) cout << dqSmall[x] << "\n";
            else cout << dqLarge[x - dqSmall.size()] << "\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
