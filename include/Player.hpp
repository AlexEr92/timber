#pragma once

#include "Side.hpp"

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Player : public sf::Drawable {
public:
    Player();

    // Load player texture
    bool loadFromFile(const std::string &texturePath);

    // Set player position
    void setPosition(Side side);

    // Reset player to initial state
    void reset();

private:
    sf::Texture m_texture; // Player texture
    sf::Sprite m_sprite;   // Player sprite
    Side m_playerSide;     // The side the player is on
    bool m_showPlayer;

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
