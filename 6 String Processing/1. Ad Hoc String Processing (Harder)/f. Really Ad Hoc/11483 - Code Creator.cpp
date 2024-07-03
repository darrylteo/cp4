#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, cases = 1;
    while (cin >> n >> ws, n) {
        cout << "Case " << cases++ << ":\n";
        cout << "#include<string.h>\n#include<stdio.h>\nint main()\n{\n";
        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);
            cout << "printf(\"";
            for (char c : s) {
                if (c == '"') cout << "\\\"";
                else if (c == '\\') cout << "\\\\";
                else cout << c;
            }
            cout << "\\n\");\n";
        }
        cout << "printf(\"\\n\");\nreturn 0;\n}\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

