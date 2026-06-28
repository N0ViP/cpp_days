#include "Serializer.hpp"

int main()
{
    Data data = {10, 'A', 2.5f};


    std::cout << "&data    = " << &data << std::endl;

    uintptr_t ptr = Serializer::serialize(&data);
    std::cout << "ptr      = " << reinterpret_cast<void*>(ptr) << std::endl;

    Data *data_add = Serializer::deserialize(ptr);
    std::cout << "data_add = " << data_add << std::endl;
}
