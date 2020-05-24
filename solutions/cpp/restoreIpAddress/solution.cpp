
#include <vector>
#include <string>

using namespace std;

void backtracking(string &prefix, string &rest, int count, vector<string> &ip) {
  if (count == 4 || rest.empty()) {
    if (count == 4 && rest.empty()) {
      ip.emplace_back(prefix);
    }
    return;
  }
  for (int i = 0; i < min(int(rest.size()), 3); i++) {
    if (i != 0 && rest[0] == '0') {
      break;
    }
    string part = rest.substr(0, i + 1).data();
    if (stoi(part) <= 255) {
      if (!prefix.empty()) {
        part = "." + part;
      }
      prefix += part;
      string newRest = rest.substr(i + 1);
      backtracking(prefix, newRest, count + 1, ip);
      prefix = prefix.substr(0, prefix.size() - part.size());
    }
  }
}

vector<string> restoreIpAddress(string s) {
  vector<string> ret;
  string prefix;
  backtracking(prefix, s, 0, ret);
  return ret;
}