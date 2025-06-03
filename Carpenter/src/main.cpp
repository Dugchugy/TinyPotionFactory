#include <Game.hpp>
#include <UI/UILabel.hpp>
#include <Graphics/Shapes.hpp>
#include "GameObjects/GameObject3D.hpp"

using namespace Engine;

class ExampleScene : public Scene {
  private:
  PotionParts::GameObject3D g3D;
  float time = 0;

  public:
  ExampleScene() : Scene("ExampleScene"), 
    g3D(PotionParts::GameObject3D(Graphics::Cube(), Graphics::Texture("Assets/placeholder.png"))) {
      g3D.Position = {0, 0, 10};
      g3D.Scale = {1, 1, 1};
    }

  void Draw() override {
    Scene::Draw();

    g3D.Rotation = {-35, time, 0};

    g3D.draw(Game::getInstance().GetRenderer());
  }

  void Update(float dt) override {
    time += 2 * dt;
  }
};

Game game{Game::getInstance(new ExampleScene())};