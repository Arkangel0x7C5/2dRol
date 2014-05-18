#include "property.h"
#include <iostream>
#include <ostream>

Property::Property(){
}

void Property::setValueFromString(const std::string &/*value*/){}

std::string Property::valueToString(){
    return "";
}


void Property::setName(const std::string &name){
    m_name = name;
}



Property::propertyType PropertyString::type(){
    return propertyType::String;
}

void PropertyString::setValue(const std::string &value){
    m_value = value;
}

std::string PropertyString::valueToString(){
    return m_value;
}


PropertyInt::PropertyInt():m_value(0){}

Property::propertyType PropertyInt::type(){
    return propertyType::Integer;
}
int PropertyInt::value() const{
    return m_value;
}

void PropertyInt::setValue(int value){
    m_value = value;
}


void PropertyInt::setValueFromString(const std::string &value){
    m_value = atoi(value.c_str());
}

std::string PropertyInt::valueToString(){
    return std::to_string(m_value);
}


PropertyDouble::PropertyDouble():m_value(0){}

Property::propertyType PropertyDouble::type(){
    return propertyType::Double;
}
double PropertyDouble::value() const{
    return m_value;
}

void PropertyDouble::setValue(double value){
    m_value = value;
}


void PropertyDouble::setValueFromString(const std::string &value){
    m_value = atof(value.c_str());
}

std::string PropertyDouble::valueToString(){
    return std::to_string(m_value);
}


PropertyBoolean::PropertyBoolean():m_value(false){}

Property::propertyType PropertyBoolean::type(){
    return propertyType::PropertySet;
}
bool PropertyBoolean::value() const{
    return m_value;
}

void PropertyBoolean::setValue(bool value){
    m_value = value;
}


void PropertyBoolean::setValueFromString(const std::string &value){
    m_value = value=="true";
}

std::string PropertyBoolean::valueToString(){
    return m_value?"true":"false";
}


PropertySet::PropertySet(){}

Property::propertyType PropertySet::type(){
    return propertyType::PropertySet;
}
std::map<std::string, Property *> PropertySet::value() const{
    return m_values;
}

void PropertySet::setValue(const std::map<std::string, Property *> &value){
    m_values = value;
}

void PropertySet::add(const std::string &name, Property *property){
    m_values.insert(std::pair<std::string,Property*>(name,property));
}

void PropertySet::remove(const std::string &name){
    m_values.erase(name);
}

Property *PropertySet::operator [](const std::string &name){
    std::map<std::string,Property*>::const_iterator it = m_values.find(name);
    return it != m_values.end()?it->second:nullptr;
}


const Point &PropertyPoint::value() const{
    return m_value;
}

PropertyPoint::PropertyPoint(){}

Property::propertyType PropertyPoint::type(){
    return propertyType::point;
}

void PropertyPoint::setValue(const Point &value){
    m_value = value;
}


const Size &PropertySize::value() const{
    return m_value;
}

PropertySize::PropertySize(){}

Property::propertyType PropertySize::type(){
    return propertyType::size;
}

void PropertySize::setValue(const Size &value){
    m_value = value;
}
