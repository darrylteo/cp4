#include <bits/stdc++.h>

using namespace std;

// huh... feels more like sorting question than iterative

struct player{
    int attack, defence;
    string name;
};

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << "Case " << i << ":\n";
        vector<player> v(10);
        for (int j = 0; j < 10; ++j) {
            cin >> v[j].name >> v[j].attack >> v[j].defence;
        }
        sort(v.begin(), v.end(), [](const player& a, const player& b) {
            if (a.attack != b.attack) return a.attack > b.attack;
            if (a.defence != b.defence) return a.defence < b.defence; // lower defence first cuz less defender on attack squad
            return a.name < b.name;
        });

        vector<string> attack, defence;
        for (int j = 0; j < 5; ++j) {
            attack.push_back(v[j].name);
        }
        for (int j = 5; j < 10; ++j) {
            defence.push_back(v[j].name);
        }
        sort(attack.begin(), attack.end());
        sort(defence.begin(), defence.end());

        cout << "(";
        for (int j = 0; j < 5; ++j) {
            cout << attack[j];
            if (j != 4) cout << ", ";
        }
        cout << ")\n";
        cout << "(";
        for (int j = 0; j < 5; ++j) {
            cout << defence[j];
            if (j != 4) cout << ", ";
        }
        cout << ")\n";

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
