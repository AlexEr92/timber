#include "Axe.hpp"

bool Axe::loadFromFile(const std::string &texturePath) {
    if (!m_texture.loadFromFile(texturePath)) {
        return false;
    }
    m_sprite.setTexture(m_texture);
    return true;
}

void Axe::setPositionBySide(Side side) {
    switch (side) {
    case Side::LEFT:
        setPosition(AXE_POSITION_LEFT, AXE_POSITION_Y);
        break;
    case Side::RIGHT:
        setPosition(AXE_POSITION_RIGHT, AXE_POSITION_Y);
        break;
    default:
        setPosition(AXE_POSITION_LEFT, AXE_POSITION_Y);
        break;
    }
}

void Axe::setPosition(float x, float y) { m_sprite.setPosition(x, y); }

void Axe::hide() { setPosition(AXE_POSITION_HIDDEN, AXE_POSITION_Y); }

void Axe::draw(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(m_sprite, states); }
