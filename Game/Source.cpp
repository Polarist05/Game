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
    void Start() override{
      printf("123\n");
    }
};
class c2 :public GameBaseClass {
public:
    void Start() override {
        printf("This is show\n");
    }
    void Update() override {
        //printf("Between Update\n");
    }
};
int main() {
    c1 a;
    c2 b;
    ActivateStart();
    Window window(VideoMode(800, 800), "My window");
    window.setFramerateLimit(60);
    // run the program as long as the window is open
    int* c;
    while (window.isOpen())
    {
        ActivateUpdate();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ActivateUpdate();
            // "close requested" event: we close the 
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::D)
                    window.close();
            }

        }
    }
}