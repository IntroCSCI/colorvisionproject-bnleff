#include <iostream>
#include <fstream>
#include <vector>
#include "theme.h"

using namespace std;


// Function Prototypes

void create_outfile(string rfile);
int display_themes();
char display_cb();
vector <string> convert_colors(string rfile_2);
void display_outcome(vector <string> & convert_colors_vec, char answer);

class user {
   public:
    int theme_choice;
    char cb_choice;
    user() {
      theme_choice = 1;
      cb_choice = 'A';
    } 
};

// Main Program

int main() {

  user a;

  theme b;

  do {
    a.cb_choice = display_cb();
    a.theme_choice = display_themes();

     if(a.theme_choice  < 6) {
      b.create_fn(a.theme_choice);
      create_outfile(b.input_file_name);
      b.create_col(a.theme_choice);
      vector <string> post_convert_vec = convert_colors(b.color_file_name);
      display_outcome(post_convert_vec,a.cb_choice);
    }
 } while(a.theme_choice  < 6);

  return 0;
}

// Functions

void create_outfile(string rfile) {
  
  ifstream inputStream;
  inputStream.open (rfile, ios::in);

  ofstream outputStream;
  outputStream.open (rfile.substr(0, rfile.length() - 8) + ".colors");

  if(!inputStream.is_open()) {
    cout << "Unable to open file: " << rfile << "." << endl;
  }
  else {
    string line;

    while (getline(inputStream, line)) {
      size_t pos = line.find("color: #");
      if(pos != string::npos) {
        if(line.length() > pos + 14) {
          string hexvalue = line.substr(pos + 8,6);

          outputStream << hexvalue << endl;
          }
        }
      }
    }

      outputStream.close();

}

int display_themes() {
  int user_file;

  cout << "Which Rstudio theme do you want to analyze?" << endl;
  do {
    cout << "Options:\n";
    cout << "(1) Ambiance\n";
    cout << "(2) Chaos\n";
    cout << "(3) Dawn\n";
    cout << "(4) Eclipse\n";
    cout << "(5) Textmate\n";
    cout << "(6) Exit Program\n";

    cin >> user_file;
  } while(user_file != 1 && user_file != 2 && user_file != 3 && user_file != 4 && user_file != 5 && user_file != 6);
  cin.ignore();

  return user_file;
}

char display_cb() {
  char user_cb;

  cout << "What type of color blindness do you want to analyze?" << endl;

  do {
    cout << "Options:\n";
    cout << "(R) Red/Green\n";
    cout << "(B) Blue/Yellow\n";

    cin >> user_cb;
  } while(user_cb != 'R' && user_cb != 'B');
  cin.ignore();

  return user_cb;
}

vector <string> convert_colors(string rfile_2) {
  ifstream inputStream;
  inputStream.open (rfile_2, ios::in);

  if(!inputStream.is_open()) {
    cout << "Unable to open file: " << rfile_2 << "." << endl;
  }

  string line_2;

  vector <string> english_colors;

  while (getline(inputStream, line_2)) {
    bool isRed = line_2.substr(0,2) == "ff" || line_2.substr(0,2) == "FF";
    bool isGreen = line_2.substr(2,2) == "ff" || line_2.substr(2,2) == "FF";
    bool isBlue = line_2.substr(4,2) == "ff" || line_2.substr(4,2) == "FF";

    if(isRed && !isGreen && !isBlue) {
      english_colors.push_back("red");
    }
    else if(isGreen && !isRed && !isBlue) {
      english_colors.push_back("green");
    }
    else if(isRed && isGreen && !isBlue) {
      english_colors.push_back("yellow");
    }
    else if(isBlue && !isGreen && !isRed) {
      english_colors.push_back("blue");
    }
    else if(isBlue && isGreen && !isRed) {
      english_colors.push_back("cyan");
    }
    else {
      english_colors.push_back("null");
    }
  }

  return english_colors;
}

void display_outcome(vector <string> & convert_colors_vec, char answer) {
  cout << convert_colors_vec.size() << " colors were analyzed." << endl;
  
  int redCount = 0;
  int greenCount = 0;
  int yCount = 0;
  int bCount = 0;
  int cCount = 0;
  int vec_size = convert_colors_vec.size();

  for (int i = 0; i < vec_size; i++) {
    string testing;
    testing = convert_colors_vec[i];

    if(testing == "red") {
      redCount = redCount + 1;
    }
    if(testing == "green") {
      greenCount = greenCount + 1;
    }
    if(testing == "yellow") {
      yCount = yCount + 1;
    }
    if(testing == "blue") {
      bCount = bCount + 1;
    }
    if(testing == "cyan") {
      cCount = cCount + 1;
    }

  }
  if(answer == 'R') {
  cout << redCount << " red colors found." << endl;
  cout << greenCount << " green colors found." << endl;
  }
  if(answer == 'B') {
  cout << yCount << " yellow colors found." << endl;
  cout << bCount << " blue colors found." << endl;
  cout << cCount << " cyan colors found." << endl;
  }
}

