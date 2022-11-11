#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

// g++ -std=c++11 solution.cpp -o a && ./a

using namespace std;

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

void solve(int N, vector<string> records){
  bool allValid = true;
  vector<string> errorCodes;
  for(string record : records){
    vector<string> r = split(record, ' ');
    bool isValid;
    istringstream(r[1]) >> isValid;
    if(allValid)
      allValid = isValid;
    if(!isValid)
      errorCodes.push_back(r[2]);
  }

  if(allValid)
    cout << "Yes" << endl;
  else{
    cout << "No" << endl;
    for(string code : errorCodes){
      cout << code << " ";
    }
  }
}

int main (int argc, char *argv[]) {
  // get input from stdin
  int N = 0;
  vector<string> records;
  int i = 0;
  for(string line; getline(cin, line);){
    cout << line << endl;
    if(!N) N = stoi(line);
    else{
      if(i<N){
        records.push_back(line);
        i++;
      }else{
        break;
      }
    }
  }

  solve(N, records);

  return 0;
}