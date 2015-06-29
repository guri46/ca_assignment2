#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include <math.h> 
#include <string>
#include <fstream>
#include <string>
#include <ostream>

using namespace std;


const int ADDRESS_SIZE = 32;
int numSets =0;
int numIndexBits = 0;
int numOffsetBits = 0;
int numTagBits =0;


/* Usage */ 
void usage(void){
   printf("Usage:\n");
   printf(" -s <size of the cache in KB>\n");
   printf(" -b <size of the block in Bytes>\n");
   printf(" -f <trace file - containing memory accesses i.e. Loads and Stores>\n");
}

void calculateCacheValues(int s, int b, int w){
    numSets= s/(b*w);
    numIndexBits = log2(numSets);
    numOffsetBits = log2(b);
    numTagBits = ADDRESS_SIZE - (numIndexBits + numOffsetBits);

}

string hexToBinary(string hex){

  string bin ;
  for(int i=0;i<hex.length(); i++){
      switch(hex[i]){
        case '0': bin += "0000";  break;
        case '1': bin += "0001";  break;
        case '2': bin += "0010";  break; 
        case '3': bin += "0011";  break;
        case '4': bin += "0100";  break; 
        case '5': bin += "0101";  break;
        case '6': bin += "0110";  break;
        case '7': bin += "0111";  break;
        case '8': bin += "1000";  break;
        case '9': bin += "1001";  break;
        case 'a': bin += "1010";  break;
        case 'b': bin += "1011";  break;
        case 'c': bin += "1100";  break;
        case 'd': bin += "1101";  break;
        case 'e': bin += "1110";  break;
        case 'f': bin += "1111";  break;
        default : return "Invalid Address"; 
        
      }
  }

  return bin;

}


void splitAddress(string address, string &tag, int &offset, int &index ){



}




int main(int argc, char *argv[]){
  int c = -2;	// Default value if no arguments are passed
  opterr = 0;
  unsigned int cacheSize;
  unsigned int blockSize;
  unsigned int ways = 1; // Default number of ways
  string filename;


  while ((c = getopt (argc, argv, "s:b:w:f:")) != -1)
    switch (c)
      {
      case 's':
        cacheSize = atoi(optarg);
        break;
      case 'b':
        blockSize = atoi(optarg);
        break;
      case 'w':
        ways = atoi(optarg);
        break;
      case 'f':
        filename = optarg;
        break;
      case '?':
        if (optopt == 's' || optopt == 'b'){
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
          usage();
       }
        else if (isprint (optopt)){
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
          usage(); 
       }
        else{
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
       }
        return 1;
      default:
        usage();
      }
    if(c == -2){ // if no arguments are passed display usage
        usage();
        return 1;
    }

    cout << hexToBinary("bfedd7a4") << endl;


   // calculateCacheValues(cacheSize,blockSize,ways);



//Reading the trace file

    /*
  string address, instruct;
  ifstream infile(filename.c_str());

  while(infile >> address >> instruct){
    
  }

  */


}