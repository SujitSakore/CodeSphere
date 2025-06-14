
//vi condition_token_recognition.l
//flex condition_token_recognition.l
//gcc lex.yy.c -o abc -lfl
//./abc

//Input:
//if a > b then c

//Output:
//<IF><ID, 1><RELOP, GT><ID, 2><THEN><ID, 3>



%{

#include<stdio.h>

int installID(char []);
int installNumber(char []);
void printSymbolTable();

#define SIZE 1000
#define maxIDLen 1024

static int id_count=0;

char symbolTableID[SIZE][maxIDLen];
char symbolTableNum[SIZE][20];


%}
ws [ \t\n]+
number [+-]?[0-9]+(\.[0-9]+)?(E[+-]?[0-9])?
id [a-zA-Z_][a-zA-Z0-9_]*
%%
{ws}
"if" {printf("<IF>");}
"then" {printf("<THEN>");}
"else" {printf("<ELSE>");}
"print" {printSymbolTable();}
{id} {printf("<ID, %d>",installID(yytext));}
{number} {printf("<NUMBER, %d>", installNumber(yytext));}
">=" {printf("<RELOP, GE>");}
"<=" {printf("<RELOP, LE>");}
"==" {printf("<RELOP, EQ>");}
">" {printf("<RELOP, GT>");}
"<" {printf("<RELOP, LT>");}
%%
int installID(char id[])
{
        for(int i = 0; i<=id_count; i++)
        {
                if(strcmp(symbolTableID[i],id) == 0)
                return i;
        }
        strcpy(symbolTableID[++id_count], id);
        return id_count;
}
int installNumber(char number[])
{
        static int num_count = 0;
        for(int i=0; i<=num_count; i++)
        {
                if(strcmp(symbolTableNum[i],number)==0)
                return i;
        }
        strcpy(symbolTableNum[++num_count], number);
        return num_count;
}

void printSymbolTable()
{
        for(int i=1; i<=id_count; i++)
        printf("%d %s\n",i, symbolTableID[i]);
}
void main()
{
        yylex();
}
yywrap()
{
}
