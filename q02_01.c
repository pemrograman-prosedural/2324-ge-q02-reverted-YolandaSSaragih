// 12S23034 - PARIAMA MARKUS
// 12S23050 - YOLANDA SEPTANIA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"

int main() {
    char input[75];
    int zdrm = 0;
    int size = 0;
    struct dorm_t *drm = NULL; 
    int zstd = 0;
    int sizee = 0;
    struct student_t *mhs = NULL;
    char *token;

    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\r\n")] = '\0';

        token = strtok(input, "#");
        if (strcmp(token, "---") == 0) {
            break;
        } else if (strcmp(token, "dorm-add") == 0) {
            size++;
            drm = realloc(drm, size * sizeof(struct dorm_t));
            drm[zdrm] = create_dorm(input);
            zdrm++;
        } else if (strcmp(token, "dorm-print-all") == 0) {
            for (int m = 0; m < zdrm; m++) {
                print_dorm(drm[m]);
            }
        } else if (strcmp(token, "dorm-print-all-detail") == 0) {
            for (int m = 0; m < zdrm; m++) {
                print_dorm_detail(drm[m]);
            }
        } else if (strcmp(token, "student-add") == 0) {
            sizee++;
            char nim[10], name[25], year[6];
            int gender = 0;
            mhs = realloc(mhs, sizee * sizeof(struct student_t));
            mhs[zstd] = create_student(nim, name, year, gender);
            zstd++;
        } else if (strcmp(token, "student-print-all") == 0) {
            for (int m = 0; m < zstd; m++) {
                print_student(mhs[m]);
            }
        } else if (strcmp(token, "student-print-all-detail") == 0) {
            for (int m = 0; m < zstd; m++) {
                print_student_detail(mhs[m]);
            }
        } else if (strcmp(token, "assign-student") == 0) {
            char *nim = strtok(NULL, "#");
            char *asrama = strtok(NULL, "#");
            assign_student(mhs, nim, asrama, zstd, zdrm, find_id);
        } else if (strcmp(token, "move-student") == 0) {
            char *nim = strtok(NULL, "#");
            char *asrama = strtok(NULL, "#");
            move_student(mhs, nim, asrama, zstd, zdrm, find_id);
        } else if (strcmp(token, "dorm-empty") == 0) {
            char *asrama = strtok(NULL, "#");
            dorm_empty(asrama, zstd, zdrm, mhs);
        }
    }
    free(mhs);
    free(drm);

    return 0;
}
