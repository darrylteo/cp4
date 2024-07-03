#include <bits/stdc++.h>

using namespace std;

class comp_char {
    std::vector<int> collation_table;
public:
    comp_char() : collation_table(std::numeric_limits<unsigned char>::max()) {
        std::iota(collation_table.begin(), collation_table.end(), 0);

        for (int i = 0; i < 26; i++) {
            collation_table['a' + i] = i * 2 + 1;
            collation_table['A' + i] = i * 2;
        }
    }

    bool operator()(unsigned char a, unsigned char b) {
        return collation_table[a] < collation_table[b];
    }
};

struct cmp_str {
    bool operator()(std::string const &a, std::string const &b) {
        comp_char cmp;
        size_t i = 0;
        while (a[i] == b[i] && i < a.size())
            ++i;
        return cmp(a[i], b[i]);
    }
};

// ref: https://stackoverflow.com/questions/19509110/sorting-a-string-with-stdsort-so-that-capital-letters-come-after-lower-case

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), comp_char());
        do {
            cout << s << '\n';
        } while (next_permutation(s.begin(), s.end(), comp_char()));
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


