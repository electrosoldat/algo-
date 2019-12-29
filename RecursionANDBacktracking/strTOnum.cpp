// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 
  
// Recursive function to convert 
// string to integer 
int stringToInt(string str) 
{ 
  
    // If the number represented as a string 
    // contains only a single digit 
    // then returns its value 
    if (str.length() == 1) 
        return (str[0] - '0'); 
  
    // Recursive call for the sub-string 
    // starting at the second character 
    double y = stringToInt(str.substr(1)); 
  
    // First digit of the number 
    double x = str[0] - '0'; 
  
    // First digit multiplied by the 
    // appropriate power of 10 and then 
    // add the recursive result 
    // For example, xy = ((x * 10) + y) 
    x = x * pow(10, str.length() - 1) + y; 
    return int(x); 
} 
  
// Driver code 
int main() 
{ 
    string str = "123485"; 
    cout << (stringToInt(str)) << endl; 
}
