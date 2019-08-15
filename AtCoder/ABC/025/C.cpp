#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

const vector<string> EMPTY(4, string(4, '.'));
int b[4][4], c[4][4];
map<vector<string>, int> rec;
string pat="ox";

void update(const vector<string>& board, int val, bool chmax){
    if(rec.count(board)){
        if(chmax == true) {
            rec[board]=max(rec[board], val);
        }
        else {
            rec[board]=min(rec[board], val);
        }
    }
    else rec[board]=val;
}

int calc(const vector<string>& board){
    int score=0;
    for(int i=1; i<=2; i++){
        for(int j=1; j<=3; j++){
            if(board[i][j] == board[i+1][j]) score += b[i][j];
        }
    }

    for(int i=1; i<=3; i++){
        for(int j=1; j<=2; j++){
            if(board[i][j] == board[i][j+1]) score += c[i][j];
        }
    }
    return score;
}

int dfs(vector<string> board, int turn=0){
    if(rec.count(board)) return rec[board];

    bool empty_cell=false;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            if(board[i][j] != '.') continue;

            empty_cell=true;
            board[i][j]=pat[turn];
            int n_cost=dfs(board, 1-turn);
            board[i][j]='.';

            if(turn == 0){ //先手、最大化
                update(board, n_cost, true);
            }
            else{ //後手、最小化
                update(board, n_cost, false);
            }
        }
    }

    if(empty_cell == false){
        int cost = calc(board);
        rec[board]=cost;
    }
    
    return rec[board];
}

int main() {
    int sum=0;
    for(int i=1; i<=2; i++){
        for(int j=1; j<=3; j++){
            cin>>b[i][j];
            sum += b[i][j];
        }
    }
    for(int i=1; i<=3; i++){
        for(int j=1; j<=2; j++){
            cin>>c[i][j];
            sum += c[i][j];
        }
    }

    int choku = dfs(EMPTY);
    cout << choku << endl << sum - choku << endl;
}