#include "dorm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct dorm_t create_dorm(char *input) {
    struct dorm_t dorm;
    strcpy(dorm.name, strtok(NULL, "#"));
    dorm.capacity = atoi(strtok(NULL, "#"));
    char *gender_str = strtok(NULL, "#");
    if (strcmp(gender_str, "male") == 0) {
        dorm.gender = GENDER_MALE;
    } else if (strcmp(gender_str, "female") == 0) {
        dorm.gender = GENDER_FEMALE;
    }
    dorm.residents_num = 0;
    return dorm;
}

void print_dorm(struct dorm_t dorm) {
    printf("%s|%hu|", dorm.name, dorm.capacity);
    if (dorm.gender == GENDER_MALE) {
        printf("male\n");
    } else if (dorm.gender == GENDER_FEMALE) {
        printf("female\n");
    }
}

void print_dorm_detail(struct dorm_t dorm) {
    printf("%s|%hu|", dorm.name, dorm.capacity);
    if (dorm.gender == GENDER_MALE) {
        printf("male|");
    } else if (dorm.gender == GENDER_FEMALE) {
        printf("female|");
    }
    printf("%hu\n", dorm.residents_num);
}

int find_dorm(char *asrama, int zdrm, struct dorm_t *dorm) {
    int found_dorm = -1;
    for (int i = 0; i < zdrm; i++) {
        if (strcmp(asrama, dorm[i].name) == 0) {
            found_dorm = i;
            break;
        }
    }
    return found_dorm;
}
