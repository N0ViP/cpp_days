#include <iostream>



class Serializer
{
    private:
        Serializer();
        Serializer(Serializer& other);
        Serializer& operator=(Serializer &other);
        ~Serializer();

    public:
        uintptr_t   serialize(Data* ptr);
        Data*       deserialize(uintptr_t raw);
}
