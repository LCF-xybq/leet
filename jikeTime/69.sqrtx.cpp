class Solution {
public:
  int left = 1, right = x;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (right - left == 1) {
      return left < x / left ? left : right;
    }
    if (mid == x / mid) {
      return mid;
    } else if (mid < x / mid) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return 0;
};
