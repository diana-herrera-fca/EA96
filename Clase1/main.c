#include <stdio.h>

int main(void) {
    char s[100];
    printf("Escribe tu nombre: \n");
    scanf("%[^\n]%*c", &s);
    printf("Hola, %s!", &s);
    return 0;
}