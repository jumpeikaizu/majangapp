#pragma once

#include<iostream>
#include<stack>
#include<stdlib.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstring>
using namespace std;

#define KIND 38
#define TEHAI 14

#define SYUNTSU 0
#define ANKO 1
#define TITOI 2
#define KOKUSHI 3

unsigned int r_gen(int n);

void init_genrand(unsigned long s);
unsigned long genrand_int32();
double genrand_real1(void);

string numchange(int kind);
int haichange(string h);
