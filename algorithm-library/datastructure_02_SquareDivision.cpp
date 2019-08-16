class SquareDivision{
    private:
        const int bucketSize = 256;
        long long N, B;
        vector<long long> data;
        vector<long long> bucketSum;
        vector<long long> bucketMin;
        vector<long long> bucketAdd;
        vector<bool> lazyFlag;
        vector<int> lazyUpdate;

    public:
        void prepare(int n){
            B = (n + bucketSize - 1)/ bucketSize;
            N = B * bucketSize;
            data.assign(N, 0);
            bucketSum.assign(B, 0);
            bucketMin.assign(B, INF);
            bucketAdd.assign(B, 0);
            lazyFlag.assign(B, false);
            lazyUpdate.assign(B, 0);
        }

        // Range Sum Query
        // initialized with 0
        void RSQadd(int x, int y){
            int k = x / bucketSize;
            data[x] += y;
            int sum　=　0;
            for(int i=k*bucketSize; i<(k+1)*bucketSize; i++){
                sum += data[i];
            }
            bucketSum[k] = sum;
        }

        // [s, t)
        int RSQgetsum(int s, int t){
            int sum=0;
            for(int k=0; k<B; k++){
                int l = k * bucketSize;
                int r = (k + 1) * bucketSize;

                if(r <= s || t <= l) continue;

                if(s <= l && r <= t){
                    sum += bucketSum[k];
                }
                else{
                    for(int i=max(s, l); i<min(t, r); i++){
                        sum += data[i];
                    }
                }
            }
            return sum;
        }

        // Range Minimum Query
        // initialized with INF
        void RMQupdate(int x, int y){
            int k = x / bucketSize;
            ll minVal = data[x] = y;
            int sum = 0;
            for(int i=k*bucketSize; i<(k+1)*bucketSize; i++){
                minVal = min(minVal, data[i]);
            }
            bucketMin[k] = minVal;
        }

        // [s, t)
        int RMQfind(int s, int t){
            long long minVal = INF;
            for(int k=0; k<B; k++){
                int l = k * bucketSize;
                int r = (k + 1) * bucketSize;

                if(r <= s || t <= l) continue;

                if(s <= l && r <= t){
                    minVal = min(minVal, bucketMin[k]);
                }
                else{
                    for(int i=max(s, l); i<min(t, r); i++){
                        minVal = min(minVal, data[i]);
                    }
                }
            }
            return minVal;
        }

        // Range Add Query
        // initialized with 0
        void RAQadd(int s, int t, int x){
            for(int k=0; k<B; k++){
                int l = k * bucketSize;
                int r = (k + 1) * bucketSize;

                if(r <= s || t <= l) continue;

                if(s <= l && r <= t){
                    bucketAdd[k] += x;
                }
                else{
                    for(int i=max(s, l); i<min(t, r); i++){
                        data[i] += x;
                    }
                }
            }
        }

        int RAQget(int i){
            int k = i / bucketSize;
            return data[i] + bucketAdd[k];
        }

        // Range Update Query
        // initialized with INF
        void RUQeval(int k){
            if(lazyFlag[k]){
                lazyFlag[k] = false;
                for(int i=k*bucketSize; i<(k+1)*bucketSize; i++){
                    data[i] = lazyUpdate[k];
                }
            }
        }

        void RUQupdate(int s, int t, int x){
            for(int k=0; k<B; k++){
                int l = k * bucketSize;
                int r = (k + 1) * bucketSize;

                if(r <= s || t <= l) continue;

                if(s <= l && r <= t){
                    lazyFlag[k] = true;
                    lazyUpdate[k] = x;
                }
                else{
                    eval(k);
                    for(int i=max(s, l); i<min(t, r); i++){
                        data[i] = x;
                    }
                }
            }
        }

        int RUQfind(int i){
            int k = i / bucketSize;
            eval(k);
            return data[i];
        }

        // Range Sum Query and Range Add Query
        // initialized with 0
        void RSQRAQadd(int s, int t, int x){
            for(int k=0; k<B; k++){
                int l = k * bucketSize;
                int r = (k + 1) * bucketSize;

                if(r <= s || t <= l) continue;

                if(s <= l && r <= t){
                    bucketAdd[k] += x;
                }
                else{
                    for(int i=max(s, l); i<min(t, r); i++){
                        data[i] += x;
                        bucketSum[k] += x;
                    }
                }
            }
        }

        long long RSQRAQgetsum(int s, int t){
            long long sum=0;
            for(int k=0; k<B; k++){
                int l = k * bucketSize;
                int r = (k + 1) * bucketSize;

                if(r <= s || t <= l) continue;

                if(s <= l && r <= t){
                    sum += bucketSum[k] + bucketAdd[k] * bucketSize;
                }
                else{
                    for(int i=max(s, l); i<min(t, r); i++){
                        sum += data[i] + bucketAdd[k];
                    }
                }
            }

            return sum;
        }

        // Range Minumun Query and Range Update Query
        // initialized with INF
        void eval(int k){
            if(lazyFlag[k]){
                lazyFlag[k] = false;
                for(int i=k*bucketSize; i<(k+1)*bucketSize; i++){
                    data[i] = lazyUpdate[k];
                }
            }
        }

        void update(int s, int t, int x){
            for(int k=0; k<B; k++){
                int l = k * bucketSize;
                int r = (k + 1) * bucketSize;

                if(r <= s || t <= l) continue;

                if(s <= l && r <= t){
                    bucketMin[k] = x;
                    lazyFlag[k] = true;
                    lazyUpdate[k] = x;
                }
                else{
                    eval(k);
                    for(int i=max(s, l); i<min(t, r); i++){
                        data[i] = x;
                    }

                    int minVal = INF;
                    for(int i=l; i<r; i++){
                        minVal = min(minVal, data[i]);
                    }
                    bucketMin[k] = minVal;
                }
            }
        }

        int find(int s, int t){
            int minVal = INF;
            for(int k=0; k<B; k++){
                int l = k * bucketSize;
                int r = (k + 1) * bucketSize;

                if(r <= s || t <= l) continue;

                if(s <= l && r <= t){
                    minVal = min(minVal, bucketMin[k]);
                }
                else{
                    eval(k);
                    for(int i=max(s, l); i<min(t, r); i++){
                        minVal = min(minVal, data[i]);
                    }
                }
            }

            return minVal;
        }
};

int main(){
    int n, q; cin>>n>>q;
    SquareDivision sd;
    sd.prepare(n);

    while(q--){
        int c, x, y; cin>>c>>x>>y;
        if(c == 0){
            sd.add(x, y);
        }
        else{
            cout << sd.getsum(x, y+1) << endl;
        }
    }
}