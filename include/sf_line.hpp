#ifndef INCLUDE_SF_LINE_HPP_
#define INCLUDE_SF_LINE_HPP_

#include <SFML/Graphics.hpp>

class sfLine : public sf::Drawable {
 public:
    sfLine(const sf::Vector2f& point1, const sf::Vector2f& point2, sf::Color color);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::Color color;
 private:
    sf::Vertex vertices[4];
    float thickness;
};

#endif  // INCLUDE_SF_LINE_HPP_
