#include "shapes.hpp"

/* Zvezda se crta iz 12 trostranih prizmi, sa leva na desno po redovima */
void Star::draw()
{
    glColor3f(_c.color_r, _c.color_g, _c.color_b);

    glPushMatrix();
        glTranslatef(_xyz.x, _xyz.y, _xyz.z);

        glPushMatrix();
            glTranslatef(0, 0, -_size*sqrt(3)/4*3);
            glRotatef(-90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-_size, 0, -_size*sqrt(3)/4);
            glRotatef(90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-_size/2, 0, -_size*sqrt(3)/4);
            glRotatef(-90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0, -_size*sqrt(3)/4);
            glRotatef(90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(_size/2, 0, -_size*sqrt(3)/4);
            glRotatef(-90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(_size, 0, -_size*sqrt(3)/4);
            glRotatef(90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-_size, 0, _size*sqrt(3)/4);
            glRotatef(-90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-_size/2, 0, _size*sqrt(3)/4);
            glRotatef(90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0, _size*sqrt(3)/4);
            glRotatef(-90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(_size/2, 0, _size*sqrt(3)/4);
            glRotatef(90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(_size, 0, _size*sqrt(3)/4);
            glRotatef(-90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0, _size*sqrt(3)/4*3);
            glRotatef(90, 1, 0, 0);
            draw_prism(_size, _size);
        glPopMatrix();

        glGetFloatv(GL_MODELVIEW_MATRIX, _system); // Pamti se sistem objekta
    glPopMatrix();
}

/* Iscrtava se odgovarajuća zvezda na glavnoj kocki */
void Star::draw_on_main_cube(Color c) const
{
    glColor3f(c.color_r, c.color_g, c.color_b);

    glPushMatrix();
        /* Na osnovu id-ja u mapi se pronalazi odgovarajuća pozicija na kocki */
        Coordinates xyz = places_on_main_cube.find(_id)->second;
        glTranslatef(xyz.x, xyz.y, xyz.z);

        glBegin(GL_TRIANGLES);
            /* Postoje tri grupe strana na osnovu toga koje ose se koriste za
                 * 2d iscrtavanje oblika na glavnoj kocki */
            switch(_id%3)
            {
                /* Koriste se x i y osa za iscrtavnje */
                case 0:
                    glVertex3f(-3*_size/2, _size*sqrt(3)/2, 0);
                    glVertex3f(0, -_size*sqrt(3), 0);
                    glVertex3f(3*_size/2, _size*sqrt(3)/2, 0);

                    glVertex3f(0, _size*sqrt(3), 0);
                    glVertex3f(-3*_size/2, -_size*sqrt(3)/2, 0);
                    glVertex3f(3*_size/2, -_size*sqrt(3)/2, 0);
                    break;
                    /* Koriste se y i z osa za iscrtavanje*/
                case 1:
                    glVertex3f(0, _size*sqrt(3)/2, 3*_size/2);
                    glVertex3f(0, -_size*sqrt(3), 0);
                    glVertex3f(0, _size*sqrt(3)/2, -3*_size/2);

                    glVertex3f(0, _size*sqrt(3), 0);
                    glVertex3f(0, -_size*sqrt(3)/2, 3*_size/2);
                    glVertex3f(0, -_size*sqrt(3)/2, -3*_size/2);
                    break;
                    /* Koriste se x i z osa za iscrtavanje*/
                case 2:
                    glVertex3f(-3*_size/2, 0, -_size*sqrt(3)/2);
                    glVertex3f(0, 0, _size*sqrt(3));
                    glVertex3f(3*_size/2, 0, -_size*sqrt(3)/2);

                    glVertex3f(0, 0, -_size*sqrt(3));
                    glVertex3f(-3*_size/2, 0, _size*sqrt(3)/2);
                    glVertex3f(3*_size/2, 0, _size*sqrt(3)/2);
                    break;
                default:
                    std::cout << "Entered default in switch; probably error..." << std::endl;
            }
        glEnd();
    glPopMatrix();
}