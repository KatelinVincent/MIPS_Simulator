// functions.h
#ifndef functions_H
#define functions_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <cmath>
#include <vector>
#include <map>
#include <limits>

using namespace std;

// Convert array of characters to string 
string convertToString(string a[], int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

//fileSize: Complete
//Keeps track of the size of the input file
int fileSize(){
  int inputLines;
    ifstream input("input.txt");
  string line;

  while (getline(input, line)){
   ++inputLines;
}
return inputLines;
}

// adds the value held in two registers
int add(int reg1, int reg2){
  int sum = reg1+reg2;
  return sum;
}

//subtracts the value held in two registers
int sub(int reg1, int reg2){
  int product = reg1 - reg2;
  return product;
}

//adds the immediate value and register
int addi(int reg1, int value){
  int sum = reg1 + value;
 return sum; 
}

//Compares one (a) register to two (b, c) other registers, then outputs true (1) if a == b or c, and false (0) if a != b or c
int Or(int reg1, int reg2){
    int count=0;
  int diff = 0;
  // For first reg:
  std::list<int> list1;
  int Num1; // holds remainder
  int iterator1 = 0; // tracking iterations
  while (reg1 != 0 && reg1 != 1) // base case
  { 
    Num1 = reg1%2; // retrieving remainder
    list1.push_front(Num1); // push remainder for bi #
    reg1=reg1/2; // divide reg by 2
    iterator1++;
  }
  if (reg1==1){
  list1.push_front(1);// last remainder
  iterator1++; //account for last num
  }
  
  // for second reg:
  std::list<int> list2;
int Num2; // holds remainder
  int iterator2 = 0; // tracking iterations
  while (reg2 != 0 && reg2 != 1) //while loop turns a decimal to a binary number
  { 
    Num2 = reg2%2; // retrieving remainder
    list2.push_front(Num2); // push remainder for bi #
    reg2=reg2/2; // divide reg by 2
    iterator2++;
  }
  if (reg2==1) //catches the final number if it's a 1, and pushes a 1 into the binary number
  {
  list2.push_front(1);// last remainder
  iterator2++; //account for last num
  }
  if (iterator1>iterator2)//makes the binary numbers the same length by adding 0's on the front
  {
    count = iterator1;
    diff = iterator1-iterator2;
    for (int i=0;i<diff;i++)
    list2.push_front(0);

    for(int i = 0; i<count; i++){
    list2.pop_front();
    }
  }
  else if(iterator1<iterator2) //makes the binary numbers the same length by adding 0's on the front
  {
    count = iterator2;
    diff = iterator2-iterator1;
    for(int i = 0; i<diff; i++)
    list1.push_front(0);    
  }
  else {
    count = iterator1;
  }
int binArr[count];
  for (int x = 0;x<count;x++){

    if (list1.front() == 1 || list2.front() == 1){
    binArr[x]=1;
    list1.pop_front();
    list2.pop_front();
    }
    else{
      list1.pop_front();
      list2.pop_front();
      binArr[x]=0;
    }

  }
  for (int i = 0; i < count; i++){

    binArr[i]=binArr[i]*pow(2,i);

  }

  int total = 0;
  for (int i = 0; i < count; i++){
      total = total + binArr[i];
  }
  return total;
}

//Compares one (a) register to two (b, c) other registers, then outputs true (1) if a == b and c, and false (0) if a != b or c
bool And(int reg1, int reg2){
  int count=0;
  int diff = 0;
  // For first reg:
  std::list<int> list1;
  int Num1; // holds remainder
  int iterator1 = 0; // tracking iterations
  while (reg1 != 0 && reg1 != 1) // base case
  { 
    Num1 = reg1%2; // retrieving remainder
    list1.push_front(Num1); // push remainder for bi #
    reg1=reg1/2; // divide reg by 2
    iterator1++;
  }
  if (reg1==1){
  list1.push_front(1);// last remainder
  iterator1++; //account for last num
  }
  
  // for second reg:
  std::list<int> list2;
int Num2; // holds remainder
  int iterator2 = 0; // tracking iterations
  while (reg2 != 0 && reg2 != 1) //while loop turns a decimal to a binary number
  { 
    Num2 = reg2%2; // retrieving remainder
    list2.push_front(Num2); // push remainder for bi #
    reg2=reg2/2; // divide reg by 2
    iterator2++;
  }
  if (reg2==1) //catches the final number if it's a 1, and pushes a 1 into the binary number
  {
  list2.push_front(1);// last remainder
  iterator2++; //account for last num
  }
  if (iterator1>iterator2)//makes the binary numbers the same length by adding 0's on the front
  {
    count = iterator1;
    diff = iterator1-iterator2;
    for (int i=0;i<diff;i++)
    list2.push_front(0);
  }
  else if(iterator1<iterator2) //makes the binary numbers the same length by adding 0's on the front
  {
    count = iterator2;
    diff = iterator2-iterator1;
    for(int i = 0; i<diff; i++)
    list1.push_front(0);
  }
  else 
    count = iterator1;

  for (int i = 0;i<count;i++){
    if (list1.front() == 1 && list2.front() == 1)
    return true;
    else{
      list1.pop_front();
      list2.pop_front();
   }
  }
  return false;
}

// shifts binary numbers left x amount of timea
// effect: multiplies reg1 by 2, x amount times
int sll(int reg1, int factor){
  for (int facCount=0; facCount<factor;facCount++)
        reg1 = reg1*2;

    return reg1;
  }
// shifts binary numbers right x amount of timea
// effect: divides reg1 by 2, x amount times
  int srl(int reg1, int factor){
  for (int facCount=0; facCount<factor;facCount++)
        reg1 = reg1/2;

    return reg1;
  }

//multiplies two registers to get a product 
int mul(int reg1, int reg2)
{
  int product = reg1 * reg2;
  return product;
}
bool beq(int reg1, int reg2){
if (reg1 == reg2)
return true;
else
return false;
}

#endif