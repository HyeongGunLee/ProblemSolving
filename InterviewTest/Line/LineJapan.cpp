#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


/*
 *  Line Japan Coding Test
 *  preprocessing
 *  string manipulation
 */

int main(int argc, char *argv[])
{
    // start from 1 to ignore script name; argv[0] will be a name of processing file.
    /*
      for (int i = 1; i < argc; i++) {
      printf ("argv[%i]: %s\n", i, argv[i]);
    }
    */

    string fileName = argv[1];
    int maxLength = atoi(argv[3]);
    ifstream read(fileName);
    char str[sizeof(read)] = {'\0'};
    char result[sizeof(read)];
    bool leading = true;
    int k  = 0;

    if(read.good()) {
        while(!read.eof()) {
            read.getline(str, sizeof(read));
            //for (int i = 0; i < sizeof(read); i++) {
            int i = 0;
            while(i < sizeof(read)) {
                // checkleading
                bool leading = false;
                if (str[i] == ' ' && i == 0) {
                    leading = true;
                    result[k++] = str[i];
                    for (int j = 1; j < sizeof(read); j++, i++) {
                        if (leading && str[j] == ' ') {
                            result[k++] = str[j];
                        } else {
                            leading = false;
                            break;
                        }
                    }
                }

                if (leading == false && str[i] == ' ') {
                    result[k++] = str[i++];
                    while(str[i] == ' ') {
                        i++;
                    }
                }

                if (i == maxLength && str[i] == ' ') {
                    result[k++] = '\n';
                    i++;
                }

                result[k++] = str[i++];
            }
        }
    }

    cout << result << endl;


    return 0;
}
