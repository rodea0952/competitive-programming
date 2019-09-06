double ternary_search(double l, double r){
    double left = l, right = r;

    // calculate minimum value
    for(int i=0; i<500; i++){
        if(solve((left * 2 + right) / 3) < solve((left + right * 2) / 3)){
            right = (left + right * 2) / 3;
        }
        else{
            left = (left * 2 + right) / 3;
        }
    }

    return solve((left + right) * 0.5);
}