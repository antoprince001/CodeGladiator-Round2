
/*----- FILE READTOKN.C ----------------------------------------------*/
/* A function to read input and tokenize it for a simple calculator   */
/*--------------------------------------------------------------------*/

#include <ctype.h>
#include <stdio.h>
#include "calc.h"

/*--------------------------------------------------------------------*/
/* action: get next input char, update index for next call            */
/* return: next input char                                            */
/*--------------------------------------------------------------------*/
static char nextchar(char buf_in[], int length)
{
/*--------------------------------------------------------------------*/
/* sample input  action for input "2 18 + = 5 / ="                    */
/*    read 2, push 2 on stack                                         */
/*    read 18, push 18                                                */
/*    read +, pop 2, pop 18, add, push result (20)                    */
/*    read =, output value on the top of the stack (20)               */
/*    read 5, push 5                                                  */
/*    read /, pop 5, pop 20, divide, push result (4)                  */
/*    read =, output value on the top of the stack (4)                */
/*--------------------------------------------------------------------*/
  static int index = 0;    
  if (index >= length) return 0; 
  char ret;
  ret = buf_in[index];
  ++index;
  return ret;
}

/*--------------------------------------------------------------------*/
/* output: buf - null terminated token                                */
/* return: token type                                                 */
/* action: reads chars through nextchar() and tokenizes them          */
/*--------------------------------------------------------------------*/
Token read_token(char buf[], char buf_in[], int in_length)
{
  int i;
  char c;
  /* skip leading white space */
  /* Input the string and the length */
  //let the character be retrieved from the buffer
  for( c=nextchar(buf_in, in_length);
       isspace(c);
       c=nextchar(buf_in, in_length))
    ;
  buf[0] = c;  /* get ready to return single char e.g."+" */
  buf[1] = 0;
  switch(c)
  {
    case '+' : return T_PLUS;
    case '-' : return T_MINUS;
    case '*' : return T_TIMES;
    case '/' : return T_DIVIDE;
    case '=' : return T_EQUALS;
    default:
      i = 0;
      while (isdigit(c)) {
        buf[i++] = c;
        c = nextchar(buf_in, in_length);
      }
      buf[i] = 0;
      if (i==0)
        return T_STOP;
      else if(i>=1 && i<=9)
        return T_INTEGER; // Only intege values
      else
        return T_INVALID; //INVALID token's condition
  }
}