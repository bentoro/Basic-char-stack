#include <iostream>
#include "char_stack.h"
#include <iomanip> 
 
using namespace std;

//error message
void error(char c, char line[], int curLine, int ch){
		//count how many spaces/tabs
		int u = 1;
		//print first part of the line
		for (int k = 0; k<ch; k++){
			cout<<line[k];
			if(line[k] == '\t'){
				u+=8;
			}else {
				u++;
			}
		}

		cout<<endl;
		
		//print whitespace
		cout<<setw(u);

		//print rest of the line
		for (int j = ch; j<cin.gcount(); j++){
			cout << line[j];
		}

		cout << endl;
}

int main() {		
	char_stack s; //create stack
	char line[250]; //array to store line
	char li[250]; //store line if stack is empty
	char c, l; //store unprocessed character
	int ch, curLine = 0; //number of curLine

	//Scan untill end of file
	while(!cin.eof()){
			cin.getline(line, 250);
			for(int k = 0; k<cin.gcount(); k++){
				li[k]=line[k];
			}
	
		curLine++;
		ch=0;

			//search for character
			for (int i=0; i<cin.gcount(); i++){
				ch++;
				c = line[i];		
					if (c == '{' || c == '(' || c == '['){
						s.push(c);
					} 
					else if (c == '}' || c == ')' || c == ']'){
						if (s.empty()){
							cout << "Error on line " << curLine << ": Too many " << c << endl;
							error(c,line,curLine,ch);
							return 0;
					}	
		l = s.pop();
		switch(l){
			case '{':
				//if c doesnt match l
				if(c!='}'){
					cout << "Error on line " << curLine << ": Read " << c << ", expected }" << endl;
					error(c,line,curLine,ch);
					return 0;
			}break;
			case '(':
				//if c doesnt match l
				if(c!=')'){
					cout << "Error on line " << curLine << ": Read " << c << ", expected )" << endl;
					error(c,line,curLine,ch);
					return 0;
			}break;
			case '[':
				//if c doesnt match l
				if(c!=']'){
					cout << "Error on line " << curLine << ": Read " << c << ", expected ]" << endl;
					error(c,line,curLine,ch);
					return 0;
			}break;
		}
		}	
	}
	}
	
	//if stack is empty
	if (!s.empty()){
		c=s.pop();
		cout << "Error on line " << curLine-1 << ": Too many " << c << endl;
		cout<<li<<endl;
	} else {
		cout << "No Errors Found" << endl;
	}
    return 0;
}
