#pragma once

#include <string>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

#include "Timebar.hpp"

// Manages and renders all user interface elements for the game
class GameUI : public sf::Drawable {
public:
    GameUI();

    // Load font
    bool loadFont(const std::string &fontPath);

    // Update score display
    void updateScore(int newScore);

    // Set score position
    void setScorePosition(float x, float y);

    // Set message text
    void setMessage(const std::string &text);

    // Set message position
    void setMessagePosition(float x, float y);

    // Center message on the game field
    void centerMessage();

    // Show/hide message
    void showMessage(bool show);

    // Reset to initial state
    void reset();

    // Check if time is up
    bool isTimeUp() const { return m_timebar.isTimeUp(); }

    // Update timebar with delta time
    void updateTimebar(float dt) { m_timebar.update(dt); }

    // Configure timebar
    void setupTimebar(float totalTime, float width, float height, const sf::Color &color, const sf::Vector2f &position);

private:
    sf::Font m_font;           // UI font
    sf::Text m_scoreText;      // Score text
    sf::Text m_messageText;    // Message text
    bool m_showMessage = true; // Current message state
    Timebar m_timebar;         // Timebar

    // Check if the font is loaded
    bool isFontLoaded() const { return !m_font.getInfo().family.empty(); }

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
