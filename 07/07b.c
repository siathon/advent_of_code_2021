#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long range_sum(long range_end){
    return (range_end * (range_end + 1)) / 2;
}

long calculate_fuel_consumption(int* locations, int allign_index){
    long sum = 0;
    for (int i = 0; i < 1000; i++){
        sum += range_sum(abs(locations[i] - locations[allign_index]));
    }
    return sum;
}

int main(){
    int *locations, *location_cnt;
    locations = (int*)calloc(sizeof(int), 1000);
    for (int i = 0; i < 1000; i++){
        scanf("%d,", &locations[i]);
    }
    long min_fuel_consumption = (long)INFINITY;
    for (int i = 0; i < 1000; i++){
        long fuel_consumption = calculate_fuel_consumption(locations, i);
        if (fuel_consumption < min_fuel_consumption){
            min_fuel_consumption = fuel_consumption;
        }
    }
    
    printf("min fuel consumption = %ld\n", min_fuel_consumption);
    return 0;
}
