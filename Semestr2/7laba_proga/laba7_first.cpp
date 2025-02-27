#include <stdio.h>
#include <string.h>

void (*P1(void(*ff)(void))) (void) {
    return ff;
}

void god(void) {
    printf("I'm God\n");
}

int main() {
    (*P1(god))();
}