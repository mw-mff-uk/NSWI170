#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : (-a))
#define round(a) ((int)(a < 0 ? a - 0.5 : a + 0.5))
#define DATAPTS 24

void rep(int, char);
void tree(int);
int sum(int[], int);
double avg(int[], int);
int amin(int[], int);
int amax(int[], int);
void aprint(int[], int);
void chartv(int[], int);
void charth(int[], int);
int mavg(int[], int[], int, int);

int main()
{
  // Christmas tree
  tree(9);

  // Average
  int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("\n%.2f\n\n", avg(nums, 9));

  // Temperature data points
  int data[DATAPTS] = {1, -7, -3, -5, 2, -7, -4, 3, 3, -10, -8, 3, 2, 3, 4, 4, -7, -3, 9, 0, 10, 5, -6, 5};

  // Charts
  aprint(data, DATAPTS);
  chartv(data, DATAPTS);
  charth(data, DATAPTS);

  // Moving averages
  int datamav[DATAPTS];
  int len = mavg(data, datamav, DATAPTS, 1);

  // Moving average charts
  aprint(datamav, len);
  chartv(datamav, len);
  charth(datamav, len);

  return 0;
}

void rep(int count, char ch)
{
  while (count-- > 0)
    putchar(ch);
}

void tree(int height)
{
  for (int i = 0; i < height; i++)
  {
    rep(height - i - 1, ' ');
    rep(i * 2 + 1, '*');
    rep(height - i - 1, ' ');
    putchar('\n');
  }
}

int sum(int items[], int len)
{
  int sum = 0;

  while (--len >= 0)
    sum += items[len];

  return sum;
}

double avg(int items[], int len)
{
  return sum(items, len) / (double)len;
}

int amin(int nums[], int len)
{
  int res = nums[0];

  for (int i = 1; i < len; i++)
    res = min(res, nums[i]);

  return res;
}

int amax(int nums[], int len)
{
  int res = nums[0];

  for (int i = 1; i < len; i++)
    res = max(res, nums[i]);

  return res;
}

void aprint(int nums[], int len)
/**
 * Prints all items in an int array
 */
{
  for (int i = 0; i < len; i++)
    printf(i == 0 ? "{ %d, " : (i == len - 1 ? "%d }\n" : "%d, "), nums[i]);
}

void chartv(int data[], int len)
/**
 * - Prints a vertical chart for data points specified in data
 */
{
  int _min = amin(data, len);

  for (int i = 0; i < len; i++)
  {
    if (data[i] > 0)
      rep(abs(min(0, _min)), ' ');
    else
      rep(abs(min(0, _min)) + data[i], ' ');

    rep(abs(data[i]), '*');
    putchar('\n');
  }
}

void charth(int data[], int len)
/**
 * - Prints a horizontal chart for data points specified in data
 */
{
  int _min = amin(data, len);
  int _max = amax(data, len);

  for (int i = _max; i >= _min; i--)
  {
    for (int j = 0; j < len; j++)
    {
      if (i > 0)
      {
        if (data[j] >= i)
          putchar('*');
        else
          putchar(' ');
      }
      else
      {
        if (data[j] < 0 && data[j] < i)
          putchar('*');
        else
          putchar(' ');
      }
    }

    putchar('\n');
  }
}

int mavg(int data[], int target[], int len, int r)
/**
 * - Iterates over all items in data and calculates the average
 *   of the items in the "common area" for each item in data
 * - The radius of the common area is specified by r
 *     r = 0 <-- normal average
 *     r = 1 <-- take one item to the right and one item to the left
 *     r = 2 <-- take two items to the right and two items to the left
 *     ...
 * - Saves the moving average to target. The caller is
 *   responsible for making sure that target has enough space
 * - The number of elements of target is returned
 */
{
  int sum;

  for (int i = r; i < len - r; i++)
  {
    sum = 0;
    for (int j = -r; j <= r; j++)
    {
      // printf("%d ", data[i + j]);
      sum += data[i + j];
    }
    // printf("| %d --> %d [%d]\n", sum, sum / (r * 2 + 1), i - r);
    target[i - r] = round((double)sum / (double)(r * 2 + 1));
  }

  return len - r * 2;
}