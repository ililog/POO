#include<stdio.h>

int string_to_number(const char *str) {
    int i = 0;
    int suma = 0;
    int semn = 1;
    if (str[0] == '-') {
        semn = -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0') {
        suma = suma * 10 + str[i] - '0';
        i++;
    }
    return suma*semn;
}

int main() {
    FILE *file;
    char buffer[256];

    file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("Eroare la deschiderea fisierului\n");
        return 1;
    }
    int sum = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        sum += string_to_number(buffer);
    }
    printf("%d\n", sum);
    fclose(file);
    return 0;
}