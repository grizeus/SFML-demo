#include <SFML/Graphics.hpp>
#include <iostream>

int main (int argc, char** argv) {

    setlocale(LC_ALL, "Ukrainian");
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)), "OpenGL with SFML", sf::Style::Default, sf::ContextSettings(32));
    window.setFramerateLimit(60);
    
    // sf::Vector2f points[] = {sf::Vector2f(700.f, 400.f), sf::Vector2f(700.f, 200.f), sf::Vector2f(800.f, 400.f)};
    // sf::ConvexShape triangle(std::size(points));
    // triangle.setPoint(0, points[0]);
    // triangle.setPoint(1, points[1]);
    // triangle.setPoint(2, points[2]);
    // triangle.setFillColor(sf::Color::Green);
    //
    // sf::CircleShape circle(50.f);
    // circle.setFillColor(sf::Color::Red);
    // circle.setPosition(sf::Vector2f(100.f, 100.f));
    // float circleMoveSpeed = 3.0f;
    //
    // sf::Font mFont;
    // if (!mFont.loadFromFile("../media/mononoki-Bold.ttf")) {
    //     printf("Error loading font\n");
    //     exit(-1);
    // }
    //
    // sf::Text text(mFont, "Hello SFML", 24);
    // sf::Text circleText(mFont, "Red circle", 14);
    //
    // circleText.setPosition(sf::Vector2f(circle.getPosition().x + circle.getRadius() - static_cast<float>(circleText.getCharacterSize()) / 2.0f,
    //                                     circle.getPosition().y + circle.getRadius() - static_cast<float>(circleText.getCharacterSize()) / 2.0f));
    // text.setPosition(sf::Vector2f(0.f, WINDOW_HEIGHT - static_cast<float>(text.getCharacterSize())));
    std::vector<sf::RectangleShape> rectangles;
    for (int x = 0; x < 25; x++) {
        for (int y = 0; y < 15; y++) {
            sf::RectangleShape rectangle(sf::Vector2f(15.f, 15.f));
            rectangle.setFillColor(sf::Color(x*10, y*10, 0));
            rectangle.setPosition(sf::Vector2f(x * 20.f, y * 20.f));
            rectangles.push_back(rectangle);
        }
    }
    while (window.isOpen()) {
	sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
		printf("Window closed\n");
		// exit(EXIT_SUCCESS);
	    }
            if (event.type == sf::Event::MouseButtonPressed) {
                printf("the mouse button button was pressed\n");
                if (event.mouseButton.button == sf::Mouse::Left) {
                    printf("\t left button pressed\n");
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    printf("\t right button pressed\n");
                }
            }

            if (event.type == sf::Event::KeyReleased) {
                std::cout << event.key.code << " was pressed" << std::endl;
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                // if (event.key.code == sf::Keyboard::X) {
                //     circleMoveSpeed *= -1.0f;
                // }
            }

        }

        // circle.move(sf::Vector2f(circleMoveSpeed, circleMoveSpeed));
        // if (circle.getPosition().x > WINDOW_WIDTH - circle.getRadius() * 2 || circle.getPosition().x < 0
        //     || circle.getPosition().y > WINDOW_HEIGHT - circle.getRadius() * 2 || circle.getPosition().y < 0) {
        //     circleMoveSpeed *= -1.0f;
        // }
        //
        // circleText.setPosition(sf::Vector2f(circle.getPosition().x + circle.getRadius() / 3 - static_cast<float>(circleText.getCharacterSize()) / 2.0f,
        //                                 circle.getPosition().y + circle.getRadius() - static_cast<float>(circleText.getCharacterSize()) / 2.0f));
        // sf::Angle angle = sf::radians(0.01f);
        // triangle.rotate(angle);
        window.clear();
        for (auto& rectangle : rectangles) {
            window.draw(rectangle);
        }
        window.display();
    }
    return 0;
}
