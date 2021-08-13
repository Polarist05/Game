#include"GameBaseClass.h"
#include"Header.h"
#include<map>
#include<vector>
using namespace std;
map<type_index, vector<shared_ptr<GameBaseClass> > > AllEntities;
map<type_index, vector<shared_ptr<GameBaseClass> > >& GetAllEntities() {return AllEntities;}