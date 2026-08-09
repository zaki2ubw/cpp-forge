#pragma once

#include <string>

class Base;

Base *generate(void);
void identify(Base *p);
void identify(Base &p);
void print_realType(const std::string &type);
