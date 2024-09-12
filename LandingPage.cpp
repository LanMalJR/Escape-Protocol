#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

// Button class to handle button rendering and interaction
class Button {
public:
    Button(const sf::String& text, float x, float y) {
        font.loadFromFile("arial.ttf");  // Load a font (make sure the font file is in the working directory)
        
        buttonShape.setSize(sf::Vector2f(200, 50));
        buttonShape.setFillColor(sf::Color::Green);
        buttonShape.setPosition(x, y);
        
        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(24);
        buttonText.setFillColor(sf::Color::White);
        buttonText.setPosition(x + 10, y + 10);
    }
    
    void draw(sf::RenderWindow& window) {
        window.draw(buttonShape);
        window.draw(buttonText);
    }
    
    bool isClicked(const sf::Vector2i& mousePos) {
        return buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
};

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Screen");

    // Create buttons
    Button playButton("Play", 300, 150);
    Button scoreboardButton("Scoreboard", 300, 250);
    Button settingsButton("Settings", 300, 350);
    Button exitButton("Exit", 300, 450);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    
                    if (playButton.isClicked(mousePos)) {
                        // Handle Play button click
                        std::cout << "Play button clicked!" << std::endl;
                    } else if (scoreboardButton.isClicked(mousePos)) {
                        // Handle Scoreboard button click
                        std::cout << "Scoreboard button clicked!" << std::endl;
                    } else if (settingsButton.isClicked(mousePos)) {
                        // Handle Settings button click
                        std::cout << "Settings button clicked!" << std::endl;
                    } else if (exitButton.isClicked(mousePos)) {
                        // Handle Exit button click
                        std::cout << "Exit button clicked!" << std::endl;
                        window.close();
                    }
                }
            }
        }

        window.clear(sf::Color::Black);
        playButton.draw(window);
        scoreboardButton.draw(window);
        settingsButton.draw(window);
        exitButton.draw(window);
        window.display();
    }

    return 0;
}
