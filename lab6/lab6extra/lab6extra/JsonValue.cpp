#define _CRT_SECURE_NO_WARNINGS
#include "JsonValue.h"

JsonValue::~JsonValue() {};

void NullValue::print(std::ostream& out, unsigned int indent) const {
	out << "null";
}
NullValue::operator unsigned() const {
	return 1;
}

NumberValue::NumberValue(double value) {
	this->value = value;
}
void NumberValue::print(std::ostream& out, unsigned int indent) const {
	out << value;
}
NumberValue::operator unsigned() const {
	return 1;
}

BoolValue::BoolValue(bool value) {
	this->value = value;
}
void BoolValue::print(std::ostream& out, unsigned int indent) const {
	out << value;
}
BoolValue::operator unsigned() const {
	return 1;
}

StringValue::StringValue(const char* value) {
	strncpy(this->value, value, 255);
	this->value[255] = 0;
}
void StringValue::print(std::ostream& out, unsigned int indent) const {
	out << "\"" << value << "\"";
}
StringValue::operator unsigned() const {
	return 1;
}

ArrayValue::ArrayValue() : count(0) {}

ArrayValue::~ArrayValue() {
	for (int i = 0; i < count; i++) {
		delete values[i];
	}
}

void ArrayValue::add(JsonValue* value) {
	if (count < 16) {
		values[count++] = value;
	}
	else {
		delete value;
	}
}

void ArrayValue::print(std::ostream& out, unsigned int indent) const {
	out << "[\n";
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < indent + 4; j++) out << ' ';
		values[i]->print(out, indent + 4);
		if (i < count - 1) out << ',';
		out << '\n';
	}
	for (int i = 0; i < indent; i++) out << ' ';
	out << "]";
}

ArrayValue::operator unsigned() const {
	int total = 1;
	for (int i = 0; i < count; i++) {
		total += (unsigned)(*values[i]);
	}
	return total;
}

ObjectValue::ObjectValue() : count(0) {};
ObjectValue::~ObjectValue() {
	for (int i = 0; i < count; i++) {
		delete pairs[i].value;
	}
}

void ObjectValue::add(const char* name, JsonValue* value) {
	if (count < 16) {
		pairs[count].value = value;
		strncpy(pairs[count].name, name, 255);
		pairs[count].name[255] = 0;
		count++;
	}
	else {
		delete value;
	}
}

void ObjectValue::print(std::ostream& out, unsigned int indent) const {
	out << "{\n";
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < indent + 4; j++) out << ' ';
		out << "\"" << pairs[i].name << "\": ";
		pairs[i].value->print(out, indent + 4);
		if (i < count - 1) out << ',';
		out << '\n';
	}
	for (int j = 0; j < indent; j++) out << ' ';
	out << '}';
}

ObjectValue::operator unsigned() const {
	int total = 1;
	for (int i = 0; i < count; i++) {
		total += (unsigned)(*pairs[i].value);
	}
	return total;
}