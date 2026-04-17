#include <bits/stdc++.h>
using namespace std;

/**
文字列の先頭に記号とその後何文字を読み取るかを記録しておく
そうすれば、文字列の中に同じ区切り文字とかあったとしても、その文字列分進めるのだから破綻しない

<len>#<body> にしたいんだけど、この場合 lenの長さが何桁か分からないから
最初の<len>から次の#までの長さを読み取らないといけない
*/
class Solution {
 public:
  string encode(vector<string>& strs) {
    string out;

    for (const string& s : strs) {
      out += to_string(s.size()) + "#" + s;
    }
    return out;
  }

  vector<string> decode(string s) {
    vector<string> out;

    size_t i = 0;
    while (i < s.size()) {
      size_t j = s.find('#', i);
      size_t n = stoi(s.substr(i, j - i));  // strs[i].lengthは200まで
      out.push_back(s.substr(j + 1, n));
      i = j + 1 + n;
    }

    return out;
  }
};

int main() {
  Solution solution;
  vector<string> strs = {"Hello, world!", "42Tokyo", "naoki"};
  string encoded = solution.encode(strs);
  vector<string> decoded = solution.decode(encoded);
  for (string& s : decoded) {
    cout << s << endl;
  }
  return 0;
}
