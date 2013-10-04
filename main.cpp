#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

void removeFirst (char *s) {
    if (*s == '\0') return;
    *s = *(s+1);
    removeFirst (s+1);
}

void printNum2Words(string value)
{
    cout << "My Input is " << value << endl;
    // check if empty
    if (value.empty()){
        cout << "empty" << endl;
        return;
    }
    // check if number is negative
    bool isNegative = false;
	if (value[0]=='-'){
        value.erase(0,1);
       isNegative = true;
    }
    if ((unsigned int )count(value.begin(),value.end(),'0')==value.length()){
        cout <<"zero" << endl;
        return;
    }

    int numLength = value.length();

    const char* ones[] =
    {"",        "one",     "two",       "three",    "four",
    "five",    "six",     "seven",     "eight",    "nine",
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };
    const char* tens[] =
    {
               "",        "twenty",    "thirty",   "fourty",
    "fifty",   "sixty",   "seventy",   "eighty",   "ninety"
    };
    const char* powers[] =
    {
    "",
    "thousand",           "million",            "billion",
    "trillion",           "quadrillion",        "quintillion"
    };
    const char* and_word = "and";

    // reverse my string
    reverse(value.begin(),value.end());

	//convert to numbers
	for (string::iterator myIt = value.begin();myIt!=value.end();++myIt)
        *myIt-='0';

	// arrange based on dictionary indice
	for (unsigned int n = 1; n < value.length(); n += 3)
		if (value[ n ]){
		  if (value[ n ] -= 1);
		  else value[ n - 1 ] += 10;
		 }
	// create buffer for grouping in threes
	value.append(3,'\0');

	unsigned int myIndex, myPower = 0;

	vector <const char*>	myWords;

	for (int n = 0; n < value.length() - 3; n += 3, myPower++)
    {
		vector <const char*>	wordGroup;
		myIndex = value[n+0];
		if(myIndex)
			wordGroup.push_back(ones[myIndex]);
		myIndex = value[n+1];
		if(myIndex)
			wordGroup.push_back(tens[myIndex]);
		myIndex = value[n+2];
		if(myIndex){
			wordGroup.push_back("hundred");
			wordGroup.push_back(ones[myIndex]);
		}
    if (wordGroup.size())
      {
      if (myPower) myWords.push_back( powers[ myPower ] );
      myWords.insert( myWords.end(), wordGroup.begin(), wordGroup.end() );
      }
    }

	if(isNegative)
		myWords.push_back("negative");

	// my answer
	string myAnswer;
	for (vector <const char*>::const_reverse_iterator  word = myWords.rbegin(); word != myWords.rend(); ++word){
		myAnswer.append(*word);
		cout << *word << " ";
	}
	cout << endl;
}


int main()
{
    cout << "Print Integers" << endl;

    string myNum = "125550";
    printNum2Words(myNum);

	string myNum2 = "123456789";
	printNum2Words(myNum2);
    return 0;
}
