#include "ImageStore.h"
#include <stdexcept>
#include "logging.h"

namespace GRAPHICS{

    ImageStore::ImageStore() {
        ImageSet = std::unordered_map<std::string, Image*>();
    }

    ImageStore::~ImageStore() {
        Clear();
    }

    Image* ImageStore::load_image_from_path(const std::string& path) {
        //checks if the iamge has been loaded before, if so, returns the loaded image
        try{
            return ImageSet.at(path);
        }catch(std::out_of_range& e){

            //creates a new image with teh specifeid path
            Image* img = this->LoadNeededImage(path);

            ImageSet[path] = img;

            return img;
        }
    }

    void ImageStore::Clear() {
        //loops through all the images in the image store
        for(const auto &i: ImageSet){

            //deletes each image
            delete i.second;

        }
    }

} //GRAPHICS