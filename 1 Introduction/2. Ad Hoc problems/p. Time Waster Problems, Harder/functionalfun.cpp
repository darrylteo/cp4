#include <bits/stdc++.h>

using namespace std;

struct mapping {
    string domain;
    string codomain;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf, s;
    while (getline(cin >> ws, buf)) {
        stringstream ss(buf);
        vector<string> domain, codomain;
        ss >> s; // "domain"
        while (ss >> s) {
            domain.push_back(s);
        }
        getline(cin >> ws, buf);
        stringstream ss2(buf);
        ss2 >> s; // "codomain"
        while (ss2 >> s) {
            codomain.push_back(s);
        }

        int n;
        cin >> n;
        vector<mapping> mappings;
        for (int i = 0; i < n; i++) {
            cin >> s;
            mapping m;
            m.domain = s;
            cin >> s; // "->"
            cin >> s;
            m.codomain = s;
            mappings.push_back(m);
        }

        // check if a same codoamin is produced by a different domain
        // e.g. 1 -> 2, 3 -> 2. both 1 and 3 produce 2 means not injective (1-1)
        bool is_injective = true;
        for (int i = 0; i < mappings.size(); i++) {
            for (int j = 0; j < mappings.size(); j++) {
                if (i != j && mappings[i].codomain == mappings[j].codomain &&
                    mappings[i].domain != mappings[j].domain) {
                    is_injective = false;
                    break;
                }
            }
        }

        // check if all codomains are present
        bool is_surjective = true;
        for (int i = 0; i < codomain.size(); i++) {
            bool found = false;
            for (int j = 0; j < mappings.size(); j++) {
                if (codomain[i] == mappings[j].codomain) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                is_surjective = false;
                break;
            }
        }

        // check if is a function
        // e.g. 1 -> 0, 1 -> 1. 1 produces 0 and 1 means not a function (it cant decide what to do with 1)
        bool is_function = true;
        for (int i = 0; i < mappings.size(); i++) {
            for (int j = 0; j < mappings.size(); j++) {
                if (i != j && mappings[i].domain == mappings[j].domain &&
                    mappings[i].codomain != mappings[j].codomain) {
                    is_function = false;
                    break;
                }
            }
        }

        if (!is_function) cout << "not a function" << endl;
        else if (is_injective && is_surjective) cout << "bijective" << endl;
        else if (is_injective) cout << "injective" << endl;
        else if (is_surjective) cout << "surjective" << endl;
        else cout << "neither injective nor surjective" << endl;


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}