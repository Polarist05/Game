#pragma once
class SubClass {
public:
    virtual void Start() {}
    virtual void Update() {}
};
//Test
class  GameBaseClass :public SubClass {
public:
    void PushQStart(SubClass* _a);
    void PushQUpdate(SubClass* _a);
    GameBaseClass();
};
