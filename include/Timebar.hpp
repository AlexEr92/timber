#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

class Timebar : public sf::Drawable {
public:
    Timebar();

    void setup(float totalTime, float width, float height, const sf::Color &color, const sf::Vector2f &position);

    bool update(float dt);

    void reset();

    bool isTimeUp() const;
    float getRemainingTime() const;

    void setColor(const sf::Color &color);
    void setPosition(const sf::Vector2f &position);

private:
    sf::RectangleShape m_bar;
    float m_totalTime;
    float m_remainingTime;
    float m_initialWidth;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
