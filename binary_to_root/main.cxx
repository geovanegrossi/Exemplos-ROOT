#include "binary_to_root.h"

using namespace std;

int main(int argc,char **argv){
  for(int i=1;i<argc;i++)
    process_bin(argv[i]);
  return 0;
}