#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // unsigned long long realization from udebug ><
    // it is written in qn longest binary number is maximum 8 bits in a byte and 8 bytes

    int b, v;
    while (cin >> b >> v) {
        pair<string, int> linesToRead[v]; // names and how many lines to read
        pair<string, unsigned long long> val[v]; // names and the values (converted binary to int)
        string s;
        int n;
        for (int i = 0; i < v; i++) {
            cin >> s >> n;
            linesToRead[i] = make_pair(s, n);
        }

        for (int i = 0; i < v; i++) {
            string binary;
            for (int j = 0; j < linesToRead[i].second; j++) {
                cin >> s;
                binary += s;
            }
            val[i] = make_pair(linesToRead[i].first, stoull(binary, nullptr, 2));
        }

        // don't reduce reuse and recycle variables!
        int v2;
        cin >> v2;
        for (int i = 0; i < v2; i++) {
            cin >> s;
            bool found = false;
            // check if s in val.first
            for (int j = 0; j < v; j++) {
                if (val[j].first == s) {
                    cout << s << "=" << val[j].second << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << s << "=" << endl;
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
