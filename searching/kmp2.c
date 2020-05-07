#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kmp(char txt[], char pattern[]) {
	int m = strlen(txt);
	int n = strlen(pattern);
	int* prefix = (int*)malloc(sizeof(int) * n);
	memset(prefix, -1, sizeof(prefix) * n);

	for (int i = 1, j = -1; i < n; ++i) {
		while (j != -1 && pattern[i] != pattern[j + 1]) j = prefix[j];
		if (pattern[i] == pattern[j + 1]) ++j;
		prefix[i] = j;
	}
	for (int i = 0, j = -1; i < m; ++i) {
		while (j != -1 && txt[i] != pattern[j + 1]) j = prefix[j];
		if (txt[i] == pattern[j + 1]) ++j;
		if (j == n - 1) return 1;
	}
	return 0;
}

int main() {
	char pattern[] = "ABABCABAA";
	char txt[]     = "ABABABCABAABABCABAACABAACBA";
	
	int res =	kmp(txt, pattern);
	printf("%d\n", res);
	
	char a[] = "ABCD";
	int res2 = kmp(txt, a);
	printf("%d\n", res2);

	return 0;
}
