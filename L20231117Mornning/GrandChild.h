#pragma once
#include "Child.h"
class FGrandChild :public FChild
{
public:
	FGrandChild();
	virtual ~FGrandChild();

	virtual void WhoamI() override;
	void PlayGround();

private:

};

