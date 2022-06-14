/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <cstddef>
#include <map>
#include <memory>
#include <vector>

#include "../ecs/system/Collide/Collide.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"
#include "../ecs/system/Draw3D/Draw3D.hpp"
#include "../ecs/system/Movement/Movement.hpp"
#include "../ecs/system/Sound/Sound.hpp"
#include "../player/Player.hpp"
#include "../screens/IScreen.hpp"
#include "../screens/end/EndScreen.hpp"
#include "../screens/game/GameScreen.hpp"
#include "../screens/menu/MenuScreen.hpp"
#include "events.hpp"
#include "../screens/game_options/GameOptionsScreen.hpp"
#include "../screens/pre_menu/PreMenuScreen.hpp"
#include "../screens/set_fps/SetFpsScreen.hpp"
#include "../screens/set_music/SetMusicScreen.hpp"
#include "../screens/set_sound/SetSoundScreen.hpp"

namespace indie
{
    class Game {
      public:
        enum class Screens { Menu = 1, Game, PreMenu, GameOptions, End, SetMusic, SetSound, SetFps, Count };
        enum Sounds { BOMB_S = 0, GAME_READY_S = 1, SELECT_S = 2};
        enum Musics { MENU_SOUND };
        Game(size_t baseFps = 60);
        ~Game();
        void init(void);
        void run(void);
        void draw(void);
        void update(void);
        bool processEvents(void);

        int handleEvent();
        void initScenes();
        void initSounds();
        void initMusic();
        void destroy();
        void destroyEntities();
        void destroySystems();
        void handleScreensSwap(int ret);
        void reinitGame();
        void setActualScreen(Screens newScreen);
        void setSoundEvent(int entititesIndex);

        void addSoundEntity(std::unique_ptr<indie::ecs::entity::Entity> entity);
        void addSoundSystem(std::unique_ptr<indie::ecs::system::ISystem> system);

        // void addMusicEntity(std::unique_ptr<indie::ecs::entity::Entity> entity);
        // void addMusicSystem(std::unique_ptr<indie::ecs::system::ISystem> system);

      protected:
      private:
        Screens _actualScreen;
        size_t _fps;
        std::vector<player::Player> _players;
        indie::menu::MenuScreen *_menu;
        indie::menu::GameScreen *_game;
        indie::menu::PreMenuScreen *_premenu;
        indie::menu::GameOptionsScreen *_gameoptions;
        indie::menu::EndScreen *_end;
        indie::menu::SetFpsScreen *_setFps;
        indie::menu::SetSoundScreen *_setSound;
        indie::menu::SetMusicScreen *_setMusic;
        indie::Event _event;
        std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _sound_entities;
        std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _sound_systems;

        std::map <int, indie::raylib::Sound> _musics;
        // std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _music_entities;
        // std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _music_systems;

    };
} // namespace indie

#endif /* !GAME_HPP_ */
