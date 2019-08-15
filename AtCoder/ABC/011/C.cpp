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
    vector<int> ng(3);
    for(int i=0; i<3; i++) {
        cin>>ng[i];
        if(n == ng[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    sort(ng.begin(), ng.end());
    int ng1=ng[0], ng2=ng[1], ng3=ng[2];

    for(int i=0; i<100; i++){
        
        if(n-3 != ng1 && n-3 != ng2 && n-3 != ng3){
            n -= 3;
        } 
        else{
            if(n-3 == ng3){
                n -= 2;
            }
            else if(n-3 == ng2){
                if(n-2 != ng3){
                    n -= 2;
                }
                else if(n-2 == ng3){
                    n -= 1;
                }
            }
            else if(n-3 == ng1){
                if(n-2 != ng2 && n-2 != ng3){
                    n -= 2;
                }
                else if(n-2 == ng2){
                    if(n-1 != ng3){
                        n -= 1;
                    }
                    else if(n-1 == ng3){
                        cout << "NO" << endl;
                        return 0;
                    }
                }
                else if(n-2 == ng3){
                    n -= 1;
                }
            }
        }
    }
    if(n <= 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}