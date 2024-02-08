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

	virtual void Interface() = 0;//�߻��Լ�
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
//interface = ���������� ����.

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
	//�ñ��� ������ �ݺ���ų���� ������ ���°���.
	for (int  i = 0; i < parent.size(); i++)
	{
		Child* GM = dynamic_cast<Child*>(parent[i]);//CAST 
		if (GM)
		{
			GM->PostLogin();
		}
	}//���÷��� �ڽĲ��� Ư���Լ� ����.


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
