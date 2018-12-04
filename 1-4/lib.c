#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

typedef struct word {
  int word_type;
  char *word_name;
  struct word *next;
} WORD;

WORD *word_list = NULL;

/*
 * 0: already defined.
 * 1: worked.
 */
int
add_word(int type, char *word)
{
  WORD *wp;

  if(lookup_word(word) != LOOKUP) {
    return 0;
  }

  /* word no there, allocate a new entry and link it on the list */

  wp = (WORD *)malloc(sizeof(WORD));
  wp->next = word_list;

  /* have to copy the word itself as well */
  wp->word_name = (char *)malloc(strlen(word)+1);
  strcpy(wp->word_name, word);
  wp->word_type = type;
  word_list = wp;
  return 1; /* it worked */
}

/*
 * LOOKUP: not found
 * else: word_type
 */
int
lookup_word(char *word)
{
  /* search down the list looking for the word */
  for(WORD *wp = word_list; wp; wp = wp->next) 
    if(strcmp(wp->word_name, word) == 0)
      return wp->word_type;
  
  return LOOKUP; /* not found */
}
