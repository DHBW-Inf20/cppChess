//
// Created by dj on 05.01.2022.
//

#include "ImportExport.hpp"
#include <fstream>

ImportExport::ImportExport(std::string path, char separator) {
    this->path = path;
    this->separator = separator;
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
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
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