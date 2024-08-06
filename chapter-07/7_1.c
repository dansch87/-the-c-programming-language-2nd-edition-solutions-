#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char **argv) {

    int c;
    
    // check if "lower" or "upper" is used as cmd    
    if ((strcmp(argv[0], "lower") != 0) && (strcmp(argv[0], "upper") != 0)) {
        fprintf(stderr, "%s is wrong command. Must be \"lower\" or \"upper\".\n", argv[0]);
        return 1;
    }
    
    // convert characters
    while ((c = getchar()) != EOF) {
        if (strcmp(argv[0], "lower") == 0) {
            putchar(tolower(c));
        } 
        if (strcmp(argv[0], "upper") == 0) {
            putchar(toupper(c));
        }
    }
    
    return 0;
}
