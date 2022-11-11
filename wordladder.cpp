#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;


// Returns a number of the shortest path from 'start' to 'target'
int shortestPath(
string start, string target,
set<string>& D
)

{

	if(start == target)
	return 0;
	
	//If the target word is not available in wordlist
	if (D.find(target) == D.end())
		return 0;
		
	//To store the current ladder length, and length of words	
	int level = 0, wordlength = start.size();
	
	//Initialize queue and push the first word in it
	queue<string> Q;
	Q.push(start);
		
		
	while (!Q.empty()) {

	++level;
	
	//Current size of the queue
	int queueSize = Q.size();
	
	for (int i = 0; i < queueSize; ++i) {

	//Removing the first word from the queue
	string word = Q.front();
	cout<< word << " ->";
	Q.pop();
	
	// For every character of the word
	for (int pos = 0; pos < wordlength; ++pos) {

	// Keep the original character at the current position
	char orig_char = word[pos];
	
	// Replace the current character with every possible lowercase alphabet
	for (char c = 'a'; c <= 'z'; ++c) {
	word[pos] = c;
	
	// If new word is equal to the target word
	if (word == target){
	return level + 1;
	}


	// Remove the word from the set if found in it	
	if (D.find(word) == D.end())

	continue;
	
	D.erase(word);

	// Push the newly generated word which will be part of the ladder
	Q.push(word);
	}
	
	
	//Restore the original character at current position
	word[pos] = orig_char;
	}
		}
	}

	return 0;

}

void getWords(string &word1, string &word2){
  while (true) {
    cout << "Please enter a word: ";
    cin>>word1;
    
    cout << "Please enter another word of the same length: ";
    cin>>word2;
    
    if (word1.length() == word2.length()) {
      break;
    }
    cout << "Please enter two words with the same length." << endl;
  }
  
}

//void print_path(string &start, string target, queue<string> Q){
//	 cout << "A ladder from " << target << " back to " << start << ":" << endl;
//    while (!Q.empty()) {
//        string s = Q.pop();
//        cout << s << " ";
//    }
//    cout << "\n" << endl;
//}


int main () {
	
	
		std::string start, target;
		getWords(start, target);
	
//		cout<<"Enter the first word of your choice: ";
//	    cin>> start;
//	    cout<<endl;
//	    
//	    cout<<"Enter the target, but ensure that it has the same length as your initial word: ";
//	    cin>>target;
//	    cout<<endl;
	
		std::ifstream in("EnglishWords.dat");

		
	
	// Read all words avalaible in the EnglishWordlist.dat file
    if (in) 
    {
		set<string> content;
        std::string line;
        while (std::getline(in, line))
        {
            content.insert(line);
        }
        
        cout << endl<< "\nLength of shortest chain is: "
		<< shortestPath(start, target, content);
        
    }


	return 0;
}
