#ifndef ASSETSTREAM_HPP
#define ASSETSTREAM_HPP

#include <String>
#include <emscripten>

namespace PotionParts {

class AssetStream {
public:

   /// @brief creates an AssetStream to access the asset at the passed path
   /// @param filename the path to the Asset this stream will access
   AssetStream( std::string filename );

   /// @brief the copy constructor for the Asset stream, copies it's filename and opens a copy of the asset if it is open
   /// @param a the asset to copy
   AssetStream( AssetStream a )

   /// @brief AssetStream destructor
   ~AssetStream();

   /// @brief takes the underlying void* from the asset
   /// @return the void* used by this asset stream to store the assets data
   /// this also sets the pointer in the AssetStream to nullptr ensuring the AssetStream doesn't unexpected free the memory. this moves full responsibility for freeing the memory to the caller of takeAsset, returning the AssetStream to an unopened state
   void* takeAsset();

   /// @breif opens the asset stream
   /// when called, the AssetStream will attempt to open the asset at its path and load it into memory. if unsuccessful it may throw an error
   /// must be called before reading data from the AssetStream.
   void open();

private:
   
    void* Asset

}; //AssetStream

} //PotionParts

#endif //ASSETSTREAM_HPP