#include <stdio.h>
#include "libs/math.c"
#include "libs/print.c"

void print_chart_vertical(int data[])
{
  int _min = arr_min(data, 24);

  for (int i = 0; i < 24; i++)
  {
    if (data[i] > 0)
      print_rep(abs(min(0, _min)), " ");
    else
      print_rep(abs(min(0, _min)) + data[i], " ");

    print_rep(abs(data[i]), "*");
    printf("\n");
  }
}

void print_chart_horizontal(int data[])
{
  int _min = arr_min(data, 24);
  int _max = arr_max(data, 24);

  for (int i = _max; i >= _min; i--)
  {
    for (int j = 0; j < 24; j++)
    {
      if (i > 0)
      {
        if (data[j] >= i)
          printf("*");
        else
          printf(" ");
      }
      else
      {
        if (data[j] < 0 && data[j] < i)
          printf("*");
        else
          printf(" ");
      }
    }

    printf("\n");
  }
}

int main()
{
  int data[] = {1, -7, -3, -5, 2, -7, -4, 3, 3, -10, -8, 3, 2, 3, 4, 4, -7, -3, 9, 0, 20, 5, -6, 5, 9, -4};

  print_chart_horizontal(data);
}