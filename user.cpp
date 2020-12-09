#include "user.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

// Member function implementations...

void user::setTheme(int answer) {
  theme_choice = answer;
}

int user::getTheme() {
  return theme_choice;
}

void user::setCB(char answer) {
  cb_choice = answer;
}

char user::getCB() {
  return cb_choice;
}



  
