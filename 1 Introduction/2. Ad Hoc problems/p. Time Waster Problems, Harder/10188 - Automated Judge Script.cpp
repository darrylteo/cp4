#include <bits/stdc++.h>

using namespace std;

bool presentationError(vector<string> solution, vector<string> output) {
    vector<char> solutionNumeric, outputNumeric;
    for (int i = 0; i < solution.size(); ++i) {
        for (int j = 0; j < solution[i].size(); ++j) {
            if (isdigit(solution[i][j])) {
                solutionNumeric.push_back(solution[i][j]);
            }
        }
    }
    for (int i = 0; i < output.size(); ++i) {
        for (int j = 0; j < output[i].size(); ++j) {
            if (isdigit(output[i][j])) {
                outputNumeric.push_back(output[i][j]);
            }
        }
    }
    if (solutionNumeric == outputNumeric) {
        return true;
    } else {
        return false;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n=1, m, run = 1;
    string tmp;
    getline(cin, tmp); // bad to mix cin and getline
    n = stoi(tmp);
    while (n) {
        cout << "Run #" << run++ << ": ";
        vector<string> solution, output;
        for (int i = 0; i < n; ++i) {
            getline(cin, tmp);
            solution.push_back(tmp);
        }
        getline(cin, tmp);
        m = stoi(tmp);
        for (int i = 0; i < m; ++i) {
            getline(cin, tmp);
            output.push_back(tmp);
        }

        getline(cin, tmp); // bad to mix cin and getline
        n = stoi(tmp);

        if (solution == output) { // std::vector::operator==
            cout << "Accepted" << endl;
            continue;
        } else if (presentationError(solution, output)) {
            cout << "Presentation Error" << endl;
            continue;
        } else {
            cout << "Wrong Answer" << endl;
            continue;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}