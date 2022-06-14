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
                /**
                * @brief Load model from files (meshes and materials)
                * 
                * @param fileName Filepath to the model file
                */
                ::Model load(const char *fileName);
                /**
                * @brief Load model from generated mesh (default material)
                * 
                * @param mesh Mesh to load
                */
                ::Model loadFromMesh(::Mesh mesh);
                /**
                * @brief Unload model (including meshes) from memory (RAM and/or VRAM)
                * 
                * @param model Model to unload
                */
                void unload(::Model model);
                /**
                * @brief Unload model (but not meshes) from memory (RAM and/or VRAM)
                * 
                * @param model Model to unload
                */
                void unloadKeepMeshes(::Model model);
                /**
                 * @brief Draw a model (with texture if set)
                 * 
                 * @param model Drawing model
                 * @param position Drawing position
                 * @param scale Drawing scale
                 * @param tint Drawing color
                 */
                void draw(::Model model, ::Vector3 position, float scale, ::Color tint);
                /**
                 * @brief Draw a model with extended parameters
                 * 
                 * @param model Drawing model
                 * @param position Drawing position
                 * @param rotationAxis Drawing rotation axis
                 * @param rotationAngle Drawing rotation angle
                 * @param scale Drawing scale
                 * @param tint Drawing color
                 */
                void drawEx(::Model model, ::Vector3 position, ::Vector3 rotationAxis, float rotationAngle, ::Vector3 scale, ::Color tint);
                /**
                 * @brief Draw a model wires (with texture if set)
                 * 
                 * @param model Drawing model
                 * @param position Drawing position
                 * @param scale Drawing scale
                 * @param tint Drawing color
                 */
                void drawWires(::Model model, ::Vector3 position, float scale, ::Color tint);
                /**
                 * @brief Draw a model wires (with texture if set) with extended parameters
                 * 
                 * @param model Drawing model
                 * @param position Drawing position
                 * @param rotationAxis Drawing rotation axis
                 * @param rotationAngle Drawing rotation angle
                 * @param scale Drawing scale
                 * @param tint Drawing color
                 */
                void drawWiresEx(::Model model, ::Vector3 position, ::Vector3 rotationAxis, float rotationAngle, ::Vector3 scale, ::Color tint);
        };
    }
}
#endif /* !MODEL_HPP_ */
