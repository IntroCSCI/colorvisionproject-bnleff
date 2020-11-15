#include <iostream>
#include <fstream>

using namespace std;

// Function Prototypes

void create_outfile(string rfile);


// Main Program

int main() {

  string themes[] = {"ambiance.rstheme"};
  int num_themes = 1;

  for (int file_idx = 0; file_idx < num_themes; file_idx++) {
    string input_file_name = themes[file_idx];

    create_outfile(input_file_name);
  }

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
        if(line.find("color:") != string::npos) {
          cout << line << endl;
          outputStream << line << endl;
        }
      }

      outputStream.close();

}






