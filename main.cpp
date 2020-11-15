#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function Prototypes

void create_outfile(string rfile);
int display_themes();
vector <string> convert_colors(string rfile_2);
void display_outcome(vector <string> convert_colors_vec);

// Main Program

int main() {

  string themes[] = {"ambiance.rstheme", "chaos.rstheme", "dawn.rstheme", "eclipse.rstheme"};
  string theme_colors[] = {"ambiance.colors", "chaos.colors", "dawn.colors", "eclipse.colors"};

  int answer;

  do {
    answer = display_themes();

    if(answer < 5) {
      string input_file_name = themes[answer - 1];
      create_outfile(input_file_name);
      string color_file_name = theme_colors[answer -1];
      vector <string> post_convert_vec = convert_colors(color_file_name);
      display_outcome(post_convert_vec);
    }
 } while(answer < 5);

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
    cout << "(5) Exit Program\n";

    cin >> user_file;
  } while(user_file != 1 && user_file != 2 && user_file != 3 && user_file != 4 && user_file != 5);
  cin.ignore();

  return user_file;
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

    if(isRed && !isGreen) {
      english_colors.push_back("red");
    }
    else if(isGreen && !isRed) {
      english_colors.push_back("green");
    }
    else if(isRed && isGreen) {
      english_colors.push_back("both");
    }
    else {
      english_colors.push_back("null");
    }
  }

  return english_colors;
}

void display_outcome(vector <string> convert_colors_vec) {
  cout << convert_colors_vec.size() << " colors were analyzed." << endl;
  
  int redCount = 0;
  int greenCount = 0;
  int bothCount = 0;

  for (int i = 0; i < convert_colors_vec.size(); i++) {
    string testing;
    testing = convert_colors_vec[i];

    if(testing == "red") {
      redCount = redCount + 1;
    }
    if(testing == "green") {
      greenCount = greenCount + 1;
    }
    if(testing == "both") {
      bothCount = bothCount + 1;
    }
  }

  cout << redCount << " red colors found." << endl;
  cout << greenCount << " green colors found." << endl;
  cout << bothCount << " red/green colors found." << endl;
}

