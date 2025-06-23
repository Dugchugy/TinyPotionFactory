#idndef LOADEDMESH_HPP
#define LOADEDNESH_HPP

#include<Graphics/Mesh.hpp>
#include<vector>

namespace PotionParts {

struct Tri {
   Engine::Graphics::Vertex v1
   Engine::Graphics::Vertex v2
   Engine::Graphics::Vertex v3
}

class LoadedMesh : public Engine::Graphics::Mesh {

   /// @brief creates a mesh from an array of triangles
   LoadedMesh( std::vector<Tri> triangles );

}

};

#endif //LOADEDMESH_HPP