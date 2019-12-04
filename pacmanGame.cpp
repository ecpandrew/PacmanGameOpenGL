#include <GL/glut.h>

#include <stdlib.h>

#include <stdio.h>

#include <math.h>

#define GLM_ENABLE_EXPERIMENTAL

#include <unistd.h>

// #include <glm/gtc/matrix_transform.hpp>

// #include <glm/glm.hpp>

// #include <glm/gtx/transform.hpp>

#include </home/daniela/Documents/OpenGL/3AV/irrklang/include/irrKlang.h>
// #include </home/andrew/cgraf/p3/irrklang/include/irrKlang.h>
using namespace irrklang;

#pragma comment(lib, "irrKlang.lib")

static GLfloat spin = 0.0;

/* pacman */
static int c_x = 200;
static int c_y = 680;
static int raio = 4;

static int cv_X = 800;
static int cv_Y = 580;
static int delay = 40;

ISoundEngine *engine;

// glm::vec2 position [2] = {200,680};

GLfloat posicaoX = 0;
GLfloat posicaoY = 0;

static GLfloat t1 = 0;
static GLfloat t2 = 0;

static int angle = 0;
static GLint anguloTotal = 360;

static bool CIMA = false;
static bool BAIXO = false;
static bool LADO_ESQUERDO = false;
static bool LADO_DIREITO = false;

static int percursoVilaoX[12] = {cv_X, cv_X - 40, cv_X - 80, cv_X - 120, cv_X - 160, cv_X - 200};
static int percursoVilaoY[12] = {cv_Y, cv_Y, cv_Y, cv_Y, cv_Y, cv_Y};
static int tamanho_vetor_vilao = 5;
class Pacman
{

public:
    void setPosicaoX(float x);
    void setPosicaoY(float y);
    float getPosicaoX();
    float getPosicaoY();
    void setAnguloTeta(float teta);
    float getAnguloTeta();
    void setCoordenadaX(int x);
    int getCoordenadaX();
    void setCoordenadaY(int y);
    int getCoordenadaY();

    void setSizePacman(float x);
    float getSizePacman();

    void setSizeOlhoPacman(float x);
    float getSizeOlhoPacman();

private:
    float x;
    float y;
    float teta;
    float sizePacman;
    float sizeOlhoPacman;
    int coordX;
    int coordY;
};

//#################################### * \ Classe Quadrados Pontos / * #######################################

class QuadradosPontos
{
public:
    void setPositionX1(int x1);
    void setPositionX2(int x2);
    void setPositionX3(int x3);
    void setPositionX4(int x4);
    void setPositionX5(int x5);

    int getPositionX1();
    int getPositionX2();
    int getPositionX3();
    int getPositionX4();
    int getPositionX5();

    void setPositionY1(int y1);
    void setPositionY2(int y2);
    void setPositionY3(int y3);
    void setPositionY4(int y4);
    void setPositionY5(int y5);

    int getPositionY1();
    int getPositionY2();
    int getPositionY3();
    int getPositionY4();
    int getPositionY5();

    void setStatus(bool status);
    bool getStatus();

private:
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;

    int y1;
    int y2;
    int y3;
    int y4;
    int y5;

    bool statusComida;
};

void QuadradosPontos::setPositionX1(int x)
{
    x1 = x;
}

void QuadradosPontos::setPositionX2(int x)
{
    x2 = x;
}

void QuadradosPontos::setPositionX3(int x)
{
    x3 = x;
}

void QuadradosPontos::setPositionX4(int x)
{
    x4 = x;
}

void QuadradosPontos::setPositionX5(int x)
{
    x5 = x;
}

int QuadradosPontos::getPositionX1()
{
    return x1;
}

int QuadradosPontos::getPositionX2()
{
    return x2;
}

int QuadradosPontos::getPositionX3()
{
    return x3;
}

int QuadradosPontos::getPositionX4()
{
    return x4;
}

int QuadradosPontos::getPositionX5()
{
    return x5;
}

void QuadradosPontos::setPositionY1(int y)
{
    y1 = y;
}

void QuadradosPontos::setPositionY2(int y)
{
    y2 = y;
}

void QuadradosPontos::setPositionY3(int y)
{
    y3 = y;
}

void QuadradosPontos::setPositionY4(int y)
{
    y4 = y;
}

void QuadradosPontos::setPositionY5(int y)
{
    y5 = y;
}

void QuadradosPontos::setStatus(bool status)
{
    statusComida = status;
}

bool QuadradosPontos::getStatus()
{
    return statusComida;
}

int QuadradosPontos::getPositionY1()
{
    return y1;
}

int QuadradosPontos::getPositionY2()
{
    return y2;
}

int QuadradosPontos::getPositionY3()
{
    return y3;
}

int QuadradosPontos::getPositionY4()
{
    return y4;
}

int QuadradosPontos::getPositionY5()
{
    return y5;
}

//#################################### * \ Classe Paredes (Wall) / * #######################################

class Wall
{

public:
    void setPositionX1(int x1);
    void setPositionX2(int x2);
    void setPositionX3(int x3);
    void setPositionX4(int x4);
    void setPositionX5(int x5);

    int getPositionX1();
    int getPositionX2();
    int getPositionX3();
    int getPositionX4();
    int getPositionX5();

    void setPositionY1(int y1);
    void setPositionY2(int y2);
    void setPositionY3(int y3);
    void setPositionY4(int y4);
    void setPositionY5(int y5);

    int getPositionY1();
    int getPositionY2();
    int getPositionY3();
    int getPositionY4();
    int getPositionY5();

private:
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;

    int y1;
    int y2;
    int y3;
    int y4;
    int y5;
};

void Wall::setPositionX1(int x)
{
    x1 = x;
}

void Wall::setPositionX2(int x)
{
    x2 = x;
}

void Wall::setPositionX3(int x)
{
    x3 = x;
}

void Wall::setPositionX4(int x)
{
    x4 = x;
}

void Wall::setPositionX5(int x)
{
    x5 = x;
}

int Wall::getPositionX1()
{
    return x1;
}

int Wall::getPositionX2()
{
    return x2;
}

int Wall::getPositionX3()
{
    return x3;
}

int Wall::getPositionX4()
{
    return x4;
}

int Wall::getPositionX5()
{
    return x5;
}

void Wall::setPositionY1(int y)
{
    y1 = y;
}

void Wall::setPositionY2(int y)
{
    y2 = y;
}

void Wall::setPositionY3(int y)
{
    y3 = y;
}

void Wall::setPositionY4(int y)
{
    y4 = y;
}

void Wall::setPositionY5(int y)
{
    y5 = y;
}

int Wall::getPositionY1()
{
    return y1;
}

int Wall::getPositionY2()
{
    return y2;
}

int Wall::getPositionY3()
{
    return y3;
}

int Wall::getPositionY4()
{
    return y4;
}

int Wall::getPositionY5()
{
    return y5;
}

static Wall vetorParedes[12];

void Pacman::setPosicaoX(float posicaoX)
{
    x = posicaoX;
}
bool wallColide2(int posicaoX, int posicaoY);

float Pacman::getPosicaoX()
{
    return x;
}

void Pacman::setPosicaoY(float posicaoY)
{
    y = posicaoY;
}

float Pacman::getPosicaoY()
{
    return y;
}

void Pacman::setSizePacman(float sizeP)
{
    sizePacman = sizeP;
}

float Pacman::getSizePacman()
{
    return sizePacman;
}

void Pacman::setSizeOlhoPacman(float sizeO)
{
    sizeOlhoPacman = sizeO;
}

float Pacman::getSizeOlhoPacman()
{
    return sizeOlhoPacman;
}

void Pacman::setAnguloTeta(float angulo)
{
    teta = angulo;
}

void Pacman::setCoordenadaX(int cx)
{
    coordX = cx;
}

int Pacman::getCoordenadaX()
{
    return coordX;
}

void Pacman::setCoordenadaY(int cy)
{
    coordY = cy;
}

int Pacman::getCoordenadaY()
{
    return coordY;
}

static QuadradosPontos vetorQuadrados[78];

void init(void);

void mapa();

void iniciarMapa();

void iniciarQuadrados();

void mapa2();

void level();

void One();

int viuDani();

void comeuComida();

void colocaImagem();

GLuint carregaTextura();

void stopGame();

void quadradosPontos();

void pacman();

void spinDisplay();

void display(void);

char *carrega_bmp();

bool colideVilao(int posicaoX, int posicaoY);

//bool wallColide2(int posicaoX, int posicaoY);

GLuint texid1;

GLuint texid2;

void colocaImagem2();

GLuint carregaTextura2();

char *carrega_bmp2();

void andarPacmanEVilao(int i);
static int indice_vilao = 0;

// GLuint tex

int w, h = 0;

bool wallColide(int posicaoX, int posicaoY);

void reshape(int x, int y);

void keyboard(unsigned char key, int x, int y);

void specialInputDoTeclado(int key, int x, int y);

int main(int argc, char **argv)
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1600, 800);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("PACMAN GAME");
    engine = createIrrKlangDevice();

    init();

    // engine->play2D("pacman.wav");
    engine->play3D("pacman.wav", vec3df(0, 0, 3), true, false, true);
    // viuDani();
    texid1 = carregaTextura();
    texid2 = carregaTextura2();
    iniciarMapa();
    iniciarQuadrados();
    // init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialInputDoTeclado);
    glutReshapeFunc(reshape);
    glutTimerFunc(delay, andarPacmanEVilao, 1);
    glutMainLoop();
    return 0;
}

void init(void)
{

    glOrtho(0, 1600, 0, 800, -1, 1);
    glShadeModel(GL_FLAT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void iniciarMapa()
{
    Wall wall1;
    wall1.setPositionX1(0);
    wall1.setPositionX2(1600);
    wall1.setPositionX3(1600);
    wall1.setPositionX4(0);
    wall1.setPositionX5(0);

    wall1.setPositionY1(0);
    wall1.setPositionY2(0);
    wall1.setPositionY3(20);
    wall1.setPositionY4(20);
    wall1.setPositionY5(0);

    Wall wall2;
    wall2.setPositionX1(0);
    wall2.setPositionX2(0);
    wall2.setPositionX3(20);
    wall2.setPositionX4(20);
    wall2.setPositionX5(0);

    wall2.setPositionY1(20);
    wall2.setPositionY2(800);
    wall2.setPositionY3(800);
    wall2.setPositionY4(0);
    wall2.setPositionY5(20);

    Wall wall3;
    wall3.setPositionX1(1580);
    wall3.setPositionX2(1600);
    wall3.setPositionX3(1600);
    wall3.setPositionX4(1580);
    wall3.setPositionX5(1580);

    wall3.setPositionY1(0);
    wall3.setPositionY2(0);
    wall3.setPositionY3(800);
    wall3.setPositionY4(800);
    wall3.setPositionY5(0);

    Wall wall4;
    wall4.setPositionX1(0);
    wall4.setPositionX2(1600);
    wall4.setPositionX3(1600);
    wall4.setPositionX4(0);
    wall4.setPositionX5(0);

    wall4.setPositionY1(780);
    wall4.setPositionY2(780);
    wall4.setPositionY3(800);
    wall4.setPositionY4(800);
    wall4.setPositionY5(780);

    Wall wall5;
    wall5.setPositionX1(380);
    wall5.setPositionX2(380);
    wall5.setPositionX3(400);
    wall5.setPositionX4(400);
    wall5.setPositionX5(380);

    wall5.setPositionY1(600);
    wall5.setPositionY2(800);
    wall5.setPositionY3(800);
    wall5.setPositionY4(600);
    wall5.setPositionY5(600);

    Wall wall6;
    wall6.setPositionX1(1200);
    wall6.setPositionX2(1200);
    wall6.setPositionX3(1220);
    wall6.setPositionX4(1220);
    wall6.setPositionX5(1200);

    wall6.setPositionY1(600);
    wall6.setPositionY2(800);
    wall6.setPositionY3(800);
    wall6.setPositionY4(600);
    wall6.setPositionY5(600);

    Wall wall7;
    wall7.setPositionX1(640);
    wall7.setPositionX2(640);
    wall7.setPositionX3(960);
    wall7.setPositionX4(960);
    wall7.setPositionX5(640);

    wall7.setPositionY1(530);
    wall7.setPositionY2(550);
    wall7.setPositionY3(550);
    wall7.setPositionY4(530);
    wall7.setPositionY5(530);

    Wall wall8;
    wall8.setPositionX1(640);
    wall8.setPositionX2(640);
    wall8.setPositionX3(960);
    wall8.setPositionX4(960);
    wall8.setPositionX5(640);

    wall8.setPositionY1(275);
    wall8.setPositionY2(275);
    wall8.setPositionY3(295);
    wall8.setPositionY4(295);
    wall8.setPositionY5(275);

    Wall wall9;
    wall9.setPositionX1(380);
    wall9.setPositionX2(380);
    wall9.setPositionX3(400);
    wall9.setPositionX4(400);
    wall9.setPositionX5(380);

    wall9.setPositionY1(0);
    wall9.setPositionY2(210);
    wall9.setPositionY3(210);
    wall9.setPositionY4(0);
    wall9.setPositionY5(0);

    Wall wall10;
    wall10.setPositionX1(1200);
    wall10.setPositionX2(1200);
    wall10.setPositionX3(1220);
    wall10.setPositionX4(1220);
    wall10.setPositionX5(1200);

    wall10.setPositionY1(0);
    wall10.setPositionY2(210);
    wall10.setPositionY3(210);
    wall10.setPositionY4(0);
    wall10.setPositionY5(0);

    Wall wall11;
    wall11.setPositionX1(220);
    wall11.setPositionX2(240);
    wall11.setPositionX3(240);
    wall11.setPositionX4(220);
    wall11.setPositionX5(220);

    wall11.setPositionY1(320);
    wall11.setPositionY2(320);
    wall11.setPositionY3(560);
    wall11.setPositionY4(560);
    wall11.setPositionY5(320);

    Wall wall12;
    wall12.setPositionX1(1380);
    wall12.setPositionX2(1400);
    wall12.setPositionX3(1400);
    wall12.setPositionX4(1380);
    wall12.setPositionX5(1380);

    wall12.setPositionY1(320);
    wall12.setPositionY2(320);
    wall12.setPositionY3(560);
    wall12.setPositionY4(560);
    wall12.setPositionY5(320);

    vetorParedes[0] = wall1;
    vetorParedes[1] = wall2;
    vetorParedes[2] = wall3;
    vetorParedes[3] = wall4;
    vetorParedes[4] = wall5; //essa aqui
    vetorParedes[5] = wall6; //essa aqui
    vetorParedes[6] = wall7; //essa aqui
    vetorParedes[7] = wall8;
    vetorParedes[8] = wall9;
    vetorParedes[9] = wall10;
    vetorParedes[10] = wall11;
    vetorParedes[11] = wall12;
}

void iniciarQuadrados()
{

    QuadradosPontos quad1;
    quad1.setPositionX1(100);
    quad1.setPositionX2(100);
    quad1.setPositionX3(120);
    quad1.setPositionX4(120);
    quad1.setPositionX5(100);

    quad1.setPositionY1(600);
    quad1.setPositionY2(580);
    quad1.setPositionY3(580);
    quad1.setPositionY4(600);
    quad1.setPositionY5(600);

    QuadradosPontos quad2;
    quad2.setPositionX1(100);
    quad2.setPositionX2(100);
    quad2.setPositionX3(120);
    quad2.setPositionX4(120);
    quad2.setPositionX5(100);

    quad2.setPositionY1(500);
    quad2.setPositionY2(480);
    quad2.setPositionY3(480);
    quad2.setPositionY4(500);
    quad2.setPositionY5(500);

    QuadradosPontos quad3;
    quad3.setPositionX1(100);
    quad3.setPositionX2(100);
    quad3.setPositionX3(120);
    quad3.setPositionX4(120);
    quad3.setPositionX5(100);

    quad3.setPositionY1(400);
    quad3.setPositionY2(380);
    quad3.setPositionY3(380);
    quad3.setPositionY4(400);
    quad3.setPositionY5(400);

    QuadradosPontos quad4;
    quad4.setPositionX1(100);
    quad4.setPositionX2(100);
    quad4.setPositionX3(120);
    quad4.setPositionX4(120);
    quad4.setPositionX5(100);

    quad4.setPositionY1(300);
    quad4.setPositionY2(280);
    quad4.setPositionY3(280);
    quad4.setPositionY4(300);
    quad4.setPositionY5(300);

    QuadradosPontos quad5;
    quad5.setPositionX1(100);
    quad5.setPositionX2(100);
    quad5.setPositionX3(120);
    quad5.setPositionX4(120);
    quad5.setPositionX5(100);

    quad5.setPositionY1(200);
    quad5.setPositionY2(180);
    quad5.setPositionY3(180);
    quad5.setPositionY4(200);
    quad5.setPositionY5(200);

    QuadradosPontos quad6;
    quad6.setPositionX1(100);
    quad6.setPositionX2(100);
    quad6.setPositionX3(120);
    quad6.setPositionX4(120);
    quad6.setPositionX5(100);

    quad6.setPositionY1(100);
    quad6.setPositionY2(80);
    quad6.setPositionY3(80);
    quad6.setPositionY4(100);
    quad6.setPositionY5(100);

    QuadradosPontos quad7;
    quad7.setPositionX1(200);
    quad7.setPositionX2(200);
    quad7.setPositionX3(220);
    quad7.setPositionX4(220);
    quad7.setPositionX5(200);

    quad7.setPositionY1(100);
    quad7.setPositionY2(80);
    quad7.setPositionY3(80);
    quad7.setPositionY4(100);
    quad7.setPositionY5(100);

    QuadradosPontos quad8;
    quad8.setPositionX1(300);
    quad8.setPositionX2(300);
    quad8.setPositionX3(320);
    quad8.setPositionX4(320);
    quad8.setPositionX5(300);

    quad8.setPositionY1(100);
    quad8.setPositionY2(80);
    quad8.setPositionY3(80);
    quad8.setPositionY4(100);
    quad8.setPositionY5(100);

    QuadradosPontos quad9;
    quad9.setPositionX1(300);
    quad9.setPositionX2(300);
    quad9.setPositionX3(320);
    quad9.setPositionX4(320);
    quad9.setPositionX5(300);

    quad9.setPositionY1(200);
    quad9.setPositionY2(180);
    quad9.setPositionY3(180);
    quad9.setPositionY4(200);
    quad9.setPositionY5(200);

    QuadradosPontos quad10;
    quad10.setPositionX1(300);
    quad10.setPositionX2(300);
    quad10.setPositionX3(320);
    quad10.setPositionX4(320);
    quad10.setPositionX5(300);

    quad10.setPositionY1(300);
    quad10.setPositionY2(280);
    quad10.setPositionY3(280);
    quad10.setPositionY4(300);
    quad10.setPositionY5(300);

    QuadradosPontos quad11;
    quad11.setPositionX1(300);
    quad11.setPositionX2(300);
    quad11.setPositionX3(320);
    quad11.setPositionX4(320);
    quad11.setPositionX5(300);

    quad11.setPositionY1(400);
    quad11.setPositionY2(380);
    quad11.setPositionY3(380);
    quad11.setPositionY4(400);
    quad11.setPositionY5(400);

    QuadradosPontos quad12;
    quad12.setPositionX1(300);
    quad12.setPositionX2(300);
    quad12.setPositionX3(320);
    quad12.setPositionX4(320);
    quad12.setPositionX5(300);

    quad12.setPositionY1(500);
    quad12.setPositionY2(480);
    quad12.setPositionY3(480);
    quad12.setPositionY4(500);
    quad12.setPositionY5(500);

    QuadradosPontos quad13;
    quad13.setPositionX1(300);
    quad13.setPositionX2(300);
    quad13.setPositionX3(320);
    quad13.setPositionX4(320);
    quad13.setPositionX5(300);

    quad13.setPositionY1(600);
    quad13.setPositionY2(580);
    quad13.setPositionY3(580);
    quad13.setPositionY4(600);
    quad13.setPositionY5(600);

    QuadradosPontos quad14;
    quad14.setPositionX1(200);
    quad14.setPositionX2(200);
    quad14.setPositionX3(220);
    quad14.setPositionX4(220);
    quad14.setPositionX5(200);

    quad14.setPositionY1(200);
    quad14.setPositionY2(180);
    quad14.setPositionY3(180);
    quad14.setPositionY4(200);
    quad14.setPositionY5(200);

    QuadradosPontos quad15;
    quad15.setPositionX1(460);
    quad15.setPositionX2(480);
    quad15.setPositionX3(480);
    quad15.setPositionX4(460);
    quad15.setPositionX5(460);

    quad15.setPositionY1(690);
    quad15.setPositionY2(690);
    quad15.setPositionY3(710);
    quad15.setPositionY4(710);
    quad15.setPositionY5(690);

    QuadradosPontos quad16;
    quad16.setPositionX1(560);
    quad16.setPositionX2(580);
    quad16.setPositionX3(580);
    quad16.setPositionX4(560);
    quad16.setPositionX5(560);

    quad16.setPositionY1(690);
    quad16.setPositionY2(690);
    quad16.setPositionY3(710);
    quad16.setPositionY4(710);
    quad16.setPositionY5(690);

    QuadradosPontos quad17;
    quad17.setPositionX1(660);
    quad17.setPositionX2(680);
    quad17.setPositionX3(680);
    quad17.setPositionX4(660);
    quad17.setPositionX5(660);

    quad17.setPositionY1(690);
    quad17.setPositionY2(690);
    quad17.setPositionY3(710);
    quad17.setPositionY4(710);
    quad17.setPositionY5(690);

    QuadradosPontos quad18;
    quad18.setPositionX1(760);
    quad18.setPositionX2(780);
    quad18.setPositionX3(780);
    quad18.setPositionX4(760);
    quad18.setPositionX5(760);

    quad18.setPositionY1(690);
    quad18.setPositionY2(690);
    quad18.setPositionY3(710);
    quad18.setPositionY4(710);
    quad18.setPositionY5(690);

    QuadradosPontos quad19;
    quad19.setPositionX1(860);
    quad19.setPositionX2(880);
    quad19.setPositionX3(880);
    quad19.setPositionX4(860);
    quad19.setPositionX5(860);

    quad19.setPositionY1(690);
    quad19.setPositionY2(690);
    quad19.setPositionY3(710);
    quad19.setPositionY4(710);
    quad19.setPositionY5(690);

    QuadradosPontos quad20;
    quad20.setPositionX1(960);
    quad20.setPositionX2(980);
    quad20.setPositionX3(980);
    quad20.setPositionX4(960);
    quad20.setPositionX5(960);

    quad20.setPositionY1(690);
    quad20.setPositionY2(690);
    quad20.setPositionY3(710);
    quad20.setPositionY4(710);
    quad20.setPositionY5(690);

    QuadradosPontos quad21;
    quad21.setPositionX1(1060);
    quad21.setPositionX2(1080);
    quad21.setPositionX3(1080);
    quad21.setPositionX4(1060);
    quad21.setPositionX5(1060);

    quad21.setPositionY1(690);
    quad21.setPositionY2(690);
    quad21.setPositionY3(710);
    quad21.setPositionY4(710);
    quad21.setPositionY5(690);

    QuadradosPontos quad22;
    quad22.setPositionX1(460);
    quad22.setPositionX2(480);
    quad22.setPositionX3(480);
    quad22.setPositionX4(460);
    quad22.setPositionX5(460);

    quad22.setPositionY1(590);
    quad22.setPositionY2(590);
    quad22.setPositionY3(610);
    quad22.setPositionY4(610);
    quad22.setPositionY5(590);

    QuadradosPontos quad23;
    quad23.setPositionX1(560);
    quad23.setPositionX2(580);
    quad23.setPositionX3(580);
    quad23.setPositionX4(560);
    quad23.setPositionX5(560);

    quad23.setPositionY1(590);
    quad23.setPositionY2(590);
    quad23.setPositionY3(610);
    quad23.setPositionY4(610);
    quad23.setPositionY5(590);

    QuadradosPontos quad24;
    quad24.setPositionX1(660);
    quad24.setPositionX2(680);
    quad24.setPositionX3(680);
    quad24.setPositionX4(660);
    quad24.setPositionX5(660);

    quad24.setPositionY1(590);
    quad24.setPositionY2(590);
    quad24.setPositionY3(610);
    quad24.setPositionY4(610);
    quad24.setPositionY5(590);

    QuadradosPontos quad25;
    quad25.setPositionX1(760);
    quad25.setPositionX2(780);
    quad25.setPositionX3(780);
    quad25.setPositionX4(760);
    quad25.setPositionX5(760);

    quad25.setPositionY1(590);
    quad25.setPositionY2(590);
    quad25.setPositionY3(610);
    quad25.setPositionY4(610);
    quad25.setPositionY5(590);

    QuadradosPontos quad26;
    quad26.setPositionX1(860);
    quad26.setPositionX2(880);
    quad26.setPositionX3(880);
    quad26.setPositionX4(860);
    quad26.setPositionX5(860);

    quad26.setPositionY1(590);
    quad26.setPositionY2(590);
    quad26.setPositionY3(610);
    quad26.setPositionY4(610);
    quad26.setPositionY5(590);

    QuadradosPontos quad27;
    quad27.setPositionX1(960);
    quad27.setPositionX2(980);
    quad27.setPositionX3(980);
    quad27.setPositionX4(960);
    quad27.setPositionX5(960);

    quad27.setPositionY1(590);
    quad27.setPositionY2(590);
    quad27.setPositionY3(610);
    quad27.setPositionY4(610);
    quad27.setPositionY5(590);

    QuadradosPontos quad28;
    quad28.setPositionX1(1060);
    quad28.setPositionX2(1080);
    quad28.setPositionX3(1080);
    quad28.setPositionX4(1060);
    quad28.setPositionX5(1060);

    quad28.setPositionY1(590);
    quad28.setPositionY2(590);
    quad28.setPositionY3(610);
    quad28.setPositionY4(610);
    quad28.setPositionY5(590);

    QuadradosPontos quad29;
    quad29.setPositionX1(460);
    quad29.setPositionX2(480);
    quad29.setPositionX3(480);
    quad29.setPositionX4(460);
    quad29.setPositionX5(460);

    quad29.setPositionY1(490);
    quad29.setPositionY2(490);
    quad29.setPositionY3(510);
    quad29.setPositionY4(510);
    quad29.setPositionY5(490);

    QuadradosPontos quad30;
    quad30.setPositionX1(460);
    quad30.setPositionX2(480);
    quad30.setPositionX3(480);
    quad30.setPositionX4(460);
    quad30.setPositionX5(460);

    quad30.setPositionY1(390);
    quad30.setPositionY2(390);
    quad30.setPositionY3(410);
    quad30.setPositionY4(410);
    quad30.setPositionY5(390);

    QuadradosPontos quad31;
    quad31.setPositionX1(460);
    quad31.setPositionX2(480);
    quad31.setPositionX3(480);
    quad31.setPositionX4(460);
    quad31.setPositionX5(460);

    quad31.setPositionY1(290);
    quad31.setPositionY2(290);
    quad31.setPositionY3(310);
    quad31.setPositionY4(310);
    quad31.setPositionY5(290);

    QuadradosPontos quad32;
    quad32.setPositionX1(460);
    quad32.setPositionX2(480);
    quad32.setPositionX3(480);
    quad32.setPositionX4(460);
    quad32.setPositionX5(460);

    quad32.setPositionY1(190);
    quad32.setPositionY2(190);
    quad32.setPositionY3(210);
    quad32.setPositionY4(210);
    quad32.setPositionY5(190);

    QuadradosPontos quad33;
    quad33.setPositionX1(460);
    quad33.setPositionX2(480);
    quad33.setPositionX3(480);
    quad33.setPositionX4(460);
    quad33.setPositionX5(460);

    quad33.setPositionY1(90);
    quad33.setPositionY2(90);
    quad33.setPositionY3(110);
    quad33.setPositionY4(110);
    quad33.setPositionY5(90);

    QuadradosPontos quad34;
    quad34.setPositionX1(560);
    quad34.setPositionX2(580);
    quad34.setPositionX3(580);
    quad34.setPositionX4(560);
    quad34.setPositionX5(560);

    quad34.setPositionY1(490);
    quad34.setPositionY2(490);
    quad34.setPositionY3(510);
    quad34.setPositionY4(510);
    quad34.setPositionY5(490);

    QuadradosPontos quad35;
    quad35.setPositionX1(560);
    quad35.setPositionX2(580);
    quad35.setPositionX3(580);
    quad35.setPositionX4(560);
    quad35.setPositionX5(560);

    quad35.setPositionY1(390);
    quad35.setPositionY2(390);
    quad35.setPositionY3(410);
    quad35.setPositionY4(410);
    quad35.setPositionY5(390);

    QuadradosPontos quad36;
    quad36.setPositionX1(560);
    quad36.setPositionX2(580);
    quad36.setPositionX3(580);
    quad36.setPositionX4(560);
    quad36.setPositionX5(560);

    quad36.setPositionY1(290);
    quad36.setPositionY2(290);
    quad36.setPositionY3(310);
    quad36.setPositionY4(310);
    quad36.setPositionY5(290);

    QuadradosPontos quad37;
    quad37.setPositionX1(560);
    quad37.setPositionX2(580);
    quad37.setPositionX3(580);
    quad37.setPositionX4(560);
    quad37.setPositionX5(560);

    quad37.setPositionY1(190);
    quad37.setPositionY2(190);
    quad37.setPositionY3(210);
    quad37.setPositionY4(210);
    quad37.setPositionY5(190);

    QuadradosPontos quad38;
    quad38.setPositionX1(560);
    quad38.setPositionX2(580);
    quad38.setPositionX3(580);
    quad38.setPositionX4(560);
    quad38.setPositionX5(560);

    quad38.setPositionY1(90);
    quad38.setPositionY2(90);
    quad38.setPositionY3(110);
    quad38.setPositionY4(110);
    quad38.setPositionY5(90);

    QuadradosPontos quad39;
    quad39.setPositionX1(560);
    quad39.setPositionX2(580);
    quad39.setPositionX3(580);
    quad39.setPositionX4(560);
    quad39.setPositionX5(560);

    quad39.setPositionY1(90);
    quad39.setPositionY2(90);
    quad39.setPositionY3(110);
    quad39.setPositionY4(110);
    quad39.setPositionY5(90);

    QuadradosPontos quad40;
    quad40.setPositionX1(660);
    quad40.setPositionX2(680);
    quad40.setPositionX3(680);
    quad40.setPositionX4(660);
    quad40.setPositionX5(660);

    quad40.setPositionY1(190);
    quad40.setPositionY2(190);
    quad40.setPositionY3(210);
    quad40.setPositionY4(210);
    quad40.setPositionY5(190);

    QuadradosPontos quad41;
    quad41.setPositionX1(760);
    quad41.setPositionX2(780);
    quad41.setPositionX3(780);
    quad41.setPositionX4(760);
    quad41.setPositionX5(760);

    quad41.setPositionY1(190);
    quad41.setPositionY2(190);
    quad41.setPositionY3(210);
    quad41.setPositionY4(210);
    quad41.setPositionY5(190);

    QuadradosPontos quad42;
    quad42.setPositionX1(860);
    quad42.setPositionX2(880);
    quad42.setPositionX3(880);
    quad42.setPositionX4(860);
    quad42.setPositionX5(860);

    quad42.setPositionY1(190);
    quad42.setPositionY2(190);
    quad42.setPositionY3(210);
    quad42.setPositionY4(210);
    quad42.setPositionY5(190);

    QuadradosPontos quad43;
    quad43.setPositionX1(960);
    quad43.setPositionX2(980);
    quad43.setPositionX3(980);
    quad43.setPositionX4(960);
    quad43.setPositionX5(960);

    quad43.setPositionY1(190);
    quad43.setPositionY2(190);
    quad43.setPositionY3(210);
    quad43.setPositionY4(210);
    quad43.setPositionY5(190);

    QuadradosPontos quad44;
    quad44.setPositionX1(1060);
    quad44.setPositionX2(1080);
    quad44.setPositionX3(1080);
    quad44.setPositionX4(1060);
    quad44.setPositionX5(1060);

    quad44.setPositionY1(190);
    quad44.setPositionY2(190);
    quad44.setPositionY3(210);
    quad44.setPositionY4(210);
    quad44.setPositionY5(190);

    QuadradosPontos quad45;
    quad45.setPositionX1(660);
    quad45.setPositionX2(680);
    quad45.setPositionX3(680);
    quad45.setPositionX4(660);
    quad45.setPositionX5(660);

    quad45.setPositionY1(90);
    quad45.setPositionY2(90);
    quad45.setPositionY3(110);
    quad45.setPositionY4(110);
    quad45.setPositionY5(90);

    QuadradosPontos quad46;
    quad46.setPositionX1(760);
    quad46.setPositionX2(780);
    quad46.setPositionX3(780);
    quad46.setPositionX4(760);
    quad46.setPositionX5(760);

    quad46.setPositionY1(90);
    quad46.setPositionY2(90);
    quad46.setPositionY3(110);
    quad46.setPositionY4(110);
    quad46.setPositionY5(90);

    QuadradosPontos quad47;
    quad47.setPositionX1(860);
    quad47.setPositionX2(880);
    quad47.setPositionX3(880);
    quad47.setPositionX4(860);
    quad47.setPositionX5(860);

    quad47.setPositionY1(90);
    quad47.setPositionY2(90);
    quad47.setPositionY3(110);
    quad47.setPositionY4(110);
    quad47.setPositionY5(90);

    QuadradosPontos quad48;
    quad48.setPositionX1(960);
    quad48.setPositionX2(980);
    quad48.setPositionX3(980);
    quad48.setPositionX4(960);
    quad48.setPositionX5(960);

    quad48.setPositionY1(90);
    quad48.setPositionY2(90);
    quad48.setPositionY3(110);
    quad48.setPositionY4(110);
    quad48.setPositionY5(90);

    QuadradosPontos quad49;
    quad49.setPositionX1(1060);
    quad49.setPositionX2(1080);
    quad49.setPositionX3(1080);
    quad49.setPositionX4(1060);
    quad49.setPositionX5(1060);

    quad49.setPositionY1(90);
    quad49.setPositionY2(90);
    quad49.setPositionY3(110);
    quad49.setPositionY4(110);
    quad49.setPositionY5(90);

    QuadradosPontos quad50;
    quad50.setPositionX1(1060);
    quad50.setPositionX2(1080);
    quad50.setPositionX3(1080);
    quad50.setPositionX4(1060);
    quad50.setPositionX5(1060);

    quad50.setPositionY1(290);
    quad50.setPositionY2(290);
    quad50.setPositionY3(310);
    quad50.setPositionY4(310);
    quad50.setPositionY5(290);

    QuadradosPontos quad51;
    quad51.setPositionX1(1060);
    quad51.setPositionX2(1080);
    quad51.setPositionX3(1080);
    quad51.setPositionX4(1060);
    quad51.setPositionX5(1060);

    quad51.setPositionY1(390);
    quad51.setPositionY2(390);
    quad51.setPositionY3(410);
    quad51.setPositionY4(410);
    quad51.setPositionY5(390);

    QuadradosPontos quad52;
    quad52.setPositionX1(1060);
    quad52.setPositionX2(1080);
    quad52.setPositionX3(1080);
    quad52.setPositionX4(1060);
    quad52.setPositionX5(1060);

    quad52.setPositionY1(490);
    quad52.setPositionY2(490);
    quad52.setPositionY3(510);
    quad52.setPositionY4(510);
    quad52.setPositionY5(490);

    QuadradosPontos quad53;
    quad53.setPositionX1(1060);
    quad53.setPositionX2(1080);
    quad53.setPositionX3(1080);
    quad53.setPositionX4(1060);
    quad53.setPositionX5(1060);

    quad53.setPositionY1(590);
    quad53.setPositionY2(590);
    quad53.setPositionY3(610);
    quad53.setPositionY4(610);
    quad53.setPositionY5(590);

    QuadradosPontos quad54;
    quad54.setPositionX1(960);
    quad54.setPositionX2(980);
    quad54.setPositionX3(980);
    quad54.setPositionX4(960);
    quad54.setPositionX5(960);

    quad54.setPositionY1(390);
    quad54.setPositionY2(390);
    quad54.setPositionY3(410);
    quad54.setPositionY4(410);
    quad54.setPositionY5(390);

    QuadradosPontos quad55;
    quad55.setPositionX1(860);
    quad55.setPositionX2(880);
    quad55.setPositionX3(880);
    quad55.setPositionX4(860);
    quad55.setPositionX5(860);

    quad55.setPositionY1(390);
    quad55.setPositionY2(390);
    quad55.setPositionY3(410);
    quad55.setPositionY4(410);
    quad55.setPositionY5(390);

    QuadradosPontos quad56;
    quad56.setPositionX1(760);
    quad56.setPositionX2(780);
    quad56.setPositionX3(780);
    quad56.setPositionX4(760);
    quad56.setPositionX5(760);

    quad56.setPositionY1(390);
    quad56.setPositionY2(390);
    quad56.setPositionY3(410);
    quad56.setPositionY4(410);
    quad56.setPositionY5(390);

    QuadradosPontos quad57;
    quad57.setPositionX1(660);
    quad57.setPositionX2(680);
    quad57.setPositionX3(680);
    quad57.setPositionX4(660);
    quad57.setPositionX5(660);

    quad57.setPositionY1(390);
    quad57.setPositionY2(390);
    quad57.setPositionY3(410);
    quad57.setPositionY4(410);
    quad57.setPositionY5(390);

    QuadradosPontos quad58;
    quad58.setPositionX1(1160);
    quad58.setPositionX2(1180);
    quad58.setPositionX3(1180);
    quad58.setPositionX4(1160);
    quad58.setPositionX5(1160);

    quad58.setPositionY1(390);
    quad58.setPositionY2(390);
    quad58.setPositionY3(410);
    quad58.setPositionY4(410);
    quad58.setPositionY5(390);

    QuadradosPontos quad59;
    quad59.setPositionX1(1160);
    quad59.setPositionX2(1180);
    quad59.setPositionX3(1180);
    quad59.setPositionX4(1160);
    quad59.setPositionX5(1160);

    quad59.setPositionY1(490);
    quad59.setPositionY2(490);
    quad59.setPositionY3(510);
    quad59.setPositionY4(510);
    quad59.setPositionY5(490);

    QuadradosPontos quad60;
    quad60.setPositionX1(1160);
    quad60.setPositionX2(1180);
    quad60.setPositionX3(1180);
    quad60.setPositionX4(1160);
    quad60.setPositionX5(1160);

    quad60.setPositionY1(390);
    quad60.setPositionY2(390);
    quad60.setPositionY3(410);
    quad60.setPositionY4(410);
    quad60.setPositionY5(390);

    QuadradosPontos quad61;
    quad61.setPositionX1(1260);
    quad61.setPositionX2(1280);
    quad61.setPositionX3(1280);
    quad61.setPositionX4(1260);
    quad61.setPositionX5(1260);

    quad61.setPositionY1(590);
    quad61.setPositionY2(590);
    quad61.setPositionY3(610);
    quad61.setPositionY4(610);
    quad61.setPositionY5(590);

    QuadradosPontos quad62;
    quad62.setPositionX1(1260);
    quad62.setPositionX2(1280);
    quad62.setPositionX3(1280);
    quad62.setPositionX4(1260);
    quad62.setPositionX5(1260);

    quad62.setPositionY1(490);
    quad62.setPositionY2(490);
    quad62.setPositionY3(510);
    quad62.setPositionY4(510);
    quad62.setPositionY5(490);

    QuadradosPontos quad63;
    quad63.setPositionX1(1260);
    quad63.setPositionX2(1280);
    quad63.setPositionX3(1280);
    quad63.setPositionX4(1260);
    quad63.setPositionX5(1260);

    quad63.setPositionY1(290);
    quad63.setPositionY2(290);
    quad63.setPositionY3(310);
    quad63.setPositionY4(310);
    quad63.setPositionY5(290);

    QuadradosPontos quad64;
    quad64.setPositionX1(1260);
    quad64.setPositionX2(1280);
    quad64.setPositionX3(1280);
    quad64.setPositionX4(1260);
    quad64.setPositionX5(1260);

    quad64.setPositionY1(190);
    quad64.setPositionY2(190);
    quad64.setPositionY3(210);
    quad64.setPositionY4(210);
    quad64.setPositionY5(190);

    QuadradosPontos quad65;
    quad65.setPositionX1(1260);
    quad65.setPositionX2(1280);
    quad65.setPositionX3(1280);
    quad65.setPositionX4(1260);
    quad65.setPositionX5(1260);

    quad65.setPositionY1(90);
    quad65.setPositionY2(90);
    quad65.setPositionY3(110);
    quad65.setPositionY4(110);
    quad65.setPositionY5(90);

    QuadradosPontos quad66;
    quad66.setPositionX1(1360);
    quad66.setPositionX2(1380);
    quad66.setPositionX3(1380);
    quad66.setPositionX4(1360);
    quad66.setPositionX5(1360);

    quad66.setPositionY1(190);
    quad66.setPositionY2(190);
    quad66.setPositionY3(210);
    quad66.setPositionY4(210);
    quad66.setPositionY5(190);

    QuadradosPontos quad67;
    quad67.setPositionX1(1360);
    quad67.setPositionX2(1380);
    quad67.setPositionX3(1380);
    quad67.setPositionX4(1360);
    quad67.setPositionX5(1360);

    quad67.setPositionY1(90);
    quad67.setPositionY2(90);
    quad67.setPositionY3(110);
    quad67.setPositionY4(110);
    quad67.setPositionY5(90);

    QuadradosPontos quad68;
    quad68.setPositionX1(1460);
    quad68.setPositionX2(1480);
    quad68.setPositionX3(1480);
    quad68.setPositionX4(1460);
    quad68.setPositionX5(1460);

    quad68.setPositionY2(190);
    quad68.setPositionY3(210);
    quad68.setPositionY4(210);
    quad68.setPositionY1(190);
    quad68.setPositionY5(190);

    QuadradosPontos quad69;
    quad69.setPositionX1(1460);
    quad69.setPositionX2(1480);
    quad69.setPositionX3(1480);
    quad69.setPositionX4(1460);
    quad69.setPositionX5(1460);

    quad69.setPositionY1(90);
    quad69.setPositionY2(90);
    quad69.setPositionY3(110);
    quad69.setPositionY4(110);
    quad69.setPositionY5(90);

    QuadradosPontos quad70;
    quad70.setPositionX1(1460);
    quad70.setPositionX2(1480);
    quad70.setPositionX3(1480);
    quad70.setPositionX4(1460);
    quad70.setPositionX5(1460);

    quad70.setPositionY1(290);
    quad70.setPositionY2(290);
    quad70.setPositionY3(310);
    quad70.setPositionY4(310);
    quad70.setPositionY5(290);

    QuadradosPontos quad71;
    quad71.setPositionX1(1460);
    quad71.setPositionX2(1480);
    quad71.setPositionX3(1480);
    quad71.setPositionX4(1460);
    quad71.setPositionX5(1460);

    quad71.setPositionY1(390);
    quad71.setPositionY2(390);
    quad71.setPositionY3(410);
    quad71.setPositionY4(410);
    quad71.setPositionY5(390);

    QuadradosPontos quad72;
    quad72.setPositionX1(1460);
    quad72.setPositionX2(1480);
    quad72.setPositionX3(1480);
    quad72.setPositionX4(1460);
    quad72.setPositionX5(1460);

    quad72.setPositionY1(490);
    quad72.setPositionY2(490);
    quad72.setPositionY3(510);
    quad72.setPositionY4(510);
    quad72.setPositionY5(490);

    QuadradosPontos quad73;
    quad73.setPositionX1(1460);
    quad73.setPositionX2(1480);
    quad73.setPositionX3(1480);
    quad73.setPositionX4(1460);
    quad73.setPositionX5(1460);

    quad73.setPositionY1(590);
    quad73.setPositionY2(590);
    quad73.setPositionY3(610);
    quad73.setPositionY4(610);
    quad73.setPositionY5(590);

    QuadradosPontos quad74;
    quad74.setPositionX1(1460);
    quad74.setPositionX2(1480);
    quad74.setPositionX3(1480);
    quad74.setPositionX4(1460);
    quad74.setPositionX5(1460);

    quad74.setPositionY1(590);
    quad74.setPositionY2(590);
    quad74.setPositionY3(610);
    quad74.setPositionY4(610);
    quad74.setPositionY5(590);

    QuadradosPontos quad75;
    quad75.setPositionX1(1360);
    quad75.setPositionX2(1380);
    quad75.setPositionX3(1380);
    quad75.setPositionX4(1360);
    quad75.setPositionX5(1360);

    quad75.setPositionY1(590);
    quad75.setPositionY2(590);
    quad75.setPositionY3(610);
    quad75.setPositionY4(610);
    quad75.setPositionY5(590);

    QuadradosPontos quad76;
    quad76.setPositionX1(1360);
    quad76.setPositionX2(1380);
    quad76.setPositionX3(1380);
    quad76.setPositionX4(1360);
    quad76.setPositionX5(1360);

    quad76.setPositionY1(690);
    quad76.setPositionY2(690);
    quad76.setPositionY3(710);
    quad76.setPositionY4(710);
    quad76.setPositionY5(690);

    QuadradosPontos quad77;
    quad77.setPositionX1(1260);
    quad77.setPositionX2(1280);
    quad77.setPositionX3(1280);
    quad77.setPositionX4(1260);
    quad77.setPositionX5(1260);

    quad77.setPositionY1(590);
    quad77.setPositionY2(590);
    quad77.setPositionY3(610);
    quad77.setPositionY4(610);
    quad77.setPositionY5(590);

    QuadradosPontos quad78;
    quad78.setPositionX1(1260);
    quad78.setPositionX2(1280);
    quad78.setPositionX3(1280);
    quad78.setPositionX4(1260);
    quad78.setPositionX5(1260);

    quad78.setPositionY1(690);
    quad78.setPositionY2(690);
    quad78.setPositionY3(710);
    quad78.setPositionY4(710);
    quad78.setPositionY5(690);

    // vetorQuadrados[0]   =   quad1;
    vetorQuadrados[1] = quad2;
    vetorQuadrados[2] = quad3;
    vetorQuadrados[3] = quad4;
    vetorQuadrados[4] = quad5;
    vetorQuadrados[5] = quad6;
    vetorQuadrados[6] = quad7;
    vetorQuadrados[7] = quad8;
    vetorQuadrados[8] = quad9;
    vetorQuadrados[9] = quad10;
    vetorQuadrados[10] = quad11;
    vetorQuadrados[11] = quad12;
    vetorQuadrados[12] = quad13;
    vetorQuadrados[13] = quad14;
    vetorQuadrados[14] = quad15;
    vetorQuadrados[15] = quad16;
    vetorQuadrados[16] = quad17;
    vetorQuadrados[17] = quad18;
    vetorQuadrados[18] = quad19;
    vetorQuadrados[19] = quad20;
    vetorQuadrados[20] = quad21;
    vetorQuadrados[21] = quad22;
    vetorQuadrados[22] = quad23;
    vetorQuadrados[23] = quad24;
    vetorQuadrados[24] = quad25;
    vetorQuadrados[25] = quad26;
    vetorQuadrados[26] = quad27;
    vetorQuadrados[27] = quad28;
    vetorQuadrados[28] = quad29;
    vetorQuadrados[29] = quad30;
    vetorQuadrados[30] = quad31;
    vetorQuadrados[31] = quad32;
    vetorQuadrados[32] = quad33;
    vetorQuadrados[33] = quad34;
    vetorQuadrados[34] = quad35;
    vetorQuadrados[35] = quad36;
    vetorQuadrados[36] = quad37;
    vetorQuadrados[37] = quad38;
    vetorQuadrados[38] = quad39;
    vetorQuadrados[39] = quad40;
    vetorQuadrados[40] = quad41;
    vetorQuadrados[41] = quad42;
    vetorQuadrados[42] = quad43;
    vetorQuadrados[43] = quad44;
    vetorQuadrados[44] = quad45;
    vetorQuadrados[45] = quad46;
    vetorQuadrados[46] = quad47;
    vetorQuadrados[47] = quad48;
    vetorQuadrados[48] = quad49;
    vetorQuadrados[49] = quad50;
    vetorQuadrados[50] = quad51;
    vetorQuadrados[51] = quad52;
    vetorQuadrados[52] = quad53;
    vetorQuadrados[53] = quad54;
    vetorQuadrados[54] = quad55;
    vetorQuadrados[55] = quad56;
    vetorQuadrados[56] = quad57;
    vetorQuadrados[57] = quad58;
    vetorQuadrados[58] = quad59;
    vetorQuadrados[59] = quad60;
    vetorQuadrados[60] = quad61;
    vetorQuadrados[61] = quad62;
    vetorQuadrados[62] = quad63;
    vetorQuadrados[63] = quad64;
    vetorQuadrados[64] = quad65;
    vetorQuadrados[65] = quad66;
    vetorQuadrados[66] = quad67;
    vetorQuadrados[67] = quad68;
    vetorQuadrados[68] = quad69;
    vetorQuadrados[69] = quad70;
    vetorQuadrados[70] = quad71;
    vetorQuadrados[71] = quad72;
    vetorQuadrados[72] = quad73;
    vetorQuadrados[73] = quad74;
    vetorQuadrados[74] = quad75;
    vetorQuadrados[75] = quad76;
    vetorQuadrados[76] = quad77;
    vetorQuadrados[77] = quad78;

    for (int i = 0; i < 78; i++)
    {
        vetorQuadrados[i].setStatus(true);
    }
}

void mapa()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glColor4f(0.0, 0.0, 1.0, 0.5);

    for (int i = 0; i < 12; i++)
    {
        glRecti(vetorParedes[i].getPositionX1(), vetorParedes[i].getPositionY1(), vetorParedes[i].getPositionX3(), vetorParedes[i].getPositionY3());

        glEnd();
        glFlush();
    }

    //glRecti(100, 200, 30, 40);
}

void quadradosPontos()
{

    glColor4f(1.0, 1.0, 1.0, 0.5);

    for (int i = 0; i < 78; i++)
    {

        if (vetorQuadrados[i].getStatus())
        {
            glBegin(GL_POLYGON);

            glVertex2i(vetorQuadrados[i].getPositionX1(), vetorQuadrados[i].getPositionY1());
            glVertex2i(vetorQuadrados[i].getPositionX2(), vetorQuadrados[i].getPositionY2());
            glVertex2i(vetorQuadrados[i].getPositionX3(), vetorQuadrados[i].getPositionY3());
            glVertex2i(vetorQuadrados[i].getPositionX4(), vetorQuadrados[i].getPositionY4());
            glVertex2i(vetorQuadrados[i].getPositionX5(), vetorQuadrados[i].getPositionY5());

            glEnd();
            glFlush();
        }
    }
}

void pacman()
{

    // glPushMatrix();
    // glTranslated(spin, 0, 0);
    // glRotated(0, c_x, c_y, 1.0);
    // glRecti(c_x, c_y, c_x+40, c_y+40);
    // glPopMatrix();
    // glutSwapBuffers();
    colocaImagem();
    // glClear(GL_COLOR_BUFFER_BIT);
    // glColor4f(1.0, 1.0, 1.0, 0.5);

    glLoadIdentity();
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glTexCoord3f(0, 0, 0);
    glVertex3f(c_x, c_y, 0);
    glTexCoord3f(0, 1, 0);
    glVertex3f(c_x, c_y + 80, 0);
    glTexCoord3f(1, 1, 0);
    glVertex3f(c_x + 80, c_y + 80, 0);
    glTexCoord3f(1, 0, 0);
    glVertex3f(c_x + 80, c_y, 0);
    glEnd(); // angulo += velocidade;
    glDisable(GL_TEXTURE_2D);

    // glRecti(800, 580, 800+80, 580+80);

    colocaImagem2();
    // glClear(GL_COLOR_BUFFER_BIT);
    // glColor4f(1.0, 1.0, 1.0, 0.5);

    glLoadIdentity();
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glTexCoord3f(0, 0, 0);
    glVertex3f(percursoVilaoX[indice_vilao], percursoVilaoY[indice_vilao], 0);
    glTexCoord3f(0, 1, 0);
    glVertex3f(percursoVilaoX[indice_vilao], percursoVilaoY[indice_vilao] + 80, 0);
    glTexCoord3f(1, 1, 0);
    glVertex3f(percursoVilaoX[indice_vilao] + 80, percursoVilaoY[indice_vilao] + 80, 0);
    glTexCoord3f(1, 0, 0);
    glVertex3f(percursoVilaoX[indice_vilao] + 80, percursoVilaoY[indice_vilao], 0);
    glEnd(); // angulo += velocidade;
    glDisable(GL_TEXTURE_2D);
}

// void spinDisplay(){
//     spin = spin + 2.0f;
//     if (spin > c_y){
//         spin = spin - c_y;
//     }
//     glutPostRedisplay();
// }

void mapa2()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor4f(0.0, 0.0, 1.0, 0.5);

    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(1600, 0);
    glVertex2i(1600, 20);
    glVertex2i(0, 20);
    glVertex2i(0, 0);

    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2i(0, 20);
    glVertex2i(0, 800);
    glVertex2i(20, 800);
    glVertex2i(20, 0);
    glVertex2i(0, 20);

    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2i(1580, 0);
    glVertex2i(1600, 0);
    glVertex2i(1600, 800);
    glVertex2i(1580, 800);
    glVertex2i(1580, 0);

    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2i(0, 780);
    glVertex2i(1600, 780);
    glVertex2i(1600, 800);
    glVertex2i(0, 800);
    glVertex2i(0, 780);

    glEnd();
    glFlush();
}

void level()
{
    glColor4f(1.0, 0.0, 0.0, 0.5);

    glBegin(GL_LINE_STRIP);
    glVertex2i(100, 600);
    glVertex2i(100, 300);
    glVertex2i(300, 300);

    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glVertex2i(500, 500);
    glVertex2i(400, 500);
    glVertex2i(400, 400);
    glVertex2i(500, 400);
    glVertex2i(400, 400);
    glVertex2i(400, 300);
    glVertex2i(500, 300);

    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glVertex2i(600, 500);
    glVertex2i(700, 300);
    glVertex2i(800, 500);

    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glVertex2i(1000, 500);
    glVertex2i(900, 500);
    glVertex2i(900, 400);
    glVertex2i(1000, 400);
    glVertex2i(900, 400);
    glVertex2i(900, 300);
    glVertex2i(1000, 300);

    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glVertex2i(1100, 600);
    glVertex2i(1100, 300);

    glEnd();
    glFlush();

    glColor4f(1.0, 1.0, 0.0, 0.5);

    glBegin(GL_LINE_STRIP);
    glVertex2i(100, 200);
    glVertex2i(1500, 200);

    glEnd();
    glFlush();
}

void One()
{
    glColor4f(1.0, 0.0, 0.0, 0.5);

    glBegin(GL_LINE_STRIP);
    glVertex2i(1300, 500);
    glVertex2i(1400, 600);
    glVertex2i(1400, 300);
    glVertex2i(1300, 300);
    glVertex2i(1500, 300);

    glEnd();
    glFlush();
}

void display(void)
{
    // colocaImagem();
    // pacman();

    // glDisable(GL_TEXTURE_2D);
    mapa();
    quadradosPontos();
    pacman();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 27:
        exit(0);
        break;
    }
}

void andarPacmanEVilao(int i)
{
    if (indice_vilao >= tamanho_vetor_vilao)
    {
        indice_vilao = 0;
    }

    if (BAIXO)
    {
        if (colideVilao(c_x, c_y - 5))
        {
            stopGame();
        }
        bool colide = wallColide(c_x, c_y - 5);
        if (!colide)
        {
            c_y -= 5;
            //    glutIdleFunc(spinDisplay);
            comeuComida();
        }
        glutPostRedisplay();
    }
    else if (CIMA)
    {
        if (colideVilao(c_x, c_y + 5))
        {
            stopGame();
        }

        if (!wallColide(c_x, c_y + 5))
        {
            c_y += 5;
            comeuComida();
        }

        glutPostRedisplay();
    }
    else if (LADO_DIREITO)
    {
        if (colideVilao(c_x + 5, c_y))
        {
            stopGame();
        }
        if (!wallColide(c_x + 5, c_y))
        {
            c_x += 5;
            // glutIdleFunc(spinDisplay);
            comeuComida();
        }

        glutPostRedisplay();
    }
    else if (LADO_ESQUERDO)
    {
        if (colideVilao(c_x - 5, c_y))
        {
            stopGame();
        }
        if (!wallColide(c_x - 5, c_y))
        {
            c_x -= 5;
            // glutIdleFunc(spinDisplay);
            comeuComida();
        }

        glutPostRedisplay();
    }
    indice_vilao++;

    glutTimerFunc(delay, andarPacmanEVilao, 1);
}

void specialInputDoTeclado(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:

        CIMA = true;
        BAIXO = false;
        LADO_DIREITO = false;
        LADO_ESQUERDO = false;

        break;

    case GLUT_KEY_DOWN:

        CIMA = false;
        BAIXO = true;
        LADO_DIREITO = false;
        LADO_ESQUERDO = false;

        break;

    case GLUT_KEY_LEFT:

        CIMA = false;
        BAIXO = false;
        LADO_DIREITO = false;
        LADO_ESQUERDO = true;

        break;

    case GLUT_KEY_RIGHT:
        CIMA = false;
        BAIXO = false;
        LADO_DIREITO = true;
        LADO_ESQUERDO = false;

        break;
    }
}

void reshape(int x, int y)
{
    glViewport(0, 0, (GLsizei)x, (GLsizei)y);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 1600, 0, 800, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void stopGame()
{
    CIMA = false;
    BAIXO = false;
    LADO_DIREITO = false;
    LADO_ESQUERDO = false;
    c_x = 200;
    c_y = 680;
    // engine->play2D("pacman_chomp.wav",false);

    for (int i = 0; i < 78; i++)
    {

        vetorQuadrados[i].setStatus(true);
    }

    CIMA = true;
    BAIXO = true;
    LADO_DIREITO = true;
    LADO_ESQUERDO = true;
}

int viuDani()
{

    for (int i = 0; i < 10; i++)
    {

        if (i == 1)
        {
            printf("%d", i);
            return i;
        }
        if (i == 2)
        {
            printf("%d", i);
            return i;
        }
        if (i == 3)
        {
            printf("%d", i);
            return i;
        }
        if (i == 4)
        {
            printf("%d", i);
            return i;
        }
        if (i == 5)
        {
            printf("%d", i);
            return i;
        }
    }
}

bool wallColide(int posicaoX, int posicaoY)
{

    int auxiliarCoordX = 0;
    int auxiliarCoordY = 0;
    bool col = false;
    for (int i = 0; i < 13; i++)
    {

        auxiliarCoordX = vetorParedes[i].getPositionX1();
        auxiliarCoordY = vetorParedes[i].getPositionY1();

        // printf("auxX %d ", auxiliarCoordX);
        // printf("auxY %d\n", auxiliarCoordY);

        bool colisaoEmX = posicaoX + 80 >= auxiliarCoordX && auxiliarCoordX + (vetorParedes[i].getPositionX3() - vetorParedes[i].getPositionX1()) >= posicaoX;
        bool colisaoEmY = posicaoY + 80 >= auxiliarCoordY && auxiliarCoordY + (vetorParedes[i].getPositionY3() - vetorParedes[i].getPositionY1()) >= posicaoY;

        if (colisaoEmX && colisaoEmY)
        {
            col = true;
        }
    }
    return col;
}

bool colideVilao(int posicaoX, int posicaoY)
{

    int auxiliarCoordX = cv_X;
    int auxiliarCoordY = cv_Y;
    bool colisao = false;

    bool colisaoEmX = posicaoX + 80 >= auxiliarCoordX && auxiliarCoordX + ((cv_X + 80) - cv_X) >= posicaoX;
    bool colisaoEmY = posicaoY + 80 >= auxiliarCoordY && auxiliarCoordY + ((cv_Y + 80) - cv_Y) >= posicaoY;

    if (colisaoEmX && colisaoEmY)
    {
        colisao = true;
    }

    return colisao;
}

void comeuComida()
{

    int auxiliarCoordX = 0;
    int auxiliarCoordY = 0;

    for (int i = 0; i < 78; i++)
    {

        auxiliarCoordX = vetorQuadrados[i].getPositionX1();
        auxiliarCoordY = vetorQuadrados[i].getPositionY1();

        bool colisaoEmX = c_x + 80 >= auxiliarCoordX && auxiliarCoordX + (vetorQuadrados[i].getPositionX3() - vetorQuadrados[i].getPositionX1()) >= c_x;
        bool colisaoEmY = c_y + 80 >= auxiliarCoordY && auxiliarCoordY + (vetorQuadrados[i].getPositionY3() - vetorQuadrados[i].getPositionY1()) >= c_y;

        if (colisaoEmX && colisaoEmY)
        {
            vetorQuadrados[i].setStatus(false);
            // engine->play2D("pacman_chomp.wav");
            // Se vc quiser aqui vc toca o som ao comer a comida
        }
    }
}

char *carrega_bmp()
{
    FILE *f = fopen("pac2.bmp", "rb");
    if (f == NULL)
    {
        printf("Erro ao carregar o arquivo %s!", "pac2.bmp");
        exit(1);
    }
    int of;
    fseek(f, 10, SEEK_SET);
    fread(&of, sizeof(int), 1, f);
    fseek(f, 4, SEEK_CUR);
    fread(&w, sizeof(int), 1, f);
    fread(&h, sizeof(int), 1, f);

    fseek(f, of, SEEK_SET);

    int by = ((w * 3 + 3) / 4) * 4 - (w * 3 % 4);
    char *tmp_m = (char *)malloc(sizeof(char) * by * h);
    char *m = (char *)malloc(sizeof(char) * w * h * 3);
    fread(tmp_m, sizeof(char) * by * h, 1, f);
    int x, y, i;
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            for (i = 0; i < 3; i++)
            {
                m[3 * (w * y + x) + i] = tmp_m[3 * (w * y + x) + (2 - i)];
            }
        }
    }
    free(tmp_m);
    return m;
}

GLuint carregaTextura()
{
    char *wa = carrega_bmp();
    GLuint texid;
    glGenTextures(1, &texid);
    glBindTexture(GL_TEXTURE_2D, texid);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, wa);
    free(wa);
    return texid;
}

void colocaImagem()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texid1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void colocaImagem2()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texid2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

GLuint carregaTextura2()
{
    char *wa = carrega_bmp2();
    GLuint texid;
    glGenTextures(1, &texid);
    glBindTexture(GL_TEXTURE_2D, texid);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, wa);
    free(wa);
    return texid;
}

char *carrega_bmp2()
{
    FILE *f = fopen("vilao.bmp", "rb");
    if (f == NULL)
    {
        printf("Erro ao carregar o arquivo %s!", "vilao.bmp");
        exit(1);
    }
    int of;
    fseek(f, 10, SEEK_SET);
    fread(&of, sizeof(int), 1, f);
    fseek(f, 4, SEEK_CUR);
    fread(&w, sizeof(int), 1, f);
    fread(&h, sizeof(int), 1, f);

    fseek(f, of, SEEK_SET);

    int by = ((w * 3 + 3) / 4) * 4 - (w * 3 % 4);
    char *tmp_m = (char *)malloc(sizeof(char) * by * h);
    char *m = (char *)malloc(sizeof(char) * w * h * 3);
    fread(tmp_m, sizeof(char) * by * h, 1, f);
    int x, y, i;
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            for (i = 0; i < 3; i++)
            {
                m[3 * (w * y + x) + i] = tmp_m[3 * (w * y + x) + (2 - i)];
            }
        }
    }
    free(tmp_m);
    return m;
}