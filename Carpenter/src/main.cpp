#include <Game.hpp>
#include <UI/UILabel.hpp>
#include <iostream>
#include <Graphics/Shapes.hpp>
#include "GameObjects/GameObject3D.hpp"
#include "GameObjects/Model.hpp"

using namespace Engine;

class ExampleScene : public Scene {
   private:
   PotionParts::ModelBase base;
   PotionParts::GameObject3D g3D;
   PotionParts::GameObject3D cald;
   std::vector< PotionParts::GameObject3D > caulds;
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
         PotionParts::ModelManager::getManager().loadStlModel( "Assets/cauldren.stl" ) ) )
      {
         AddChild(&label);

         for ( int i = 0; i < 20; i++ ) {
            caulds.push_back( 
               PotionParts::GameObject3D(
                  PotionParts::Transform( PotionParts::Vector3( -20 + ( i * 2 ), 0, 15 ) ),
                  PotionParts::ModelManager::getManager().loadObjModel( "Assets/cauldren.obj" ) )
               );
         }
      }

   void Draw() override {

      std::cout << "starting draw\n";
      Scene::Draw();
 
      g3D.transform.rotation().yIs(time);
      cald.transform.rotation().xIs(time);
 
      g3D.draw(Game::getInstance().GetRenderer());
      std::cout << "rendering cauld\n";
      cald.draw(Game::getInstance().GetRenderer());
      //std::cout << "rendering cauld2\n";
      //for ( int i = 0; i < 20; i++ ) {
         //caulds[ i ].draw( Game::getInstance().GetRenderer() );
      //}
   }

   void Update(float dt) override {
      time += 2 * dt;
   }
};

Game game{Game::getInstance(new ExampleScene())};