#pragma once
class Point {
private:
    int x, y;
public:
    Point();
    Point(int xCoord, int yCoord);
    int getX() const;
    int getY() const;
    void setX(int xCoord);
    void setY(int yCoord);
};
