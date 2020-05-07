#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix_table(char pattern[], int prefix[], int n) {
	prefix[0] = 0;
	int len		= 0;
	int i = 1;
	while (i < n) {
		if (pattern[i] == pattern[len]) {
			len++;
			prefix[i] = len;
			i++;
		} else {
			if (len > 0)
				len = prefix[len - 1];
			else {
				prefix[i] = len;
				i++;
			}
		}
	}
}

void move_prefix_table(int prefix[], int n) {
	for (int i = n - 1; i > 0; --i) {
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;
}

void kmp_search(char txt[], char pattern[]) {
	int n = strlen(pattern);
	int m = strlen(txt);
	int* prefix = (int*)malloc(sizeof(int) * n);
	prefix_table(pattern, prefix, n);
	move_prefix_table(prefix, n);

	// txt[i],     len(txt)     = m
	// pattern[j], len(pattern) = n

	int i = 0, j = 0;
	while (i < m) {
		if (j == n-1 && txt[i] == pattern[j]) {
			printf("Found pattern at %d\n", i - j);
			j = prefix[j];
		}
		if (txt[i] == pattern[j]) {
			i++;
			j++;
		} else {
			j = prefix[j];
			if (j == -1) {
				i++;
				j++;
			}
		}
	}
}

int main() {
	char pattern[] = "ABABCABAA";
	char txt[] = "ABABABCABAABABCABAACABAACBA";
	kmp_search(txt, pattern);

	return 0;
}
