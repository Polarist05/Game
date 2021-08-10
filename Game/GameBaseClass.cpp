#include "GameBaseClass.h"
#include<vector>
#include<queue>
using namespace std;
queue<SubClass*> qStart;
queue<SubClass*> qUpdate;
void GameBaseClass::PushQStart(SubClass* _a) {
	qStart.push(_a);
}
void GameBaseClass::PushQUpdate(SubClass* _a) {
	qUpdate.push(_a);
}
	
void ActivateStart() {
	queue<SubClass*> _q;
	while (!qStart.empty())
	{
		qStart.front()->Start();
		_q.push(qStart.front());
		qStart.pop();
	}
	qStart = _q;
}
void ActivateUpdate() {
	queue<SubClass*> _q;
	while (!qUpdate.empty())
	{
		qUpdate.front()->Update();
		_q.push(qUpdate.front());
		qUpdate.pop();
	}
	qUpdate = _q;
}
GameBaseClass::GameBaseClass() {
	GameBaseClass::PushQStart(this);
	GameBaseClass::PushQUpdate(this);
}

