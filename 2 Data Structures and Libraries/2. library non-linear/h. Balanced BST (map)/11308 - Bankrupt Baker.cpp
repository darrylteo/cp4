#include <bits/stdc++.h>

using namespace std;

struct record{
    string dateTime;
    int hour, enter, distance;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string buf;
    cin >> N;
    while (N--) {
        getline(cin >> ws, buf);
        for (char &i : buf) {
            if (isalpha(i)) cout << (char) toupper(i);
            else cout << i;
        }
        cout << '\n';
        int m, n, b;
        cin >> m >> n >> b;
        unordered_map<string, int> ingredients;
        while (m--) {
            string ingredient;
            int price;
            cin >> ingredient >> price;
            ingredients[ingredient] = price;
        }
        set<pair<int, string>> recipeCosts;
        while (n--) {
            string recipe;
            int k;
            getline(cin >> ws, recipe);
            cin >> k;
            int cost = 0;
            while (k--) {
                string ingredient;
                int quantity;
                cin >> ingredient >> quantity;
                cost += ingredients[ingredient] * quantity;
            }
            recipeCosts.insert({cost, recipe});
        }
        bool flag = false;
        for (auto &i : recipeCosts) {
            if (i.first <= b) {
                flag = true;
                cout << i.second << '\n';
            }
            else break;
        }
        if (!flag) cout << "Too expensive!\n";
        cout << '\n';


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}