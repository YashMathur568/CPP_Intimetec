#include <iostream>

#pragma pack(1)
struct IDs
{
    unsigned short manufactureId;
    unsigned int productId;
};
#pragma pack()

union UUID
{
    unsigned char byteArray[6];
    IDs id;
};

int main()
{

    UUID dId;

    dId.id.manufactureId = 1001;
    dId.id.productId = 23456;

    std::cout << "Size of struct: " << sizeof(dId.id) << std::endl;

    for (int i = 0; i < 6; i++)
    {
        std::cout << (int)dId.byteArray[i] << std::endl;
    }
}