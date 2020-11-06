#include <iostream>
#include <string.h>

#define PARAM_TEXT  1

using namespace std;

char usage[] = "./morse <text>";

// Numbers
const char * morse_code_num_table[10] = {
  // 0    , 1      , 2      , 3      , 4      , 5      , 6      , 7      , 8      , 9
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

// Alphabets
const char * morse_code_alpha_table[26] = {
  // A , B     , C     , D    , E  , F     , G    , H     , I   , J     , K    , L
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
  // M, N   , O    , P     , Q     , R    , S    , T  , U    , V     , W    , X
  "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
  // Y  , Z
  "-.--", "--.."
};

/**
 * Convert alphanumeric characters to Morse Code.
 */
char * convert_to_morse_code(char * text)
{
  unsigned int morse_code_len = 0;
  unsigned int ascii_int = 0;

  char * iter = text;

  /**
   * Allocate maximum memory for morse code.
   * Max len of morse code for a character is 5.
   * Total space = 5 * length of string (for morse characters)
   *             + length of string (for spaces)
   *             + 1 (null terminator)
   */
  char * morse_code = new char[(6 * strlen(text)) + 1];

  // Convert each character to morse.
  while ((*iter) != '\0')
  {
    // Need to check if character is within alphanumeric window.
    ascii_int = (int) *iter;

    // For "a-z"
    if (ascii_int >= 97 && ascii_int <= 122)
    {
      strcat(morse_code, morse_code_alpha_table[ascii_int - 97]);
    }
    // For "A-Z"
    else if (ascii_int >= 65 && ascii_int <= 90)
    {
      strcat(morse_code, morse_code_alpha_table[ascii_int - 65]);
    }
    // "For 0-9"
    else if (ascii_int >= 48 && ascii_int <= 57)
    {
      strcat(morse_code, morse_code_num_table[ascii_int - 48]);
    }
    else
    {
      cout << "Can't convert to morse code." << endl;
      exit(-1);
    }

    // Add space between letters.
    strcat(morse_code, " ");

    iter++;
  }

  return morse_code;
}

int main(int argc, char * argv[])
{
  if (argc != 2)
  {
    cout << usage << endl;
    return -1;
  }

  cout << convert_to_morse_code((char *) argv[PARAM_TEXT]) << endl;

  return 0;
}
