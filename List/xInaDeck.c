int gcd(int x, int y) {
	if (x < y) 
		return gcd(y, x);
	if (y == 0) return x;
	return gcd(y, x % y);
}

bool hasGroupsSize(int* deck, int deckSize) {
	int counts[10000];
	for (int i = 0; i < 10000; ++i) counts[i] = 0;
	for (int i = 0; i < deckSize; ++i) ++counts[*(deck + i)];

	int g = -1;
	for (int i = 0; i < 10000; ++i) {
		switch(counts[i]) {
			case 0 : continue; break;
			case 1 : return false; break;
			default : {
				if (g == -1)
					g = counts[i];
				else {
					g = gcd(g, counts[i]);
					if (g == 1)
						return false;
				}
			} break;
		}
	}
	return true;
}
