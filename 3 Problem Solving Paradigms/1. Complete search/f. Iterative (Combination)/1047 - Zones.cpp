#include <bits/stdc++.h>

using namespace std;

vector<int> bitsToTowers(bitset<25> &towersInUse) {
    vector<int> towers;
    for (int i = 0; i < towersInUse.size(); i++) {
        if (towersInUse[i]) {
            towers.push_back(i);
        }
    }
    return towers;
}

// somewhat misleading hint... ain't no inclusion-exclusion here
// spent an hour doing inclusion-exclusion, but it's not the right approach based on their representation of intersections
// just realized for lines 66-77 the outer for loop should have been for common.size()

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int plan, actual, cases = 1;
    while (cin >> plan >> actual, plan || actual) {
        vector<int> tower(plan);
        for (int i = 0; i < plan; i++) {
            cin >> tower[i];
        }
        int m;
        cin >> m;
        vector<vector<int>> common(m);
        for (int i = 0; i < m; i++) {
            int n;
            cin >> n;
            common[i].resize(n + 1);
            for (int j = 0; j < n; j++) {
                cin >> common[i][j];
                common[i][j]--;
            }
            cin >> common[i][n];
        }

        // get towers ONLY, i.e., customers served that are not common
        // from sample diagram, tower 2 only = 20 - 2 - 3 - 7 = 8
        for (int i = 0; i < tower.size(); i++) {
            for (int j = 0; j < common.size(); j++) {
                // - 1 because last element is the number of customers served
                if (find(common[j].begin(), common[j].end() - 1, i) != common[j].end() - 1) {
                    tower[i] -= common[j][common[j].size() - 1];
                }
            }
        }

        vector<vector<int>> bestTowersInUse; // number of customers, towers in use
        int maxCustomers = 0;
        for (int i = 0; i < (1 << plan); i++) {
            bitset<25> towersInUse(i);
            // if number of towers in use is not equal to actual, skip
            if (towersInUse.count() != actual) {
                continue;
            }

            int customers = 0;
            bitset<15> usedCommon; // mark common services used
            for (int j = 0; j < tower.size(); j++) {
                if (towersInUse[j]) {
                    // add the customers served by the towers ONLY
                    customers += tower[j];
                    // add whenever this tower is present in a common service
                    for (int k = 0; k < common.size(); k++) {
                        if (!usedCommon[k] && find(common[k].begin(), common[k].end() - 1, j) != common[k].end() - 1) {
                            customers += common[k][common[k].size() - 1];
                            usedCommon[k] = true;
                        }
                    }
                }
            }
            if (customers >= maxCustomers) {
                maxCustomers = customers;
                vector<int> tmp, tmp1 = bitsToTowers(towersInUse);
                tmp.push_back(-customers);
                tmp.insert(tmp.end(), tmp1.begin(), tmp1.end());
                bestTowersInUse.push_back(tmp);
            }
        }

        cout << "Case Number  " << cases++ << endl;
        cout << "Number of Customers: " << maxCustomers << endl;
        cout << "Locations recommended:";
        sort(bestTowersInUse.begin(), bestTowersInUse.end());
        for (int i = 1; i < bestTowersInUse[0].size(); i++) {
            cout << " " << bestTowersInUse[0][i] + 1;
        }
    cout << endl << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}