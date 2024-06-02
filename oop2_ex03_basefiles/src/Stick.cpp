#include <iostream> 
#include <fstream>
#include <sstream> 
#include <cmath>
#include "Stick.h"
#include "Macros.h"
#include "IncorrectFileException.h"
#include "InvalidGameStateException.h"

Stick::Stick(int id) : m_id(id), m_highlight(false)
{
    m_length = (rand() % (280 - 50 + 1)) + 50;
    m_startPoint = { float((rand() % (910 - 520 + 1) + 520)),
                     float((rand() % (520 - 280 + 1) + 280)) };
    m_angle = float(rand() % 360);
    m_stick.setSize(sf::Vector2f(float(m_length), 9.0f));
    m_stick.setPosition(m_startPoint);
    m_stick.setRotation(m_angle);
    m_color = rand() % 5;

    setStickScoreByColorIndex(m_color);
}

Stick::Stick() : m_id(0), m_score(0), m_length(0), m_highlight(false),
                 m_color(0), m_angle(0){}


void Stick::setStickScoreByColorIndex(int colorIndex)
{  
    switch (colorIndex) 
    {
    case 0:
        m_stick.setFillColor(sf::Color::Black);
        m_score = 25;
        break;
    case 1:
        m_stick.setFillColor(sf::Color(105, 138, 255)); // Purple 
        m_score = 15;
        break;
    case 2:
        m_stick.setFillColor(sf::Color(255, 234, 97)); // Yellow
        m_score = 6;
        break;
    case 3:
        m_stick.setFillColor(sf::Color(205, 243, 152)); // Green
        m_score = 5;
        break;
    case 4:
        m_stick.setFillColor(sf::Color(194, 59, 34)); // Red
        m_score = 4;
        break;
    default:
        break;
    }
}

void Stick::draw(sf::RenderWindow& window)
{
    if (m_highlight &&
        m_highlightClock.getElapsedTime().asMilliseconds() < 500) 
    {
        m_stick.setOutlineColor(sf::Color::Yellow);
        m_stick.setOutlineThickness(2);
    }

    else 
    {
        m_stick.setOutlineThickness(0);
    }
    window.draw(m_stick);
}

bool Stick::intersects(const Stick& other) const 
{
    sf::Vector2f p1 = getStartPoint();
    sf::Vector2f q1 = getEndPoint();
    sf::Vector2f p2 = other.getStartPoint();
    sf::Vector2f q2 = other.getEndPoint();

    auto onSegment = [](sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) 
        {
            return (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
                    q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y));
        };

    auto orientation = [](sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) 
        {
            float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
            if (val == 0) return 0;  // collinear
            return (val > 0) ? 1 : 2; // clock or counterclock wise
        };

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

sf::Vector2f Stick::getStartPoint() const
{  
    return m_startPoint;
}

sf::Vector2f Stick::getEndPoint() const
{
    float rotation = float(m_angle * PI / 180.0f);

    return {m_startPoint.x + m_length * cos(rotation),
            m_startPoint.y + m_length * sin(rotation)};
}

bool Stick::canBePicked() const 
{
    return m_sticksAbove.size() == 0;
}

bool Stick::contains(const sf::Vector2f& point) const 
{
    sf::Vector2f position = m_stick.getTransform().getInverse().transformPoint(point);
    return m_stick.getLocalBounds().contains(position);
}

void Stick::highlightSticksAbove() 
{
    for (auto& aboveStick : m_sticksAbove) 
    {
        aboveStick->highlightStick();
    }
}

void Stick::update() 
{
    if (m_highlight &&
        m_highlightClock.getElapsedTime().asMilliseconds() >= 500) 
    {
        m_highlight = false;
    }
}

void Stick::highlightStick() 
{
    m_highlight = true;
    m_highlightClock.restart();
}


void Stick::removeStickAbove(Stick* stickAbove)
{
    m_sticksAbove.erase(std::remove(m_sticksAbove.begin(),
                        m_sticksAbove.end(), stickAbove), 
                        m_sticksAbove.end());
}

void Stick::addStickAbove(Stick* stick)
{
    m_sticksAbove.push_back(stick);
}

int Stick::getScore() const
{
    return m_score;
}
int Stick::getId() const
{
    return m_id;
}

bool Stick::getHighlightStatus() const
{
    return m_highlight;
}

void Stick::save(std::ofstream& outFile) const
{
    outFile << m_id << ' ' << m_length << ' ' << m_startPoint.x << ' ' 
            << m_startPoint.y << ' ' << m_color << ' ' << m_angle << ' '
            << '\n';
}

void Stick::load(std::ifstream& inFile, int numOfSticks) 
{
    std::string line;

    if (std::getline(inFile, line))
    {
        std::istringstream iss(line);

        if (!(iss >> m_id >> m_length >> m_startPoint.x >> m_startPoint.y >>
              m_color >> m_angle))
        {
            throw IncorrectFileException("Failed to read stick data.");
        }

        if (m_id < 0 || m_id > numOfSticks ||
            m_length < MIN_STICK_LENGTH || m_length > MAX_STICK_LENGTH ||
            m_startPoint.x < MIN_START_X || m_startPoint.x > MAX_START_X ||
            m_startPoint.y < MIN_START_Y || m_startPoint.y > MAX_START_Y ||
            m_color < 0 || m_color > MAX_COLOR_INDEX ||
            m_angle < 0 || m_angle > MAX_ANGLE)
        {
            throw InvalidGameStateException("Stick data is not valid.");
        }

        m_stick.setSize(sf::Vector2f(float(m_length), 9.0f));
        m_stick.setPosition(m_startPoint);
        m_stick.setRotation(m_angle);
        m_highlight = false;
        setStickScoreByColorIndex(m_color);
    }
    else
    {
        throw IncorrectFileException("Failed to read stick data.");
    }

}