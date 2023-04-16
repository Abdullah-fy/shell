#include "main.h"

ssize_t read_input(char **lineptr, size_t *n)
{
        ssize_t nchars_read;

        /*stdio.h*/
        nchars_read = getline(lineptr, n, stdin);

        /*
            What happened with the getline?
            is that it copied what the person typed into our lineptr variable.
            Therefore to print out what was type,
            we just need to print what lineptr contains (technically,
            what it is pointing to)
        */

        if (nchars_read == -1)
        {
            printf("Exiting shell....\n");
            free(*lineptr);
            *lineptr = NULL;
            *n = 0;
        }

        return nchars_read;
}
