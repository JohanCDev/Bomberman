/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** OptionsScreen.cpp
*/

#include "OptionsScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::OptionsScreen::OptionsScreen() : _cursorPosition(RESUME)
{
    std::unique_ptr<ecs::Entity> new_game = std::make_unique<ecs::Entity>();
    new_game->addComponent<ecs::Transform>(static_cast<float>(400.0), static_cast<float>(500.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    new_game->addComponent<ecs::Rectangle>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    new_game->addComponent<ecs::Text>("Resume", static_cast<float>(50.0), BLACK);
    addEntity(std::move(new_game));

    std::unique_ptr<ecs::Entity> load_game = std::make_unique<ecs::Entity>();
    load_game->addComponent<ecs::Transform>(static_cast<float>(400.0), static_cast<float>(600.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    load_game->addComponent<ecs::Rectangle>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    load_game->addComponent<ecs::Text>("Menu", static_cast<float>(50.0), BLACK);
    addEntity(std::move(load_game));

    std::unique_ptr<ecs::Entity> options = std::make_unique<ecs::Entity>();
    options->addComponent<ecs::Transform>(static_cast<float>(400.0), static_cast<float>(700.0), static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    options->addComponent<ecs::Rectangle>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    options->addComponent<ecs::Text>("EXIT", static_cast<float>(50.0), BLACK);
    addEntity(std::move(options));

    std::unique_ptr<ecs::Entity> cursor = std::make_unique<ecs::Entity>();
    cursor->addComponent<ecs::Transform>(static_cast<float>(320.0), static_cast<float>(510.0), static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    cursor->addComponent<ecs::Rectangle>("", static_cast<float>(40.0), static_cast<float>(40.0), RED);
    addEntity(std::move(cursor));
}

void indie::menu::OptionsScreen::draw()
{
    indie::vec2u WindowDim = indie::Raylib::getWindowDimensions();
    indie::Raylib::beginDrawing();
    indie::Raylib::clearBackground();

    for (auto &ent : this->_entities) {
        ent->draw(ecs::drawableType::D2);
    }

    indie::Raylib::endDrawing();
}

int indie::menu::OptionsScreen::handleEvent(indie::Event &event)
{
    if (event.key.down) {
        ecs::Transform *transformCompo = _entities.at(3)->getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
        transformCompo->update(static_cast<float>(320.0), static_cast<float>(checkCursorPosition(true)),
            static_cast<float>(0.0), static_cast<float>(0.0));
    }
    if (event.key.up) {
        ecs::Transform *transformCompo = _entities.at(3)->getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
        transformCompo->update(static_cast<float>(320.0), static_cast<float>(checkCursorPosition(false)),
            static_cast<float>(0.0), static_cast<float>(0.0));
    }
    if (event.key.enter && _cursorPosition == RESUME)
        return 2;
    if (event.key.enter && _cursorPosition == MENU)
        return 1;
    if (event.key.enter && _cursorPosition == EXIT)
        return 10;
    return 0;
}

void indie::menu::OptionsScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::OptionsScreen::addEntity(std::unique_ptr<ecs::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

int indie::menu::OptionsScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == RESUME) {
            _cursorPosition = MENU;
            return MENU;
        }
        if (_cursorPosition == MENU) {
            _cursorPosition = EXIT;
            return EXIT;
        }
        if (_cursorPosition == EXIT)
            return EXIT;
    } else if (!direction) {
        if (_cursorPosition == RESUME)
            return RESUME;
        if (_cursorPosition == MENU) {
            _cursorPosition = RESUME;
            return RESUME;
        }
        if (_cursorPosition == EXIT) {
            _cursorPosition = MENU;
            return MENU;
        }
    }
    return 0;
}