#include <stdio.h>

int summ_num(int num)
{
    if (num == 0) {
        return 0;
    }
    return num % 10 + summ_num(num / 10);
}
int num_check(int num)
{
    if (num == 0) {
        return 1;
    }
    if (num % 10 != 3 && num % 10 != 7) {
        return 0;
    }
    return num_check(num / 10);
}

int main() {
    int num = 1;
    while (1) {
        if (num_check(num) && summ_num(num) % 3 == 0 && summ_num(num) % 7 == 0) {
            printf("result: %d\n", num);
            break;
        }
        num++;
    }

    return 0;
}

