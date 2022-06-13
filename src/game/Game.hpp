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
    /// @brief Game class
    class Game {
      public:
        /// @brief enum containing all navigable screens
        enum class Screens { Menu = 1, Game, PreMenu, GameOptions, End, SetMusic, SetSound, SetFps, Count };
        /// @brief Constructor
        /// @param baseFps base fps (60 by default)
        Game(size_t baseFps = 60);
        /// @brief Destructor
        ~Game();
        /// @brief Initialize the game class elements
        void init(void);
        /// @brief Run the game class
        void run(void);
        /// @brief Draw game elements
        void draw(void);
        /// @brief Update game elements
        void update(void);
        /// @brief Process events
        bool processEvents(void);
        /// @brief Handle the events
        int handleEvent();
        /// @brief Init all scenes
        void init_scenes();
        /// @brief Swap between screens
        void handleScreensSwap(int ret);
        /// @brief Reinitialize the game class elements
        void reinitGame();
        /// @brief Set the actual screen
        void setActualScreen(Screens newScreen);

      protected:
      private:
        /// @brief Actual screen
        Screens _actualScreen;
        /// @brief Game fps
        size_t _fps;
        /// @brief Players
        std::vector<player::Player> _players;
        /// @brief Menu screen
        indie::menu::MenuScreen *_menu;
        /// @brief Game screen
        indie::menu::GameScreen *_game;
        /// @brief PreMenu screen
        indie::menu::PreMenuScreen *_premenu;
        /// @brief GameOptions screen
        indie::menu::GameOptionsScreen *_gameoptions;
        /// @brief End screen
        indie::menu::EndScreen *_end;
        /// @brief SetFps screen
        indie::menu::SetFpsScreen *_setFps;
        /// @brief SetSound screen
        indie::menu::SetSoundScreen *_setSound;
        /// @brief SetMusic screen
        indie::menu::SetMusicScreen *_setMusic;
        /// @brief Actual Event
        indie::Event _event;
    };
} // namespace indie

#endif /* !GAME_HPP_ */
