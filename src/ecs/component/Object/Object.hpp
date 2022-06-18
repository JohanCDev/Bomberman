/**
 * @file Object.hpp
 * @author Johan Chrillesen (johan.chrillesen@epitech.eu)
 * @brief Object component header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <memory.h>
#include <string>

#include "../IComponent.hpp"
#include "Vec3.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            /// @brief Object component
            class Object : public IComponent {
              public:
                enum ORIENTATION { NORTH = 270, SOUTH = 90, EAST = 180, WEST = 0 };
                /**
                 * @brief Create a new animated Object component.
                 */
                Object(std::string const &texturePath, std::string const &objectPath, std::string const &animationsPath,
                    vec3f scaleVec, vec3f rotationVec, float orientation);
                /**
                 * @brief Create a new non animated Object component.
                 */
                Object(std::string const &texturePath, std::string const &objectPath);
                /**
                 * @brief Create a new non animated Object component.
                 */
                Object(std::string const &texturePath, std::string const &objectPath, vec3f scaleVec, vec3f rotationVec,
                    float orientation);
                /**
                 * @brief Destroy Object component.
                 */
                ~Object();
                /**
                 * @brief Get type of the component.
                 *
                 * @return indie::ecs::component::compoType CompoType of the component.
                 */
                indie::ecs::component::compoType getType() const;
                /**
                 * @brief Get the draw type of the component.
                 *
                 * @return indie::ecs::component::drawableType DrawableType of the component.
                 */
                indie::ecs::component::drawableType getDrawType();
                /**
                 * @brief Get the color.
                 *
                 * @return Color Color of the component.
                 */
                Color getColor();
                /**
                 * @brief Get the height value.
                 *
                 * @return float Height of the component.
                 */
                float getHeight();
                /**
                 * @brief Get the width value.
                 *
                 * @return float Width of the component.
                 */
                float getWidth();
                /**
                 * @brief Get the Texture Path of the component
                 *
                 * @return std::string Path to the texture of the component
                 */
                std::string getTexturePath() const;
                /**
                 * @brief Set the Texture Path of the component
                 *
                 * @param texturePath Path to the texture for the component
                 */
                void setTexturePath(std::string texturePath);
                /**
                 * @brief Get the Texture object of the component
                 *
                 * @return Texture2D Texture of the component
                 */
                Texture2D getTexture() const;
                /**
                 * @brief Set the Texture of the component
                 *
                 * @param texturePath Path to the texture for the component
                 */
                void setTexture(std::string texturePath);
                /**
                 * @brief Get the Model Path of the component
                 *
                 * @return std::string Path to the Model of the component
                 */
                std::string getModelPath() const;
                /**
                 * @brief Set the Model Path of the component
                 *
                 * @param modelPath Path to the model for the component
                 */
                void setModelPath(std::string modelPath);
                /**
                 * @brief Get the Model object of the component
                 *
                 * @return Model Model of the component
                 */
                Model getModel() const;
                /**
                 * @brief Set the Model of the component
                 *
                 * @param modelPath Path to the model for the component
                 */
                void setModel(std::string modelPath);

                std::string getAnimationsPath() const;

                void setAnimationsPath(std::string animationsPath);

                ::ModelAnimation *getAnimations() const;

                void setAnimations(std::string animationsPath);

                void setOrientation(ORIENTATION orientation);
                float getOrientation() const;

                vec3f getScale() const;

                vec3f getRotationVec() const;

                unsigned int getMaxCounter() const;

                int getAnimationsCounter() const;

                void setMaxCounter(unsigned int maxCounter);

                void setAnimationsCounter(int animationsCounter);

              private:
                /**
                 * @brief Value for height
                 *
                 */
                float _height;
                /**
                 * @brief Value for width
                 *
                 */
                float _width;
                /**
                 * @brief Color object for the component
                 *
                 */
                Color _color;
                /**
                 * @brief Path to the texture for the component
                 *
                 */
                std::string _texturePath;
                /**
                 * @brief Texture2D object for the component
                 *
                 */
                Texture2D _texture;
                /**
                 * @brief Path to the texture for the component
                 *
                 */
                std::string _modelPath;
                /**
                 * @brief Model object for the component
                 *
                 */
                Model _model;
                /**
                 * @brief Path to the texture for the component
                 *
                 */
                std::string _animationsPath;
                /**
                 * @brief animation model pointer
                 *
                 */
                ModelAnimation *_modelAnimation;
                /**
                 * @brief CompoType of the component
                 *
                 */
                indie::ecs::component::compoType _compoType;
                /**
                 * @brief DrawableType of the component
                 *
                 */
                indie::ecs::component::drawableType _drawableType;
                /**
                 * @brief Animation counter
                 *
                 */
                int _animationCounter;
                /**
                 * @brief nb of animations in the model
                 *
                 */
                unsigned int _maxCounter;
                vec3f _rotationVec;
                vec3f _scale;
                float _orientation;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
