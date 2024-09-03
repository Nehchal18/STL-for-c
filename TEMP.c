#include <stdio.h>
#include <stdlib.h>

int greater(const void* a, const void* b, size_t s) {
    if(s == sizeof(int)) {
        return *(int*)a > *(int*)b;
    }else if(s == sizeof(char)) {
        return *(char*)a > *(char*)b;
    }else if(s == sizeof(float)) {
        return *(float*)a > *(float*)b;
    }else if(s == sizeof(double)) {
        return *(double*)a > *(double*)b;
    }
}