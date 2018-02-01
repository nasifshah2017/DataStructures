#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

class Rectangle
{
    private:
        double width;
        double length;

        void drawTop() const;
    public:
        Rectangle(double w, double len)  // Constructor
        {
            setWidth(w);
            setLength(len);
        }
        void   setWidth  (double);
        void   setLength (double);
        double getWidth  ()	const { return width; }
        double getLength ()	const { return length; }
        double getArea   ()	const { return length * width; }
        void draw()  const;
};

#endif // RECTANGLE_H_INCLUDED
