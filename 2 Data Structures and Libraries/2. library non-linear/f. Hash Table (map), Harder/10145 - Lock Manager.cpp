#include <bits/stdc++.h>

using namespace std;

// keep track of blocked transaction numbers (ignore all the way later), unordered_set
// keep track for each item, set of transactions with S locks, set of transactions with X locks
// can insert into item if ((sEmpty && xEmpty) || (only 1 transaction no. && == curr transaction no.) || (xEmpty && insert S)) && !blocked

struct status {
    bool containsX, containsS;
    int trId; // use only 1 S or X lock
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        unordered_set<int> blocked;
        unordered_map<int, status> items;
        char mode;
        while (cin >> mode, mode != '#') {
            int trId, itemId;
            cin >> trId >> itemId;
            if (blocked.find(trId) != blocked.end()) {
                cout << "IGNORED" << endl;
                continue;
            } else if (mode == 'S') {
                // no transactions on this item before
                if (items.find(itemId) == items.end()) {
                    items[itemId] = {false, true, trId};
                    cout << "GRANTED" << endl;
                } // else if have X, if same trId ok, else ban this trId
                else if (items[itemId].containsX) {
                    if (items[itemId].trId == trId) {
                        cout << "GRANTED" << endl;
                        items[itemId].containsS = true;
                    } else {
                        blocked.insert(trId);
                        cout << "DENIED" << endl;
                    }
                } else if (items[itemId].containsS) {
                    cout << "GRANTED" << endl;
                    if (items[itemId].trId != trId) items[itemId].trId = -1; // so if got multiple S trId on this itemId, will block X locks since can't match
                }
                else {
                    items[itemId].containsS = true;
                    items[itemId].trId = trId;
                    cout << "GRANTED" << endl;
                }
            } else if (mode == 'X') {
                // no transactions on this item before
                if (items.find(itemId) == items.end()) {
                    items[itemId] = {true, false, trId};
                    cout << "GRANTED" << endl;
                } // else if have S, if same trId ok, else ban this trId
                else if (items[itemId].containsS || items[itemId].containsX) {
                    if (items[itemId].trId == trId) {
                        cout << "GRANTED" << endl;
                        items[itemId].containsX = true;
                    } else {
                        blocked.insert(trId);
                        cout << "DENIED" << endl;
                    }
                } else {
                    items[itemId].containsX = true;
                    items[itemId].trId = trId;
                    cout << "GRANTED" << endl;
                }
            }
        }
        if (n) cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
