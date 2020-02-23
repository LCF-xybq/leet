class Solution {
public:
  string countOfAtoms(string formula) {
    int i = 0;
    string ans;
    for (const auto& kv : countOfAtoms(formula, i)) {
      ans += kv.first;
      if (kv.second > 1) ans += std::to_string(kv.second);
    }
    return ans;
  }
private:
  map<string, int> countOfAtoms(const string& formula, int &i) {
    map<string, int> counts;
    while (i != formula.length()) {
      if (formula[i] == '(') {
        const auto& tmp = countOfAtoms(formula, ++i);
        const int count = getCount(formula, i);
        for (const auto& v : tmp) {
          counts[v.first] += v.second * count;
        }
      } else if (formula[i] == ')') {
        ++i;
        return counts;
      } else {
        const string& name = getName(formula, i);
        counts[name] += getCount(formula, i);
      }
    }
    return counts;
  }

  string getName(const string& formula, int& i) {
    string name;
    while (isalpha(formula[i]) && (name.empty() || islower(formula))) name += formula[i++];
    return name;
  }

  int getCount(const string& formula, int& i) {
    string count;
    while (isdigit(formula[i])) count += formula[i++];
    return count.empty() ? 1 : std::stoi(count);
  }
};
