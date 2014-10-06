#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "gate.h"
#include "andGate.h"
#include "clockGate.h"
#include <unistd.h>

using namespace std;

int main(){

    /* CIRCUIT */

    ClockGate clock1("clock1", 2);
    ClockGate clock2("clock2", 4);
    AndGate and1;
    clock1.addSuccessor(&and1);
    clock2.addSuccessor(&and1);
    clock1.start();
    clock2.start();
    and1.start();

    /***********/

    vector<Gate*> drawableGates;
    drawableGates.push_back(&and1);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Works !");

    window.setFramerateLimit(60);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        for(unsigned int i=0; i<drawableGates.size(); i++){
            window.draw(drawableGates[i]->getShape());
        }
        window.display();
    }

    clock1.join();
    clock2.join();
    and1.join();

    return 0;

}
