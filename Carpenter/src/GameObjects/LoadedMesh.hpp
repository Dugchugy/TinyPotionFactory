#idndef LOADEDMESH_HPP
#define LOADEDNESH_HPP

#include<Graphics/Mesh.hpp>

namespace PotionParts {

struct Tri {
   Engine::Graphics::Vertex v1
   Engine::Graphics::Vertex v2
   Engine::Graphics::Vertex v3
}

class LoadedMesh : public Engine::Graphics::Mesh {

}

};

#endif //LOADEDMESH_HPP