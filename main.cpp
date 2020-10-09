#include <iostream>
#include <fstream>

using namespace std;

int main() {

  string themes_total[] = {"ambiance.rstheme", "chaos.rstheme", "chrome.rstheme", "clouds_midnight.rstheme", "clouds.rstheme", "cobalt.rstheme", "crimson_editor.rstheme", "dawn.rstheme","dreamweaver.rstheme", "eclipse.rstheme"};

  string themes[] = {"ambiance.rstheme"}

  int num_themes = 10;

  for(int file_index = 0; file_index < num_themes; file_index++) {

    ifstream file_stream;
    file_stream.open (themes[file_index], ios::in);
    if(!file_stream.is_open()) {
      cout << "Unable to open file." << endl;
    }
    else {
      string content;

      while(getline(file_stream,content)) {
        if(content.find("color:") != string::npos) {
                cout << content << endl;
        }
      }
      
  }
  return 0;
}
