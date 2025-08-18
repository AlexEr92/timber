#pragma once

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

class GameUI : public sf::Drawable {
public:
    GameUI();

    // Load font
    bool loadFont(const std::string &fontPath);

    // Update score display
    void updateScore(int newScore);

    void setScorePosition(float x, float y);
    void setMessagePosition(float x, float y);

    void setMessage(const std::string &text);

    void showMessage(bool show);

private:
    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_messageText;

    bool m_showMessage = true;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
