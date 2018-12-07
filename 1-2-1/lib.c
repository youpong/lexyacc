#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static WORD *word_list = NULL;

void add_word(WORD_TYPE type, char *name) {
  WORD *wp;

  if (lookup_word(name) != LOOKUP) {
    printf("!!! warning: word %s already defined \n", name);
    return;
  }

  /* word no there, allocate a new entry and link it on the list */

  wp = (WORD *)malloc(sizeof(WORD));
  wp->next = word_list;

  /* have to copy the word itself as well */
  wp->name = strdup(name);
  wp->type = type;
  word_list = wp;
}

/*
 * LOOKUP: not found
 * else: word_type
 */
WORD_TYPE lookup_word(char *name) {
  /* search down the list looking for the word */
  for (WORD *wp = word_list; wp; wp = wp->next)
    if (strcmp(wp->name, name) == 0)
      return wp->type;

  return LOOKUP; /* not found */
}
