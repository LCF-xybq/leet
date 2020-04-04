#include <stdio.h>

void swap(int tree[], int a, int b) {
  int tmp = tree[a];
  tree[a] = tree[b];
  tree[b] = tmp;
}

void heapify(int tree[], int n, int i) {
  if (i >= n) {
    return;
  }
  int max = i;
  int c1 = 2 * i + 1;
  int c2 = 2 * i + 2;
  if (c1 < n && tree[c1] > tree[max]) {
    max = c1;
  }
  if (c2 < n && tree[c2] > tree[max]) {
    max = c2;
  }
  if (max != i) {
    swap(tree, max, i);
    heapify(tree, n, max);
  }
}

void buildHeap(int tree[], int n) {
  int last_node = n - 1;
  int parent = (last_node - 1) / 2;
  for (int i = parent; i >= 0; --i) {
    heapify(tree, n, i);
  }
}

void heapSort(int tree[], int n) {
  buildHeap(tree, n);
  for (int i = n - 1; i >= 0; --i) {
    swap(tree, 0, i);
    heapify(tree, i, 0);
  }
}

int main() {
  int tree[4] = {5,2,3,1};
  heapSort(tree, 4);
  for (int i = 0; i < 4; ++i) {
    printf("%d\n", tree[i]);
  }
  return 0;
}
