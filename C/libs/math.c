int abs(int a)
{
  if (a < 0)
    return -a;

  return a;
}

int min(int a, int b)
{
  if (a < b)
    return a;

  return b;
}

int max(int a, int b)
{
  if (a > b)
    return a;

  return b;
}

int arr_min(int nums[], int len)
{
  int res = nums[0];

  for (int i = 1; i < len; i++)
    res = min(res, nums[i]);

  return res;
}

int arr_max(int nums[], int len)
{
  int res = nums[0];

  for (int i = 1; i < len; i++)
    res = max(res, nums[i]);

  return res;
}
