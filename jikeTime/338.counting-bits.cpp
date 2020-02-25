class Solution {
public:
  vector<int> countBits(int num) {
    int count[num + 1]£»
    count[0] = 0;
    for (int i = 1; i <= num; i++) {
      count[i] = count[i & (i - 1)] + 1;
    }

    vector<int> res;
    for (int i = 0; i <= num; i++) {
      res.push_back(count[i]);
    }

    return res;
  }
};
