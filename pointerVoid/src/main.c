// C_BEG
#include <stdio.h>
#include <stdlib.h>
#include "cbase/log.h"

#undef LOG_LVL
#define LOG_LVL LOG_LVL_ERROR

void * create_str(void *);

int main() {
    char letter_1 = 'w';
    char letter_2 = 'g';

    char * w3 = (char *)create_str(&letter_1);
    void * g3 = create_str(&letter_2);

    printf("Знаем тип: %s\n", w3);
    printf("Не знаем тип: %s\n", (char *)g3);

}

void * create_str(void * cv) {
    char c = *(char *)cv; // 1

    char * result  = malloc(sizeof(char) * 4);
    result[0] = result[1] = result[2] = c; 
    result[3] = '\0';

    return (void*)result; // 3
}