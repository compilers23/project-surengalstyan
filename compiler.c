#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void compileToken(FILE *out, const char *token) {
    if (isdigit(token[0])) {
        fprintf(out, "  push $%s\n", token);
    } else if (strcmp(token, "+") == 0) {
        fprintf(out, "  pop %%rbx\n  pop %%rax\n  add %%rax, %%rbx\n  push %%rbx\n");
    } else if (strcmp(token, ".s") == 0) {
        fprintf(out, "  call _print\n");
    }
    // Other cases gose here....
}

int main(int argc, char *argv[]) {

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        perror("Cant open file");
        return 1;
    }

    FILE *out = fopen(argv[2], "w");
    if (!out) {
        perror("cant open file");
        fclose(in);
        return 1;
    }

    fprintf(out, ".globl _main\n_main:\n");

    char token[100];
    while (fscanf(in, "%99s", token) == 1) {  // fscanf reads formatted input
        compileToken(out, token);
    }

    fprintf(out, "  mov $60, %%rax\n  xor %%rdi, %%rdi\n  syscall\n");

    fclose(in);
    fclose(out);
    return 0;
}
