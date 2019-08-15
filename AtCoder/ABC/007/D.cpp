#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

template <typename T> inline string toString(const T &a){ostringstream oss; oss<<a; return oss.str();};

ll solve(string &s){
    int n=s.size();

    ll dp[20][2][2];
    // dp[決めた桁数][未満フラグ][4または9を含むか] := 求める総数

    memset(dp, 0, sizeof(dp));
    dp[0][0][0]=1;

    for(int i=0; i<n; i++){         // 桁
        int D=s[i]-'0';
        for(int j=0; j<2; j++){     // 未満フラグ
            for(int k=0; k<2; k++){ // k=1 のとき4または9を含む
                for(int d=0; d<=(j?9:D); d++){
                    dp[i+1][j || (d<D)][k || d==4 || d==9]+=dp[i][j][k];
                }
            }
        }
    }
    return dp[n][0][1]+dp[n][1][1];
}

int main(){
    ll a, b; cin>>a>>b;
    string A=toString(a-1), B=toString(b);
    cout << solve(B) - solve(A) << endl;
}

