#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
#include "main.h"

static struct {
  char **list;
  unsigned int current; /* 0 .. (length-1) */
  unsigned int length;
} files;

unsigned long int totalCC = 0;
unsigned long int totalWC = 0;
unsigned long int totalLC = 0;

int
main(int argc, char* argv[])
{
  FILE *file = NULL;
  
  files.list = argv + 1;
  files.current = 0;
  files.length = argc - 1;

  switch (files.length) {
  case 0:
    // yyin = stdin; 
    break;
  case 1:
    /* we handle the single file case differently from 
     * the multiple file case since we don't need to
     * print a summary line
     */
    file = fopen(files.list[files.current], "r");
    if(!file) {
      fprintf(stderr, "could not open %s\n", files.list[files.current]);
      return EXIT_FAILURE;
    }
    yyin = file;
    break;
  default: // multi-file
    for(unsigned int i = 0; i < files.length; i++) {
      file = fopen(files.list[i], "r");
      if(!file) {
	fprintf(stderr, "could not open %s\n", files.list[i]);
	continue;
      }
      yyin = file;
      files.current = i;
      break;
    }
    if(!file) { /* ひとつも処理すべきファイルがなかった場合 */
      printf("%8lu %8lu %8lu total\n", 0lu, 0lu, 0lu);
      return EXIT_FAILURE;
    }
    break;
  }
  
  yylex();

  if( files.length >= 2 ) {
    totalCC += charCount;
    totalWC += wordCount;
    totalLC += lineCount;

    printf("%8lu %8lu %8lu total\n", totalLC, totalWC, totalCC);
  }
  
  return EXIT_SUCCESS;
}

/*
 * the lexer calls yywrap to handle EOF conditions (e.g., to
 * connect to a new file, as we do in this case.)
 */
int
yywrap(void)
{
  FILE *file = NULL;

  /* done with the file */
  fclose(yyin);
  
  /* 
   * 結果出力
   * ファイルを引数で与えられた場合、その処理したそのファイル名を添えて
   * 出力する。
   */
  switch (files.length) {
  case 0:
    printf("%8lu %8lu %8lu\n", lineCount, wordCount, charCount);
    break;
  default:
    printf("%8lu %8lu %8lu %s\n", lineCount, wordCount, charCount,
	   files.list[files.current]);
  }

  /* 総カウンターへの積み上げとカウンタの初期化 */
  totalCC += charCount;
  totalWC += wordCount;
  totalLC += lineCount;
  charCount = wordCount = lineCount = 0;

  /* 次に処理するファイルのオープン処理 */
  for (unsigned int i = files.current + 1; i < files.length; i++) {
    file = fopen(files.list[i], "r");
    if(!file) {
      fprintf(stderr,"could not open %s\n", files.list[i]);
      continue;
    }
    yyin = file;
    files.current = i;
  }
      
  return (file ? 0 : 1); /* 0 means there's more input */
}
