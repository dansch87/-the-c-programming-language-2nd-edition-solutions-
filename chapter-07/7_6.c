#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* EXERCISE
 * Write a program to compare two files, printing the first line where they differ.
 *
 * QUESTIONS
 * - getline() saves '\n' character to line buffer; is it possible to change that behaviour?
 *
 * TODO:
 * - handling newline character differently, so that the difference is showed in oneline
 * */


int main(int argc, char **argv) {


    FILE *fp1, *fp2;
    char *file1, *file2;
    char *line1, *line2;
    ssize_t nread1, nread2;
    size_t len = 0;
    int files_equal;
    int line_count = 0;
    char *prog = *argv;

    // check if enough arguments are served to command
    if (argc != 3) {
        fprintf(stderr, "%s: Not enough arguments. Two files are expected as command arguments.\n", prog);
        exit(EXIT_FAILURE);
    }

    file1 = *++argv;
    file2 = *++argv;

    // read files
    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        fprintf(stderr, "%s: Couldn't read file %s\n", prog, *argv);
        exit(2);
    }
    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        fprintf(stderr, "%s: Couldn't read file %s\n", prog, *argv);
        exit(3);
    }

    while (1) {
       ++line_count;
      
       if (nread1 = getline(&line1, &len, fp1) == -1) {
           line1 = "\n";
       }

       if (nread2 = getline(&line2, &len, fp2) == -1) {
           line2 = "\n";
       }

       files_equal = strcmp(line1, line2);
       if (files_equal != 0) {
           printf("lines are unequal:\n");
           printf("%s: %s", file1, line1);
           printf("%s: %s", file2, line2);
           break;
       }
    } 

    // close files
    fclose(fp1);
    fclose(fp2);

    exit(0);
}
