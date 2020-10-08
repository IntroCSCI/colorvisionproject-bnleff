#include <iostream>
#include <fstream>

using namespace std;

int main() {

  string themes[] = {"ambiance.rstheme", "chaos.rstheme", "chrome.rstheme", "clouds_midnight.rstheme", "clouds.rstheme", "cobalt.rstheme", "crimson_editor.rstheme", "dawn.rstheme","dreamweaver.rstheme", "eclipse.rstheme"};

  for(int j = 0; j < 10; j++) {
    ifstream myfile;
    myfile.open (themes[j], ios::in);
    if(!myfile.is_open()) {
      cout << "File can not be opened!" << endl;
    }
    else {
      string content;
      myfile >> content;

      cout << themes[j] << endl;
      for(int q = 0; q < 4; q++) {
        getline(myfile, content);
        cout << content << endl;
      }
      myfile.close();
    }
  }
  return 0;
}
