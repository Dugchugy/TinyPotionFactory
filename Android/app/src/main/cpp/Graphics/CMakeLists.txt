cmake_minimum_required(VERSION 3.22.1)

project("Graphics")

add_library(Graphics SHARED
        DisplayCameraAndroid.cpp
        ImageAndroid.cpp
        ImageStore.cpp
)

