#include "shapes.hpp"

/* Iscrtava se cilindar */
void Cylinder::draw(Color c)
{
    glColor3f(c.color_r/255.0, c.color_g/255.0, c.color_b/255.0);

    glPushMatrix();
        glTranslatef(_xyz.x, _xyz.y, _xyz.z);
        draw_cylinder(_height, _size);
    glPopMatrix();
}

/* Iscrtava se odgovarajući krug na glavnoj kocki */
void Cylinder::draw_on_main_cube(Color c) const
{
    glColor3f(c.color_r/255.0, c.color_g/255.0, c.color_b/255.0);

    glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
        /* Postoje tri grupe strana na osnovu toga koje ose se koriste
         * za 2d iscrtavanje oblika na glavnoj kocki*/
            switch(_id % 3)
            {
                /* Koriste se x i y osa za iscrtavnje */
                case 0:
                    for(int i = 0; i <= NUM_OF_VERTEXES; i++)
                    {
                        glVertex3f(cos(i)*_size, sin(i)*_size, 0);
                    }
                    break;
                    /* Koriste se y i z osa za iscrtavanje*/
                case 1:
                    for(int i = 0; i <= NUM_OF_VERTEXES; i++)
                    {
                        glVertex3f(0, cos(i)*_size, sin(i)*_size);
                    }
                    break;
                    /* Koriste se x i z osa za iscrtavanje*/
                case 2:
                    for(int i = 0; i <= NUM_OF_VERTEXES; i++)
                    {
                        glVertex3f(cos(i)*_size, 0, sin(i)*_size);
                    }
                    break;
                default:
                    std::cout << "Entered default in switch; probably error..." << std::endl;
            }
        glEnd();
    glPopMatrix();
}