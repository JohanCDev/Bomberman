/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** GameScreen
*/

#include "GameScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::GameScreen::GameScreen()
{
    std::unique_ptr<ecs::Entity> entity2 = std::make_unique<ecs::Entity>();
    std::unique_ptr<ecs::Entity> entity3 = std::make_unique<ecs::Entity>();

    entity2->addComponent<ecs::Transform>(static_cast<float>(100.0), static_cast<float>(100.0), static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity2->addComponent<ecs::Text>("INDIE STUDIOOOO GAME BONJOURRRRRR", static_cast<float>(50.0), BLACK);
    entity3->addComponent<ecs::Transform>(static_cast<float>(500.0), static_cast<float>(500.0), static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity3->addComponent<ecs::Rectangle>("", static_cast<float>(100.0), static_cast<float>(250.0), GREEN);
    addEntity(std::move(entity2));
    addEntity(std::move(entity3));
}

void indie::menu::GameScreen::draw()
{
    indie::vec2u WindowDim = indie::Raylib::getWindowDimensions();
    indie::Raylib::beginDrawing();
    indie::Raylib::clearBackground();

    for (auto &ent : this->_entities) {
        ent->draw(ecs::drawableType::D2);
    }

    indie::Raylib::endDrawing();
}

bool indie::menu::GameScreen::handleEvent(indie::Event &event)
{
    (void)event;
    return true;
}

void indie::menu::GameScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::GameScreen::addEntity(std::unique_ptr<ecs::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}