#include <iostream>
#include <string>
#include <format>
#include <vector>
using namespace std;

// Compiled all resource files into one execuable program
// Files used: frame.cpp, frame2.cpp, personalized_hello.cpp, vector_simple_demo.cpp

// vector_simple_demo.cpp
auto square(auto x) { return x * x; }

int vectorSimple()
{
    vector v = { 1, 2 }; // Init a vector of ints
    v.push_back(4); // Add an element on to the end

    for (int j = 0; j < v.size(); j++)
        cout << square(v[j]) << ", ";
    return 0;
}

// personalized_hello.cpp
int hello(string name)
{
    cout << format("Hello, {}!\n", name);
    return 0;
}

// frame2.cpp
int frame2(string name)
{
  // The message we intend to write
  const string greeting = format("Hello, {}!", name);
  const string mixed = "* " + string(greeting.size(), ' ') + " *\n";
  const string stars = string(mixed.size() - 1, '*') + "\n";

  cout << endl;
  cout << stars << mixed << format("* {} *\n", greeting) << mixed << stars << endl;

  return 0;
}

// frame.cpp
int frame(string name)
{

  // The message we intend to write
  string const greeting = "Hello, " + name + "!";

  // The number of blanks surrounding the greeting
  int const pad = 5;

  // Rows and columns to write
  const int rows = pad * 2 + 3;
  const auto cols = greeting.size() + pad * 2 + 2;

  cout << endl;

  for (int r = 0; r != rows; ++r) {
    // How many characters we have written in the row
    string::size_type c = 0;
    while (c != cols) {
      if (r == pad + 1 && c == pad + 1) {
        cout << greeting;
        c += greeting.size();
      } else {
        // On the border?
        if (r == 0 || r == rows - 1
          || c == 0 || c == cols - 1) {
          cout << "*";
        } else {
          cout << " ";
        }
        ++c;
      }
    }
    cout << endl;
  }
  return 0;
}

int main() {
    vectorSimple(); // vector_simple_demo.cpp
    string name;
    cout << "\nWhat's your name? "; // only one cout/cin
    cin >> name;
    hello(name); // personalized_hello.cpp
    frame(name); // frame.cpp
    frame2(name); // frame2.cpp
}