#include "Child.h"
#include <iostream>

FChild::FChild()
{
	std::cout << "Child Constructor" << std::endl;
}

FChild::~FChild()
{
	std::cout << "Child Constructor" << std::endl;
}

void FChild::WhoamI()
{
	std::cout << "ChildWhoamI" << std::endl;
}

