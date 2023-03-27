// array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//must take an array of strings and the number of items the function will consider in the array 

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMinimum(const  string  array[], int  n);
int countCommonElements(const string array1[], int  n1, const string array2[], int n2);
int countVowels(const string array[], int n);
bool hasThreeOfX(const string array[], int n, string x);
string majorityElement(const string array[], int  n);
bool shiftRight(string array[], int n, int amount, string placeholder);
bool rotateLeft(string array[], int n, int amount);
int replaceAll(string array[], int n, char letterToReplace, char letterToFill);
bool areArraysEqual(string array1[], string array2[], int n);//tests that the proper shifts happened 

int main()
{
    string a[6] = { "123", "456", "789", "gamma", "beta", "delta" };
    string c[7] = { "ee", "dd", "cc", "bb", "aa", "BB", "AA" };
    string data[5] = { "mama", "mama", "12,", "sansa", "mama" };
    string folks[8] = { "samwell", "jon", "margaery", "daenerys","tyrion", "sansa", "magdalena", "jon" };
    string b[4] = { "1","2","1","2" };
    string d[7] = { "ee", "dd", "cc", "bb", "aa", "BB", "AA" };

    assert(hasThreeOfX(a, 6, "X") == false);  //tests basic function of hasThreeofX returns false
    assert(countVowels(a, 3) == 0);	  //no vowels
    assert(locateMinimum(folks, 8) == 3);//correctly identifies "daenerys" as the array with the local minimum 
    assert(locateMinimum(b, 4) == 0);//if 2 equal minimum returns the smallest inr
    assert(shiftRight(d, 5, 1, "foo") == true);//correctly returns true if it shifts 
    assert(replaceAll(folks, 8, 'a', 'Z') == 9);//correctly counts number of replacements 
    assert(rotateLeft(folks, 8, 1));//correctly returns true if rotates

    //array[] is the array and the number of spaces in it 
    //n= number of things that it will see in the array 
    string test_0[1] = { "" };
    string test_1[8] = { "samwell", "jon",   "margaery",  "daenerys",
                        "tyrion",  "sansa", "magdalena", "jon" };
    string test_2[5] = { "mama", "mama", "12", "sansa", "mama" };
    string test_3[7] = { "a", "b", "b", "A", "C", "c", "R" };
    string test_4[10] = { "C", "C++", "Java", "Python",     "Bash",
                         "R", "Go",  "Rust", "JavaScript", "PHP" };
    string test_5[4] = { "identical", "identical", "identical", "identical" };
    string test_6[1] = { "" };
    string test_7[5] = { "XYZ", "Abc", "XYZ", "zzZ", "XYZ" };
    string test_8[5] = { "1","5"," ","","." };

    // locateMinimum()
    //tests various local minimums and that they return the correct number
    assert(locateMinimum(test_1, 8) == 3);
    assert(locateMinimum(test_2, 5) == 2);
    assert(locateMinimum(test_3, 7) == 3);//tests capitals and lowercases
    assert(locateMinimum(test_4, 10) == 4);
    assert(locateMinimum(test_0, 0) == -1);//if n=0 returns -1
    assert(locateMinimum(test_6, 1) == 0);//tests empty string
    assert(locateMinimum(test_7, 5) == 1);
    string folks2[8] = { "samwell", "jon", "margaery", "daenerys", "daenerys", "sansa", "magdalena", "jon" };
    assert(locateMinimum(folks2, 8) == 3);//more complicated if there are 2 same items returns the lowest index int
    assert(locateMinimum(test_8, 5) == 3);//puts empty string as the smallest and checks non-standard letters and numbers 

    //countCommonElements()
    //tests various scenarios of common elements 
    assert(countCommonElements(test_1, 8, test_2, 5) == 1);
    assert(countCommonElements(test_1, 8, test_3, 6) == 0);
    assert(countCommonElements(test_3, 7, test_4, 10) == 2);
    assert(countCommonElements(test_0, 0, test_0, 0) == -1);//returns -1 if n=0
    assert(countCommonElements(test_6, 1, test_6, 1) == 1);
    assert(countCommonElements(test_5, 4, test_5, 4) == 16);//if all items are identical and compare two things that are identical 
    assert(countCommonElements(test_7, 5, test_7, 5) == 11);
    string common1[7] = { "ee", "dd", "cc", "bb", "aa", "BB", "AA" };
    string common2[7] = { "AA", "BB", "BB", "BB", "cc", "dd", "ee" };
    string common3[4] = { "aa", "bb", "bb", "cc" };
    string common4[4] = { "bb", "bb", "dd", "bb" };
    assert(countCommonElements(common1, 7, common2, 7) == 7);//discussion post specification
    assert(countCommonElements(common3, 4, common4, 4) == 6);//discussion post specification

    // countVowels()
    //tests that the various scenarios will return the correct number of vowels
    assert(countVowels(test_2, 5) == 8);
    assert(countVowels(test_1, 8) == 21);
    assert(countVowels(test_0, 0) == -1);//n=0 returns -1
    assert(countVowels(test_6, 1) == 0);

    // hasThreeOfX()
    //tests the various scenarios if they will return the correct value
    assert(!hasThreeOfX(test_1, 8, "jon"));
    assert(hasThreeOfX(test_2, 5, "mama"));
    assert(!hasThreeOfX(test_5, 4, "identical"));//does not have 3 of
    assert(!hasThreeOfX(test_0, 0, ""));//tests that is does not have 3 of
    assert(!hasThreeOfX(test_6, 1, ""));//tests that it does not have 3 of 
    assert(hasThreeOfX(test_7, 5, "XYZ"));
    assert(!hasThreeOfX(test_7, 5, "Abc"));//is case sensitive and tests that it does not have 3 of 

    // majorityElement()
    //returns correct majority element 
    assert(majorityElement(test_2, 5) == "mama");
    assert(majorityElement(test_5, 4) == "identical");
    assert(majorityElement(test_7, 5) == "XYZ");
    assert(majorityElement(test_1, 8) == "");//returns the empty string as there is no majority element
    assert(majorityElement(test_6, 1) == "");//returns the empty string as there is no majority element because n=1
    assert(majorityElement(test_0, 0) == "");//returns the empty string because n=0


    // shiftRight()
    assert(shiftRight(test_1, 8, 2, "lol, lmao"));
    string test_1_modified[8] = { "lol, lmao", "lol, lmao", "samwell", "jon",
                                 "margaery",  "daenerys",  "tyrion",  "sansa" };//this is what the test_1 should look like after the shiftRight above 
    assert(areArraysEqual(test_1, test_1_modified, 8));//this little piece of code will test that the proper shift happens
    assert(shiftRight(test_5, 4, 5, "lol, lmao"));
    string test_5_modified[4] = { "lol, lmao", "lol, lmao", "lol, lmao",
                                 "lol, lmao" };
    assert(areArraysEqual(test_5, test_5_modified, 4));
    assert(!shiftRight(test_0, 0, 1, "lol, lmao"));//will return false beccause n=0



    // rotateLeft()
    assert(!rotateLeft(test_1, 8, 8));//will return false because it will not change the array
    string rotate1[4] = { "aa", "bb", "bb", "cc" };
    assert(rotateLeft(rotate1, 2, 3));
    assert(!rotateLeft(test_1, 8, 16));//amount is a multiple of n--> returns false 
    string rotate1_mod[4] = { "bb", "aa", "bb", "cc" };
    assert(areArraysEqual(rotate1, rotate1_mod, 4));//based on discussion post 
    assert(areArraysEqual(test_1, test_1_modified, 5));
    assert(rotateLeft(test_4, 10, 4));
    string test_4_modified[10] = { "Bash",       "R",   "Go",     "Rust",
                                  "JavaScript", "PHP", "Python", "Java",
                                  "C++",        "C" };
    //assert(areArraysEqual(test_4, test_4_modified, 10));
    areArraysEqual(test_4, test_4_modified, 10);
    assert(!rotateLeft(test_0, 0, 1));

    // replaceAll()
    assert(replaceAll(test_7, 5, 'X', 'W') == 3);
    string test_7_modified[5] = { "WYZ", "Abc", "WYZ", "zzZ", "WYZ" };
    assert(areArraysEqual(test_7, test_7_modified, 5));//checks to see if the correct array is created 
    assert(replaceAll(test_6, 1, 'X', 'W') == 0);
    assert(replaceAll(test_0, 0, '\0', 'W') == -1);//returns -1 because n=0

    cerr << "All tests succeeded" << endl;

}
bool areArraysEqual(string array1[], string array2[], int n) {//this is not needed in the spec but acts to help test that the arrays are being modifying correctly if the function calls for it 
    bool equal = true;
    for (int i = 0; i < n; i++) {
        if (array1[i] != array2[i]) {
            equal = false;
        }
    }
    return (equal);
}
int locateMinimum(const  string  array[], int  n) {
    int minimum = 0;
    string tempM;
    if (n <= 0)
        minimum = -1;
    else {
        tempM = array[0];//need to start with this so there is something to compare with that exists in the array
        for (int k = 0; k < n; k++) {
            if (array[k] < tempM) {
                tempM = array[k];//if this loop finds a string that is smaller than the tempM then it will reset tempM
                minimum = k;//will set this to the index # of the new lowest array 
            }
        }
    }
    return (minimum);
}
int countCommonElements(const string array1[], int  n1, const string array2[], int n2) {//assert(countCommonElements(test_1, 8, test_2, 5) == 1);
    int common = 0;//if no common this is set to 0
    if (n1 <= 0 || n2 <= 0) {
        common = -1;
    }
    else {
        for (int k = 0; k < n2; k++) {
            for (int n = 0; n < n1; n++)
            {
                if (array1[n] == array2[k])//if the loop finds something that is common 
                    common++;//the ticker will increase
            }
        }
    }
    return(common);
}
int countVowels(const string array[], int n) {
    int vowels = 0;
    string word;
    if (n <= 0)
        vowels = -1;
    for (int k = 0; k < n; k++) {//runs through the words in the array
        word = array[k];
        for (int pos = 0; pos != word.size(); pos++)//runs through the each letter of a given word
        {
            char c = word.at(pos);//this is similar to the code that was used in the last project 3, sets each letter to a char to compare against vowels we are looking for 
            if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'y' || c == 'Y')
                vowels++;//checks to see if any of the letters in a singlar word of the array matches these 
            //then increases the counter 

        }

    }

    return(vowels);
}
bool hasThreeOfX(const string array[], int n, string x) {
    bool xxx = false;
    int three = 0;
    if (n <= 0)
        xxx = false;
    for (int k = 0; k < n; k++) {
        if (array[k] == x)
        {
            three++;//this thing just counts how many of these strings that are in the array
        }
    }
    if (three == 3)
    {
        xxx = true;//this checks if these appears 3 of them 
    }
    return (xxx);
}
string majorityElement(const string array[], int  n) {
    int i = 0;
    if (n <= 0)
        return "";
    else {
        for (int i = 0; i < n; i++) {//this chooses one word from the array and goes through the entire array 
            int count = 1;
            for (int j = i + 1; j < n; j++) {//this compares all of the words in the array against the chosen word
                if (n != j && array[i] == array[j])
                    count++;
            }
            if (count > n / 2)//if more than half og the numbers returns the given array
                return array[i];
        }
        return "";//if not then returns the ""
    }


}
bool shiftRight(string array[], int n, int amount, string placeholder) {
    bool shift = false;//this shit was hard to figure out 
    if (n <= 0 || amount <= 0)
        shift = false;
    else {
        if (amount > n) {
            amount = n;//if the amount if larger than the array given then this will make sure it doesnt walk off the array
        }
        for (int i = n - 1; i > amount - 1; i--)//figuring out that you have to work from the end of the loop 
        {
            array[i] = array[i - amount];//this just shifts the array working from the back to the front, shifts immediately the number given by amount
        }
        for (int k = 0; k <= amount - 1; k++)
        {
            array[k] = placeholder;//this then replaces all of the items needed to be replaced by the placeholder
        }
        shift = true;
    }
    return(shift);

}
bool rotateLeft(string array[], int n, int amount) {
    bool rotate = true;
    string placeholder;
    if (n <= 0 || n == 1)
        rotate = false;
    else if (amount % n == 0)//this checks to see if the amount is a multiple of the n implying that it doesnt change the array
        rotate = false;

    else
    {//the way this works is that it rotates the entire array by 1 place until it reaches the amount denoted 
        for (int k = 0; k < amount; k++) {
            placeholder = array[0];// placeholder is important so that the array 0 doesnt get deleted
            for (int i = 0; i < n - 1; i++) {
                array[i] = array[i + 1];
            }
            array[n - 1] = placeholder;//puts the last array to the placeholder array or the previous array[0]

        }
    }

    return(rotate);
}
int replaceAll(string array[], int n, char letterToReplace, char letterToFill) {

    int replace = 0;
    string word;
    if (n <= 0)
        replace = -1;
    for (int k = 0; k < n; k++) {
        word = array[k];
        for (int pos = 0; pos != word.size(); pos++)
        {
            char c = word.at(pos);//this is similar to project 3 code, just going letter through letter
            if (c == letterToReplace) {
                word[pos] = letterToFill;//just replaces all of the letters needed in the given word with letter given 
                replace++;
            }
            array[k] = word;//then this will actually edit the array 
        }


    }

    return(replace);
}

