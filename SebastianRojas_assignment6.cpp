//Sebastian Rojas
//Assignment 6
// 11/26/2023

#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

class StringVar {
public:
  StringVar(int size1); 
  // Initializes object to accept strings up to size1
  
  StringVar();
  // Initializes object to accept strings up to 100 chars
  
  StringVar(const char a[]);
  // Initializes from array a
  
  StringVar(const StringVar& string_object);
  // Copy constructor
  
  ~StringVar(); 
  // Frees memory
  
  int length() const;
  // Returns length of current string
  
  void input_line(istream& ins);
  // Inputs a line from ins into the string
  
  char* copy_piece(int start, int num); 
  // Returns substring from start index and of num chars 
  
  char one_char(int loc);
  // Returns character at index loc
  
  void set_char(int loc, char newChar);
  // Sets character at index loc to newChar
  
  bool operator==(const StringVar& rhs);
  // Checks if two strings are equal 
  
  StringVar operator+(const StringVar& rhs);
  // Concatenates two StringVar objects
  
  friend ostream& operator<<(ostream& outs, const StringVar& the_string);
  // Outputs value to stream outs
  
  friend istream& operator>>(istream& ins, StringVar& str);
  // Inputs one word from ins into str
  
private:
  char* value; 
  int max_length;
};

// Constructors and destructor
StringVar::StringVar(int size1) 
{
  max_length = size1;
  value = new char[max_length + 1]; 
  value[0] = '\0';
}

StringVar::StringVar() 
{
  max_length = 100;
  value = new char[max_length + 1];
  value[0] = '\0';  
}

StringVar::StringVar(const char a[]) 
{
  max_length = strlen(a);
  value = new char[max_length + 1];
  strcpy(value, a);
}

StringVar::StringVar(const StringVar& string_object) 
{
  max_length = string_object.length(); 
  value = new char[max_length + 1];
  strcpy(value, string_object.value);  
}

StringVar::~StringVar() 
{
  delete [] value;
}

// Existing member functions

int StringVar::length() const 
{
  return strlen(value); 
}

void StringVar::input_line(istream& ins) 
{
  ins.getline(value, max_length + 1);  
}

ostream& operator<<(ostream& outs, const StringVar& the_string) 
{
  outs << the_string.value;
  return outs;
}

// New member functions

char* StringVar::copy_piece(int start, int num) 
{
  char* result = new char[num+1];
  strncpy(result, value+start, num);
  result[num] = '\0';
  return result;
}

char StringVar::one_char(int loc) 
{
  return value[loc];
}

void StringVar::set_char(int loc, char newChar) 
{
  value[loc] = newChar; 
}

bool StringVar::operator==(const StringVar& rhs) 
{
  return strcmp(value, rhs.value) == 0;
}

StringVar StringVar::operator+(const StringVar& rhs) 
{
  int totalLen = strlen(value) + strlen(rhs.value);
  char* result = new char[totalLen + 1];
  strcpy(result, value);
  strcat(result, rhs.value);
  return StringVar(result);
}

istream& operator>>(istream& ins, StringVar& str) 
{
  ins >> str.value;
  return ins;  
}
int main() 
{

  StringVar s1(10);
  s1 = "Hello";
  cout << "s1: " << s1 << endl;

  StringVar s2 = s1.copy_piece(1, 3);
  cout << "s2: " << s2 << endl;

  if(s1 == "Hello") {
    cout << "Strings are equal" << endl;  
  }

  StringVar s3 = s1 + " World";
  cout << "s3: " << s3 << endl;

  StringVar word;
  cin >> word;
  cout << "Word: " << word << endl;

  StringVar s4(5);
  s4.set_char(2, 'X');
  cout << "s4: " << s4 << endl;

  char c = s1.one_char(1);
  cout << "Second char of s1: " << c << endl;

  return 0;
}