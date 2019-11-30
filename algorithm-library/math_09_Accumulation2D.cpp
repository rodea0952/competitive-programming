vector<vector<ll>> accumulation2D(vector<vector<ll>> &v){
    int h = v.size(), w = v[0].size();
    vector<vector<ll>> sum(h+1, vector<ll>(w+1, 0));

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            sum[i+1][j+1] = sum[i+1][j] + v[i][j];
        }
    }

    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            sum[j+1][i+1] += sum[j][i+1];
        }
    }

    return sum;
}