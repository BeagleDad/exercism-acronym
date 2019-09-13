#include "acronym.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// uncomment to disable assert()
// #define NDEBUG
#include <assert.h>

/**
 * @brief Creates an acronym given a phrase with words separated by space, comma, or hyphen
 * 
 * NOTE: caller is responsible for FREEing the memory allocated in this function for the acronym.
 * 
 * @param phrase  The phrase to convert to an acronym
 * @return char*  Pointer to the acronym (NULL terminated string)
 */
char *abbreviate(const char *phrase)
{
    // Check to see if phrase is NULL or empty string (Can't make a acronym from nothing)
    if (phrase == NULL || strlen(phrase) == 0)
    {
        return NULL;
    }

    // Need to make a copy of input phrase as it is declared const and strtok modifies it.
    char *phrase_copy = malloc(strlen(phrase) * sizeof(char));
    // Check if malloc succeeded
    assert(phrase_copy != NULL);
    // Make the copy
    strcpy(phrase_copy, phrase);

    // Allocate room for one letter of acronym. It will be expanded as it is built
    char *acronym = calloc(sizeof(char), sizeof(char));
    // Check if calloc succeeded
    assert(acronym != NULL);

    // Set the delimeters to use for tokenizer
    const char *delims = ",- ";

    // Use to Count the tokens
    int token_count = 0;

    char *token = strtok(phrase_copy, delims);
    while (token)
    {
        //Build the acronym using first letter of each token, converted to upper case.
        acronym[token_count] = toupper(*token);

        // Allocate space for next character of acronym, or NULL terminator if there are no more tokens.
        acronym = realloc(acronym, sizeof(char));
        // Check if realloc succeeded
        assert(acronym != NULL);

        ++token_count;
        token = strtok(NULL, delims);
    }

    // Make sure acronym is null terminated
    acronym[token_count] = 0;

    // Clean up
    free(phrase_copy);
    phrase_copy = NULL;

    return acronym;
}
