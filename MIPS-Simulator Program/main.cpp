#include "functions.h"
using namespace std;

int add(int reg1, int reg2);
bool And(int reg1, int reg2);
int fileSize();
string lines(int inputLines, int lineNum); 
int addi();
int Or(int reg1, int reg2);
int sll(int reg1, int multNum);
void j(string jumpDest);

int numLines = fileSize();

string convertToString(string a[], int size);


int main() {
  ifstream input("input.txt");

  int regFile[32]= {0,0,0,0,0,0,0,0,0,0}; // creates register file

  int memCapacity = pow(2,15); // calculate dataMem capacity
  int dataMem[memCapacity]; // Data Memory
  regFile[0] = 0;
  regFile[1] = 0; //reserved for assembler
  regFile[26] = 0; // reserved for operating system
  regFile[27] = 0; // reserved for operating system
  int reg1, reg2, regStore;
  int sum;
  int lineNum = 0; // track line #
  int charCount = 0; // track length for line 
  map<string, int> instrMap; // keep track of branches
  //map<string,pair<string,int> >::iterator iter; // iterate through map
  string line;
  vector<string> linesTest;
  string instrArr[numLines];
  string firstWord[numLines];


  int i = 1; //current line
while (getline(input, line)){
        linesTest.push_back(line);
string firstW = line.substr(0, line.find(" "));

firstWord[i-1] = firstW;
int foundColon = line.find(':');
if (foundColon > 0 && foundColon < 20){
    
    instrMap.insert(std::make_pair(line, i)); // insert in map 
        instrArr[i-1]=line; // store instruction
   }
    else{
          instrArr[i-1]=line; // store instruction
    }
    i++;
  }


  string instruction;
  int positionArr[3];
for(int i = 0; i<numLines; i++)
{
  if(firstWord[i] == "addi"){
    instruction = instrArr[i];//add $r4, $r3, 1 // pulling string from array 
    int posArr[3];
    string regArr[3];
    int temp = instruction.find('r');
    int comma = instruction.find(',');
    string destreg = instruction.substr(temp+1, 1);
    regStore = stoi(destreg);

    string reg1str = instruction.substr(12,1);
    string reg2str = instruction.substr(15,'\n');
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);
    regFile[regStore]= addi(regFile[reg1], reg2);
  }
  else if(firstWord[i] == "add"){
    instruction = instrArr[i];//add $r4, $r3, 1 // pulling string from array 
    int posArr[3];
    string regArr[3];
  int temp = instruction.find('r');
  int comma = instruction.find(',');
    string destreg = instruction.substr(temp+1, 1);
    regStore = stoi(destreg);
    string reg1str = instruction.substr(11,1);
    string reg2str = instruction.substr(16,1);
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);
    regFile[regStore]= add(regFile[reg1], regFile[reg2]);
}

  else if(firstWord[i] == "sub"){
    instruction = instrArr[i];//add $r4, $r3, 1 // pulling string from array 
    int posArr[3];
    string regArr[3];
  int temp = instruction.find('r');
  int comma = instruction.find(',');
    string destreg = instruction.substr(temp+1, 1);
    regStore = stoi(destreg);
    string reg1str = instruction.substr(11,1);
    string reg2str = instruction.substr(16,1);
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);
    regFile[regStore]= sub(regFile[reg1], regFile[reg2]);
  }
  else if(firstWord[i] == "mul"){
    instruction = instrArr[i];//add $r4, $r3, 1 // pulling string from array 
    int posArr[3];
    string regArr[3];
  int temp = instruction.find('r');
  int comma = instruction.find(',');
    string destreg = instruction.substr(temp+1, 1);
    regStore = stoi(destreg);
    string reg1str = instruction.substr(11,1);
    string reg2str = instruction.substr(16,1);
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);
    regFile[regStore]= mul(regFile[reg1], regFile[reg2]);
  }
  else if(firstWord[i] == "and"){
      instruction = instrArr[i];//add $r4, $r3, 1 // pulling string from array 
    int posArr[3];
    string regArr[3];
  int temp = instruction.find('r');
  int comma = instruction.find(',');
    string destreg = instruction.substr(temp+1, 1);
    regStore = stoi(destreg);
    string reg1str = instruction.substr(11,1);
    string reg2str = instruction.substr(16,1);
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);
    regFile[regStore]= And(regFile[reg1], regFile[reg2]);
  }
  else if(firstWord[i] == "or"){
        instruction = instrArr[i];//add $r4, $r3, 1 // pulling string from array 
    int posArr[3];
    string regArr[3];
    int temp = instruction.find('$');
    int comma = instruction.find(',');
    string destreg = instruction.substr(temp+2, 1);
    regStore = stoi(destreg);
    //10
    //11
    //11

    string reg1str = instruction.substr(10,1);
    string reg2str = instruction.substr(15,'\n');
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);

    regFile[regStore]= Or(regFile[reg1], regFile[reg2]);
  }
  else if(firstWord[i] == "sll"){
    instruction = instrArr[i];//add $r4, $r3, 1 // pulling string from array 
    int posArr[3];
    string regArr[3];
    int temp = instruction.find('r');
    int comma = instruction.find(',');
    string destreg = instruction.substr(temp+1, 1);
    regStore = stoi(destreg);

    string reg1str = instruction.substr(11,1);
    string reg2str = instruction.substr(14,'\n');
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);
    regFile[regStore]= sll(regFile[reg1], reg2);
  }
  else if(firstWord[i] == "srl"){
    instruction = instrArr[i];//add $r4, $r3, 1 // pulling string from array 
    int posArr[3];
    string regArr[3];
    int temp = instruction.find('$');
    int comma = instruction.find(',');
    string destreg = instruction.substr(temp+2, 1);
    regStore = stoi(destreg);

    string reg1str = instruction.substr(11,1);
    string reg2str = instruction.substr(14,'\n');
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);

    regFile[regStore]= srl(regFile[reg1], reg2);
  }
  else if(firstWord[i] == "lw"){
    int offset;
    instruction = instrArr[i];
    int posArr[3];
    string regArr[3];
    int temp = instruction.find('$');
    int comma = instruction.find(',');
    string reg1str = instruction.substr(5,1);
    string reg2str = instruction.substr(12,1);
    string offsetstr = instruction.substr(8, 2);
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);
    offset = stoi(offsetstr);
    offset=offset/4;
    regFile[reg1] = regFile[reg2+offset];
  }
  else if(firstWord[i] == "sw"){
    int offset;
    instruction = instrArr[i];
    int posArr[3];
    string regArr[3];
    int temp = instruction.find('$');
    int comma = instruction.find(',');
    string reg1str = instruction.substr(5,1);
    string reg2str = instruction.substr(12,1);
    string offsetstr = instruction.substr(8, 2); 
    reg1 = stoi(reg1str);
    reg2 = stoi(reg2str);
    offset = stoi(offsetstr);
    offset = offset/4;
    dataMem[reg2+offset] = reg1;
  }
  else if(firstWord[i] == "beq"){
      int jumpLine = 0;
      instruction = instrArr[i];//add $r4, $r3, 1 // pulling string from array 
    int posArr[3];
    string regArr[3];
  int temp = instruction.find('r');
  int comma = instruction.find(',');
    string destreg = instruction.substr(temp+1, 1);
    regStore = stoi(destreg);
    string reg1str = instruction.substr(6,1);
    string reg2str = instruction.substr(11,'\n');

    regFile[regStore]= And(regFile[reg1], regStore);
    if(regFile[regStore] == 1){
      i = reg2-1;
      
      string locReg = instruction.substr(14, '\n');
      locReg = locReg + ':';
      reg1 = stoi(reg1str);
      reg2 = stoi(reg2str);

      if (beq(reg1, reg2) == true)
      {
        for (int j = 0; j < numLines; j++)
        {
          if(firstWord[j]==locReg)
          jumpLine = j;
        }
    i = jumpLine--;
    }
    }
  }
  else if(firstWord[i] == "j"){
    int jumpLine = 0;
    instruction = instrArr[i];
    int temp = instruction.find(' ');
    string locReg = instruction.substr(temp+1, '\n');
    locReg = locReg + ':';
    for (int j = 0; j < numLines; j++)
    {
      if(firstWord[j]==locReg)
      jumpLine = j;
    }
    //int branchLine = instrMap.begin()->second;
    i = jumpLine--;
  }
  else if(firstWord[i] == "nop"){
   instruction = instrArr[i];
   //does nothing?
   //like a stall
   // sll $zero, $zero, 0; <-- == to nop
  }
}
for (int i =0;i<10;i++){
  cout<< "r["<<i<<"] = "<<regFile[i]<<endl;
}
 return 0;
}

