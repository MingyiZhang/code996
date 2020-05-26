
int climbStairs(int n) {
  if (n <= 2) {
    return n;
  }

  int a = 1, b = 2, i = 3;
  int ret;
  while (i++ <= n) {
    ret = a + b;
    a = b;
    b = ret;
  }
  return ret;
}