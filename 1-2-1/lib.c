#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static WORD *word_list = NULL;

void add_word(WORD_TYPE type, char *word) {
  WORD *wp;

  if (lookup_word(word) != LOOKUP) {
    printf("!!! warning: word %s already defined \n", word);
    return;
  }

  /* word no there, allocate a new entry and link it on the list */

  wp = (WORD *)malloc(sizeof(WORD));
  wp->next = word_list;

  /* have to copy the word itself as well */
  wp->word_name = strdup(word);
  wp->word_type = type;
  word_list = wp;
}

/*
 * LOOKUP: not found
 * else: word_type
 */
WORD_TYPE lookup_word(char *word) {
  /* search down the list looking for the word */
  for (WORD *wp = word_list; wp; wp = wp->next)
    if (strcmp(wp->word_name, word) == 0)
      return wp->word_type;

  return LOOKUP; /* not found */
}
