#pragma once

#include "figure.h"
#include <iostream>

using namespace std;

template <class T>
class Pentagon : public Figure<T>{

    template <class F>
    friend std::ostream& operator << (std::ostream& os, const Pentagon<F>& f);
    template <class F>
    friend std::istream& operator >> (std::istream& is, Pentagon<F>& f);

public:
    Pentagon();
    Pentagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5);

    virtual T square() const override;
    virtual Point<T> center() const override;

    Pentagon<T>& operator = (const Pentagon<T> &other);
    Pentagon<T>& operator = (Pentagon<T> &&other);
    bool operator == (const Pentagon<T> &other) const;
    virtual operator double() const override;

    ~Pentagon(){};

private:
    static const size_t angles_ = 5;
    Point<T> po[angles_];
};
