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
    int n; cin>>n;
    vector<bool> rain(2410, false);
    for(int i=0; i<n; i++){
        string s; cin>>s;
        
        string h=s.substr(0, 4);
        int head=stoi(h);
        string t=s.substr(5, 4);
        int tail=stoi(t);
        
        head-=head%5;
        if(tail%100==56 || tail%100==57 || tail%100==58 || tail%100==59){
            tail-=tail%100;
            tail+=100;
        }
        else{
            tail+=4;
            tail-=tail%5;
        }

        for(int j=head; j<=tail; j++){
            rain[j]=true;
        }
    }

    for(int i=0; i<=2405; i++){
        if(rain[i]){
            cout << setfill('0') << right << setw(4) << i << "-";
            i++;
            while(rain[i]){
                i++;
            }
            cout << setfill('0') << right << setw(4) << i-1 << endl;
        }
    }
}