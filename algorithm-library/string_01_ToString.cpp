namespace patch{
    template <typename T> string to_string(const T& n){
        ostringstream stm;
        stm << n;
        return stm.str();
    }
}

// patch::to_string()