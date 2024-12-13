#include <iostream>
#include <fstream>
#include <string>

void read_file(std::string){

}

int main (int argc, char *argv[]) {
  std::ofstream myfile;
  myfile.open("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();

  printf("Created a file `example.txt with some text in it.\n");
  return 0;
}
