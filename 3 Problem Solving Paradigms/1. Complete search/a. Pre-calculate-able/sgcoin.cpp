#include <bits/stdc++.h>

using namespace std;

// we can either fix a string and find a token, or fix a token and find a string
// it is easier to fix a string and find a token since token is a number
// just some simple algebra... here 97 is the ascii value of 'a'
// (((prev * 31 + 97) % 1000000007) * 7 + token) % 1000000007 = new
// token = new - ((prev * 31 + 97) % 1000000007) * 7

long long firstHash = 10000000, secondHash = 20000000;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long previousHash;
    cin >> previousHash;

    long long token = firstHash - ((previousHash *  31 + 'a') % 1000000007) * 7;
    while (token < 0){
        token += 1000000007;
    }
    token %= 1000000007;
    cout << 'a' << " " << token << endl;

    token = secondHash - ((firstHash *  31 + 'b') % 1000000007) * 7;
    while (token < 0){
        token += 1000000007;
    }
    token %= 1000000007;
    cout << 'b' << " " << token << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
