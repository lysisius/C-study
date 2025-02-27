#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test_defs.h"


basic_errs_e get_count2(char *buf, char *key)
{
    char *kw_ptr;
    int retstats = NO_ERR;

    if ((kw_ptr=strstr(buf, key))==NULL) {
        retstats = KW_NOT_FOUND;
    } else {
        int result; /* conversion result */
        if ((result=atoi(kw_ptr))==0) {
            while (result==0 && *kw_ptr!='\n') {
                result = atoi(++kw_ptr);
            }
        }
        printf("result is: %d\n", result);
    }

    return retstats;
}

basic_errs_e get_count(char *buf)
{
    char kw[] ="Total-Patterns";
    char *kw_ptr;
    int retstats = NO_ERR;
    
    if ((kw_ptr=strstr(buf, kw))==NULL) {
        retstats = KW_NOT_FOUND;
    } else {
        char d[] = "0123456789";
        char *d_ptr;

        printf("kw_ptr is %s\n", kw_ptr);
        if((d_ptr=strpbrk (kw_ptr, d))==NULL) {
            retstats = NUM_NOT_FOUND;
        } else {
            while ((d_ptr!=NULL)) {
                putchar((char)*d_ptr);
                //if ((*(d_ptr+1)=='\n') || (*(d_ptr+1)==EOF)) {
                if (*(d_ptr+1)=='\n') {  //XXX: EOF check is not useful here because EOF won't be in the memory
                    break; /* already found */
                }
                d_ptr = strpbrk(d_ptr+1, d);
            }
            putchar('\n');
        }
    }
    return retstats;
}

int main()
{
    FILE *file;
    basic_errs_e retstats = NO_ERR;
    
    if ((file=fopen("./test.txt", "r"))==NULL) {
    //if ((file=fopen("./atoi_test.c", "r"))==NULL) {
        retstats = FOPEN_ERR;
    } else {
        long lSize;

        fseek(file, 0, SEEK_END);
        lSize = ftell(file);
        if (lSize < 0) {
            retstats = FTELL_ERR;
        } else {
            char *buf;

            if ((buf=malloc(sizeof(char)*lSize+1))==NULL) {
                retstats = MALLOC_ERR;
            } else {
                int readByte;

                rewind(file);
                if ((readByte=fread(buf, sizeof(char), lSize, file))!=lSize) {
                    retstats = FREAD_ERR;
                } else {
                    //retstats = get_count(buf);
                    //retstats = get_count2(buf, "Cate");
                    retstats = get_count2(buf, "Patte");
                }
                free(buf);
            }
        }
        fclose(file);
    }

    if (retstats) printf("err is %d\n", retstats);

    return retstats;
}


