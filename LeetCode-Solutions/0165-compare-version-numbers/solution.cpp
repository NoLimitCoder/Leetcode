#pragma GCC optimize("O3", "unroll-loops")
#include <cstring>
class Solution {
public:
    int compareVersion(string v1, string v2) {
        const char* dot = ".";
        char *token1, *token2, *ptr1, *ptr2;
        char* v1c = new char[v1.length()+ 1]; strcpy(v1c, v1.c_str()); 
        char* v2c = new char[v2.length()+ 1]; strcpy(v2c, v2.c_str()); 
        token1 = strtok_r(v1c, dot, &ptr1);
        token2 = strtok_r(v2c, dot, &ptr2);
        while(token1 != NULL || token2 != NULL){
        int x1 = token1 != NULL ? atoi(token1) : 0;
        int x2 = token2 != NULL ? atoi(token2) : 0;
        if (x1 <x2) return -1;
        else if (x1 > x2) return 1;
        token1 = strtok_r(NULL, dot, &ptr1);
        token2 = strtok_r(NULL, dot, &ptr2);
    }
    return 0;
    }
};
