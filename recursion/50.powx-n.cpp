class Solution {
public:
  double fastPow(double x, long long n) {
    if (n == 0) {
      return 1.0;
    }
    double res = 1.0;
    double half = fastPow(x, n / 2);
    if (n % 2 == 0) {
      res = half * half;
    } else {
      res = half * half * x;
    }
    return res;
  }

  double pow(double x, int n) {
    long long N = n;
    if (N < 0) {
      N = -N;
      x = 1 / x;
    }
    return fastPow(x, N);
  }
};
