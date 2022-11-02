unsigned char digit_count(unsigned long n){
    unsigned char result = 1;
    while (n > 9){
        n /= 10;
        result += 1;
    }
    return result;
}