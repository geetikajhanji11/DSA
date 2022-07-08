#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

// ************* SSTREAM *************
void sstreamTokenization() {

    // taking input from user
    string input;
    getline(cin, input);

    // create a string stream object
    stringstream buffer(input);

    // >> and << operators
    string token;
    vector<string> tokens;
    char delimiter = ' '; // can be changed to , or . or /... anything
    while(getline(buffer, token, delimiter)) {
        tokens.push_back(token);
    }

    cout<<"\nAll tokens are:\n";
    for(string token : tokens) {
        cout<<token<<endl;
    }

}

// ************* STRTOK *************
void strtokTokenization() {
    char input[1000];
    cin.getline(input, 1000);

    char *token = strtok(input, " ");

    while(token != NULL) {
        cout<<token<<endl;
        token = strtok(NULL, " ");
    }
}

// ************* MY TOKEN *************
char *my_strtok(char *str, char delimiter) {
    
    static char *input = NULL;
    
    if(str != NULL) {
        input = str;
    }
    
    if(input == NULL) {
        return NULL;
    }

    char *token = new char[strlen(input) + 1];
    int i = 0;

    for( ; input[i] != '\0'; i++) {
        
        // generating token if del is not encountered
        if(input[i] != delimiter) {
            token[i] = input[i];
        } 
        
        // if del is encountered, return token
        else {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }

    // last token
    token[i] = '\0';

    // reset input
    input = NULL;

    // return token
    return token;
}

// ************* MAIN *************
int main() {

    // sstreamTokenization();
    // strtokTokenization();

    // using own token
    char s[1000];
    cin.getline(s, 1000);

    char *token = my_strtok(s, ' ');

    cout<<"\nAll tokens:\n";
    while(token != NULL) {
        cout<<token<<endl;
        token = my_strtok(NULL, ' ');
    }

    return 0;
}

