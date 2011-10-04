#include <stdio.h>
#include <stdlib.h>

int hashing (char* input);

int main(int argc, char* argv[])
{
    int i = 0;

    if (argc != 2) {perror("invalid input\n"); exit(0);}

    for (i=0; i<argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    printf("the hash of %s is %d\n", argv[1], hash(argv[1], 7));


    return 0;
}

