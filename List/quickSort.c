int partition(int* nums, int left, int right) {
  int pivot = nums[left];
  while (left < right) {
    while (left < right && nums[right] >= pivot) right--;
    nums[left] = num[right];
    while (left < right && nums[left] <= pivot) left++;
    nums[right] = nums[left];
  }
  list[left] = base;

  return left;
}

void quickSort(int* nums, int left, int right) {
  if (left < right) {
    int base_index = partition(nums, left, right);
    quickSort(nums, left, base_index - 1);
    quickSort(nums, base_index + 1, right);
  }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  quickSort(nums, 0, numsSize - 1);

  return nums;
}
