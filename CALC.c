
/*----- FILE CALC.C --------------------------------------------------*/
/* A simple calculator that does operations on integers that          */
/* are pushed and popped on a stack                                   */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "./CALC.h"

IntStack stack = { 0 };
void getinput(char input_data[], int maxlength)
{
  fgets(input_data, MaxData, stdin);
}


int main()
{
  Token tok;
  int num, num2;
  char input_data[MaxData]; //receive the input in an array
  char word[MaxWord]; 
  char buf_out[MaxWord]; //output buffer
  getinput(input_data, MaxData); //get the input into the array

  for(;;)
  {
    tok=read_token(word, input_data, MaxData); 
    switch(tok)
    {
      case T_STOP:
        break;
      case T_INTEGER:
        num = atoi(word);
        push(&stack,num);     /*  CALC1  statement */
        break;

      case T_PLUS:
        push(&stack, pop(&stack)+pop(&stack) );
        break;

      case T_MINUS:
        num = pop(&stack);
        push(&stack, pop(&stack)-num);
        break;

      case T_TIMES:
        push(&stack, pop(&stack)*pop(&stack));
        break;

      case T_DIVIDE:
        num2 = pop(&stack);
        num = pop(&stack);
        push(&stack, num/num2);   /* CALC2  statement */
        break;

      case T_EQUALS:
        num = pop(&stack);
        sprintf(buf_out,"%d ",num);
        push(&stack,num);
        break;
    }

    if (tok==T_STOP) //stop when value is 0
      break;
    else if(tok==T_INVALID) //INVALID token's condition
      break;

  }
  printf("%s\n", buf_out); // output buffer value
  return 0;
}




