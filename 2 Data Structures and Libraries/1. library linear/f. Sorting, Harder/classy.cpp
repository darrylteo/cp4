#include <bits/stdc++.h>

using namespace std;

struct person {
    string name;
    vector<string> classes;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<person> people(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            s.pop_back();
            people[i].name = s;
            cin >> s;
            stringstream ss(s);
            while (getline(ss, s, '-')) {
                people[i].classes.push_back(s);
            }
            cin >> s;
        }
        // "base" class highest weight
        for (auto &p: people) {
            reverse(p.classes.begin(), p.classes.end());
        }
        // add leading (or trailing after reverse) middles so easier to compare
        // e.g. "middle" vs "lower-middle" vs "higher-middle"
        // if we don't add middle in front of middle, we can't compare as CORRECT: "lower" < ""
        // but it will return "lower" > ""
        int longest = 0;
        for (auto &p: people) {
            longest = max(longest, (int) p.classes.size());
        }
        for (auto &p: people) {
            while (p.classes.size() < longest) {
                p.classes.emplace_back("middle");
            }
        }
        // sort by class then by name
        sort(people.begin(), people.end(), [](const person &a, const person &b) {
            if (a.classes == b.classes) {
                return a.name < b.name;
            }
            return a.classes > b.classes;
        });
        // print
        for (auto &p: people) {
            cout << p.name << endl;
        }
        cout << "==============================" << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
