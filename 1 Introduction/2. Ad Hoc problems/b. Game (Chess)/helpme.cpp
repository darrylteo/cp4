#include <bits/stdc++.h>

// IMPORTANT: use stable_sort to preserve order of equal elements
// or just make sure u sort once with a good cmp functions


using namespace std;

string line;
vector<string> white, black;

std::string tail(std::string const &source, size_t const length) {
    if (length >= source.size()) { return source; }
    return source.substr(source.size() - length);
} // tail

// for cmp, swap if false
// true if first argument should go before 2nd
bool cmp(const string &s1, const string &s2) {
    map<char,int> vals;
    vals['K'] = 0;
    vals['Q'] = 1;
    vals['R'] = 2;
    vals['B'] = 3;
    vals['N'] = 4;

    if(s1.length() < s2.length()) {
        return false;
    }

    if(s1.length() > s2.length()) {
        return true;
    }

    // this means ascending, starting from K
    return vals[s1[0]] < vals[s2[0]];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // get all pieces into vectors black and white
    for (int i = 0; i < 8; i++) {
        getline(cin, line); // throwaway line with +---+
        getline(cin, line);
        int row;
        char tmp;
        string col, toPrint;
        for (int j = 0; j < 8; j++) {
            tmp = line[2 + 4 * j];
            col = j + 'a';
            row = 8 - i;

            // pawns have their identifier omitted
            if (tmp == 'P' || tmp == 'p') toPrint = col + to_string(row);
            else toPrint = static_cast<char>(toupper(tmp)) + col + to_string(row);

            // add to list if is a chess piece
            if (isupper(tmp)) {
                white.push_back(toPrint);
            } else if (islower(tmp)) {
                black.push_back(toPrint);
            }
        }
    }


//    // no need col since read in order but just try
//    sort(white.begin(), white.end(), [](const string &a, const string &b) {
//        return tail(a, 2)[0] < tail(b, 2)[0];
//    });
//    sort(black.begin(), black.end(), [](const string &a, const string &b) {
//        return tail(a, 2)[0] < tail(b, 2)[0];
//    });

    // sort white ascending row, black descending row.
    stable_sort(white.begin(), white.end(), [](const string &a, const string &b) {
        return tail(a, 1) < tail(b, 1);
    });
    stable_sort(black.begin(), black.end(), [](const string &a, const string &b) {
        return tail(a, 1) > tail(b, 1);
    });

    // sort piece type
    stable_sort(white.begin(), white.end(), cmp);
    stable_sort(black.begin(), black.end(), cmp);

    // print result
    cout << "White: ";
    for(int i = 0; i < (int)white.size()-1; i++) {
        cout << white[i] << ",";
    }
    if(white.size() > 0) {
        cout << white.back();
    }
    cout << endl;

    cout << "Black: ";
    for(int i = 0; i < (int)black.size()-1; i++) {
        cout << black[i] << ",";
    }
    if(black.size() > 0) {
        cout << black.back();
    }
    cout << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

