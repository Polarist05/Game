#include "GameBaseClass.h"
#include<vector>
#include<queue>
using namespace std;
queue<weak_ptr<GameBaseClass> > qStart;
queue<weak_ptr<GameBaseClass> > qUpdate;
void PushQStart(weak_ptr<GameBaseClass> _a) { qStart.push(_a);}
void PushQUpdate(weak_ptr<GameBaseClass> _a) { qUpdate.push(_a);}
void ActivateStart() {
	queue<weak_ptr<GameBaseClass> > _q;
	while (!qStart.empty())
	{
		if (!qStart.front().expired()) {
			qStart.front().lock()->Start();
			_q.push(qStart.front());
		}
		qStart.pop();
	}
	qStart = _q;
}
void ActivateUpdate() {
	queue<weak_ptr<GameBaseClass> > _q;
	while (!qUpdate.empty())
	{
		if (!qUpdate.front().expired()) {
			qUpdate.front().lock()->Update();
			_q.push(qUpdate.front());
		}
		qUpdate.pop();
	}
	qUpdate = _q;
}

