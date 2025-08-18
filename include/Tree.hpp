#pragma once

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Tree : public sf::Drawable {
public:
    Tree() = default;

    bool loadFromFile(const std::string &texturePath);

    void setPosition(float x, float y);

    void centerHorizontally(const sf::RenderWindow &window, float verticalOffset = 0.f);

private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
