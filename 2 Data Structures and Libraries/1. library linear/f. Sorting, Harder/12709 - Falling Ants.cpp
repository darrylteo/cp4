#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n, n) {
        vector<string> names;
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            names.push_back(name);
        }
        sort(names.begin(), names.end());

        string name1, name2;
        name1 = names[n / 2 - 1];
        name2 = names[n / 2];

        int i = 0;
        while (name1[i] == name2[i]) {
            i++;
        }
        cout << name1.substr(0, i); // sure must print
        if (i != name1.size()) {
            while (i < name1.size()) {
                // squeeze if can (both longer than i)
                if (i < name1.size() - 1 && i < name2.size() - 1) {
                    if (name1[i] == 'Z') {
                        cout << 'Z';
                    } else {
                        cout << (char) (name1[i] + 1);
                        break;
                    }
                }
                    // continue if cant squeeze OR last char (can be equal no need bigger)
                else if (name1[i] + 1 == name2[i] || i == name1.size() - 1) {
                    cout << name1[i];
                } else {
                    if (name1[i] == 'Z') {
                        cout << 'Z';
                    } else {
                        cout << (char) (name1[i] + 1);
                        break;
                    }
                }
                i++;
            }
        }
        cout << endl;

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
