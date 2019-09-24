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
    // 1-indexed
    int n, k; cin>>n>>k;
    vector<vector<int>> g(n+1);
    vector<P> edge;
    for(int i=1; i<=8; i++){
        int num=(1<<(i-1));
        if(n<num) break;
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            if(num & j){
                g[i].push_back(j);
                g[j].push_back(i);
                edge.push_back(P(i, j));
            }
        }
    }

    cout << edge.size() << endl;
    for(int i=0; i<edge.size(); i++){
        cout << edge[i].fs << " " << edge[i].sc << endl;
    }

    while(k){
        string s;
        int sum=0;
        for(int i=1; i<=8; i++){
            int num=(1<<(i-1));
            if(n<num) break;

            // i ビット目が立っているか
            cout << i << endl;
            cin>>s;
            if(s=="Yes"){
                k--;
                goto END;
            }
            if(s=="Near"){
                sum+=num;
            }
        }
        cout << sum << endl;
        cin>>s;
        k--;
        END:;
    }
}