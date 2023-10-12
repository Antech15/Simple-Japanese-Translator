#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// holds each translation in a pair

/* Look for all **'s and complete them */

//=====================================================
// File mytranslator.cpp written by: Group Number: 3
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA
// Done by: Reese Hodge
// RE: (vowel | vowel n | consonant vowel | consonant vowel n | consonant-pair
// vowel | consonant-pair vowel n)^+
bool word(string s) {
  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0') {

    // STATE 0
    if (state == 0 &&
        (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' ||
         s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'o' ||
         s[charpos] == 'u'))
      state = 7;
    else if (state == 0 &&
             (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' ||
              s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' ||
              s[charpos] == 'p' || s[charpos] == 'r'))
      state = 4;
    else if (state == 0 &&
             (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
              s[charpos] == 'y' || s[charpos] == 'j'))
      state = 2;
    else if (state == 0 && s[charpos] == 's')
      state = 5;
    else if (state == 0 && s[charpos] == 'c')
      state = 6;
    else if (state == 0 && s[charpos] == 't')
      state = 3;

    // STATE 1
    else if (state == 1 && s[charpos] == 'n')
      state = 0;

    // STATE 2
    else if (state == 2 &&
             (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' ||
              s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'o' ||
              s[charpos] == 'u'))
      state = 7;

    // STATE 3
    else if (state == 3 &&
             (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' ||
              s[charpos] == 'E' || s[charpos] == 'E' || s[charpos] == 'o' ||
              s[charpos] == 'u'))
      state = 7;
    else if (state == 3 && s[charpos] == 's')
      state = 2;

    // STATE 4
    else if (state == 4 &&
             (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' ||
              s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'o' ||
              s[charpos] == 'u'))
      state = 7;
    else if (state == 4 && s[charpos] == 'y')
      state = 2;

    // STATE 5
    else if (state == 5 &&
             (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' ||
              s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'o' ||
              s[charpos] == 'u'))
      state = 7;
    else if (state == 5 && s[charpos] == 'h')
      state = 2;

    // STATE 6
    else if (state == 6 && s[charpos] == 'h')
      state = 2;

    // STATE 7
    else if (state == 7 &&
             (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' ||
              s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'o' ||
              s[charpos] == 'u'))
      state = 7;
    else if (state == 7 &&
             (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' ||
              s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' ||
              s[charpos] == 'r'))
      state = 4;
    else if (state == 7 &&
             (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
              s[charpos] == 'y' || s[charpos] == 'j'))
      state = 2;
    else if (state == 7 && s[charpos] == 's')
      state = 5;
    else if (state == 7 && s[charpos] == 'c')
      state = 6;
    else if (state == 7 && s[charpos] == 't')
      state = 3;
    else if (state == 7 && s[charpos] == 'n')
      state = 8;

    // STATE 8
    else if (state == 8 &&
             (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' ||
              s[charpos] == 'E' || s[charpos] == 'I' || s[charpos] == 'o' ||
              s[charpos] == 'u'))
      state = 7;
    else if (state == 8 &&
             (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' ||
              s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' ||
              s[charpos] == 'p' || s[charpos] == 'r'))
      state = 4;
    else if (state == 8 &&
             (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
              s[charpos] == 'y' || s[charpos] == 'j'))
      state = 2;
    else if (state == 8 && s[charpos] == 's')
      state = 5;
    else if (state == 8 && s[charpos] == 'c')
      state = 6;
    else if (state == 8 && s[charpos] == 't')
      state = 3;
    else
      return false;

    charpos++;
  } // end of while

  // where did I end up????
  if (state == 0 || state == 7 || state == 8)
    return (true); // end in a final state
  else
    return (false);
}

// PERIOD DFA
// Done by: Reese Hodge
bool period(string s) {
  int state = 0;
  int charpos = 0;

  // checks for single period
  while (s[charpos] != '\0') {
    if (state == 0 && s[charpos] == '.')
      state = 1;
    else
      return false;
    charpos++;
  }
  if (state == 1)
    return (true);
  else
    return (false);
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: Andres Hinojosa

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {
  ERROR,
  WORD1,
  WORD2,
  PERIOD,
  EOFM,
  VERB,
  VERBNEG,
  VERBPAST,
  VERBPASTNEG,
  IS,
  WAS,
  OBJECT,
  SUBJECT,
  DESTINATION,
  PRONOUN,
  CONNECTOR
};

// ** For the display names of tokens - must be in the same order as the
// tokentype.
string tokenName[30] = {"ERROR",       "WORD1",       "WORD2",   "PERIOD",
                        "EOFM",        "VERB",        "VERBNEG", "VERBPAST",
                        "VERBPASTNEG", "IS",          "WAS",     "OBJECT",
                        "SUBJECT",     "DESTINATION", "PRONOUN", "CONNECTOR"};

// ** Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.
string reservedwords[19] = {
    "masu", "masen",   "mashita",  "masendeshita", "desu", "deshita", "o",
    "wa",   "ni",      "watashi",  "anata",        "kare", "kanojo",  "sore",
    "mata", "soshite", "shikashi", "dakara",       "eofm"};

// ------------ Scanner and Driver -----------------------

ifstream fin;  // global stream for reading from the input file
ofstream fout; // global stream for writing to the output file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Hilda Antonio & Andres Hinojosa
int scanner(tokentype &tt, string &w) {
  // Grab the next word from the file via fin
  fin >> w;
  cout << "Scanner called using word: " << w << endl;
  // 1. If it is eofm, return right now.
  if (w == "eofm") {
    return 1;
  }
  /*
    2. Call the token functions (word and period)
    one after another (if-then-else).
    Generate a lexical error message if both DFAs failed.
    Let the tokentype be ERROR in that case.
  */

  // resets the token type
  tt = ERROR;

  // calls word
  if (word(w)) {

    // Checks to see if it is WORD1 or WORD2
    if (w[w.length() - 1] == 'a' || w[w.length() - 1] == 'e' ||
        w[w.length() - 1] == 'i' || w[w.length() - 1] == 'o' ||
        w[w.length() - 1] == 'u' || w[w.length() - 1] == 'n') {
      tt = WORD1;
    } else if (w[w.length() - 1] == 'I' || w[w.length() - 1] == 'E') {
      tt = WORD2;
    }

    // If word is in reservedwords
    for (int i = 0; i < 19; i++) {
      if (w == reservedwords[i]) {

        // match index with its token type
        switch (i) {
        case 0:
          tt = VERB;
          return i;
        case 1:
          tt = VERBNEG;
          return i;
        case 2:
          tt = VERBPAST;
          return i;
        case 3:
          tt = VERBPASTNEG;
          return i;
        case 4:
          tt = IS;
          return i;
        case 5:
          tt = WAS;
          return i;
        case 6:
          tt = OBJECT;
          return i;
        case 7:
          tt = SUBJECT;
          return i;
        case 8:
          tt = DESTINATION;
          return i;
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
          tt = PRONOUN;
          return i;
        case 14:
        case 15:
        case 16:
        case 17:
          tt = CONNECTOR;
          return i;
        case 18:
          tt = EOFM;
          return i;
        }
      }
    }
  } else if (period(w)) { // If not word, check if it is a period
    tt = PERIOD;
    return 18;
  }
  /* Generating a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.*/

  // Has not been accepted by word or period

  if (tt == ERROR)
    cout << "Lexical error: " << w << " is not a valid token" << endl;

  /*
    3. If it was a word,
    check against the reservedwords list.
    If not reserved, tokentype is WORD1 or WORD2
    decided based on the last character.

  4. Return the token type & string  (pass by reference)
  */
  return 0;
} // the end of scanner

// The temporary test driver to just call the scanner repeatedly
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!!
// Done by:  Louis

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.

// Type of error: Match fails
// Done by: Hilda Antonio
void syntaxerror1(string thang, tokentype tt) {
  cout << "SYNTAX ERROR: expected " << tokenName[tt] << " but found " << thang
       << endl;
  exit(1);
}
// Type of error: Switch default
// Done by: Hilda Antonio
void syntaxerror2(string lexeme, string func) {
  cout << "SYNTAX ERROR: unexpected " << lexeme << " found in " << func << endl;
  exit(1);
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme
tokentype saved_token;
string saved_lexeme;
bool token_available;

// holds each translation in a pair
vector<pair<string, string> > d;
string savedEword;


//Done by: Andres Hinojosa
void getEword() {
  savedEword = saved_lexeme;
  for (int i = 0; i < d.size(); i++) {
    if (d[i].first == savedEword) {
      savedEword = d[i].second;
      return;
    }
  }
}

//Done by: Hilda Antonio
void gen(string thang) {
  fout << thang << ": ";
  if (thang == "TENSE")
    fout << tokenName[saved_token] << endl;
  else
    fout << savedEword << endl;
}

// Purpose: Looks ahead to see what token comes next from the scanner
// Done by: Andres Hinojosa
tokentype next_token() {
  if (!token_available) {
    scanner(saved_token, saved_lexeme);

    token_available = true;
  }
  return saved_token;
}

// Purpose: Checks and eats up the expected token
// Done by: Andres Hinojosa
bool match(tokentype expected) {
  if (next_token() != expected) {
    syntaxerror1(saved_lexeme, expected);
    return false;
  } else {
    token_available = false;
    cout << "Matched " << tokenName[expected] << endl;
    return true;
  }
}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: WORD1 | PRONOUN
// Done by: Hilda Antonio
void noun() {
  cout << "Processing <noun>" << endl;
  switch (next_token()) {
  case WORD1:
    match(WORD1);
    break;

  case PRONOUN:
    match(PRONOUN);
    break;

  default:
    syntaxerror2(saved_lexeme, "noun");
  }
}

// Grammar: WORD2
// Done by: Reese Hodge
void verb() {
  cout << "Processing <verb>" << endl;
  match(WORD2);
}

// Grammar: IS | WAS
// Done by: Andres Hinojosa
void be() {
  cout << "Processing <be>" << endl;
  switch (next_token()) {
  case IS:
    match(IS);
    break;

  case WAS:
    match(WAS);
    break;

  default:
    syntaxerror2(saved_lexeme, "be");
  }
}

// Grammar: VERBPAST | VERBPASTNEG | VERB | VERBNEG
// Done by: Hilda Antonio
void tense() {
  cout << "Processing <tense>" << endl;
  switch (next_token()) {
  case VERBPAST:
    match(VERBPAST);
    break;

  case VERBPASTNEG:
    match(VERBPASTNEG);
    break;

  case VERB:
    match(VERB);
    break;

  case VERBNEG:
    match(VERBNEG);
    break;

  default:
    syntaxerror2(saved_lexeme, "tense");
  }
}

// Grammar: <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD | <noun> #getEword# DESTINATION #gen(TO)# <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD 
// Done by: Reese Hodge
void after_object() {
  cout << "Processing <after_object>" << endl;
  switch (next_token()) {
  case WORD2:
    verb();
    getEword();
    gen("ACTION");
    tense();
    gen("TENSE");
    match(PERIOD);
    break;

  case WORD1:
  case PRONOUN:
    noun();
    getEword();
    match(DESTINATION);
    gen("TO");
    verb();
    getEword();
    gen("ACTION");
    tense();
    gen("TENSE");
    match(PERIOD);
    break;

  default:
    syntaxerror2(saved_lexeme, "after_object");
  }
}

// Grammar: <be> #gen(DESCRIPTION)# #gen(TENSE)# PERIOD | DESTINATION #gen(TO)# <verb> #getEword# #gen(ACTION)# <tense>  #gen(TENSE)# PERIOD | OBJECT #gen(OBJECT)# <after object> 
// Done by: Andres Hinojosa
void after_noun() {
  cout << "Processing <after_noun>" << endl;
  switch (next_token()) {
  case IS:
  case WAS:
    be();
    gen("DESCRIPTION");
    gen("TENSE");
    match(PERIOD);
    break;

  case DESTINATION:
    match(DESTINATION);
    gen("TO");
    verb();
    getEword();
    gen("ACTION");
    tense();
    gen("TENSE");
    match(PERIOD);
    break;

  case OBJECT:
    match(OBJECT);
    gen("OBJECT");
    after_object();
    break;

  default:
    syntaxerror2(saved_lexeme, "after_noun");
  }
}

// Grammar: <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD | <noun> #getEword# <after noun> 
// Done by: Hilda Antonio
void after_subject() {
  cout << "Processing <after_subject>" << endl;
  switch (next_token()) {
  case WORD2:
    verb();
    getEword();
    gen("ACTION");
    tense();
    gen("TENSE");
    match(PERIOD);
    break;

  case WORD1:
  case PRONOUN:
    noun();
    getEword();
    after_noun();
    break;

  default:
    syntaxerror2(saved_lexeme, "after_subject");
  }
}

// Grammar: [CONNECTER #getEword# #gen(CONNECTOR)#] <noun> #getEword# SUBJECT #gen(ACTOR)# <after subject>
// Done by: Reese Hodge
void s() {
  cout << "Processing <s>" << endl;
  if (next_token() == CONNECTOR) {
    match(CONNECTOR);
    getEword();
    gen("CONNECTOR");
  }

  noun();
  getEword();

  match(SUBJECT);
  gen("ACTOR");

  after_subject();
}

// Grammar: <s> {<s>}
// Done by: Andres Hinojosa
void story() {
  cout << "Processing <story>\n" << endl;
  s();

  while (true) {
    switch (next_token()) {
    case CONNECTOR:
    case WORD1:
    case PRONOUN:
      fout << endl;
      s();
      break;

    default:
      cout << "\n Succesfully parsed <story>." << endl;
      return;
    }
  }
}

string filename;

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  Reese Hodge
int main() {

  string tempj;
  string tempe;

  cout << "Project group 3: Andres Hinojosa, Hilda Antonio, Reese Hodge" << endl;

  fin.open("lexicon.txt");
  //Done by: Reese Hodge
  while (fin >> tempj) {
    fin >> tempe;
    d.push_back(make_pair(tempj, tempe));
  }
  fin.close();

  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());
  fout.open("translated.txt");

  //** calls the <story> to start parsing
  story();

  //** closes the input and output file
  fin.close();
  fout.close();
} // end
  //** require no other input files!
  //** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
