#include <iostream>

int main() {
  std::string s;
  std::cin >> s;

  std::size_t start = 0;
  for (std::size_t i = 0; i < s.length(); ++i) {
    if (isupper(s[i])) {
      if (i - start > 0) {
        std::cout << toupper(s[start]) << s.substr(start + 1, i - start - 1) << '\n';
      }
      start = i + 1;
      s[i] = tolower(s[i]);
    }
  }

  if (start < s.length()) {
    std::cout << toupper(s[start]) << s.substr(start + 1) << '\n';
  }

  return 0;
}