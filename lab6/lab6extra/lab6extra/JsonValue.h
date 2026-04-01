#pragma once
#include<iostream>
class JsonValue {
public:
    virtual ~JsonValue() = 0; //clasa abstracta

    virtual void print(std::ostream& out, unsigned int indent = 0) const = 0;
    virtual operator unsigned() const = 0;
};

class NullValue : public JsonValue {
public:
    ~NullValue() override = default;
    void print(std::ostream& out, unsigned int indent = 0) const override;
    operator unsigned() const override;
};

class NumberValue : public JsonValue {
private:
    double value;
public:
    NumberValue(double value);
    ~NumberValue() override = default;
    void print(std::ostream& out, unsigned int indent = 0) const override;
    operator unsigned() const override;
};

class BoolValue : public JsonValue {
private:
    bool value;
public:
    BoolValue(bool value);
    ~BoolValue() override = default;
    void print(std::ostream& out, unsigned int indent = 0) const override;
    operator unsigned() const override;
};

class StringValue : public JsonValue {
private:
    char value[256];
public:
    StringValue(const char* value);
    ~StringValue() override = default;
    void print(std::ostream& out, unsigned int indent = 0) const override;
    operator unsigned() const override;
};

class ArrayValue : public JsonValue {
private:
    JsonValue* values[16];
    int count;
public:
    ArrayValue();
    ~ArrayValue() override;
    void add(JsonValue* value);
    void print(std::ostream& out, unsigned int indent = 0) const override;
    operator unsigned() const override;
};

class ObjectValue : public JsonValue {
private:
    struct Pair {
        char name[256];
        JsonValue* value;
    } pairs[16];
    int count;
public: 
    ObjectValue();
    ~ObjectValue() override;
    void add(const char* name, JsonValue* value);
    void print(std::ostream& out, unsigned int indent = 0) const override;
    operator unsigned() const override;
};