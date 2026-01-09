#include "DragDetector.hpp"

using namespace PotionParts;

Engine::Input::Mouse& mouse{Engine::Input::Mouse::GetInstance()};

DragDetector::DragDetector() {
    currentState = {0, 0, false, 0, 0};

    manager.AddInput("click", {-1, 0});
}

void DragDetector::update() {
    MouseState prevState = currentState;

    // records wether or not to broadcast a mouse update for this update
    bool update = false;

    currentState.mouse_x = mouse.GetPosition().x;
    currentState.mouse_y = mouse.GetPosition().y;

    update = update || ( currentState.mouse_x != prevState.mouse_x ||
                         currentState.mouse_y != prevState.mouse_y );

    if ( manager.GetInput( "click" )->IsPressed() ) {
        currentState.clicked = true;
        update = true;

        // records the current mouse position as the start of the last drag
        currentState.start_x = currentState.mouse_x;
        currentState.start_y = currentState.mouse_y;
    }

    if ( manager.GetInput( "click" )->IsReleased() ) {
        currentState.clicked = false;
        update = true;
    }

    if ( update ) {
        for( auto iter = reactors.begin(); iter != reactors.end(); iter++) {
            (*iter)->OnUpdate( currentState, prevState );
        }
    }
}

void DragDetector::addReactor( MouseReactor* reactor ) {
    reactors.push_back( reactor );
}

void DragDetector::clearReactors() {
    reactors = std::vector<MouseReactor*>();
}