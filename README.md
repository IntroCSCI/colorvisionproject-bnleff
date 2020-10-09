# How do people with color blindness see Rstudio's themes?

## Description

The goal of my program is to ultimately calculate out how much of a problem and which colors could pose problems to people with specific types of coloblindness in Rstudio's color themes.

## Developer

Brandon Leff

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
!!!Replace with an example of the program running with user interaction!!!
```

## C++ Guide

### Variables and Data Types

I use variables in the process to extract lines from the text files.
```
int num_themes = 10;
```
### Input and Output

I am using cout to display lines from the text files.
```
cout >> content >> endl;
```
### Decisions

!!!Replace with a summary and examples of how multiple decision constructs have been used effectively and appropriately!!!

### Iteration

I use iteration to loop through the array of file names.

```
for(int file_index = 0; file_index < num_themes; file_index++) {
```

### File Input and Output

So far all my code is about file input. I am taking multiple text files and extracting lines that contain the word "color". 

```
ifstream file_stream;
    file_stream.open (themes[file_index], ios::in);
    if(!file_stream.is_open()) {
```
