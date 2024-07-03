#include <bits/stdc++.h>

using namespace std;

// difficult to comprehend what they are asking for... so here i go
// for any equation C = A +* B.
// 1. if A or B is int, no need do anything to it
// 2. if A is variable, find its original operator
// 2.1. if it is + and current operator is * then add brackets to A (else ans wrong)
// 2.2. else no need do anything to A, just substitute in
// 2.2.1. going left to right so no diff based on the 2 + 3 + 4 example,
// 2.2.1. only terms at back will make a diff for operators with same precedence
// 3. if B is variable, find its original operator
// 3.1. if B operator is * and current operator is + then dont add brackets to B since * has higher precedence than +
// 3.2. else no add brackets to B (ans wrong for B+C*, precedence problem for B+C+ or B*C*)
// 4. substitute the new A and B into C, along with its operator and save it
// extra note. if the variable is a number, i save its operator as $ so that i dont put brackets around it

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        // variable, operator, expression
        map<string, pair<char, string>> variables;
        int m;
        cin >> m;
        string varC, varA, varB, tmp;
        char op;
        while (m--) {
            cin >> varC >> tmp >> varA >> op >> varB;
            // get expression of C based on A and B
            string expr;
            if (variables.count(varA)) {
                if (variables[varA].first == '+' && op == '*') {
                    expr += '(' + variables[varA].second + ')';
                } else {
                    expr += variables[varA].second;
                }
            } else {
                expr += varA;
                // just to say dont do anything to this variable, it is just a number
                variables[varA] = {'$', varA};
            }
            expr += op;
            if (variables.count(varB)) {
                if (variables[varB].first == '*' && op == '+' || variables[varB].first == '$') {
                    expr += variables[varB].second;
                } else {
                    expr += '(' + variables[varB].second + ')';
                }
            } else {
                expr += varB;
                variables[varB] = {'$', varB};
            }
            variables[varC] = {op, expr};
        }
        cout << "Expression #" << i << ": " << variables[varC].second << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}