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
        int n; cin>>n;
        if(n==0) return 0;

        vector<int> tanku={5, 7, 5, 7, 7};
        vector<string> w(n);
        for(int i=0; i<n; i++) cin>>w[i];

        for(int i=0; i<n; i++){
            int cnt=0, sum=0;
            for(int j=i; j<n; j++){
                sum+=w[j].size();
                if(sum==tanku[cnt]){
                    sum=0;
                    cnt++;

                    if(cnt==5){
                        cout << i+1 << endl;
                        goto END;
                    }
                }
            }
        }

        END:;
    }
}