#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_set<string> read_dictionary_file(){
	std::unordered_set<string> dictionary_words;
	//read permissions. 
	ifstream fs( "/usr/share/dict/words");
	string word;
	while (fs >>word){
		dictionary_words.insert(word);
	}
	return dictionary_words;
}
void all_possible_char_combo(vector<string> input_chars, unordered_set<string> &ret, size_t start=0){
	if (start==input_chars.size())
		return; 
	string construct_word=""; 
	for (size_t i=0; i< input_chars.size(); i++){
		construct_word+=input_chars[i];
		ret.insert(construct_word);
		swap(input_chars[start], input_chars[i]);
		all_possible_char_combo(input_chars, ret, start+1);
	}
}

int main(){
	std::unordered_set<string> dictionary_words;
	dictionary_words=read_dictionary_file();
	vector<string> input_chars={"r", "e", "i", "e", "a", "r","u"};
	unordered_set<string> possible_combinations={ };
	all_possible_char_combo(input_chars, possible_combinations);
	
	for (auto i: possible_combinations){
		if (i== "aerier" || i== "rare" )
			cout<<i<<endl;
		if (dictionary_words.find(i) != dictionary_words.end())
			cout<<i<<endl;
	}
	cout<<possible_combinations.size();
		
	//find all possible combinations with these letters :) check. 

	//check which ones are in library check. 

	//find a way to see the best scoring words-> score for letters. 

	//create file for file associated with number.  EASY? 
}