unsigned long divisor_sum(unsigned long n){
    unsigned long i;
    unsigned long sum = 0;

    for(i = 2; i*i < n; i++){
        if(n % i == 0){
            if(i*i == n){
                sum += i;
            } else{
                sum += i + (n / i);
            }
        }
    }
    return sum + 1;
}