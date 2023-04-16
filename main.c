#include "main.h"

int main(int ac, char **argv)
{
    /*
        ► lineptr: used to store the address of the buffer
        that will hold the line read from the input stream
        ► lineptr_copy: used to hold copy of string to be
        passed to "strtok" function
    */
    char *lineptr = NULL, *lineptr_copy = NULL;

    /*
        size of the buffer which pointed to lineptr
        used to return number of chars read by getline
        ► unsigned can only represent non negative values
    */
    size_t n = 0;

    /*signed represent negative value need unistd*/
    ssize_t nchars_read;

    char *token;

    int num_tokens = 0, i;

    /*
        string contain characters that function "strtok will use
        to spilt the string into tokens
    */
    const char *delim = " \n";

    /*to avoid warning of unused arguments cast then to void*/
    (void)ac;

    while (1)
    {
        /*function to print the prompt*/
        print_prompt();

        nchars_read = read_input(&lineptr, &n);

        if (nchars_read == -1)
        {
            return (-1);
        }

        /* allocate space for a copy of the lineptr */
        lineptr_copy = malloc(sizeof(char) * nchars_read);

        /*if memory for coping string return null then there is an error*/
        if (lineptr_copy == NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }

        /* copy lineptr to lineptr_copy */
        strcpy(lineptr_copy, lineptr);

        /* split the string (lineptr) into an array of words */
        token = strtok(lineptr, delim);

        /* determine how many tokens are there*/
        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        /*
            because will be stored in argv means array of string
            so must last char is null = '\0'
        */
        num_tokens++;

        /*
            now use argv to allocate memory for tokens
            so we have to delete casting to void from
            the beginning of the program because we find
            use to it now
        */
        argv = malloc(sizeof(char *) * num_tokens);

        /*
            After determining the number of tokens in the input line,
            the program needs to actually split the line into separate tokens
            and store them in an array. However, the original lineptr variable
            has been modified by the strtok() function
            in order to count the number of tokens.
            Therefore, the program needs to make a copy of lineptr
            in order to actually split it into tokens.
        */
        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        /*last index \0*/
        argv[i] = NULL;

        execmd(argv);

        /*printf("%s\n", lineptr);*/

        /*stdlib.h*/
        free(lineptr);
        free(lineptr_copy);
        lineptr = NULL;
        n = 0;
}

    return (0);
}
