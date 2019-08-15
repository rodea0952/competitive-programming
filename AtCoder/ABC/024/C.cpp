#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, d, k; cin>>n>>d>>k;
    int L[d], R[d], S[k], T[k];
    for(int i=0; i<d; i++) cin>>L[i]>>R[i];
    for(int i=0; i<k; i++) cin>>S[i]>>T[i];

    for(int i=0; i<k; i++){
        int now=S[i];
        for(int j=0; j<d; j++){
            if(L[j] <= now && now <= R[j]){
                if(S[i] < T[i]){
                    now=R[j];

                    if(now >= T[i]){
                        cout << j + 1 << endl;
                        break;
                    }
                }
                else{
                    now=L[j];

                    if(now <= T[i]){
                        cout << j + 1 << endl;
                        break;
                    }
                }
            }   
        }
    }
}