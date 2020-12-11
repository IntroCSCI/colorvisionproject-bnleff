#include "theme.h"
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;

// Member function implementations...

string theme::create_fn(int theme_choice) {
  input_file_name = themes[theme_choice -1];
  return input_file_name;
}

string theme::create_col(int theme_choice) {
  color_file_name = theme_colors[theme_choice -1];
  return color_file_name;
}



  
