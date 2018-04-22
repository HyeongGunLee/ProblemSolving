#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

char arr[1000001];
char result[1000001];

void reverseChar(char* str)
{
    int len = strlen(str);
    int maxLen = len/2;
    for (int i = 0; i <maxLen; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

int main(void) {
    scanf(" %s", arr);
    int len = strlen(arr);
    int i = len-1;
    int x = 0;
    while (i >= 0) {
        int temp = 0;
        int k = 1;
        for (int j = 0; j < 3; j++) {
            if (i >= 0) {
                int x = arr[i] - 48;
                temp += x*k;
            }
            k *= 2;
            i--;
        }
        result[x++] = temp + '0';
    }
    reverseChar(result);
    printf("%s", result);
    return 0;
}