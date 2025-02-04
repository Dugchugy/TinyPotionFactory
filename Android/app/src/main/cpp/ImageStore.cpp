#include "ImageStore.h"
#include <stdexcept>

namespace GRAPHICS{

    ImageStore::ImageStore() {
        ImageSet;
    }

    ImageStore::~ImageStore() {
        Clear();
    }

    Image* ImageStore::load_image_from_path(const std::string& path) {
        //checks if the iamge has been loaded before, if so, returns the loaded image
        try{
            return ImageSet[path];
        }catch(std::out_of_range e){


            //creates a new image with teh specifeid path
            Image* img = new Image(path);

            ImageSet[path] = img;

            return img;
        }
    }

    void ImageStore::Clear() {
        //loops through all the images in the image store
        for(auto i: ImageSet){

            //deletes each image
            delete i.second;

        }
    }

} //GRAPHICS