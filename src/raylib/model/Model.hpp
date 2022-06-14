/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        /**
         * @brief Class for the 3D Models with RayLib
         * 
         */
        class Model {
            public:
                /**
                 * @brief Construct a new Model object
                 * 
                 */
                Model() = default;
                /**
                 * @brief Destroy the Model object
                 * 
                 */
                ~Model() = default;

                // Model loading/unloading functions
                /**
                * @brief Load model from files (meshes and materials)
                */
                ::Model load(const char *fileName);

                /**
                * @brief Load model from generated mesh (default material)
                */
                ::Model loadFromMesh(::Mesh mesh);

                /**
                * @brief Unload model (including meshes) from memory (RAM and/or VRAM)
                */
                void unload(::Model model);

                /**
                * @brief Unload model (but not meshes) from memory (RAM and/or VRAM)
                */
                void unloadKeepMeshes(::Model model);

                // Model drawing functions
                /**
                * @brief Draw a model (with texture if set)
                */
                void draw(::Model model, ::Vector3 position, float scale, ::Color tint);

                /**
                * @brief Draw a model with extended parameters
                */
                void drawEx(::Model model, ::Vector3 position, ::Vector3 rotationAxis, float rotationAngle, ::Vector3 scale, ::Color tint);

                /**
                * @brief Draw a model wires (with texture if set)
                */
                void drawWires(::Model model, ::Vector3 position, float scale, ::Color tint);

                /**
                * @brief Draw a model wires (with texture if set) with extended parameters
                */
                void drawWiresEx(::Model model, ::Vector3 position, ::Vector3 rotationAxis, float rotationAngle, ::Vector3 scale, ::Color tint);
        };
    }
}
#endif /* !MODEL_HPP_ */
