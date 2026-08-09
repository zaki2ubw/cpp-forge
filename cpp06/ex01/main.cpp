#include <iostream>

#include "Serializer.hpp"

int main(void) {
  {
    std::cout << "===NORMAL CASE===" << std::endl;
    Data data;
    data.id = 1;
    data.name = "Normal";
    std::cout << "**Check original Data**" << std::endl;
    std::cout << "dataId =" << data.id << " dataName=" + data.name << std::endl;
    uintptr_t serialized;
    Data *deserialized;

    serialized = Serializer::serialize(&data);
    deserialized = Serializer::deserialize(serialized);
    std::cout << std::endl;
    std::cout << "**Compare Address**" << std::endl;
    std::cout << "Original Ptr :" << &data << std::endl;
    std::cout << "Serialized   :" << serialized << std::endl;
    std::cout << "Restored Ptr :" << deserialized << std::endl;
    std::cout << std::endl;
    std::cout << "**Check deserialized Data**" << std::endl;
    std::cout << "dataId =" << deserialized->id
              << " dataName=" + deserialized->name << std::endl;
    if (&data == deserialized)
      std::cout << "Serialize success" << std::endl;
    else
      std::cout << "Serialize Failed" << std::endl;
  }
  {
    std::cout << "===NULL CASE===" << std::endl;
    Data *data = NULL;
    uintptr_t serialized;
    Data *deserialized;

    serialized = Serializer::serialize(data);
    deserialized = Serializer::deserialize(serialized);
    std::cout << std::endl;
    std::cout << "**Compare Address**" << std::endl;
    std::cout << "Original Ptr :" << data << std::endl;
    std::cout << "Serialized   :" << serialized << std::endl;
    std::cout << "Restored Ptr :" << deserialized << std::endl;
    std::cout << std::endl;
    if (data == deserialized)
      std::cout << "Serialize success" << std::endl;
    else
      std::cout << "Serialize Failed" << std::endl;
  }
  return 0;
}
