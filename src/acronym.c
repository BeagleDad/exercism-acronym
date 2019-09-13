#include "acronym.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <stdio.h> //todo: remove
char *buildAcronym(const char *phrase);

/**
 * @brief Builds acronym from a phrase
 * 
 * @param phrase - the phrase to use
 * @return char* - acronym string
 */
char *buildAcronym(const char *phrase)
{
    char *phrase_copy = malloc(strlen(phrase) * sizeof(char));

    char *acronym = malloc(strlen(phrase) * sizeof(char));

    // Need to copy input phrase because strtok modifies it, and it is const.
    strcpy(phrase_copy, phrase);
    // Set the delimeters to use for tokenizer
    const char *delims = ",- ";
    // Use to Count the tokens
    int token_count = 0;
    char *token = strtok(phrase_copy, delims);
    while (token)
    {
        //Build the acronym using first letter of each token, converted to upper case.
        acronym[token_count] = toupper(*token);
        ++token_count;
        token = strtok(NULL, delims);
    }

    // Make sure acronym is null terminated
    acronym[token_count] = 0;

    // // Allocate space to return a copy of the acronym. (can't return a local variable)
    // // Use calloc to insure zero termination by adding 1 to token count.
    // char *acronym = calloc(token_count + 1, sizeof(char));
    // strncpy(acronym, acronym, token_count);

    // Clean up
    free(phrase_copy);
    //printf("Tokens: %d\n", token_count);
    // printf("Acronym: %s\n", acronym);
    return acronym;
}
char *abbreviate(const char *phrase)
{
    // Check to see if NULL was passed and and return NULL (Can't make a TLA from nothing)
    if (phrase == NULL || strlen(phrase) == 0)
    {
        return NULL;
    }
    return buildAcronym(phrase);
}
