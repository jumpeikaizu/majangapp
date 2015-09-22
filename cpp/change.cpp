#include<iostream>
#include<string>
#include"util.h"
using namespace std;

string hai[] = {"","m1","m2","m3","m4","m5","m6","m7","m8","m9",
				"","p1","p2","p3","p4","p5","p6","p7","p8","p9",
				"","s1","s2","s3","s4","s5","s6","s7","s8","s9",
				"","tn","nn","sy","pe","hk","ht","ch"};
string numchange(int kind){
  return hai[kind];
}
int haichange(string h){
  for(int i=0;i<38;i++){
	if(hai[i] == h){
	  return i;
	}
  }
  return 38;
}

