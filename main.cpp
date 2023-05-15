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

int main(int argc, char** argv)
{
    int words = 0;
    int lines = 0;
    int symbols = 0;
    char ch;
    size_t longestLine = 0;
    if (!argv[1]) { // pacanov
        throw std::invalid_argument("Invalid argument");
    }
    if (argv[2]) { // ebut
        words = wordCount("anna_karenina.txt");
    }
    if (argv[3]) { // na
        lines = lineCount("anna_karenina.txt");
    }
    if (argv[4]) { // plusah
        symbols = symbolCount("anna_karenina.txt");
    }
    if (argv[5]) { // does not exist

    }
    cout << "Number of symbols in text: " << symbols << "\n";
    cout << "Number of lines in text: " << lines-1 << "\n";
    cout << "Number of words in text: "<< words;
    return 0;
}