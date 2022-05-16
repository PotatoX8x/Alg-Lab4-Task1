#pragma once
#include <iostream>
using namespace std;

struct Dictionary {
	char* element;
	Dictionary* next;
	static int dictSize;
};

Dictionary** Makenull(Dictionary**);
bool Member(const char*, Dictionary**);
void Insert(const char*, Dictionary**);
void Delete(const char*, Dictionary**);
void Print(Dictionary**);
int h(const char*);