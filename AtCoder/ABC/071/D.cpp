#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n; cin>>n;
    string s1, s2; cin>>s1>>s2;

    vector<int> domino(60);
    int i=0, j=0;
    while(i<n){
        if(s1[i] == s1[i+1]){
            domino[j]=2;
            i += 2;
        }
        else{
            domino[j]=1;
            i++;
        }
        j++;
    }
    
    ll ans=1;
    for(int i=0; i<j; i++){
        if(i == 0){
            if(domino[i] == 1){
                ans *= 3;
            }
            else{
                ans *= 6;
            }
        }
        else{
            if(domino[i-1] == 1){
                ans *= 2;
            }
            else if(domino[i] == 2){
                ans *= 3;
            }
        }
        ans %= MOD;
    }
    cout << ans << endl;
}