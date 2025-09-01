#pragma once

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

// Static tree object with positioning capability
class Tree : public sf::Drawable {
public:
    Tree(const std::string &texturePath);

    // Set tree position
    void setPosition(float x, float y);

    // Set tree horizontally in window
    void centerHorizontally(const sf::RenderWindow &window, float verticalOffset = 0.f);

private:
    sf::Sprite m_sprite;   // Tree sprite
    sf::Texture m_texture; // Tree texture

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
