#include<SFML\Audio.hpp>
#include<SFML\Config.hpp>
#include<SFML\Graphics.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>
#include<iostream>
#include<stdio.h>
#include<iostream>
#include "GameBaseClass.h"
using namespace sf;
using namespace std;
void ActivateStart();
void ActivateUpdate();
class c1 :public GameBaseClass {
public:
    c1() {printf("C1 hase been made\n");}
    ~c1() { printf("C1 hase been destoyed\n"); }
    void Start()override { printf("C1 starting\n"); }
    void Update()override{ printf("C2 ending\n"); }
};
int main() {
    weak_ptr<GameBaseClass> a = Instantiate<GameBaseClass>();
    cout << endl;
    weak_ptr<c1> b = Instantiate<c1>();
    cout << endl;
    ActivateStart();
    cout << endl;
    ActivateUpdate();
    cout << endl;
    Destroy(b);
    cout << endl;
    printf("Use count:%d\n", a.use_count());
    if (a.expired()) { printf("Already Destroy\n"); }
    Window window(VideoMode(800, 800), "My window");
    window.setFramerateLimit(60);
    // run the program as long as the window is open
    /*while (window.isOpen())
    {
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            // "close requested" event: we close the 
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::D)
                    window.close();
            }

        }
    }*/
    cout << endl<<"end program"<<endl; 
}