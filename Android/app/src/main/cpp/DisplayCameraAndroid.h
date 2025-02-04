#ifndef TINY_POTION_FACTORY_GRAPHIC_DISPLAY_CAMERA_ANDROID_H
#define TINY_POTION_FACTORY_GRAPHIC_DISPLAY_CAMERA_ANDROID_H

#include "DisplayCamera.h"

#include <memory>

#include <GLES/egl.h>
#include <game-activity/native_app_glue/android_native_app_glue.h>

namespace GRAPHICS {

    /// @brief creats a camera used to render things on to the screen. only one should be needed
    class DisplayCameraAndroid : public DisplayCamera {

    public:

        /// @brief creates a new camera and sets up the rendering system to use that camera
        /// @param app the android app used by the camera, require to link rendering
        DisplayCameraAndroid(android_app* app);

        /// @brief deconstructor for the display camera, destroy the context and the rendering pipeline
        ~DisplayCameraAndroid();

        /// @brief Draws the passed image on the screen at the passed position
        /// @param pos the position of the image, position is in world space.
        /// @param i the image to draw.
        virtual void DrawImage(Position pos, Image& i);

        /// @brief used to set up the frame so that the Draw Image functions can be ran
        virtual void PrepFrame();

        /// @brief used to finish up the rendering of the frame
        virtual void finishFrame();

    private: 

        EGLDisplay display;
        EGLConfig config;
        EGLSurface  surface;
        EGLContext  context;

        //voa = vertex area: used to draw, vbo = vertex buffer: stores type of vertex data
        //in GPU memory
        GLuint vao{}, vbo{}, ebo{};
        GLint ProjectionLink, ModelLink;

        
        GLuint shaderProgram{};

    }; //DisplayCameraAndroid

} //GRAPHICS

#endif