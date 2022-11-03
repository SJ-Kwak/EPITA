#include <stddef.h>

long is_partition(unsigned char a[], size_t len, unsigned char pivot)
{
	unsigned char max[len], min[len];

	for(size_t i = 0; i < len; i++){
		if(i == 0){
			max[i] = a[i];
			min[len-1] = a[len-1];
		}
		else {
			max[i] = ((max[i-1] >= a[i]) ? max[i-1] : a[i]);
			min[len-1-i] = ((min[len-i] <= a[len-1-i]) ? min[len-i] : 
a[len-1-i]);
		}
	}

	for(size_t i = 1; i < len-1; i++){
		if((a[i] >= max[i-1] && a[i] <= min[i+1]) || a[i] == pivot)
			return i;
	}

	return -1;
}
