#ifndef STLMESH_HPP
#define STLMESH_HPP

#include <string>

#include <Graphics/Mesh.hpp>

namespace PotionParts {

class StlMesh : public Engine::Graphics::Mesh {
   public:

   /// @brief loads a mesh from an STL file
   /// @param filename the path at read the STL file from
   /// reads the passed filename assuming it to be a binary STL file and uses that file to specify the triangles in the mesh

   StlMesh( std::string filename );

}; //StlMesh

} //PotionParts 

#endif //STLMESH_HPP