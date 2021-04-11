#ifndef _VECTOR_H_
#define _VECTOR_H_

class Vector {
    private:
        double m_x;
        double m_y;

    public:
        // default constructor
        Vector();
        // constructor with arguments
        Vector(double x, double y);
        // destructor
        ~Vector();

        // Set the coordinate values
        void set(double x, double y);
        // get x value
        double getX();
        // get y value
        double getY();
};

#endif // _VECTOR_H_
