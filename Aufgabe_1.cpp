#include "header.hpp"

int main(int argc, char **argv) {
	string tags;
	char flag = argv[1][1];
	vector<string> cont;
	if(argc == 3) {
		tags = argv[2];
	} else if (argc > 3) {
		tags = argv[2];
		for(int i = 3; i < argc; ++i) {
			string new_cont = argv[i];
			cont.push_back(new_cont);
		}
	} else	cout << "Wrong Arguments" << endl;

	vector<content> database = load_database();
	
	switch(flag) {
		case'a': add_content(tags, cont, database); break;
		case'q': print_tags(tags, database); break;
		default: cout << "Keine valid Flag!" << endl;
	}

		safe_database(database);
	return 0;
}
