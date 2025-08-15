#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <string>

class Tree {
public:
    Tree() = default;

    bool loadFromFile(const std::string &texturePath);

    void setPosition(float x, float y);

    void centerHorizontally(const sf::RenderWindow &window, float verticalOffset = 0.f);

    const sf::Sprite &getSprite() const;

private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
};
