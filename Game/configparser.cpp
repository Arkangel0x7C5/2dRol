#include "configparser.h"

using namespace std;

configParser::configParser(){
}

bool configParser::parseInitFile(std::ifstream& file){

    string strBuff,keyName,value;
    size_t ecualPos;
    int i = 0;

    //Parseo las lineas y las guardo en un map
    while (!file.eof()) {
        std::getline(file,strBuff);
        if(!strBuff.empty() && (ecualPos = strBuff.find_first_of('=')) != string::npos){
            keyName = strBuff.substr(0,ecualPos);
            value = strBuff.substr(ecualPos+1);
            values.insert(pair<string,string>(keyName,value));
            i++;
        }
    }
    return i;
}

bool configParser::empy(){
    return values.empty();
}

int configParser::queryInt(const string& key, int defaultValue){
    map<string,string>::const_iterator it = values.find(key);
    if(it != values.end()){
        defaultValue = atoi((*it).second.c_str());
    }
    return defaultValue;
}

bool configParser::queryBool(const string &key, bool defaultValue){
    map<string,string>::const_iterator it = values.find(key);
    if(it != values.end()){
        defaultValue = ((*it).second == "true");
    }
    return defaultValue;

}

double configParser::queryDouble(const string &key, double defaultValue){
    map<string,string>::const_iterator it = values.find(key);
    if(it != values.end()){
        defaultValue = atof((*it).second.c_str());
    }
    return defaultValue;
}

string configParser::queryString(const string &key, const string &defaultValue){
    map<string,string>::const_iterator it = values.find(key);
    if(it != values.end()){
        return (*it).second;
    }
    return defaultValue;
}
