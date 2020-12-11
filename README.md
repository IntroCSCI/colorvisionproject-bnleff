# How do people with color blindness see Rstudio's themes?

## Description

The goal of my program is to ultimately calculate out how much of a problem and which colors could pose problems to people with specific types of coloblindness in Rstudio's color themes.

### v0.2 Updates

The goal of my program is to show possible complications in color choices for each color theme in Rstudio. The user can choose which color theme and which type of color blindness and they can see if there could potentially be problems using the theme.

### v0.3 Updates

The goal remained the same since v0.2. The user can input which type of color blindness they are interested in analyzing as well as which Rstudio theme to analyze. In v0.3. Blue/Yellow colorblindness was added as a choice along side Red/Green colorblindness.

## Developer

Brandon Leff

## C++ Guide

### Variables and Data Types

I use variables in the process to extract lines from the text files.
```
int num_themes = 10;
```

#### v0.2 Updates

I use variables for many tasks in this project. I use string variables to read in files, integer variables for user input choice of which file, and integer variables to count how many colors could pose problems.
```
int redCount = 0;
int greenCount = 0;
int bothCount = 0;
``` 

#### v0.3 Updates

Variables are used in the newly updated ways to count for colors being found in the R theme. In the below example, I converted hex codes to english words, and this string variable named testing loops through the vector of english words comparing the current string to any color. Since Blue and Yellow coloblindness was added in v0.3, here is a demonstration of how I increased counts of blue, yellow, and cyan colors.

```
string testing;
    if(testing == "yellow") {
      yCount = yCount + 1;
    }
    if(testing == "blue") {
      bCount = bCount + 1;
    }
    if(testing == "cyan") {
      cCount = cCount + 1;
    }
```

### Input and Output

I am using cout to display lines from the text files.
```
cout >> content >> endl;
```

#### v0.2 Updates

I use input to let the user pick which theme they want to analyze. In the future I would like to add a user input option for which type of color blindness they want to analyze as well. I use output to display the results of what was found in each file. 

```
cin >> user_file;
  } while(user_file != 1 && user_file != 2 && user_file != 3 && user_file != 4 && user_file != 5);
  cin.ignore();
```

#### v0.3 Updates

I use input and output in this new update in the form of the new display_cb function that is similar to the display_themes function I had in earlier versions. It prompts the user with a cout statement asking which of th two types of colorblindness they would like to analyze and then the user uses a cin statement to enter a char variable.

```
cout << "Options:\n";
    cout << "(R) Red/Green\n";
    cout << "(B) Blue/Yellow\n";

    cin >> user_cb;
```

### Decisions

#### v0.2 Updates

I use decisions to decide if each string in the vector is red, green, both, or neither. I do this using if statements. 

```
if(testing == "red") {
  redCount = redCount + 1;
}
if(testing == "green") {
  greenCount = greenCount + 1;
}
if(testing == "both") {
  bothCount = bothCount + 1;
}
```

#### v0.3 Updates

Decisions are not changed as much in this update. I added the support for testing to be blue, cyan, and yellow colors.

```
if(testing == "yellow") {
      yCount = yCount + 1;
    }
    if(testing == "blue") {
      bCount = bCount + 1;
    }
    if(testing == "cyan") {
      cCount = cCount + 1;
    }
``` 

### Iteration

I use iteration to loop through the array of file names.

```
for(int file_index = 0; file_index < num_themes; file_index++) {
```

#### v0.2 Updates

I use iteration to loop through the values in my vector of strings to decide if they are red, green, both, or neither.

```
for (int i = 0; i < convert_colors_vec.size(); i++) {
    string testing;
    testing = convert_colors_vec[i];
```

### File Input and Output

So far all my code is about file input. I am taking multiple text files and extracting lines that contain the word "color". 

```
ifstream file_stream;
    file_stream.open (themes[file_index], ios::in);
    if(!file_stream.is_open()) {
```

#### v0.2 Updates

I use file input and output both for multiple ways in my project. For file input, I read in the .rstheme files and filter through only the hex codes. I then use file output to write new .colors files that are the old text files but only hex codes so I don't edit my raw data. I also use file input to later read in the .colors files for further analysis.

```
ifstream inputStream;
inputStream.open (rfile, ios::in);

ofstream outputStream;
outputStream.open (rfile.substr(0, rfile.length() - 8) + ".colors");
```

### Arrays/Vectors

#### v0.2 Updates

In my program, I use arrays by having an array of file names that the user input can index to access the file they want to analyze.

I use vectors to store string values "red", "green", "both", "null", in order to eventually count how many colors there are versus how many problematic colors there are using .size() and if statments.

```
string themes[] = {"ambiance.rstheme", "chaos.rstheme", "dawn.rstheme", "eclipse.rstheme"};

vector <string> english_colors;

  while (getline(inputStream, line_2)) {
    bool isRed = line_2.substr(0,2) == "ff" || line_2.substr(0,2) == "FF";
    bool isGreen = line_2.substr(2,2) == "ff" || line_2.substr(2,2) == "FF";

    if(isRed && !isGreen) {
      english_colors.push_back("red");
    }
```

#### v0.3 Updates

The only update added for v0.3 for arrays and vectors is that the vectors for themes[] and theme_colors[] are out of main.cpp and into the class theme. 

```
string themes[5];
    string theme_colors[5]; 
```


### Functions

#### v0.2 Updates

In my program I use several functions to write output files, create string vectors, convert hex codes to english words, and display output to the user.

```
void create_outfile(string rfile);
int display_themes();
vector <string> convert_colors(string rfile_2);
void display_outcome(vector <string> convert_colors_vec);
```

#### v0.3 Updates

For functions the function display_cb was created to prompt the user which colorblindness they would like to analyze. It returns the character that was typed in by the user either R or B. There are also two new functions in the class that take the integer and character the user inputs and creates a string for the file name desired in the array of theme names.

```
char display_cb();

string theme::create_fn(int theme_choice) {
  input_file_name = themes[theme_choice -1];
  return input_file_name;
}

string theme::create_col(int theme_choice) {
  color_file_name = theme_colors[theme_choice -1];
  return color_file_name;
}
```

### Classes

#### v0.3 Updates

The main updates to v0.3 are the introduction of classes into my program. The class user was created directly in the main.cpp file and is for user interaction. It stores the character and integer the user enters in for their cin statments prompted to choose which type of colorblindness and what theme to analyze. The class theme was created using a theme.h and theme.cpp file. It uses the char and int variables from class a to make file names and color file names and extract those specific file names from the arrays theme and theme_colors. There is also a contstuctor to initialize the arrays of strings as well as the default choices for input_file_name and color_file_name.

```
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
    string create_col(int theme_choice);

};
```



## Stakeholder Interaction

After talking to my stakeholder, I was informed that my original idea of how to calculate how problematic the themes would be was not the best way to go at it. I was reccommended to display how many colors there were in the theme and then display how many problematic colors there would be as well as show the percentage breakdown of those problematic colors. I was also informed that my project is useful for identifying colors, but there's no guarantee that those colors are next to eachother in the rstudio UI that would even pose a problem of not being able to identify. I would like to look into this problem in the future if time allows for it. Overall, my conversation with the stakeholder went well however which motivated me to continue the work.
