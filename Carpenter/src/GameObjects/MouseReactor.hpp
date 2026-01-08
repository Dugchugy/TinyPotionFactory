#ifndef MOUSEREACTOR_HPP
#define MOUSEREACTOR_HPP

namespace PotionParts {

struct MouseState {
    float mouse_x = 0;
    float mouse_y = 0;

    bool clicked = false;

    float start_x = 0;
    float start_y = 0;

}; //MouseState

class MouseReactor {
    public:

    /**
     * The reactor function. called whenever the mouses state is updated
     * 
     * @param state the current state of the mouse
     * @param previous_state the state the mouse was in before the update
     */
    void OnUpdate( MouseState state, MouseState previous_state ) {}
}; //MouseReactor

} // PotionParts

#endif //MOUSEREACTOR_HPP