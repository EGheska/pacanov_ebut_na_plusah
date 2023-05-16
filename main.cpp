#include <iostream>
#include <sstream>
#include "fstream"
#include "ostream"

using namespace std;

int wordCount(std::string filename) {
    int count = 0;
    string line;
    ifstream file(filename);
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            count++;
        }
    }
    return count;
}

int lineCount(std::string filename) {
    int count = 0;
    string line;
    ifstream file(filename);
    while (getline(file, line)) {
        count++;
    }
    return count;
}

int symbolCount(std::string filename) {
    int count = 0;
    string line;
    char ch;
    ifstream file(filename);
    while (file.get(ch)) {
        count++;
    }
    return count;
}

int longestLine(std::string filename) {
    int size = 0;
    string line;
    ifstream file(filename);
    while (getline(file, line)) {
        int lineSize = 0;
        for (char c: line) {
            if (c != '\n' && c != '\r') {
                lineSize++;
            }
        }
        if (lineSize > size) {
            size = lineSize;
        }
    }
    return size;
}

int main(int argc, char *argv[]) {
    int words = 0;
    int lines = 0;
    int symbols = 0;
    int longLine = 0;
    for (int i=1;i<argc; i++) {
        string s(argv[i]);
        if (s == "pacanov") {
            // TODO: size of line is 1 instead of the real size
            longLine = longestLine("anna_karenina.txt");
            cout << "Size of the longest line in text: " << longestLine << "\n";
        }
        if (s == "ebut") { // ebut
            words = wordCount("anna_karenina.txt");
            cout << "Number of words in text: " << words << "\n";
        }
        if (s == "na") { // na

            lines = lineCount("anna_karenina.txt");
            cout << "Number of lines in text: " << lines - 1 << "\n";
        }
        if (s == "plusah") { // plusah
            symbols = symbolCount("anna_karenina.txt");
            cout << "Number of symbols in text: " << symbols << "\n";
        } else if (s == " ") {
            words = wordCount("anna_karenina.txt");
            cout << "Number of words in text: " << words << "\n";
            lines = lineCount("anna_karenina.txt");
            cout << "Number of lines in text: " << lines - 1 << "\n";
            symbols = symbolCount("anna_karenina.txt");
            cout << "Number of symbols in text: " << symbols << "\n";
        }
    }
    return 0;
}


