#ifndef GENDER_H
#define GENDER_H

enum gender_t
{
    GENDER_MALE,
    GENDER_FEMALE
};


struct student_t create_student(char *input);
void print_student(struct student_t mhs);
void print_student_detail(struct student_t mhs);
void assign_student(struct student_t *mhs, char *nim, char *asrama, int zstd, int zdrm, int find_id(char *nim, int zstd, struct student_t *mhs));
int find_id(char *nim, int zstd, struct student_t *mhs);
void move_student(struct student_t *mhs, char *nim, char *asrama, int zstd, int zdrm, int find_id(char *nim, int zstd, struct student_t *mhs));
void dorm_empty(char *asrama, int zstd, int zdrm, struct student_t *mhs);

#endif
