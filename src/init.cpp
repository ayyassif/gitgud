#include "filesystem"
#include "fstream"
#include "gitgud.h"
#include "iostream"
#include "vector"

int create_dirs(void) {
  int result = FAILURE;
  std::vector<std::string> directories = {
      ".git/objects", ".git/objects/info", ".git/objects/pack",
      ".git/refs",    ".git/refs/heads",   ".git/refs/tags"};
  int n = 0; // used for track the number of successful calls
  for (const auto &dir : directories) {
    if (std::filesystem::create_directories(dir)) {
      n++;
    } else {
      std::cerr << "Failed to create: " << dir << "\n";
      result = FAILURE;
      break;
    }
  }
  // checks if the created directory numbers is the same as required
  result = (n == directories.size()) ? SUCCESS : FAILURE;
  return result;
}

int create_files(void) {
  int result = FAILURE;
  std::vector<std::string> files = {".git/HEAD", ".git/config"};
  int n = 0;
  for (const auto &file : files) {
    std::filesystem::path file_path(file);
    std::ofstream out_file(file);
    if (out_file) {
      n++;
      out_file << "" << file;
    } else {
      std::cerr << "Failed to create: " << file << '\n';
      result = FAILURE;
    }
  }
  result = (n == files.size()) ? SUCCESS : FAILURE;
  return result;
}

int init(void) {
  int result = create_dirs();
  if (result == 1) {
    result = create_files();
  }
  return result;
}
