class Solution {
public:
  static bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  }

  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    int i = 0, sum = 0;
    map<int, int> m;
    map<int, int>::iterator mit;
    vector<pair<int, int>> v;
    vector<pair<int, int>>::iterator vit;
    vector<vector<int>> res;
    for (auto k : points) {
      for (auto v : k) {
        sum += v * v;
      }
      m[i++] = sum;
      sum = 0;
    }

    for (mit = m.begin(); mit != m.end(); mit++) {
      v.push_back(pair<int, int>(mit->first, mit->second));
    }
    sort(v.begin(), v.end(), cmp);
    for (vit = v.begin(); K-- && vit != v.end(); vit++) {
      res.push_back(points[vit->first]);
    }

    return res;
  }
};
