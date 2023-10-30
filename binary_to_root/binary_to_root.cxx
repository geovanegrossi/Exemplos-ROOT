#include "binary_to_root.h"
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TTree.h>


using namespace std;

char* rootfname(const char* binfname)
{
  char* str = new char[100];
  char* dot;
  sprintf(str,"%s",binfname);
  dot = strstr(str,".dat");
  strcpy (dot,".root");
  return str;
}

void process_bin(const char *infile)
{

  ifstream EndPointsFile;
  EndPointsFile.open(infile);
  std::fstream file(infile, std::ios::in | std::ios::out | std::ios::binary);


  TFile* out = new TFile(rootfname(infile),"RECREATE");
  
  Int_t Amp;
  TTree *MyTree = new TTree("evt","evt");
  MyTree->Branch("Amp",&Amp,"Amp/I");
  
  const std::size_t N = 1024; // length of the buffer
  int32_t buf[N]; // our buffer

  file.seekg(0); // rewind to beginning 
  while(file.read((char*)buf, N * sizeof(int32_t)))
  // display the buffer
  for (std::size_t i = 0; i < N; ++i) // fill the buffer
    std::cout << buf[i] << " ";


  MyTree->Write();
  EndPointsFile.close();
  delete out;


}
	


