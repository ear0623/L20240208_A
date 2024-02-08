#include <iostream>
#include "Parent.h"
#include "Child.h"
#include "GrandChild.h"
#include <vector>


using namespace std;

int main()
{
	//FParent* Parent = new FParent();

	//delete Parent;

	//FChild* Child = new FChild();

	//delete Child;

	FParent* Child = new FChild();

	delete Child;
	//반복문를 편하게 쓰기위해

	vector<FParent*>Family;
	Family.push_back(new FChild());
	Family.push_back(new FChild());
	Family.push_back(new FGrandChild());
	Family.push_back(new FGrandChild());


	for (int i = 0; i < Family.size(); i++)
	{
		Family[i]->WhoamI();
		//isvalid
		FGrandChild* GrandChild =  dynamic_cast<FGrandChild*>(Family[i]);
		if (GrandChild != nullptr)
		{
			GrandChild->PlayGround();
		}
	}
	//dynamic_cast 는 성능이 안좋음
	//다운캐스팅

	for (int i = 0; i <Family.size(); i++)
	{
		delete Family[i];

	}
	Family.clear();

	return 0;
}