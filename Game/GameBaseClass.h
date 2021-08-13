#pragma once
#include<memory>
#include<typeinfo>
#include <map>
#include <vector>
#include<string>
#include<iterator>
#include<typeindex>
using namespace std;
class SubClass {
public:
	SubClass(){ printf("Subclass is made\n"); }
	virtual ~SubClass() { printf("Subclass is destroy\n"); }
	virtual void Start() { printf("start\n"); }
    virtual void Update() { printf("update\n"); }
};
class  GameBaseClass :public SubClass {
public:
    void PushQStart(SubClass* _a);
    void PushQUpdate(SubClass* _a);
	GameBaseClass() { printf("GameBaseClass is made\n"); }
	virtual ~GameBaseClass() {printf("GameBaseClass is destroy\n");}
};
void PushQStart(weak_ptr<GameBaseClass> _a);
void PushQUpdate(weak_ptr<GameBaseClass> _a);
map<type_index, vector<shared_ptr<GameBaseClass> > >& GetAllEntities();
template <typename T>
weak_ptr<T> Instantiate() {

	shared_ptr<GameBaseClass> sp = make_shared<T>();
	GetAllEntities()[type_index(typeid(T))].push_back(sp);
	PushQUpdate(sp);
	PushQStart(sp);
	return dynamic_pointer_cast<T>(sp);
}
template <typename T>
void Destroy(weak_ptr<T> _wp) {

	vector<shared_ptr<GameBaseClass> > ::iterator it=find(GetAllEntities()[type_index(typeid(T))].begin(), GetAllEntities()[type_index(typeid(T))].end(),_wp.lock());
	if (it == GetAllEntities()[type_index(typeid(T))].end()) {
		
		printf(" Cant find that entity error please check your code\n");
	}
	else {
		GetAllEntities()[type_index(typeid(T))].erase(it);
		if (!_wp.expired())
			printf("It have left some share_ptr somewhere after destroy entity please check your code");
	}
		
}