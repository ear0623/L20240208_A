#include "GrandChild.h"
#include <iostream>

FGrandChild::FGrandChild()
{
	std::cout << "GrandChild Constructor" << std::endl;
}

FGrandChild::~FGrandChild()
{
	std::cout << "GrandChild Constructor" << std::endl;
}

void FGrandChild::WhoamI()
{
	std::cout << "ChildWhoamI" << std::endl;
}

void FGrandChild::PlayGround()
{
	std::cout << "PlayGround" << std::endl;
}
