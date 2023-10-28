# Coursework

This program is a tool for processing text in C language. It performs various operations on the entered text, including substring search, removal of specific characters, sorting of sentences, and more. The program is developed and created by Egor Grebnev as a part of the course work for option 5.11.

## Running the Program

The program runs in the command line. Make sure you have a C runtime environment and all necessary dependencies installed before starting.

1. **Compile and run the program**: Enter the following command in the terminal to compile the program:
   ```sh
   #compile
   make
   
   #run
   ./cw
   
   #clear
   make clean

4. **Debug the program (temporary disabeled)**: Enter the following command in the terminal to compile the program:
   ```sh
   #optional - name of file with tests
    ./debug <optinal>    
## Available Functions

1. **Basic Output**: Outputs the text after initial mandatory processing.
2. **Substring Search by Format**: For each substring in the text representing time in the format "hours:minutes," it outputs the sentence number where it occurs and the number of minutes until the current time.
3. **Removal of Uppercase Letters**: Removes all uppercase Latin letters in each sentence.
4. **Sorting**: Sorts sentences in descending order of the number of Cyrillic letters.
5. **Remove Sentences**: Removes all sentences that do not contain special characters.
6. **Help**: Displays help information about the functions.

## Example Usage

Input text into the program.
Choose one of the available commands (0-5) corresponding to the function you want to perform.
The program will execute the chosen operation and display the result.

## Dependencies

C Runtime Environment
Libraries: stdio.h, locale.h, ctype.h, wctype.h, wchar.h, and stdarg.h

## Author

- Egor Grebnev

## License

- This project is licensed under the MIT License. You are free to use, modify, and distribute this code.
