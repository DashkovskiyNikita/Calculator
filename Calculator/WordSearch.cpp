#include<iostream>;
#include<sstream>;
#include<vector>;
#include <algorithm>
#include <cctype>
using namespace std;


void toLowerCase(string& str) {
	transform(str.begin(), str.end(), str.begin(), tolower);
}

void wordSearch(istringstream* stream,string *search_word) {
	string str = *search_word;
	vector<string> words;
	string word;
	cout << "Search " << str << " result :" << endl;
	toLowerCase(str);
	while (*stream >> word) {
		string value = word;
		toLowerCase(value);
		if (value.length() >= str.length()) {
			bool isRight = true;
			for (int i = 0; i < str.length(); i++) {
				if (value[i] != str[i]) {
					isRight = !isRight;
					break;
				}
			}
			if (isRight) cout << word << endl;
		}
	}
}



int main() {
	string text, word;
	istringstream stream(text, istringstream::in);
	cin >> word;
	wordSearch(&stream, &word);

}