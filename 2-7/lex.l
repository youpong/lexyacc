%{
int comments, code, whiteSpace;
%}

%option nounput noinput

%s COMMENT

%%
^[ \t]*"/*"               { BEGIN COMMENT; /* enter comment eating state */ }
^[ \t]*"/*".*"*/"[ \t]*\n {
   		   	  comments++; /* self-contained comment */
			  }
<COMMENT>"*/"[ \t]*\n     { BEGIN 0; comments++; }
<COMMENT>"*/"             { BEGIN 0; }
<COMMENT>\n		  { comments++; }
<COMMENT>.\n		  { comments++; /* need . ? */}
^[ \t]*\n		  { whiteSpace++; }
.+"/*".*"*/".*\n	  { code++; }
.*"/*".*"*/".+\n	  { code++; }
.+"/*".*\n		  { code++; BEGIN COMMENT; }
.\n			  { code++; /* need .? */}

.			  ; /* ignore everything else */
%%

