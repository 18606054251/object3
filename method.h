#include<stdio.h>
#include<iostream>
using namespace std;
char* first();
void scan(FILE *f,int n);
void init(FILE *f);
pair<int,int> run(FILE *fp,int n,FILE *f);
void result(FILE *f,pair<int,int> p);
int ReadFile(FILE *f);

