#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class content {
private:
	string tags;
	vector<string> cont;
public:
	content(string t, vector<string> c) : tags(t), cont(c) {}
	vector<string> get_content() {
		return cont;
	}
	string get_tags() {
		return tags;
	}
};

vector<content> load_database();

vector<string> split(const string& input);

void add_content(string tag, vector<string> &cont, vector<content> &database);

void print_tags(string tag, vector<content> database);

void print_help();

void safe_database(vector<content> &database);

