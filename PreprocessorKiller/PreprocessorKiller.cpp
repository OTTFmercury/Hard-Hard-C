

#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main (int argc, char* argv[]) {

    if (argc != 2 && argc != 3) {
        cout << "PreprocessorKiller requires exactly 1 or 2 argument(s)." << endl;
        return 0;
    }

    ifstream fin(argv[1]);
    ofstream fout((argc == 3) ? argv[2] : "program.cpp");
    ostringstream ossDefine;
    ostringstream ossProgram;

    unordered_map<string, string> code;
    unordered_set<string> exist;

    default_random_engine engine(time(0));
    uniform_real_distribution<double> distribution(0.0, 1.0);

    string line;
    while (getline (fin, line)) {
        istringstream iss (line);

        if (iss.str().starts_with("#")) {
            ossProgram << iss.str() << endl;
            continue;
        }

        bool blank = true;
        string word;
        while (iss >> word) {
            blank = false;
            if (!code.count (word)) {
                string newCode = "CcC";

                do {
                    if (distribution (engine) < 0.5) {
                        newCode += 'c';
                    }
                    else {
                        newCode += 'C';
                    }
                } while (exist.count(newCode));

                code[word] = newCode;
                exist.insert(newCode);
                ossDefine << "#define " << code[word] << " " << word << endl;
            }

            ossProgram << code[word] << " ";
        }

        if (!blank) {
            ossProgram << endl;
        }
    }

    fout << ossDefine.str() << endl << ossProgram.str();

    return 0;
}