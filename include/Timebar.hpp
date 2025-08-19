#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

// Visual countdown timer represented as a shrinking rectangle
class Timebar : public sf::Drawable {
public:
    Timebar();

    // Initialize timebar
    void setup(float totalTime, float width, float height, const sf::Color &color, const sf::Vector2f &position);

    // Update with delta time
    void update(float dt);

    // Reset to initial state
    void reset();

    // Check if time is up
    bool isTimeUp() const;

    // Get remaining time
    float getRemainingTime() const;

    // Set fill color
    void setColor(const sf::Color &color);

    // set position with vector
    void setPosition(const sf::Vector2f &position);

private:
    sf::RectangleShape m_bar; // Visual representation of the timebar
    float m_totalTime;        // Total duration of the timebar
    float m_remainingTime;    // Current remaining time in seconds
    float m_initialWidth;     // Initial width of the timebar

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
