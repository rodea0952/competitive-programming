#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n, k; cin>>n>>k;
    string s; cin>>s;
    
    vector<char> s_sort;
    for(int i=0; i<n; i++){
        s_sort.push_back(s[i]);
    }

    sort(s_sort.begin(), s_sort.end());

    int s_sort_size=n;
    string ans;
    for(int i=0; i<n; i++){
        string s_head, s_tail;

        for(int j=0; j<n; j++){
            if(j <= i) s_head.push_back(s[j]);
            else s_tail.push_back(s[j]);
        }

        for(int j=0; j<s_sort_size; j++){
            string ans_head=ans, ans_tail;

            ans_head.push_back(s_sort[j]);

            for(int k=0; k<s_sort_size; k++){
                if(k == j) continue;
                ans_tail.push_back(s_sort[k]);
            }
            
            int dif_head=0;
            for(int k=0; k<s_head.size(); k++){
                if(s_head[k] != ans_head[k]) dif_head++;
            }

            int dif_tail=0;
            for(int letter=0; letter<26; letter++){
                int s_tail_cnt=0, ans_tail_cnt=0;
                for(int l=0; l<s_tail.size(); l++){
                    if(s_tail[l] - 'a' == letter) s_tail_cnt++;
                    if(ans_tail[l] - 'a' == letter) ans_tail_cnt++;
                }
                dif_tail += min(s_tail_cnt, ans_tail_cnt);
            }
            dif_tail = s_tail.size() - dif_tail;

            if(dif_head + dif_tail <= k){
                ans.push_back(s_sort[j]);
                for(int k=j; k<s_sort_size; k++){
                    s_sort[k] = s_sort[k+1];
                }
                s_sort_size--;
                break;
            }
        }
    }
    cout << ans << endl;
}
