#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h" // Jika diperlukan

struct student_t {
    char nim[10];
    char name[25];
    char year[6];
    enum gender_t gender;
};

struct student_t create_student(char *nim, char *name, char *year, int gender);
void print_student(struct student_t mhs);
void print_student_detail(struct student_t mhs);
void assign_student(struct student_t *mhs, char *nim, char *asrama, int zstd, int zdrm, int (*find_id)(char *, int, struct student_t *));
void move_student(struct student_t *mhs, char *nim, char *asrama, int zstd, int zdrm, int (*find_id)(char *, int, struct student_t *));
void dorm_empty(char *asrama, int zstd, int zdrm, struct student_t *mhs);
int find_id(char *nim, int zstd, struct student_t *mhs);

#endif /* STUDENT_H */
