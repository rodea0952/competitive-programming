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
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    while(1){
        int M, T, P, R; cin>>M>>T>>P>>R;
        if(M==0) return 0;

        // 初期化が必要？
        vector<T> team(T);

        for(int i=0; i<R; i++){
            int m, t, p, j; cin>>m>>t>>p>>j;
            t--;

            int pro, time, id;
            tie(pro, time, id)=team[t];

            if(j==0){
                pro++;
                time+=t;
                team[t]=T(pro, time, id);
            }
            else{
                time+=20;
                team[t]=T(pro, time, id);
            }
        }

        sort(team.begin(), team.end(), greater<T>());
        for(int i=0; i<T; i++){
            int pro, time, id;
            tie(pro, time, id)=team[i];

            cout << pro << " " << time << " " << id+1 << endl;
        }

    }
}