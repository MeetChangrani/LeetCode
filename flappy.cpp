#include "glut.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include<cmath>
#include <sstream>

// Bird variables
float birdY = 0.0f;
float velocity = 0.0f;
float gravity = -0.0015f;
bool isGameOver = false;
int score = 0;

// Pipe variables
float pipeX = 1.2f;
float gapY = 0.0f;
float gapHeight = 0.4f;

// Function to draw text
void drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    for (char ch : text)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch);
}

// Function to reset game
void resetGame() {
    birdY = 0.0f;
    velocity = 0.0f;
    pipeX = 1.2f;
    gapY = 0.0f;
    score = 0;
    isGameOver = false;
}

// Draw bird (circle)
void drawBird() {
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.5f, birdY);
    for (int i = 0; i <= 20; i++) {
        float angle = i * 2.0f * 3.1416f / 20;
        glVertex2f(-0.5f + 0.03f * cos(angle), birdY + 0.03f * sin(angle));
    }
    glEnd();
}

// Draw pipes
void drawPipes() {
    glColor3f(0.0, 1.0, 0.0);
    // Top pipe
    glBegin(GL_QUADS);
    glVertex2f(pipeX, gapY + gapHeight / 2.0f);
    glVertex2f(pipeX + 0.1f, gapY + gapHeight / 2.0f);
    glVertex2f(pipeX + 0.1f, 1.0f);
    glVertex2f(pipeX, 1.0f);
    glEnd();

    // Bottom pipe
    glBegin(GL_QUADS);
    glVertex2f(pipeX, -1.0f);
    glVertex2f(pipeX + 0.1f, -1.0f);
    glVertex2f(pipeX + 0.1f, gapY - gapHeight / 2.0f);
    glVertex2f(pipeX, gapY - gapHeight / 2.0f);
    glEnd();
}

// Main game display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawBird();
    drawPipes();

    // Score text
    glColor3f(1.0, 1.0, 1.0);
    std::stringstream ss;
    ss << "Score: " << score;
    drawText(-0.95f, 0.9f, ss.str());

    if (isGameOver) {
        drawText(-0.2f, 0.0f, "GAME OVER!");
        drawText(-0.25f, -0.1f, "Press R to Restart");
    }

    glutSwapBuffers();
}

// Timer function
void update(int value) {
    if (!isGameOver) {
        velocity += gravity;
        birdY += velocity;

        pipeX -= 0.01f;

        if (pipeX < -1.2f) {
            pipeX = 1.2f;
            gapY = (rand() % 100 / 100.0f) * 1.2f - 0.6f;
            score++;
        }

        // Collision Detection
        if (
            (-0.5f + 0.03f > pipeX && -0.5f - 0.03f < pipeX + 0.1f) && 
            (birdY + 0.03f > gapY + gapHeight / 2.0f || birdY - 0.03f < gapY - gapHeight / 2.0f)
            || birdY < -1.0f || birdY > 1.0f
        ) {
            isGameOver = true;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}

// Keyboard input
void keyboard(unsigned char key, int x, int y) {
    if (key == ' ' && !isGameOver) {
        velocity = 0.03f;
    } else if (key == 'r' || key == 'R') {
        resetGame();
    }
}

// Setup OpenGL
void init() {
    glClearColor(0.0, 0.6, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

// Main
int main(int argc, char** argv) {
    srand(time(0));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Flappy Bird (GLUT)");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
