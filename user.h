#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class user
{
  private: // Only can be used directly INSIDE this class
    int theme_choice;
    char cb_choice;
  
  public: // Can be used directly INSIDE and OUTSIDE this class
    // Member function prototypes...
    void setTheme(int answer);
    int getTheme();
    void setCB(char answer2);
    char getCB();
    
    
};

#endif