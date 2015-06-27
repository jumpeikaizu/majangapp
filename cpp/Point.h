#pragma once

#include<vector>
#include<cstring>
#include"agari.h"
#include"util.h"
using namespace std;

extern double alpha;

class Point{
	int tehai[KIND];
	int dora;
	void nuki_mentsu(int num,int k,vector<int> mentsu,vector<agari> &V,int last_kind,int atama);
	void kokushi(int k,vector<int> mentsu,vector<agari> &V);
	void titoi(int num,int k,vector<int> mentsu,vector<agari> &V);

public:
	Point(int init_tehai[KIND],int init_dora){
		memset(tehai,0,sizeof(tehai));
		for(int i=0;i<KIND;i++)
			tehai[i]=init_tehai[i];

		dora=init_dora;
	}
	void print_tehai(){
		for(int i=0;i<KIND;i++)
			for(int j=0;j<tehai[i];j++)
				cout<<i<<" ";
		cout<<endl;
	}
	int calc_point(int last_kind);
};

class multi_Point{
	int tehai[KIND];
	int M_tehai[KIND];
	int dora;
	vector<int> history;
	void nuki_mentsu(int num,int k,vector<int> mentsu,vector<agari> &V,int atama);
	void kokushi(int k,vector<int> mentsu,vector<agari> &V);
	void titoi(int num,int k,vector<int> mentsu,vector<agari> &V);
public:
	multi_Point(int init_tehai[KIND],int init_dora,vector<int> init_history,int init_M_tehai[KIND]){
		history=init_history;//最後の牌を特定するために必要
		memset(tehai,0,sizeof(tehai));
		for(int i=0;i<KIND;i++){
			tehai[i]=init_tehai[i];
			M_tehai[i]=init_M_tehai[i];
		}
		dora=init_dora;
	}
	void print_tehai(){
		for(int i=0;i<KIND;i++)
			for(int j=0;j<tehai[i];j++)
				cout<<i<<" ";
		cout<<endl;
	}
        vector<double> calc_point(vector<int> &count);

};
