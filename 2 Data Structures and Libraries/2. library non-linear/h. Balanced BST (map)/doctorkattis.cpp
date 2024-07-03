#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, pair<int, int>> namesToInfectionLevel; // name -> (infection level, time)
    map<int, map<int, string>> infectionLevelToNames; // infection level -> (time, name)
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cmd, infection;
        string name;
        cin >> cmd;
        if (cmd == 0) {
            // add new cat to both maps
            cin >> name >> infection;
            namesToInfectionLevel[name] = {infection, i};
            infectionLevelToNames[infection][i] = name;
        } else if (cmd == 1) {
            // add infection to existing cat
            cin >> name >> infection;
            int oldInfectionLevel = namesToInfectionLevel[name].first;
            int catTime = namesToInfectionLevel[name].second;
            infectionLevelToNames[oldInfectionLevel].erase(catTime); // also removes cat name
            namesToInfectionLevel[name] = {oldInfectionLevel + infection, catTime}; // no change to time
            infectionLevelToNames[oldInfectionLevel + infection][catTime] = name;
            // if no more cats with this infection level, remove from map
            if (infectionLevelToNames[oldInfectionLevel].empty()) {
                infectionLevelToNames.erase(oldInfectionLevel);
            }
        } else if (cmd == 2) {
            // remove cat
            cin >> name;
            int infectionLevel = namesToInfectionLevel[name].first;
            int catTime = namesToInfectionLevel[name].second;
            infectionLevelToNames[infectionLevel].erase(catTime); // also removes cat name
            namesToInfectionLevel.erase(name);
            // if no more cats with this infection level, remove from map
            if (infectionLevelToNames[infectionLevel].empty()) {
                infectionLevelToNames.erase(infectionLevel);
            }
        } else if (cmd == 3) {
            if (namesToInfectionLevel.empty()) {
                cout << "The clinic is empty" << endl;
            } else {
                // print cat with highest infection level
                auto it = infectionLevelToNames.rbegin();
                cout << it->second.begin()->second << endl;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
