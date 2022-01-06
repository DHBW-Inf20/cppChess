//
// Created by dj on 05.01.2022.
//

#include "ImportExport.hpp"
#include <fstream>

ImportExport::ImportExport(std::string path, char separator) {
    this->path = path;
    this->separator = separator;
}

bool ImportExport::exists() {
    std::ifstream stream(this->path);
    bool result = stream.good();
    stream.close();
    return result;
}

std::string ImportExport::getPath() {
    return this->path;
}

void ImportExport::setPath(std::string path) {
    this->path = path;
}

char ImportExport::getSeparator() {
    return this->separator;
}

void ImportExport::setSeparator(char separator) {
    this->separator = separator;
}

void tokenize(std::string const &str, const char delim,std::vector<std::string> &out) {
    std::string::size_type lastPos = 0;
    std::string::size_type pos = str.find_first_of(delim, lastPos);

    while(std::string::npos != pos && std::string::npos != lastPos) {
        out.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = pos+1;
        pos = str.find_first_of(delim, lastPos);
    }

    out.push_back(str.substr(lastPos, pos - lastPos));
}

std::vector <std::vector<std::string>> ImportExport::importData() {
    std::vector<std::vector<std::string>> data;
    std::ifstream stream;
    stream.open(this->path);
    if(stream.is_open()) {
        std::string line;
        while (std::getline(stream, line)) {
            std::vector<std::string> row;
            tokenize(line, this->separator, row);
            data.push_back(row);
        }
    }
    stream.close();
    return data;
}

void ImportExport::exportData(std::vector<std::vector<std::string>> data) {
    std::ofstream stream;
    stream.open(this->path);
    for(std::vector<std::string> line : data) {
        for(std::string col : line) {
            stream << col << this->separator;
        }
        stream << std::endl;
    }
    stream.flush();
    stream.close();
}