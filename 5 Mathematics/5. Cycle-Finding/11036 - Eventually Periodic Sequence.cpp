#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef unsigned long long ull;

string line;
int N, L; // what to mod, first number

// reads postfixed expression from line
ull f(int x) {
    stack<ull> s;
    stringstream ss(line);
    string token;
    while (ss >> token) {
        if (token == "N") break;
        if (token == "x") {
            s.push(x);
        } else if (token == "+") {
            ull a = s.top();
            s.pop();
            ull b = s.top();
            s.pop();
            s.push(a + b % N);
        } else if (token == "*") {
            ull a = s.top();
            s.pop();
            ull b = s.top();
            s.pop();
            s.push(a * b % N);
        } else {
            s.push(stoi(token));
        }
    }
    return s.top() % N;
}

ii floydCycleFinding(int x0) {                   // f(x) is defined above
    // 1st part: finding k*mu, hare h's speed is 2x tortoise t's
    int t = f(x0), h = f(f(x0));                   // f(x0) is after x0. int should be able to hold the val by here
    while (t != h) {
        t = f(t);
        h = f(f(h));
    }
    // 2nd part: finding mu, hare h and tortoise t move at the same speed
    int mu = 0;
    h = x0;
    while (t != h) {
        t = f(t);
        h = f(h);
        ++mu;
    }
    // 3rd part: finding lambda, hare h moves, tortoise t stays
    int lambda = 1;
    h = f(t);
    while (t != h) {
        h = f(h);
        ++lambda;
    }
    return {mu, lambda};
}

// for sample input 3, it should be f(x) = (x*(x+1))(2+x)%1728

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    while (getline(cin, buf)) {
        stringstream ss(buf);
        ss >> N >> L;
        if (N == 0 && L == 0) break;
        string s;
        ss >> line; // resets line
        while (ss >> s) {
            line += " " + s;
        }
        auto [mu, lambda] = floydCycleFinding(L);
        cout << lambda << '\n';

    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}