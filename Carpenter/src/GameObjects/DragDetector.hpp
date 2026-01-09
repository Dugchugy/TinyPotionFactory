#ifndef DRAGDETECTOR_HPP
#define DRAGDETECTOR_HPP

#include <Input/InputManager.hpp>
#include <Input/Mouse.hpp>

#include <vector>

#include "MouseReactor.hpp"

namespace PotionParts {

//Input::Mouse& mouse{Input::Mouse::GetInstance()};

class DragDetector {

private:
    MouseState currentState;

    std::vector<MouseReactor*> reactors;

    Engine::Input::InputManager manager;

public:

    /**
     * Creates a new drag detector. The drag detector needs to be
     * updated each frame but will create its own input manager to
     * moniter the mouse button as needed
     */
    DragDetector();

    /**
     * Updates the current state of the mouse. checks the button and updates the position
     * 
     * this will call all of the register reactors for the mouse object
     */
    void update();

    /**
     * adds a new reactor to the reactor list
     * 
     * @param reactor a pointer to the reactor that will be updated when the mouse updates
     */
    void addReactor( MouseReactor* reactor );

    /**
     * Removes all the reactors from the Drag detector
     */
    void clearReactors();

}; //DragDetector

} //PotionParts

#endif //DRAGDETECTOR_HPP