unsigned long facto(unsigned long n){
    if (n == 0)
        return 1;
    
    unsigned long result = 1;
    for(unsigned long i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}