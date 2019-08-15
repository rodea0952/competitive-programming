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

int main(){
    int n;
    while(cin>>n, n){
        char c[n];
        vector<int> cnt(30, 0);
        for(int i=0; i<n; i++){
            cin>>c[i];
        }

        int cmax=0, sc_cmax=0;
        for(int i=0; i<n; i++){
            cnt[c[i]-'A']++;

            int maxid;
            for(int i=0; i<26; i++){
                if(cmax<cnt[i]){
                    cmax=cnt[i];
                    maxid=i;
                }
            }

            for(int i=0; i<26; i++){
                if(i==maxid) continue;
                
                chmax(sc_cmax, cnt[i]);
            }

            if(cmax > sc_cmax+n-(i+1)){
                cout << (char)(maxid+'A') << " " << i+1 << endl;
                break;
            }

            if(i==n-1){
                cout << "TIE" << endl;
            }
        }
    }
}