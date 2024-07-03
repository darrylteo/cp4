#include <bits/stdc++.h>

using namespace std;

string line;
vector<string> white, black;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // get white pieces (upper case)
    getline(cin, line);
    line = line.substr(7, line.size());
    stringstream ss(line);
    string token;
    while(getline(ss, token, ','))
    {
        white.push_back(token);
    }
    // get black pieces (lower case)
    getline(cin, line);
    line = line.substr(7, line.size());
    for (int i = 0; i < line.size(); i++)
    {
        if (isalpha(line[i]))
        {
            line[i] = tolower(line[i]);
        }
    }
    stringstream ss2(line);
    while(getline(ss2, token, ','))
    {
        black.push_back(token);
    }


    // get empty board... 34 chars per line
    string board;
    board = "+---+---+---+---+---+---+---+---+\n|...|:::|...|:::|...|:::|...|:::|\n+---+---+---+---+---+---+---+---+\n|:::|...|:::|...|:::|...|:::|...|\n+---+---+---+---+---+---+---+---+\n|...|:::|...|:::|...|:::|...|:::|\n+---+---+---+---+---+---+---+---+\n|:::|...|:::|...|:::|...|:::|...|\n+---+---+---+---+---+---+---+---+\n|...|:::|...|:::|...|:::|...|:::|\n+---+---+---+---+---+---+---+---+\n|:::|...|:::|...|:::|...|:::|...|\n+---+---+---+---+---+---+---+---+\n|...|:::|...|:::|...|:::|...|:::|\n+---+---+---+---+---+---+---+---+\n|:::|...|:::|...|:::|...|:::|...|\n+---+---+---+---+---+---+---+---+\n";
    int row, col;
    for (int i = 0; i < white.size(); i++){
        if (white[i].size() == 2){
            col = white[i][0] - 'a';
            row = 7 - (white[i][1] - '1');
            board[34 * 2 * (row+1) - 34 + 4 * col + 2] = 'P';
        } else {
            col = white[i][1] - 'a';
            row = 7 - (white[i][2] - '1');
            board[34 * 2 * (row+1) - 34 + 4 * col + 2] = white[i][0];
        }
    }
    for (int i = 0; i < black.size(); i++){
        if (black[i].size() == 2){
            col = black[i][0] - 'a';
            row = 7 - (black[i][1] - '1');
            board[34 * 2 * (row+1) - 34 + 4 * col + 2] = 'p';
        } else {
            col = black[i][1] - 'a';
            row = 7 - (black[i][2] - '1');
            board[34 * 2 * (row+1) - 34 + 4 * col + 2] = black[i][0];
        }
    }
    cout << board << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

