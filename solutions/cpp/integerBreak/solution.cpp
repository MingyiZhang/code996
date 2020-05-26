#include <cmath>

int integerBreak(int n) {
  switch (n) {
    case 2: return 1;
    case 3: return 2;
    default:
      int q = n / 3;
      int r = n % 3;
      if (r == 0) {
        return pow(3, q);
      } else if (r == 1) {
        return pow(3, q - 1) * 4;
      } else {
        return pow(3, q) * 2;
      }
  }
}