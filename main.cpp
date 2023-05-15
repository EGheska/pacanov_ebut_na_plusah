#include <iostream>
#include <cstring>
#include <sstream>
#include "fstream"
#include "ostream"

using namespace std;
int wordCount(std::string filename){
    int count=0;
    string line;
    ifstream file(filename);
    while(getline(file, line)){
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            count++;
        }
    }
    return count;
}

int lineCount(std::string filename){
    int count=0;
    string line;
    ifstream file(filename);
    while(getline(file, line)) {
        count++;
    }
    return count;
}

int symbolCount(std::string filename){
    int count=0;
    string line;
    char ch;
    ifstream file(filename);
    while(getline(file, line)){
        while(file.get(ch)){
            if (ch != ' ' && ch != '\t' && ch != '\n'){
                count++;
            }
        }
    }
    return count;
}

int longestLine(std::string filename){
    int size = 0;
    string line;
    ifstream file(filename);
    while(getline(file, line)){
        int lineSize =0;
        for(char c : line){
            if (c !='\n' && c != '\r'){
                lineSize++;
            }
        }
        if (lineSize > size){
            size = lineSize;
        }
    }
    return size;
}

int main(int argc, char** argv)
{
    int words = 0;
    int lines = 0;
    int symbols = 0;
    int longLine = 0;
    if (argc == 1) {
        words = wordCount("anna_karenina.txt");
        cout << "Number of words in text: "<< words << "\n";
        lines = lineCount("anna_karenina.txt");
        cout << "Number of lines in text: " << lines-1 << "\n";
        symbols = symbolCount("anna_karenina.txt");
        cout << "Number of symbols in text: " << symbols << "\n";
    }
    if (argc > 1){ // pacanov
        // TODO: size of line is 1 instead of the real size
        longLine = longestLine("anna_karenina.txt");
        cout << "Size of the longest line in text: " << longestLine << "\n";
    }
    if (argc > 2) { // ebut
        words = wordCount("anna_karenina.txt");
        cout << "Number of words in text: "<< words << "\n";
    }
    if (argc > 3) { // na
        lines = lineCount("anna_karenina.txt");
        cout << "Number of lines in text: " << lines-1 << "\n";
    }
    if (argc > 4) { // plusah
        // TODO: count of symbols is not correct
        symbols = symbolCount("anna_karenina.txt");
        cout << "Number of symbols in text: " << symbols << "\n";
    }
    return 0;
}