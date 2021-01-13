/*
	University of Electro-Communications
		Information processing laboratory 2
*/
#include <stdio.h>
#include <string.h>

/*
 * Define and Macros
 */
#define yywrap()    	1
#define DISPLAY_MAX	100
#define NAME_MAX	16

/*
 * External declarations
 */
extern char    yytext[];

/*
 * type declarations
 */
typedef char * STRING;

typedef enum idclass {
    types, konst, vars, prog, proc, func, enums, field
} IDCLASS;

typedef struct linenolink {
    int     lineno;
    struct  linenolink *next;
} *LINENOLINK_PTR, LINENOLINK;

typedef struct identifier {
	STRING name;
    	struct identifier *llink;
    	struct identifier *rlink;
    	IDCLASS klass;
    	int defineline;
    	LINENOLINK_PTR next;
	STRING scope;
	struct identifier *recordtype;
} *IDENTIFIER_PTR, IDENTIFIER;

/*
 * Static declarations
 */
static char *IdClassStr[] = {
	"type ", "const", "var  ", "prog ", 
	"proc ", "func ", "enum ", "field"
};

static char *ValueType[] = {
	"char", "integer", "real", "boolean"
};

static IDENTIFIER_PTR DisPlay[DISPLAY_MAX];
static IDENTIFIER *IdRoot;
static IDCLASS IdClass;

/* 
 * Function declarations
 */
void yyerror();
void initialize();
IDENTIFIER_PTR enterid();
void makeline();
LINENOLINK_PTR makelinenode();
void delete();
void delline();
IDENTIFIER_PTR maketree();
void closs();
void inorder_act();
void inorder();
void kindset();
void put_table();

/*
 * Yacc and Lex Include 
 *	
 *	y.tab.c  ... yacc file
 *	lex.yy.c ... lex file
 */
#include "s4ytab.c"
#include "s4yylex.c"

/*
 * Functions
 */
main()
{
    	IdRoot = NULL;
	initialize();
    	yyparse();
    	put_table();
    	inorder( IdRoot );
    	delete( IdRoot );
	printf("yytext =%s", yytext);
}

void yyerror( s )
char *s;
{
    	printf( "%s at %d\n", s, yylineno );
    	printf( "%s\n", yytext );
}

void initialize() 
{
		
}

IDENTIFIER_PTR enterid(nameval, klassval, linenoval, scopeval)
STRING nameval;
IDCLASS klassval;
int linenoval;
STRING scopeval;
{
		
	
}

void kindset( classval )
IDCLASS classval;
{
    IdClass = classval;
}

void makeline( no_ptr )
LINENOLINK_PTR *no_ptr;
{
    	if( *no_ptr == NULL ) 
		*no_ptr = makelinenode();
    	else
		makeline( &( *no_ptr )->next );
}

LINENOLINK_PTR makelinenode()
{
	LINENOLINK_PTR  no_ptr;

    	no_ptr = (LINENOLINK_PTR)malloc(sizeof(LINENOLINK));
    	if( no_ptr == NULL ) {
        	delete( IdRoot );
        	exit( 1 );
    	}
    	no_ptr->lineno = yylineno;
    	no_ptr->next = NULL;
    	return( no_ptr );
}

void delete( id_ptr )
IDENTIFIER_PTR id_ptr;
{
    	if( id_ptr->llink  != NULL ) 
		delete( id_ptr->llink  );
    	if( id_ptr->rlink != NULL ) 
		delete( id_ptr->rlink );
    	delline( id_ptr->next );
    	free( id_ptr );
}

void delline( no_ptr )
LINENOLINK_PTR  no_ptr;
{
    	if( no_ptr->next != NULL ) 
		delline( no_ptr->next );
    	free( no_ptr );
}

IDENTIFIER_PTR maketree( name )
STRING name;
{
    	IDENTIFIER_PTR    id_ptr;

    	id_ptr = ( IDENTIFIER_PTR )malloc(sizeof(IDENTIFIER));
    	id_ptr->name = ( STRING )malloc(sizeof(NAME_MAX));
    	if( id_ptr == NULL ) {
        	delete( IdRoot );
        	exit( 1 );
    	}
    	strcpy( id_ptr->name, name );
    	id_ptr->klass = IdClass;
    	id_ptr->next = makelinenode();
    	id_ptr->llink = id_ptr->rlink = NULL;
    	return( id_ptr );
}  

void closs( id_ptr, name )
IDENTIFIER_PTR *id_ptr;
STRING name;
{
	int i, cmp;

	printf("name=%s", name);
    	for( i=0 ; i<4 ; i++ )
        	if( strcmp( name, ValueType[i] ) == 0 ) return; 
    	if( *id_ptr == NULL ) 
		*id_ptr = maketree( name );
	{
        	if( ( cmp = strcmp( name, ( *id_ptr )->name ) ) != 0 ) {
            		if( cmp < 0 ) 
				closs( &( *id_ptr )->llink,  name );
            		else          
				closs( &( *id_ptr )->rlink, name );
        	} else 
			makeline( &( *id_ptr )->next );
    	}  
}

void inorder_act(id_ptr)
IDENTIFIER_PTR id_ptr;
{
	LINENOLINK_PTR tmp;
	int count = 0;
	int init_flg; 

    	printf( "%-15s", id_ptr->name );
	if (id_ptr->klass < types || id_ptr->klass > field) 
		printf("----- ");
	else	
		printf("%s ", IdClassStr[id_ptr->klass]); 
    	tmp = id_ptr->next; 
	init_flg = 1;
    	while( tmp != NULL )
    	{
        	if( count++ == 10 )
        	{
            		count = 0;
            		printf( "\n" );
            		printf( "                     " );
		}
		if (init_flg == 2) 
        		printf( "%8d", tmp->lineno );
		else	
        		printf( "%4d", tmp->lineno );
        	tmp = tmp->next;
		init_flg ++;
    	}
    	printf( "\n" ); 
}

void inorder( id_ptr )
IDENTIFIER_PTR id_ptr;
{

    	if( id_ptr->llink  != NULL ) 
		inorder( id_ptr->llink  );
	inorder_act(id_ptr);
    	if( id_ptr->rlink != NULL ) 
		inorder( id_ptr->rlink );
}

void put_table()
{
      	printf( "name           kind    define  refer\n" ) ;
      	printf( "------------------------------------\n" ) ;
}

