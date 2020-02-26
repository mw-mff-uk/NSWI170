#include <stdio.h>

void print_spaces(int count)
{
  for (int j = 0; j < count; j++)
  {
    printf(" ");
  }
}

void print_asterisks(int count)
{
  for (int j = 0; j < count; j++)
  {
    printf("*");
  }
}

void print_new_line()
{
  printf("\n");
}

void tree(int height)
{
  int width = height * 2 - 1;

  for (int i = 0; i < height; i++)
  {
    print_spaces(height - i - 1);
    print_asterisks(i * 2 + 1);
    print_spaces(height - i - 1);
    print_new_line();
  }
}

int main()
{
  tree(4);
}