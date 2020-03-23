#include <vector>
#include <string>

#ifndef CPP_EX2_1_FRACTAL_H
#define CPP_EX2_1_FRACTAL_H


class Fractal
{
public:
    Fractal(int dim);

    ~Fractal() = default;

    virtual void doDraw() = 0;

    virtual void createFrac() = 0;

    virtual char isFill(int x, int y) = 0;

protected:
    int _dim;
    std::vector<std::vector<char>> frac;

};

class SierpinskiCarpet: public Fractal
{
public:
    SierpinskiCarpet(int dim);

    ~SierpinskiCarpet() = default;

    void doDraw() override;

    void createFrac() override;

    char isFill(int x, int y) override;

};

#endif //CPP_EX2_1_FRACTAL_H
