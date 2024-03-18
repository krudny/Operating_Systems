#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(void) {
    DIR *dir;
    struct dirent *entry;
    struct stat buf;
    long long totalSize = 0;
    FILE *output_file;

    output_file = fopen("results.txt", "w");
    if (output_file == NULL) {
        printf("Cannot open file! \n");
        return 1;
    }

    dir = opendir(".");
    if (dir == NULL) {
        fprintf(output_file, "Cannot open directory!\n");
        fclose(output_file);
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        stat(entry->d_name, &buf);

        if (!S_ISDIR(buf.st_mode)) {
            fprintf(output_file, "Size: %lld, Name: %s\n", (long long)buf.st_size, entry->d_name);
            totalSize += buf.st_size;
        }
    }

    fprintf(output_file, "Total size of files: %lld\n", totalSize);

    closedir(dir);
    fclose(output_file);

    return 0;
}