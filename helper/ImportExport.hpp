//
// Created by dj on 05.01.2022.
//

#ifndef YETANOTHERCHESSGAME_IMPORTEXPORT_H
#define YETANOTHERCHESSGAME_IMPORTEXPORT_H

#include <string>
#include <vector>

class ImportExport {
    public:
        ImportExport(std::string path, char separator);
        std::string getPath();
        void setPath(std::string path);
        char getSeparator();
        void setSeparator(char separator);
        std::vector<std::vector<std::string>> importData();
        void exportData(std::vector<std::vector<std::string>> data);

    private:
        std::string path;
        char separator;
};


#endif //YETANOTHERCHESSGAME_IMPORTEXPORT_H
