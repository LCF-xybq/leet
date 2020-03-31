void merge(int* raw, int size, int left, int right) {
  int list[size];
  int mid = left + (right - left) / 2;
  int i = left, j = mid + 1;
  int k = 0;
  while (i <= mid && j <= right) {
    if (raw[i] <= raw[j]) {
        list[k++] = raw[i++];
    } else {
        list[k++] = raw[j++];
    }
  }
  while (i <= mid) list[k++] = raw[i++];
  while (j <= right) list[k++] = raw[j++];
  for (int p = 0; p < k; p++) {
    raw[left + p] = list[p];
  }
}

void mergeSort(int* raw, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(raw, left, mid);
    mergeSort(raw, mid + 1, right);
    merge(raw, right - left + 1, left, right);
  }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  mergeSort(nums, 0, numsSize - 1);

  return nums;
}
