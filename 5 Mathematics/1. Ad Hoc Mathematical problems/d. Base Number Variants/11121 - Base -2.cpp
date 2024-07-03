#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;


// https://en.wikipedia.org/wiki/Negative_base
bitset<32> to_negabinary(int value) {
    std::bitset<sizeof(int) * CHAR_BIT> result;
    std::size_t bit_position = 0;

    while (value != 0) {
        const auto div_result = std::div(value, -2);

        if (div_result.rem < 0)
            value = div_result.quot + 1;
        else
            value = div_result.quot;

        result.set(bit_position, div_result.rem != 0);

        ++bit_position;
    }

    return result;
}

// https://stackoverflow.com/questions/25726531/how-to-remove-leading-zeros-from-string-using-c
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n;
        cin >> n;
        string str = to_negabinary(n).to_string();
        str.erase(0, std::min(str.find_first_not_of('0'), str.size()-1));
        cout << "Case #" << cases << ": " << str << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
