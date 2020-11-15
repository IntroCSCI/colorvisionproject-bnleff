# How do people with color blindness see Rstudio's themes?

## Description

The goal of my program is to ultimately calculate out how much of a problem and which colors could pose problems to people with specific types of coloblindness in Rstudio's color themes.

### v0.2 Updates

The goal of my program is to show possible complications in color choices for each color theme in Rstudio. The user can choose which color theme and which type of color blindness and they can see if there could potentially be problems using the theme.

## Developer

Brandon Leff

## C++ Guide

### Variables and Data Types

I use variables in the process to extract lines from the text files.
```
int num_themes = 10;
```

#### v0.2 Updates

I use variables for many tasks in this project. I use string variables to read in files, integer varaibles for user input choice of which file, and integer variables to count how many colors could pose problems.
```
int redCount = 0;
int greenCount = 0;
int bothCount = 0;
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

### Functions

#### v0.2 Updates

In my program I use several functions to write output files, create string vectors, convert hex codes to english words, and display output to the user.

```
void create_outfile(string rfile);
int display_themes();
vector <string> convert_colors(string rfile_2);
void display_outcome(vector <string> convert_colors_vec);
```

## Stakeholder Interaction

After talking to my stakeholder, I was informed that my original idea of how to calculate how problematic the themes would be was not the best way to go at it. I was reccommended to display how many colors there were in the theme and then display how many problematic colors there would be as well as show the percentage breakdown of those problematic colors. I was also informed that my project is useful for identifying colors, but there's no guarantee that those colors are next to eachother in the rstudio UI that would even pose a problem of not being able to identify. I would like to look into this problem in the future if time allows for it. Overall, my conversation with the stakeholder went well however which motivated me to continue the work.
