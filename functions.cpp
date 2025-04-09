#include "header.hpp"

vector<string> split(const string& input, char delimiter) {
	vector<string> tags;
	istringstream iss(input);
	string tag;

	while (getline(iss, tag, delimiter)) 
		tags.push_back(tag);
	return tags;
}

vector<content> load_database() {
	ifstream datei("database.txt");
	string tags, cont, line;
	vector<content> database;
	if(datei.is_open()) {
		while(getline(datei, line)) {
			vector<string> split_line = split(line, ' ');
			tags = split_line.front();	
			split_line.erase(split_line.begin());
			content newContent(tags, split_line);
			database.push_back(newContent);
		}
		datei.close();
	} else {
		cout << "Fehler beim Öffnen der Datei" << endl;
	}
	return database;
}

void print_tags(string tag, vector<content> database) {
	bool erased = false;
	vector<string> wanted_tags = split(tag, ',');
	for(size_t i = 0; i < database.size(); ++i) {
		erased = false;
		vector<string> tags = split(database[i].get_tags(), ',');
		for(auto c : wanted_tags) {
			for(auto d : tags) {
				if(c == d) {
					vector<string> cont = database[i].get_content();
					for(auto l : cont) {
						cout << l << " ";
					}
					cout << "\n";
					database.erase(database.begin() + i);
					erased = true;
					break;
				}
			}
		if(erased) break;
		}
	if(erased) --i;
	}
}

void add_content(string tag, vector<string> &cont, vector<content> &database) {
	//cout << "content added" << endl;
	content newContent(tag, cont);
	database.push_back(newContent);
}

void safe_database(vector<content> &database) {
	ofstream datei("database.txt");
	if(datei.is_open()) {
		for(auto c : database) {
			datei << c.get_tags();
			vector<string> cont = c.get_content();
			for(auto s : cont) {
				datei << " " << s;
			}
			datei << "\n";
		}
		datei.close();
	} else {
		cout << "Fehler beim speichern der Database" << endl;
	}
}

