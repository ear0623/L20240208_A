#pragma once
#include "Parent.h"
class FChild : public FParent
{
public:
	FChild();
	virtual ~FChild();

	virtual void WhoamI() override;
private:

};

