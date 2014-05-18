#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <map>
#include <set>

#include "engine_global.h"

class Property;

class PropertyChangeListener{
    public:
        PropertyChangeListener() {}
        virtual void onChange(Property& property,Property& lastValue) = 0;
};

class Property{
    public:
        typedef enum propertyType{
            String,
            Integer,
            Double,
            Bolean,
            point,
            size,
            PropertySet
        }propertyType;

        Property();
        virtual propertyType type() = 0;
        virtual void setValueFromString(const std::string& value);
        virtual std::string valueToString();

        const std::string& name() const{
            return m_name;
        }
        void setName(const std::string &name);
    protected:
        std::set<PropertyChangeListener*> m_listeners;
    private:
        std::string m_name;
};
class PropertyString:public Property{
public:
        PropertyString() {}

        virtual propertyType type() override;
        virtual void setValue(const std::string& value);
        virtual std::string valueToString();
    private:
        std::string m_value;
};

class PropertyInt:public Property{
    public:
        PropertyInt();

        virtual propertyType type() override;
        virtual void setValueFromString(const std::string& value) override;
        virtual std::string valueToString() override;
        int value() const;
        void setValue(int value);

private:
        int m_value;
};
class PropertyDouble:public Property{
    public:
        PropertyDouble();

        virtual propertyType type() override;
        virtual void setValueFromString(const std::string& value) override;
        virtual std::string valueToString() override;
        virtual double value() const;
        virtual void setValue(double value);
    private:
        double m_value;
};
class PropertyBoolean:public Property{
    public:
        PropertyBoolean();

        virtual propertyType type() override;
        virtual void setValueFromString(const std::string& value) override;
        virtual std::string valueToString() override;
        virtual bool value() const;
        virtual void setValue(bool value);

    private:
        bool m_value;
};
class PropertyPoint:public Property{
    public:
        PropertyPoint();

        virtual propertyType type() override;

        virtual const Point& value() const;
        virtual void setValue(const Point& value);

    private:
        Point m_value;
};
class PropertySize:public Property{
    public:
        PropertySize();

        virtual propertyType type() override;

        virtual const Size& value() const;
        virtual void setValue(const Size& value);

    private:
        Size m_value;
};
class PropertySet:public Property{
    public:
        PropertySet();

        virtual propertyType type() override;
        //virtual void setValueFromString(const std::string& value) override;
        //virtual std::string valueToString() override;

        virtual std::map<std::string, Property *> value() const;
        virtual void setValue(const std::map<std::string, Property *> &value);

        void add(const std::string& name,Property* property);
        void add(Property* property){
            add(property->name(),property);
        }

        void remove(const std::string& name);

        Property* operator [](const std::string& name);

    private:
        std::map<std::string,Property*> m_values;
};

#endif // PROPERTY_H
