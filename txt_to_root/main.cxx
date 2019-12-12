#include "txt_to_root.h"

using namespace std;

int main(int argc,char **argv){
  for(int i=1;i<argc;i++)
    ReadEvtFile(argv[i]);
  return 0;
}

