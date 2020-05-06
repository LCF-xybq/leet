class Solution {
private:
	vector<int> days, costs;
	vector<int> memo;
	int durations[3] = {1, 7, 30};

public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		this->days = days;
		this->costs = costs;
		memo.assign(days.size(), -1);
		if (memo[i] != -1) {
			return memo[i];
		}
		int j = i;
		memo[i] = INT_MAX;
		for (int k = 0; k < 3; ++k) {
			while (j < days.size() && days[j] < days[i] + durations[k]) {
				++j;
			}
			memo[i] = min(memo[i], dp(j) + costs[k]);
		}
		return memo[i];
	}
};
