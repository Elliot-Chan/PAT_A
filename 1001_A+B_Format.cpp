#include <stdio.h>
#include <string.h>

int main() {
    char c1[8], c2[8], result[8];
    int  i1, i2, length;
    bool minus = false;
    scanf("%s", &c1);
    scanf("%s", &c2);
    bool i1_is_minus = (c1[0] == '-');
    bool i2_is_minus = (c2[0] == '-');
    sscanf(i1_is_minus? c1 + 1 : c1, "%d", &i1);
    sscanf(i2_is_minus? c2 + 1 : c2, "%d", &i2);
    if(!i1_is_minus && !i2_is_minus) sprintf(result, "%d", i1 + i2);
    else if(!i1_is_minus && i2_is_minus) sprintf(result, "%d", i1 - i2);
    else if(i1_is_minus && !i2_is_minus) sprintf(result, "%d", i2 - i1);
    else if(i1_is_minus && i2_is_minus) sprintf(result, "%d", -i1 - i2);
    if(result[0] == '-') { 
        printf("-");
        length = strlen(result + 1);
        minus = true;
    } else {
        length = strlen(result);
    }
    for(int i = 0; i < length; i++) {
        if((length - i) % 3 == 0 && i != 0) printf(",");
        printf("%c", result[i+minus]);
    }

    return 0;
}
