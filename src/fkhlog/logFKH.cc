//
// Created by casauser on 2020-11-04.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class LogFKH {
public:

    void logfkh(std::string message) {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
        std::string str(buffer);

        std::cout << str;


        std::ofstream outfile;
        const char *path = "/etc/logFKH/fkh.log.txt ";
        outfile.open(path, ofstream::app);
        outfile << ("\n" + str+" ___ "+message);

    }

};
