/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "dictionary.h"

// declare struct
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *tree[26];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // load dictionary file
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Cannot load %s\n", dictionary);
        return false;
    }
    
    // init temporary storage
    char temp[LENGTH + 1];
    
    for(int j = 0; j < 26; j++)
    {
        tree[j] = malloc(sizeof(node));
        tree[j]->next = NULL;
    }
    
    // loop for iterating over each line in inptr
    while(fscanf(inptr, "%s", temp) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        
        // check for NULL
        if (new_node == NULL)
        {
            fclose(inptr);
            unload();
            return false;
        }
        
        // put the word
        strcpy(new_node->word, temp);
        
        // insert a node
        int C = (temp[0] - 97);
        node *TEMP;
        TEMP = tree[C]->next;
        tree[C]->next = new_node;
        new_node->next = TEMP;
        
            
    }
    // close the file
    fclose(inptr);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{  
  
    for(int i = 0; i < 26; i++)
    {
        node *cursor = tree[i]->next;
        while(cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    
    for(int j = 0; j < 26; j++)
    {
        free(tree[j]);
    }
    
    return true;
}
