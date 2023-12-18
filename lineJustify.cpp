// Demonstrates folding and unfolding
// Kaila Anderson
// October 17, 2022

#include <iostream>
#include <string>

using std::string; using std::cout; using std::cin; using std::endl; using std::getline;

void spaceAfterPunctuation(string&, int);
void randomSpace(string, int);

const int maxSize = 80;

int main() {

	cout << "Insert a string: " << endl;
	string unjust;
	getline(cin, unjust);

	int position = 0; 
	spaceAfterPunctuation(unjust, position); 
	if (unjust.size() < maxSize)
		randomSpace(unjust, position);
	else
		cout << "Your line justified is: " << endl << unjust;

}

void spaceAfterPunctuation(string& line, int pos) {

		pos = line.find_first_of("!?.,:");

		while (pos != line.size() - 1 && line.size() < maxSize) {
			
			line.insert(pos + 1, "  ");
			pos = line.find_first_of("?.,:!", pos + 1);
		}
		 
	
}

void randomSpace(string line, int pos) {
	pos = 0;
	
	while (line.size() < maxSize) {
		pos = rand() % 81; 
		pos = line.find_first_of(" ", pos);
		if (pos != maxSize - 1)
			line.insert(pos + 1, " ");
	}
	cout << "This is your line justified: " << endl << line << endl; 
}