#include <stdio.h>

int sum(int nums[], int len)
{
  int res = 0;

  for (int i = 0; i < len; i++)
  {
    res += nums[i];
  }

  return res;
}

int avg(int nums[], int len)
{
  return sum(nums, len) / len;
}

int main()
{
  int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("%d\n", avg(nums, 9));
}