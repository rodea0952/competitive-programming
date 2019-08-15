#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<bool> sosu(100010, true);
void eratosthenes(int n){
	sosu[1]=false;
	for(int i=2; i<=sqrt(n); i++){
		if(sosu[i]){
			for(int j=2; i*j<=n; j++){
				sosu[i*j]=false;
			}
		}
	}
}

int main(){
    eratosthenes(100005);
    
    vector<int> ans_sum(100005, 0);
    ans_sum[1]=0;
    for(int i=3; i<100000; i+=2){
        if(sosu[i] && sosu[(i+1)/2]){
            ans_sum[i]=ans_sum[i-2]+1;
        }
        else{
            ans_sum[i]=ans_sum[i-2];
        }
    }

    int q; cin>>q;
    for(int i=0; i<q; i++){
        int l, r; cin>>l>>r;
        if(l == 1){
            cout << ans_sum[r] << endl;
        }
        else{
            cout << ans_sum[r] - ans_sum[l-2] << endl;
        }
    }
}