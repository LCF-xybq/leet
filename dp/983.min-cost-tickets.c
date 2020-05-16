int min(int a, int b, int c) {
	a = a > b ? b : a;
	return a > c ? c : a;
}

int dp(int i, int* memo, int* days, int* costs) {
	if (i > 365) {
		return 0;
	}
	if (memo[i] != -1) {
		return memo[i];
	}
	if (days[i]) {
		memo[i] = min(costs[0]+dp(i+1, memo, days, costs), costs[1]+dp(i+7, memo, days, costs), costs[2]+dp(i+30, memo, days, costs));
	} else {
		memo[i] = dp(i + 1, memo, days, costs);
	}
	return memo[i];
}

int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
	int memo[366];
	int day[366];
	memset(memo, -1, sizeof(memo));
	memset(day, 0, sizeof(day));
	for (int i = 0; i < daysSize; ++i) {
		day[days[i]] = 1;
	}
	return dp(1, memo, day, costs);
}
