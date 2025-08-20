#pragma once

#include "Side.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Axe : public sf::Drawable {

public:
    Axe() = default;

    // Load axe texture
    bool loadFromFile(const std::string &texturePath);

    // Set axe position based on side
    void setPositionBySide(Side side);

    // Set axe position
    void setPosition(float x, float y);

    // Hide the axe
    void hide();

private:
    sf::Texture m_texture; // Axe texture
    sf::Sprite m_sprite;   // Axe sprite

    // Position constants
    static constexpr float AXE_POSITION_LEFT = 700.f;
    static constexpr float AXE_POSITION_RIGHT = 1075.f;
    static constexpr float AXE_POSITION_HIDDEN = 2000.f;
    static constexpr float AXE_POSITION_Y = 830.f;

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
