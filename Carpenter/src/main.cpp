#include <Game.hpp>
#include <UI/UILabel.hpp>
#include <Graphics/Shapes.hpp>
#include "GameObjects/GameObject3D.hpp"
#include "GameObjects/StlMesh.hpp"
#include "GameObjects/Model.hpp"

using namespace Engine;

class ExampleScene : public Scene {
   private:
   PotionParts::ModelBase base;
   PotionParts::GameObject3D g3D;
   PotionParts::GameObject3D cald;
   float time = 0;
   UI::UILabel label;

   public:
   ExampleScene() : 
      Scene("ExampleScene"), 
      g3D(PotionParts::GameObject3D(
         PotionParts::Transform( PotionParts::Vector3( -1, 0, 10 ) ),
         PotionParts::ModelManager::getManager().loadCube( "Assets/placeholder.png" ) ) ),
      label("Label", "Hello World" ),
      cald( PotionParts::GameObject3D( 
         PotionParts::Transform( PotionParts::Vector3( 1, 0, 10 ) ),
         PotionParts::ModelManager::getManager().loadStlModel( "Assets/cauldren.stl" ) ) ) {
        AddChild(&label);
     }

   void Draw() override {
     Scene::Draw();
 
     g3D.transform.rotation().yIs(time);
     cald.transform.rotation().xIs(time);
 
     g3D.draw(Game::getInstance().GetRenderer());
     cald.draw(Game::getInstance().GetRenderer());
   }

   void Update(float dt) override {
      time += 2 * dt;
   }
};

Game game{Game::getInstance(new ExampleScene())};