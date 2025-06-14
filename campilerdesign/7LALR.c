//vi lalr.l
//vi lalr.y
//yacc -d lalr.y
//lex lalr.l
// gcc y.tab.c lex.yy.c -o lalr
//./lalr
//Enter production rules (e.g., S -> A B):
//S -> L e R
//S -> R
//L -> S R
//L -> id
//R -> L

//Enter a string to check:
//idid
//ACCEPTED


//lalr.y

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char*);
int yylex();

typedef struct Rule {
    char* lhs;
    char* rhs[10];
    int rhs_count;
} Rule;

Rule rules[100];
int rule_count = 0;
char* start_symbol = NULL;

char* input_string = NULL;
int input_pos = 0;
char* rhs_symbols[100];
int rhs_index = 0;

// Function to match rule
int match(char* symbol);
%}

%union {
    char* str;
}

%token <str> ID
%token ARROW

%%

input:
    productions
    ;

productions:
    production productions
    |
    ;

production:
    ID ARROW rhs '\n'
    {
        rules[rule_count].lhs = $1;
        rules[rule_count].rhs_count = 0;
        for (int i = 0; i < rhs_index; i++) {
            rules[rule_count].rhs[i] = rhs_symbols[i];
        }
        rules[rule_count].rhs_count = rhs_index;
        rhs_index = 0;
        if (rule_count == 0)
            start_symbol = $1;
        rule_count++;
    }
    ;

rhs:
    ID
    {
        rhs_symbols[rhs_index++] = $1;
    }
    |
    rhs ID
    {
        rhs_symbols[rhs_index++] = $2;
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Parse Error: %s\n", s);
}

// Check if symbol is non-terminal
int is_non_terminal(char* symbol) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].lhs, symbol) == 0) return 1;
    }
    return 0;
}

// Try to match input string starting from a symbol
int match(char* symbol) {
    if (!is_non_terminal(symbol)) {
        int len = strlen(symbol);
        if (strncmp(&input_string[input_pos], symbol, len) == 0) {
            input_pos += len;
            return 1;
        } else {
            return 0;
        }
    }

    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].lhs, symbol) == 0) {
            int backup = input_pos;
            int success = 1;
            for (int j = 0; j < rules[i].rhs_count; j++) {
                if (!match(rules[i].rhs[j])) {
                    success = 0;
                    break;
                }
            }
            if (success) return 1;
            input_pos = backup; // backtrack
        }
    }
    return 0;
}

int main() {
    printf("Enter production rules (e.g., S -> A B):\n");
    yyparse();

    printf("Enter a string to check:\n");
    char buffer[1000];
    scanf("%s", buffer);
    input_string = buffer;
    input_pos = 0;

    int result = match(start_symbol);
    if (result && input_pos == strlen(input_string)) {
        printf("ACCEPTED\n");
    } else {
        printf("REJECTED\n");
    }

    return 0;
}

    


//lalr.l

%{
#include "y.tab.h"
%}

%%
"->"              { return ARROW; }
[a-zA-Z=\*]+         { yylval.str = strdup(yytext); return ID; }
[ \t\r]+          ;
\n                { return '\n'; }
.                 { return yytext[0]; }
%%
int yywrap() { return 1; }

chk1.l