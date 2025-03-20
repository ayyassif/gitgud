#include "filesystem"
#include "gitgud.h"
#include "iostream"
#include "vector"

int init(void) {
  int result = FAILURE;
  std::vector<std::string> directories = {
      ".git/objects", ".git/objects/info", ".git/objects/pack",
      ".git/refs",    ".git/refs/heads",   ".git/refs/tags"};
  int n = 0; // used for track the number of successful calls
  for (const auto &dir : directories) {
    if (std::filesystem::create_directories(dir)) {
      n++;
    } else {
      result = FAILURE;
    }
  }
  // checks if the created directory numbers is the same as required
  result = (n == directories.size()) ? SUCCESS : FAILURE;
  return result;
}
