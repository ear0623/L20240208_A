#include "Parent.h"
#include <iostream>

FParent::FParent()
{
	std::cout << "FParent Constructor" << std::endl;
}

FParent::~FParent()
{
	std::cout << "FParent Constructor" << std::endl;
}

void FParent::Spend()
{
}

void FParent::WhoamI()
{
	std::cout << "WhoamI" << std::endl;
}
