// Copyright Tashia Boddu 2021

#include <iostream>
#include <fstream>
#include <string>

#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/regex.hpp>

using boost::posix_time::time_duration;

int main(int argc, char *argv[]) {
    int numLines = 1;

    std::string str, inputfilename;
    boost::regex startMessage("( \\(log.c.166\\) server started)");
    boost::regex endMessage(
        "(oejs.AbstractConnector:Started SelectChannelConnector)");
    inputfilename = argv[1];
    std::ifstream myFile(inputfilename);
    std::ofstream output_file;
    std::string outputname = inputfilename + ".rpt";

    bool stillBooting = false;
    boost::posix_time::ptime startTime, endTime;

    if (!myFile) {
        std::cout << "Could not open file\n";
        exit(-1);
    }
    output_file.open(outputname);
    if (!output_file.is_open()) {
        std::string out_err = "Unable to create file: " + outputname;
        exit(1);
    }
    auto get_time = [](std::string time_str) {
        return time_str.substr(0, 19);
    };

    if (output_file.is_open()) {
        output_file << "Device Boot Report\n";
        output_file << "InTouch log file: " << argv[1] << "\n\n";
    }

    while (getline(myFile, str)) {
        if (regex_search(str, startMessage)) {
            startTime = boost::posix_time::time_from_string(get_time(str));

            if (stillBooting) {
                output_file << "**** Incomplete Booting **** \n\n";
                stillBooting = false;
            }

            stillBooting = true;
            output_file << "=== Device Boot ===\n";
            output_file << numLines << "(" << argv[1] << "): "
                << startTime << " Boot Start\n";

        } else if (regex_search(str, endMessage)) {
            stillBooting = false;
            endTime = boost::posix_time::time_from_string(get_time(str));

            time_duration duration = endTime - startTime;

            output_file << numLines << "(" << argv[1] << "): "
                << endTime << " Boot Completed\n\tBoot Time: "
                << duration.total_milliseconds() << "ms\n\n";
        }
        numLines++;
    }

    // If reached end of file and still hadn't completed
    if (stillBooting) {
        output_file << "**** Incomplete Booting **** \n\n";
    }

    return 0;
}
