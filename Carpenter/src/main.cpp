#include <Game.hpp>
#include <UI/UILabel.hpp>
#include <Graphics/Shapes.hpp>
#include "GameObjects/GameObject3D.hpp"

using namespace Engine;

class ExampleScene : public Scene {
  private:
  PotionParts::GameObject3D g3D;
  PotionParts::GameObject3D cald;
  float time = 0;
  UI::UILabel label;

  public:
  ExampleScene() : Scene("ExampleScene"), 
    g3D(PotionParts::GameObject3D( Graphics::Cube(), Graphics::Texture( "Assets/placeholder.png" ), PotionParts::Transform( PotionParts::Vector3( 0, 0, 10 ) ) ) ), label("Label", "Hello World" ), cald( PotionParts::GameObject3D( PotionParts::StMesh( "Assets/Caldren.stl" ), Graphics::Texture( "Assets/placeholder.png" ), PotionParts::Transform( PotionParts::Vector3( 0, 2, 10 ) ) ) ) {
       AddChild(&label);
    }

  void Draw() override {
    Scene::Draw();

    g3D.transform.rotation().yIs(time);

    g3D.draw(Game::getInstance().GetRenderer());
    cald draw(Game::getInstance().GetRenderer());
  }

  void Update(float dt) override {
    time += 2 * dt;
  }
};

Game game{Game::getInstance(new ExampleScene())};