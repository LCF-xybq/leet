#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseLeftWords(char* s, int n) {
	int len = strlen(s);
	if (n == 0 || n >= len) return s;
	char* tmp = (char*)malloc(sizeof(char) * (len + 1));
	char* p = s + n;
	int k = 0;
	for (int i = 0; i < len - n; ++i) {
		tmp[k++] = p[i];
	}
	for (int i = 0; i < n; ++i) {
		tmp[k++] = s[i];
	}
	tmp[k] = '\0';

	return tmp;
}

int main() {
	char s[] = "dfdhthyrqw";
	char* res = reverseLeftWords(s, 2);
	printf("%s\n", res);

	return 0;
}
