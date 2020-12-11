#ifndef THEME_H
#define THEME_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class theme
{
  private: // Only can be used directly INSIDE this class
    string themes[5];
    string theme_colors[5];   
  
  public: // Can be used directly INSIDE and OUTSIDE this class

    string input_file_name;
    string color_file_name;
    theme() {
      themes[0] = "ambiance.rstheme";
      themes[1] = "chaos.rstheme";
      themes[2] = "dawn.rstheme";
      themes[3] = "eclipse.rstheme";
      themes[4] = "textmate.rstheme";
      theme_colors[0] = "ambiance.colors";
      theme_colors[1] = "chaos.colors";
      theme_colors[2] = "dawn.colors";
      theme_colors[3] = "eclipse.colors";
      theme_colors[4] = "textmate.colors";
      input_file_name = "ambiance.rstheme";
      color_file_name = "ambiance.colors";
    }


    // Member function prototypes...

    string create_fn(int theme_choice);
    void create_outfile(string rfile);
    string create_col(int theme_choice);

};

#endif