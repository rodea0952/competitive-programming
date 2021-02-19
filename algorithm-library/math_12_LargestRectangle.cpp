long long LargestRectangle(vector<long long> &h){
    h.emplace_back(0);
    int n = h.size();
    stack<pair<long, long>> S;
    long long maxv = 0;

    for(int i=0; i<n; i++){
        if(S.empty()){
            S.emplace(h[i], i);
        }
        else{
            if(S.top().first < h[i]){
                S.emplace(h[i], i);
            }
            else if(S.top().first > h[i]){
                int target = i;
                while(S.size() && S.top().first >= h[i]){
                    pair<long, long> pre = S.top(); S.pop();
                    ll area = pre.first * (i - pre.second);
                    maxv = max(maxv, area);
                    target = pre.second;
                }
                S.emplace(h[i], target);
            }
        }
    }

    return maxv;
}