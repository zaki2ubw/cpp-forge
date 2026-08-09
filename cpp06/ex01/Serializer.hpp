#pragma once

#include <stdint.h>
#include <string>

struct Data {
  int id;
  std::string name;
};

class Serializer {
public:
  // Required Functions
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  // Forbidden OCF Functions
  Serializer();
  Serializer(const Serializer &src);
  ~Serializer();
  Serializer &operator=(const Serializer &src);
};
