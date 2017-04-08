#include<cstdio>
#include<cstring>

typedef enum
{
   OPEN_PARENTHESIS = 1,
   CLOSE_PARENTHESIS,
   OPEN_BRACKET,
   CLOSE_BRACKET
} TYPE;

TYPE typechk(char a)
{
   switch(a)
   {
      case '(': return OPEN_PARENTHESIS;
      case ')': return CLOSE_PARENTHESIS;
      case '[': return OPEN_BRACKET;
      case ']': return CLOSE_BRACKET;
   }
}
int main()
{
   int n, i, length, top=0, mul=1, result=0;
   char str[31], stack[31];
   scanf("%s", str);
   length = strlen(str);

   for(i = 0; i < length; i++)
   {
      if(typechk(str[i]) == OPEN_PARENTHESIS)
      {
         stack[top++] = str[i];
         mul *= 2;
         if(typechk(str[i + 1]) == CLOSE_PARENTHESIS)
            result += mul;
      }
      else if(typechk(str[i]) == OPEN_BRACKET)
      {
         stack[top++] = str[i];
         mul *= 3;
         if(typechk(str[i + 1]) == CLOSE_BRACKET)
            result += mul;
      }
      else if(typechk(str[i]) == CLOSE_PARENTHESIS)
      {
         if(typechk(stack[top - 1]) == OPEN_PARENTHESIS)
         {
            stack[top--] = '0';
            mul /= 2;
         }
         else
            stack[top++] = str[i];
      }
      else if(typechk(str[i]) == CLOSE_BRACKET)
      {
         if(typechk(stack[top - 1]) == OPEN_BRACKET)
         {
            stack[top--] = '0';
            mul /= 3;
         }
         else
            stack[top++] = str[i];
      }
   }
   if(top == 0)
      printf("%d", result);
   else
      printf("0");
}