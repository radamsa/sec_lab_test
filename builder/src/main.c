// Sample application

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096

void encode(char* source_name, char* target_name) {
    printf("Encode: %s --> %s\n", source_name, target_name);

    FILE* fsrc = fopen(source_name, "rb");
    if (NULL == fsrc) {
        perror("Can't open input file");
        return;
    }

    FILE* fdst = fopen(target_name, "wb");
    if (NULL == fdst) {
        perror("Can't create output file");
        fclose(fsrc);
        return;
    }

    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];
    int len;
    do {
        len = fread(input_buffer, sizeof(char), BUFFER_SIZE, fsrc);
        if (len < BUFFER_SIZE && ferror(fsrc)) {
            perror("\nRead failed");
            break;
        }

        // TODO encode buffer
        memcpy(output_buffer, input_buffer, BUFFER_SIZE);

        int written = fwrite(output_buffer, sizeof(char), len, fdst);
        if (written < BUFFER_SIZE && ferror(fdst)) {
            perror("\nWrite failed");
            break;
        }
    } while(len == BUFFER_SIZE);

    fclose(fsrc);
    fclose(fdst);
}

void decode(char* source_name, char* target_name) {
    printf("Decode: %s --> %s\n", source_name, target_name);

    FILE* fsrc = fopen(source_name, "rb");
    if (NULL == fsrc) {
        perror("Can't open input file");
        return;
    }

    FILE* fdst = fopen(target_name, "wb");
    if (NULL == fdst) {
        perror("Can't create output file");
        fclose(fsrc);
        return;
    }

    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];
    int len;
    do {
        len = fread(input_buffer, sizeof(char), BUFFER_SIZE, fsrc);
        if (len < BUFFER_SIZE && ferror(fsrc)) {
            perror("Read failed");
            break;
        }

        // TODO decode buffer
        memcpy(output_buffer, input_buffer, BUFFER_SIZE);

        int written = fwrite(output_buffer, sizeof(char), len, fdst);
        if (written < BUFFER_SIZE && ferror(fdst)) {
            perror("Write failed");
            break;
        }
    } while(len == BUFFER_SIZE);

    fclose(fsrc);
    fclose(fdst);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Invalid argument list\n");
        return -1;
    }

    if (argv[1][0] == 'e') {
        encode(argv[2], argv[3]);
    } else if (argv[1][0] == 'd') {
        decode(argv[2], argv[3]);
    } else {
        printf("Invalid command\n");
        return -1;
    }

    return 0;
}
