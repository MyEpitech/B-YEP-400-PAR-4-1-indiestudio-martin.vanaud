/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** AThreeDimensionObject
*/

#ifndef ATHREEDIMENSIONOBJECT_HPP_
    #define ATHREEDIMENSIONOBJECT_HPP_

    #include <raylib.h>
    #include <nlohmann/json.hpp>

    #include "IRenderding.hpp"
    #include "Rendering/Animation.hpp"
    #include "Rendering/Model.hpp"
    #include "Rendering/Texture.hpp"

    #include "IThreeDimensionObject.hpp"

namespace Object
{
    class AThreeDimensionObject : public IThreeDimensionObject
    {
    public:
        // Non Animated
        AThreeDimensionObject(std::pair<std::string, std::string> const &pathToRessources, Position const &position, Object::MAP_OBJECTS type);
        AThreeDimensionObject(Object::Render::MyModel pathToModel, Object::Render::MyTexture pathToTexture, Position const &position, Object::MAP_OBJECTS type);

        // Animated
        AThreeDimensionObject(std::pair<std::string, std::string> const &pathToRessources, std::string const &pathToAnimation, unsigned int nbAnimation, Position const &position, Object::MAP_OBJECTS type);
        AThreeDimensionObject(Object::Render::MyModel &pathToModel, Object::Render::MyTexture &pathToTexture, Object::Render::MyAnimation &pathToAnimation, unsigned int numberOfAnimations, Position const &position, Object::MAP_OBJECTS type);

        // Via JSON
        AThreeDimensionObject(nlohmann::json const &jsonData);

        virtual ~AThreeDimensionObject() = default;

        virtual void draw() = 0;

        virtual void enable() override;
        virtual void disable() override;
        virtual bool isEnable() const override;

        void setPosition(Position const &position) override;
        void setPosition(float x, float y) override;
        void setPosition(float x, float y, float z) override;

        Texture2D getTexture() const;
        Model getModel() const;
        Position getPosition() const;
        Position getDimensions() const;
        float getScale() const;

        void setScale(float scale);

        Object::MAP_OBJECTS getType() const { return _type; };

    protected:
        bool _isEnable;
        Texture2D _texture;
        Model _model;

        Position _position;
        Position _dimensions;
        bool _isAnimated;

        unsigned int _animsCount = 0;
        int _animFrameCounter = 0;
        ModelAnimation *_anims;
        Object::MAP_OBJECTS _type;

        float _scale = 0.5f;
    private:
    };
}

#endif /* !ATHREEDIMENSIONOBJECT_HPP_ */
