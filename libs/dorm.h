#ifndef DORM_H
#define DORM_H

#include "gender.h"

struct dorm_t {
    char name[20];
    unsigned short capacity;
    enum gender_t gender;
    unsigned short residents_num;
};

struct dorm_t create_dorm(char *input);
void print_dorm(struct dorm_t dorm);
void print_dorm_detail(struct dorm_t dorm);
int find_dorm(char *asrama, int zdrm, struct dorm_t *dorm);

#endif
