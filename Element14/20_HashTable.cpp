// pay attention to:
// * hash tables are like array but index with sth other than int
// * how to create, append, and display a hash table object
// * the use of iterator of a hash table unordered_map object
// * hash table works fast when insert, remove and retrieve entries
// * the MakeHash and ModelHash method for caculating the hash value
// * the long and short version of itr for traversal a hash table

#include <unordered_map>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// even a class could be the key for hash table
class Make {
	public:
		string Name;

	Make(string name) {
		Name = name;
	}

	bool operator==(const Make &make) const {
		return Name == make.Name;
	}
};

class Model {
	public:
		string Name;
		int Year;

	Model(string name, int year) {
		Name = name;
		Year = year;
	}

	bool operator==(const Model &model) const {
		return (Name == model.Name && Year == model.Year);
	}
};

class ModelHash {
	public:
		size_t operator()(const Model &model) const {
			return hash<string>()(model.Name) ^ hash<int>()(model.Year);
		}
};

class MakeHash {
	public:
		size_t operator()(const Make &make) const {
			return hash<string>()(make.Name);
		}
};

int main() {
	// create and initialize an unordered_map object
	unordered_map<string, string> hashtable;
	hashtable.emplace("www.element14.com","184.51.49.225");
	cout << "IP Address: " << hashtable["www.element14.com"] << endl;
	
	// append the unordered_map object
	hashtable.insert(make_pair("www.newark.com","184.51.50.121"));
	
	// display all of the data in the unordered_map obj
	//for(auto itr=hashtable.begin(); itr!=hashtable.end();itr++) {
		//cout << (*itr).first << ": " << (*itr).second << endl;
	// a short version of the itr as follows
	for(auto &itr : hashtable) {
		cout << itr.first << ": " << itr.second << endl;
	}

	Model camry2005("Camry", 2005);
	Model tercel1993("Tercel", 1993);
	Make toyota("Toyota");

	// key and value of a hash table could both be class objects
	unordered_map<Model, Make, ModelHash> model2make;
	model2make.emplace(camry2005, toyota);
	model2make.emplace(tercel1993, toyota);

	for (auto &itr : model2make) {
		cout << itr.first.Name << " " << itr.first.Year << ": " 
			<< itr.second.Name << endl;
	}
	
	unordered_map<Make, vector<Model>, MakeHash> make2model;
	vector<Model> toyotaModels;
	toyotaModels.push_back(camry2005);
	make2model.emplace(toyota, toyotaModels);
	make2model[toyota].push_back(tercel1993);
	
	for(auto &make : make2model) {
		cout << make.first.Name << ":" << endl;
		vector<Model> models = make.second;
		for(auto &model : models) {
			cout << "* " << model.Name << " " << model.Year << endl;
		}
	}
		
	return 0;
}
