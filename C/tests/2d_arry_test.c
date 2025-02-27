/* how to create and clean-up the 2d array '\0' */
/*  */
/* the difference between strcpy and stpcpy. i like stpcpy better because the
 * return is more useful (the last char) */
/* strlen doesn't consider the '\0' */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERR -1
int main(int argc, char* argv[])
{
    char **list_p;
    int list_size = argc;
    int str_len = 80;

    if ((list_p=malloc(sizeof(char *)*list_size))==NULL) { //10 string list
        //malloc failed
    } else {
        int ret = OK;
        int i = 0;

        for (; i<list_size; i++) {
            list_p[i] = malloc(sizeof(char)*str_len); //including \0
            if (list_p[i]==NULL) {
                //malloc failed
                break;
            }
        }
        
        if (i<list_size) {
            /* clean up */
            for (i-1; i>=0; i--) {
                free(list_p[i]);
            }
        } else {
            char *end_p = NULL;
            for (i=0; i<list_size; i++) {
                //end_p = strncpy(list_p[i], argv[i], str_len);
                end_p = stpncpy(list_p[i], argv[i], str_len);
                printf("end_p's int value is %d\n", *end_p);
                printf("strnlen list_p[i] is %ld\n", strnlen(list_p[i], str_len));
                list_p[i][str_len-1] = '\0';
            }

            for (i=0; i<list_size; i++) {
                printf("[%d]: %s, ", i, list_p[i]);
            }
            printf("\n");


            /* clean up */
            for (; i>0; i--) { 
                free(list_p[i-1]); 
            }
        }
        free(list_p);
    }
}

