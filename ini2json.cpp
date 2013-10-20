// Copyright (c) 2013 Jonathan Sifuentes <jayands@gmail.com>

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:

// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cstdlib>
#include <cerrno>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

void parse_ini(std::istream &infile);
int main(int argc, char* argv[])
{

  std::ifstream infile;
  std::string str;
  if(argc > 1) {
    infile.open(argv[1], std::ios::in);
    if(!infile) {
      std::cerr << "Could not open file \"" << argv[1] << "\": " << std::strerror(errno) << std::endl;
      exit(EXIT_FAILURE);
    } else {
      parse_ini(infile);
      infile.close();
    }
  } else {
    //TODO read the person's ini code until the eof
    do {
      std::string buf;
      std::cin >> buf;
      str+= buf+((buf.find(',') != std::string::npos) ? " " : "\n");
    } while(std::cin.good());
    std::istringstream ifs(str);
    parse_ini(ifs);

  }
  exit(EXIT_SUCCESS);
}

void parse_ini(std::istream &infile)
{
  std::string line;
  bool braces_open = false, more_than_first = false;
  std::cout << "{" << std::endl;
  while(getline(infile, line)) {
    switch(line[0]) {
    case '[':
      if (braces_open) std::cout << "}, " << std::endl;
      std::cout << "\"" << line.substr(1,line.find("]")-1) << "\": {" << std::endl;
      braces_open=true;
      break;
    case '\0':
    case '\n':
      if (braces_open) std::cout << "}," << std::endl;
      braces_open = false;
      more_than_first = false;
      break;
    default:
      if (line.find("=") != std::string::npos) {
        int pos = line.find("=");
        if(more_than_first) std::cout << ", ";
        std::cout << "\"" << line.substr(0,pos) << "\":" << "\"";
        if (line.find(',') == std::string::npos) std::cout << << line.substr(pos+1) << "\"" << std::endl;
        more_than_first = true;
      } else {
        std::cout << line << std::endl;
      }
      break;
    }
  }
  if (braces_open) std::cout << "}" << std::endl;
  std::cout << "}" << std::endl;
}