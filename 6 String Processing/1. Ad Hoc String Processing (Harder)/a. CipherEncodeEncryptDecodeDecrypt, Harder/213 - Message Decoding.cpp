#include <bits/stdc++.h>

using namespace std;

// the starting index of a code of length n
vector<int> v = {0, 0, 1, 4, 11, 26, 57, 120, 247, 502};

int binToInt(const string &s) {
    int res = 0;
    for (char i: s) {
        res = res * 2 + (i - '0');
    }
    return res;
}

int codeToIdx(const string &s) {
    return binToInt(s) + v[s.size()];
}

string removeSpaces(const string &s) {
    string res;
    for (char i: s) {
        if (i != ' ') {
            res += i;
        }
    }
    return res;
}

bool lineIsBinary(const string &s) {
    for (char i: s) {
        if (i != '0' && i != '1') {
            return false;
        }
    }
    return true;
}

// tedious dealing with a header = "".

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    string header, q, buf;;
    getline(cin, buf);
    int flag = 1;
    while (flag) {
        q = "";
        header = buf;
        while (getline(cin, buf) && lineIsBinary(buf)) {
            q += removeSpaces(buf);
        }
        if (buf.empty() && cin.peek() == EOF) {
            flag = 0;
        }
        int idx = 0;
        while (q.substr(idx, 3) != "000") {
            int n = binToInt(q.substr(idx, 3)); // get length of strings to read.
            idx += 3;
            while (q.substr(idx, n) != string(n, '1')) {
                cout << header[codeToIdx(q.substr(idx, n))];
                idx += n;
            }
            idx += n;
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

