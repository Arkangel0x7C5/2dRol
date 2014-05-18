#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <map>
#include <fstream>

class configParser{
    public:
        configParser();
        bool parseInitFile(std::ifstream &file);
        bool empy();

        int queryInt(const std::string &key, int defaultValue = 0);
        bool queryBool(const std::string &key,bool defaultValue = false);
        double queryDouble(const std::string &key,double defaultValue = 0);
        std::string queryString(const std::string& key,const std::string &defaultValue = "");
    private:
        std::map<std::string,std::string> values;
};

#endif // CONFIGPARSER_H
