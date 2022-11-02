unsigned long isqrt(unsigned long n){
    unsigned long r = n;
    while(r*r > n){
        r = r + n/r;
        r /= 2;
    }
    return r;
}