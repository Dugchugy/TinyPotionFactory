#include <Game.hpp>
#include <UI/UILabel.hpp>
#include <iostream>
#include <Graphics/Shapes.hpp>
#include <GameObjects/Camera.hpp>
#include <Graphics/Shader.hpp>
//#include "GameObjects/GameObject3D.hpp"
//#include "GameObjects/Model.hpp"
#include "PotionTiles/GridBoard.hpp"
#include "PotionTiles/CauldronTile.hpp"
#include "PotionTiles/LecturnTile.hpp"
#include <string>

using namespace Engine;

class ExampleScene : public Scene {
   private:
   //PotionParts::GameObject3D g3D;
   //PotionParts::GameObject3D cald;
   PotionGrid::GridBoard board;
   float time = 0;
   //UI::UILabel label;

   Camera cam;
   Graphics::Shader shader;
   bool need_to_link_cam = true;

   public:
   ExampleScene() : 
      Scene("ExampleScene"), 
      //g3D(PotionParts::GameObject3D(
         //PotionParts::Transform( PotionParts::Vector3( 0, 0, 0 ) ),
         //PotionParts::ModelManager::getManager().loadCube( "Assets/placeholder.png" ) ) ),
      //label("Label", "Hello World" ),
      //cald( PotionParts::GameObject3D( 
         //PotionParts::Transform( PotionParts::Vector3( 1, 0, 10 ) ),
         //PotionParts::ModelManager::getManager().loadObjModel( "Assets/cauldren.obj" ) ) )
      board(),
      cam( "main cam", 1.0f ),
      shader( "Assets/DugShader.frag" )
      {
         //AddChild(&label);

         auto cauld = new CauldronTile( PotionGrid::TilePosition() );
         auto cauld2 = new CauldronTile( PotionGrid::TilePosition( 1, 1 ) );
         auto lect = new LecturnTile( PotionGrid::TilePosition( -1, 0 ) );
         board.addTile( cauld, PotionGrid::TilePosition() );
         board.addTile( cauld2, PotionGrid::TilePosition( 1, 1 ) );
         board.addTile( lect, PotionGrid::TilePosition( -1, 0 ) );
      }

   /* virtual void Init() override {
      std::cout << "starting init\n";

      // links the camera to the renderer
      //cam.Rotation = { 90, 0, 0 };
      Game::getInstance().GetRenderer().SetCameraReference( cam );
      cam.Position = { 1.0f, 0.0f, 0.0f };
      std::cout << "initial cam pos: (" << cam.Position.x << ", " << cam.Position.y << ", " << cam.Position.z << ")\n";
   } */

   void Draw() override {

      if ( need_to_link_cam ) {
         //shader.GetShaderProgram();
         Game::getInstance().GetRenderer().UseShader( shader );
         Game::getInstance().GetRenderer().SetCameraReference( cam );
         //auto defaultShader = new Graphics::Shader()
         //td::cout << "current shader:\n" << defaultShader
         cam.Position = { 0, -5, 5 };
         cam.Rotation = { 315, 0, 0 };
         need_to_link_cam = false;
      }

      //std::cout << "starting draw\n";
      Scene::Draw();
 
      //g3D.transform.rotation().yIs(time);
      //cald.transform.rotation().yIs(time);
 
      //g3D.draw( Game::getInstance().GetRenderer() );
      //std::cout << "rendering cauld\n";
      //cald.draw( Game::getInstance().GetRenderer() );

      //cam.Rotation.x = time;

      //label.SetText( std::string( "current rotation: " ) + std::to_string( time ) );

      std::cout << "cam rotation: (" << cam.Rotation.x << ", " << cam.Rotation.y << ", " << cam.Rotation.z << ")\n";

      board.draw( Game::getInstance().GetRenderer() );
   }

   void Update(float dt) override {
      time += 2 * dt;
   }
};

Game game{Game::getInstance(new ExampleScene())};