/*----- FILE CALC.H --------------------------------------------------*/
/* Header file for CALC.C PUSHPOP.C READTOKN.C                        */
/* a simple calculator                                                */
/*--------------------------------------------------------------------*/

#define MaxWord 100
#define MaxData 1000

typedef enum toks {
  T_INTEGER,
  T_PLUS,
  T_TIMES,
  T_MINUS,
  T_DIVIDE,
  T_EQUALS,
  T_STOP,
  T_INVALID
} Token;

Token read_token(char buf[], char buf_in[], int in_length);

typedef struct int_link  {
  struct int_link * next;
  int i;
} IntLink;

typedef struct int_stack {
  IntLink * top;
} IntStack;

extern void  push(IntStack *, int);
extern int pop(IntStack *);
