#include"GameBaseClass.h"
#include"WorldControl.h"
#include<map>
#include<vector>
using namespace std;
float worldScale = (float)0.9;
map<type_index, vector<shared_ptr<GameBaseClass> > > AllEntities;
map<type_index, vector<shared_ptr<GameBaseClass> > >& GetAllEntities() {return AllEntities;}
//weak_ptr<GameSprite> _hierarchy = Instantiate<GameSprite>();
//weak_ptr<GameSprite>& WorldControl::Hierarchy() { return _hierarchy; }
float WorldControl::WorldScale() { return worldScale; };
RenderWindow _window(VideoMode((int)(1920.* WorldControl::WorldScale()), (int)(1080.* WorldControl::WorldScale())), "My window");
RenderWindow& WorldControl::window() { return _window; }

