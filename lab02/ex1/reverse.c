#include <stdio.h>
#include <time.h>

void reverse(FILE* input_file, FILE* output_file) {
    fseek(input_file, -1, SEEK_END);
    long bytes_to_read = ftell(input_file) + 1;

    while (bytes_to_read > 0) {
        fprintf(output_file, "%c", getc(input_file));
        bytes_to_read--;
        fseek(input_file, -2, SEEK_CUR);
    }
}

void reverse1024(FILE* input_file, FILE* output_file) {
    int buffer_size = 1024;
    char buffer[1024];
    fseek(input_file, 0, SEEK_END);
    long bytes_to_read = ftell(input_file);

    while (bytes_to_read > 0) {
        int currently_reading = bytes_to_read > buffer_size ? buffer_size : bytes_to_read;
        bytes_to_read -= currently_reading;
        fseek(input_file, bytes_to_read, SEEK_SET);
        fread(buffer, sizeof(char), currently_reading, input_file);

        for (int i = 0; i < currently_reading / 2; i++) {
            char temp = buffer[i];
            buffer[i] = buffer[currently_reading - i - 1];
            buffer[currently_reading - i - 1] = temp;
        }
        fwrite(buffer, sizeof(char), currently_reading, output_file);
    }
}

int main(int argc, char** argv) {
    FILE* input_file = fopen(argv[1], "r");
    FILE* output_file = fopen(argv[2], "w");
    FILE* time_file = fopen("files/pomiar_zad_2.txt", "w");

    if (input_file == NULL || output_file == NULL || time_file == NULL) {
        printf("Cannot open files!\n");
        return 1;
    }

    clock_t start, end;
    double cpu_time_used;

    //reverse
    start = clock();
    reverse(input_file, output_file);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(time_file, "Czas wykonania funkcji reverse: %f sekund\n", cpu_time_used);


    //reverse1024
    start = clock();
    reverse1024(input_file, output_file);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(time_file, "Czas wykonania funkcji reverse1024: %f sekund\n", cpu_time_used);

    fclose(input_file);
    fclose(output_file);
    fclose(time_file);
}
