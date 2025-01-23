#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_NUMBERS 1000000

void check_duplicates_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }

    int numbers[MAX_NUMBERS];
    int count = 0;
    while (fscanf(file, "%d", &numbers[count]) == 1) {
        count++;
    }
    fclose(file);

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] == numbers[j]) {
                printf("There are duplicate numbers in the file %s.\n", filename);
                return;
            }
        }
    }

    printf("No duplicate numbers found in the file %s.\n", filename);
}

int main() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG) { // Only process regular files
                const char *ext = strstr(dir->d_name, "result");
                if (!ext || strcmp(ext, "result") != 0) {
                    check_duplicates_in_file(dir->d_name);
                }
            }
        }
        closedir(d);
    } else {
        perror("Directory opening failed");
        return 1;
    }

    return 0;
}
