#include <iostream>
#include <vector>

using namespace std;

class Parent
{
public:
	virtual void Do() { cout<<"parent"; }
};

class Child :public Parent
{
public:
	virtual void Do() override { cout<< "Child"; }
	void PostLogin() { cout << "PostLogin"; }

};
class GrandChild :public Parent
{
public:
	virtual void Do() override { cout << "Child"; }

};


class IInterface
{

public:

	virtual void Interface() = 0;//추상함수
};


class RemoteControl : public IInterface
{

};

class IItem
{
public:

	virtual void Use() = 0;
};

class Knife :public IItem
{

	virtual void Use() override
	{
		cout << "knife" << endl;
	}
};
class Gun : public IItem
{
	virtual void Use() override
	{
		cout << "gun" << endl;
	}
};
//interface = 문법적으로 지원.

class Inventory
{
public:
	void PicUp(IItem* PickUpItem)
	{
		Data.push_back(PickUpItem);
	}
	IItem* operator[](int Index) const
	{
		return Data[Index];
	}
private:

	vector<IItem*>Data;
};
int main()
{
	Knife* knife;

	vector<Parent*> parent;
	parent.push_back(new Child);
	parent.push_back(new GrandChild);
	//궁극의 목적은 반복시킬려고 문법을 쓰는거임.
	for (int  i = 0; i < parent.size(); i++)
	{
		Child* GM = dynamic_cast<Child*>(parent[i]);//CAST 
		if (GM)
		{
			GM->PostLogin();
		}
	}//리플렉션 자식꺼를 특정함수 실행.


	//Child* child=new Child();
	//child->Do();
	return 0;
}

void IItem::Use()
{
}

void IInterface::Interface()
{
}
