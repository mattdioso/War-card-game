#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <algorithm>
using namespace std;

int start();
int war();
vector<int> p1;
vector<int> p2;
vector<int> warPot;

int main(int argc, char *argv[]) {
  if (argc <2) {
    cout<<"Error, not enough arguments"<<endl;
    return 0;
  }

  if (argc>2) {
    cout<<"Error, too many arguments"<<endl;
    return 0;
  }
  fstream file;
  string filename = argv[1];
  file.open(filename, ios::in);

  if (!file) {
    cout<<"Error opening file"<<endl;
    return 0;
  }

  string line;
  getline(file, line);
  int num;
  istringstream iss(line);
  while (iss >> num)
    p1.push_back(num);
  
  getline(file, line);
  istringstream is1(line);
  while (is1 >> num)
    p2.push_back(num);

  cout<<"Starting game"<<endl;
  int winner = start();
  if (winner ==1) {
    cout<<"Player 1 won"<<endl;
    return 0;
  }
  else if (winner ==0) {
    cout<<"TIE"<<endl;
    return 0;
  }
  else {
    cout<<"Player 2 won"<<endl;
    return 0;
  }
}

int war() {
  if (p1.size() == 0)
    return 2;
  if (p2.size() == 0)
    return 1;
  
  for (int i =0; i<2; i++) {
    warPot.push_back(p1.front());
    warPot.push_back(p2.front());
    p1.erase(p1.begin());
    p2.erase(p2.begin());
  }/*
  int p1War = p1.front();
  int p2War = p2.front();
   */
  int p1War = p1[3];  
  int p2War = p2[3];
  
  if (p1War > p2War) {
    for (int i =0; i<warPot.size(); i++) {
      p1.push_back(warPot.front());
      warPot.erase(warPot.begin());
    }
    return 1;
  }

  if (p2War > p1War) {
    for (int i =0; i<warPot.size(); i++) {
      p2.push_back(warPot.front());
      warPot.erase(warPot.begin());
    }
    return 2;
  }
  if (p1War == p2War)
    war();
}

int start() {
  if(p1.size() ==0 && p2.size() == 0)
    return 0;
  if (p1.size()==0)
    return 2;
  if (p2.size()==0)
    return 1;

  int p1Card=p1.front();
  int p2Card=p2.front();

  
  if (p1Card > p2Card) {
    cout<<"p1 won a round"<<endl;
    p1.push_back(p1Card);
    p1.push_back(p2Card);
    p1.erase(p1.begin());
    p2.erase(p2.begin());
  }
  if (p2Card > p1Card) {
    cout<<"p2 won a round"<<endl;
    p2.push_back(p1Card);
    p2.push_back(p2Card);
    p1.erase(p1.begin());
    p2.erase(p2.begin());
  }
  if (p1Card == p2Card) {
    int battle = war();
    if (battle ==1)
      cout<<"Player 1 won a war"<<endl;
    else
      cout<<"Player 2 won a war"<<endl;
  }
  return start();
}
