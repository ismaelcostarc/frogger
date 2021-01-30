/*
  Name: Street Frog
  Description: Baseado no jogo de atari no qual o sapo tem que atravessar a avenida. 
*/

#include <stdio.h> //Imput Output
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

/*
SOM
*/
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
Mix_Music *musica = NULL; //- música de fundo
Mix_Chunk *transito = NULL;
Mix_Chunk *crash = NULL;

//Declaracoes das variaveis
GLint mover = 0;
GLint movercarro = 0;
GLint movercarro2 = 0;
GLint movermadeira = 0;
GLint movermadeira1 = 0;
GLint movermadeira2 = 0;
GLint direcao = 1;
GLint moversapox = 0;
GLint moversapoy = 0;
GLint prediox = 0;
GLint predioy = 0;
GLint tempo = 0;
GLint lado = 0;

int W = 690;
int H = 530;

//Desenha a pista
void Pista()
{
   glColor3f(1, 1, 1);
   glLineWidth(3);
   glBegin(GL_LINES);
   glVertex2i(1, 1);
   glVertex2i(29, 1);
   glVertex2i(1, 7);
   glVertex2i(29, 7);
   glEnd();

   glColor3f(1, 1, 1);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2i(2, 3);
   glVertex2i(6, 3);
   glVertex2i(10, 3);
   glVertex2i(14, 3);
   glVertex2i(18, 3);
   glVertex2i(22, 3);
   glVertex2i(26, 3);
   glVertex2i(29, 3);
   glVertex2i(2, 5);
   glVertex2i(6, 5);
   glVertex2i(10, 5);
   glVertex2i(14, 5);
   glVertex2i(18, 5);
   glVertex2i(22, 5);
   glVertex2i(26, 5);
   glVertex2i(29, 5);
   glEnd();

   glColor3f(0, 0.5, 0);
   //Gramado
   glBegin(GL_QUADS);
   glVertex2f(1.0, 0.0);
   glVertex2f(1.0, 0.8);
   glVertex2f(29.0, 0.8);
   glVertex2f(29.0, 0.0);
   glEnd();

   glColor3f(0, 0.5, 0);
   //Gramado
   glBegin(GL_QUADS);
   glVertex2f(1.0, 7.2);
   glVertex2f(1.0, 8.0);
   glVertex2f(29.0, 8.0);
   glVertex2f(29.0, 7.2);
   glEnd();
}

//Desenha a Lagoa
void Lagoa()
{
   glColor3f(0, 0, 1.0);
   glBegin(GL_QUADS);
   glVertex2f(1.0, 1.5);
   glVertex2f(1.0, 6.5);
   glVertex2f(29.0, 6.5);
   glVertex2f(29.0, 1.5);
   glEnd();

   glColor3f(1, 1, 1); //ponte   linha
   glBegin(GL_LINES);
   glVertex2f(1, 4.7);
   glVertex2f(29, 4.7);
   glVertex2f(1, 5.3);
   glVertex2f(29, 5.3);
   glEnd();
   glColor3f(1, 1, 1); //ponte   linha
   glBegin(GL_LINES);
   glVertex2f(1, 2.7);
   glVertex2f(29, 2.7);
   glVertex2f(1, 3.3);
   glVertex2f(29, 3.3);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(1.5, 2.5);
   glVertex2f(1.5, 3.5);
   glVertex2f(2.0, 3.5);
   glVertex2f(2.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(2.5, 2.5);
   glVertex2f(2.5, 3.5);
   glVertex2f(3.0, 3.5);
   glVertex2f(3.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(3.5, 2.5);
   glVertex2f(3.5, 3.5);
   glVertex2f(4.0, 3.5);
   glVertex2f(4.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(4.5, 2.5);
   glVertex2f(4.5, 3.5);
   glVertex2f(5.0, 3.5);
   glVertex2f(5.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(5.5, 2.5);
   glVertex2f(5.5, 3.5);
   glVertex2f(6.0, 3.5);
   glVertex2f(6.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(6.5, 2.5);
   glVertex2f(6.5, 3.5);
   glVertex2f(7.0, 3.5);
   glVertex2f(7.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(7.5, 2.5);
   glVertex2f(7.5, 3.5);
   glVertex2f(8.0, 3.5);
   glVertex2f(8.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(8.5, 2.5);
   glVertex2f(8.5, 3.5);
   glVertex2f(9.0, 3.5);
   glVertex2f(9.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(9.5, 2.5);
   glVertex2f(9.5, 3.5);
   glVertex2f(10.0, 3.5);
   glVertex2f(10.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(10.5, 2.5);
   glVertex2f(10.5, 3.5);
   glVertex2f(11.0, 3.5);
   glVertex2f(11.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(11.5, 2.5);
   glVertex2f(11.5, 3.5);
   glVertex2f(12.0, 3.5);
   glVertex2f(12.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(12.5, 2.5);
   glVertex2f(12.5, 3.5);
   glVertex2f(13.0, 3.5);
   glVertex2f(13.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(13.5, 2.5);
   glVertex2f(13.5, 3.5);
   glVertex2f(14.0, 3.5);
   glVertex2f(14.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(14.5, 2.5);
   glVertex2f(14.5, 3.5);
   glVertex2f(15.0, 3.5);
   glVertex2f(15.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(15.5, 2.5);
   glVertex2f(15.5, 3.5);
   glVertex2f(16.0, 3.5);
   glVertex2f(16.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(16.5, 2.5);
   glVertex2f(16.5, 3.5);
   glVertex2f(17.0, 3.5);
   glVertex2f(17.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(17.5, 2.5);
   glVertex2f(17.5, 3.5);
   glVertex2f(18.0, 3.5);
   glVertex2f(18.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(18.5, 2.5);
   glVertex2f(18.5, 3.5);
   glVertex2f(19.0, 3.5);
   glVertex2f(19.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(19.5, 2.5);
   glVertex2f(19.5, 3.5);
   glVertex2f(20.0, 3.5);
   glVertex2f(20.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(20.5, 2.5);
   glVertex2f(20.5, 3.5);
   glVertex2f(21.0, 3.5);
   glVertex2f(21.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(21.5, 2.5);
   glVertex2f(21.5, 3.5);
   glVertex2f(22.0, 3.5);
   glVertex2f(22.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(22.5, 2.5);
   glVertex2f(22.5, 3.5);
   glVertex2f(23.0, 3.5);
   glVertex2f(23.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(23.5, 2.5);
   glVertex2f(23.5, 3.5);
   glVertex2f(24.0, 3.5);
   glVertex2f(24.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(24.5, 2.5);
   glVertex2f(24.5, 3.5);
   glVertex2f(25.0, 3.5);
   glVertex2f(25.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(25.5, 2.5);
   glVertex2f(25.5, 3.5);
   glVertex2f(26.0, 3.5);
   glVertex2f(26.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(26.5, 2.5);
   glVertex2f(26.5, 3.5);
   glVertex2f(27.0, 3.5);
   glVertex2f(27.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(27.5, 2.5);
   glVertex2f(27.5, 3.5);
   glVertex2f(28.0, 3.5);
   glVertex2f(28.0, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(28.5, 2.5);
   glVertex2f(28.5, 3.5);
   glVertex2f(28.7, 3.5);
   glVertex2f(28.7, 2.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(1.5, 4.5);
   glVertex2f(1.5, 5.5);
   glVertex2f(2.0, 5.5);
   glVertex2f(2.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(2.5, 4.5);
   glVertex2f(2.5, 5.5);
   glVertex2f(3.0, 5.5);
   glVertex2f(3.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(3.5, 4.5);
   glVertex2f(3.5, 5.5);
   glVertex2f(4.0, 5.5);
   glVertex2f(4.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(4.5, 4.5);
   glVertex2f(4.5, 5.5);
   glVertex2f(5.0, 5.5);
   glVertex2f(5.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(5.5, 4.5);
   glVertex2f(5.5, 5.5);
   glVertex2f(6.0, 5.5);
   glVertex2f(6.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(6.5, 4.5);
   glVertex2f(6.5, 5.5);
   glVertex2f(7.0, 5.5);
   glVertex2f(7.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(7.5, 4.5);
   glVertex2f(7.5, 5.5);
   glVertex2f(8.0, 5.5);
   glVertex2f(8.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(8.5, 4.5);
   glVertex2f(8.5, 5.5);
   glVertex2f(9.0, 5.5);
   glVertex2f(9.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(9.5, 4.5);
   glVertex2f(9.5, 5.5);
   glVertex2f(10.0, 5.5);
   glVertex2f(10.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(10.5, 4.5);
   glVertex2f(10.5, 5.5);
   glVertex2f(11.0, 5.5);
   glVertex2f(11.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(11.5, 4.5);
   glVertex2f(11.5, 5.5);
   glVertex2f(12.0, 5.5);
   glVertex2f(12.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(12.5, 4.5);
   glVertex2f(12.5, 5.5);
   glVertex2f(13.0, 5.5);
   glVertex2f(13.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(13.5, 4.5);
   glVertex2f(13.5, 5.5);
   glVertex2f(14.0, 5.5);
   glVertex2f(14.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(14.5, 4.5);
   glVertex2f(14.5, 5.5);
   glVertex2f(15.0, 5.5);
   glVertex2f(15.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(15.5, 4.5);
   glVertex2f(15.5, 5.5);
   glVertex2f(16.0, 5.5);
   glVertex2f(16.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(16.5, 4.5);
   glVertex2f(16.5, 5.5);
   glVertex2f(17.0, 5.5);
   glVertex2f(17.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(17.5, 4.5);
   glVertex2f(17.5, 5.5);
   glVertex2f(18.0, 5.5);
   glVertex2f(18.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(18.5, 4.5);
   glVertex2f(18.5, 5.5);
   glVertex2f(19.0, 5.5);
   glVertex2f(19.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(19.5, 4.5);
   glVertex2f(19.5, 5.5);
   glVertex2f(20.0, 5.5);
   glVertex2f(20.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(20.5, 4.5);
   glVertex2f(20.5, 5.5);
   glVertex2f(21.0, 5.5);
   glVertex2f(21.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(21.5, 4.5);
   glVertex2f(21.5, 5.5);
   glVertex2f(22.0, 5.5);
   glVertex2f(22.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(22.5, 4.5);
   glVertex2f(22.5, 5.5);
   glVertex2f(23.0, 5.5);
   glVertex2f(23.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(23.5, 4.5);
   glVertex2f(23.5, 5.5);
   glVertex2f(24.0, 5.5);
   glVertex2f(24.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(24.5, 4.5);
   glVertex2f(24.5, 5.5);
   glVertex2f(25.0, 5.5);
   glVertex2f(25.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(25.5, 4.5);
   glVertex2f(25.5, 5.5);
   glVertex2f(26.0, 5.5);
   glVertex2f(26.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(26.5, 4.5);
   glVertex2f(26.5, 5.5);
   glVertex2f(27.0, 5.5);
   glVertex2f(27.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(27.5, 4.5);
   glVertex2f(27.5, 5.5);
   glVertex2f(28.0, 5.5);
   glVertex2f(28.0, 4.5);
   glEnd();

   glColor3f(0.6, 0.2, 0); //ponte blocos
   glBegin(GL_QUADS);
   glVertex2f(28.5, 4.5);
   glVertex2f(28.5, 5.5);
   glVertex2f(28.7, 5.5);
   glVertex2f(28.7, 4.5);
   glEnd();

   //Gramado
   glColor3f(0, 0.5, 0);
   glBegin(GL_QUADS);
   glVertex2f(1.0, 0.0);
   glVertex2f(1.0, 0.8);
   glVertex2f(29.0, 0.8);
   glVertex2f(29.0, 0.0);
   glEnd();
   glColor3f(0, 0.5, 0);
   //Gramado
   glBegin(GL_QUADS);
   glVertex2f(1.0, 7.2);
   glVertex2f(1.0, 8.0);
   glVertex2f(29.0, 8.0);
   glVertex2f(29.0, 7.2);
   glEnd();
}

//Desenha o sapo
void Sapo()
{
   glColor3f(0, 1, 0);
   glPointSize(20.0);
   glBegin(GL_POINTS);
   glVertex2f(moversapox + 15, moversapoy + 1);
   glEnd();

   glColor3f(1, 1, 0);
   glPointSize(3.0);
   glBegin(GL_POINTS);
   glVertex2f(moversapox + 14.8, moversapoy + 1.2); //Olho esquerdo
   glVertex2f(moversapox + 15.2, moversapoy + 1.2); //Olho direito
   glEnd();

   //Desenha as pernas
   glColor3f(0, 1, 0);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(moversapox + 14.3, moversapoy + 1.3);
   glVertex2f(moversapox + 14.8, moversapoy + 1.1);
   glVertex2f(moversapox + 15.7, moversapoy + 1.3);
   glVertex2f(moversapox + 15.2, moversapoy + 1.1);
   glVertex2f(moversapox + 14.8, moversapoy + 0.9);
   glVertex2f(moversapox + 14.3, moversapoy + 0.7);
   glVertex2f(moversapox + 15.7, moversapoy + 0.7);
   glVertex2f(moversapox + 15.2, moversapoy + 0.9);
   glEnd();

   //Ponto das maos
   glColor3f(0, 1, 0);
   glPointSize(1.0);
   glBegin(GL_POINTS);
   glVertex2f(moversapox + 14.3, moversapoy + 1.15);
   glVertex2f(moversapox + 15.7, moversapoy + 1.15);
   glVertex2f(moversapox + 14.2, moversapoy + 1.3);
   glVertex2f(moversapox + 15.8, moversapoy + 1.3);
   glVertex2f(moversapox + 14.4, moversapoy + 1.4);
   glVertex2f(moversapox + 15.6, moversapoy + 1.4);
   glEnd();
}

//Desenha o predio
void Predio()
{
   glColor3f(1, 1, 1);
   glBegin(GL_QUADS);
   glVertex2f(1, 8);
   glVertex2f(1, predioy + 10);
   glVertex2f(6, predioy + 10);
   glVertex2f(6, 8);
   glEnd();

   //Janela Esquerda
   glColor3f(0, 0, 0);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(2, 9.3);
   glVertex2f(3, 9.3);
   glVertex2f(2, 9.8);
   glVertex2f(3, 9.8);
   glVertex2f(2, 9.3);
   glVertex2f(2, 9.8);
   glVertex2f(3, 9.3);
   glVertex2f(3, 9.8);
   glEnd();

   //Janela Direita
   glColor3f(0, 0, 0);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(4, 9.3);
   glVertex2f(5, 9.3);
   glVertex2f(4, 9.8);
   glVertex2f(5, 9.8);
   glVertex2f(4, 9.3);
   glVertex2f(4, 9.8);
   glVertex2f(5, 9.3);
   glVertex2f(5, 9.8);

   //Janela Esquerda Escondida
   glColor3f(0, 0, 0);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(2, 10.3);
   glVertex2f(3, 10.3);
   glVertex2f(2, 10.8);
   glVertex2f(3, 10.8);
   glVertex2f(2, 10.3);
   glVertex2f(2, 10.8);
   glVertex2f(3, 10.3);
   glVertex2f(3, 10.8);
   glEnd();

   //Janela Direita Escondida
   glColor3f(0, 0, 0);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(4, 10.3);
   glVertex2f(5, 10.3);
   glVertex2f(4, 10.8);
   glVertex2f(5, 10.8);
   glVertex2f(4, 10.3);
   glVertex2f(4, 10.8);
   glVertex2f(5, 10.3);
   glVertex2f(5, 10.8);
   glEnd();

   //Janela Esquerda Escondida
   glColor3f(0, 0, 0);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(2, 11.3);
   glVertex2f(3, 11.3);
   glVertex2f(2, 11.8);
   glVertex2f(3, 11.8);
   glVertex2f(2, 11.3);
   glVertex2f(2, 11.8);
   glVertex2f(3, 11.3);
   glVertex2f(3, 11.8);
   glEnd();

   //Janela Direita Escondida
   glColor3f(0, 0, 0);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(4, 11.3);
   glVertex2f(5, 11.3);
   glVertex2f(4, 11.8);
   glVertex2f(5, 11.8);
   glVertex2f(4, 11.3);
   glVertex2f(4, 11.8);
   glVertex2f(5, 11.3);
   glVertex2f(5, 11.8);
   glEnd();
}

//Desenha a casa
void Casa()
{
   glColor3f(1, 0, 0);
   // Desenha um tri�ngulo no centro da janela
   glBegin(GL_TRIANGLES);
   //Telhado
   glVertex3f(8.0, 10.0, 0);
   glVertex3f(12.0, 10.0, 0);
   glVertex3f(10.0, 11.0, 0);
   glEnd();

   glColor3f(1, 1, 1);
   //Quadrado casa
   glBegin(GL_QUADS);
   glVertex2f(8.0, 8.0);
   glVertex2f(8.0, 10.0);
   glVertex2f(12.0, 10.0);
   glVertex2f(12.0, 8.0);
   glEnd();

   glColor3f(0, 0, 1);
   //Porta
   glBegin(GL_QUADS);
   glVertex2f(8.5, 8.0);
   glVertex2f(8.5, 9.0);
   glVertex2f(9.5, 9.0);
   glVertex2f(9.5, 8.0);
   glEnd();

   glColor3f(4, 1, 0);
   //Janela
   glBegin(GL_QUADS);
   glVertex2f(10.0, 8.5);
   glVertex2f(10.0, 9.5);
   glVertex2f(11.5, 9.5);
   glVertex2f(11.5, 8.5);
   glEnd();

   glColor3f(0, 0, 0);
   glBegin(GL_LINES);
   glVertex2f(10.0, 9.0);
   glVertex2f(11.5, 9.0);
   glVertex2f(10.8, 8.5);
   glVertex2f(10.8, 9.5);
   glEnd();
}

//Desenha madeira
void Madeira()
{
   glColor3f(0.6, 0.2, 0.0);
   glBegin(GL_QUADS);
   glVertex2f(movermadeira2 + 1.0, 1.5);
   glVertex2f(movermadeira2 + 1.0, 2.5);
   glVertex2f(movermadeira2 + 3.0, 2.5);
   glVertex2f(movermadeira2 + 3.0, 1.5);
   glEnd();

   glColor3f(0.6, 0.2, 0.0);
   glBegin(GL_QUADS);
   glVertex2f(movermadeira1 + 0.5, 3.5);
   glVertex2f(movermadeira1 + 0.5, 4.5);
   glVertex2f(movermadeira1 + 3.5, 4.5);
   glVertex2f(movermadeira1 + 3.5, 3.5);
   glEnd();

   glColor3f(0.6, 0.2, 0.0);
   glBegin(GL_QUADS);
   glVertex2f(movermadeira + 1, 5.5);
   glVertex2f(movermadeira + 1, 6.5);
   glVertex2f(movermadeira + 5, 6.5);
   glVertex2f(movermadeira + 5, 5.5);
   glEnd();
}

//Desenha o caminhao
void Caminhao()

{
   glColor3f(0.5, 1, 0);
   glBegin(GL_QUADS);
   glVertex2f(movercarro + 2, 3.5);
   glVertex2f(movercarro + 2, 4.5);
   glVertex2f(movercarro + 4, 4.5);
   glVertex2f(movercarro + 4, 3.5);
   glEnd();
   glBegin(GL_QUADS);
   glVertex2f(movercarro + 1, 3.5);
   glVertex2f(movercarro + 1, 4.0);
   glVertex2f(movercarro + 2, 4.0);
   glVertex2f(movercarro + 2, 3.5);
   glEnd();
   glPointSize(5.0);
   glBegin(GL_POINTS);
   glColor3f(0.5, 0.5, 0.5);
   glVertex2f(movercarro + 1.5, 3.5);
   glVertex2f(movercarro + 3.5, 3.5);
   glEnd();
}

//Desenha o caminhao2
void Caminhao2()
{
   glColor3f(0, 0, 0.5);
   glBegin(GL_QUADS);
   glVertex2f(movercarro2 + 2, 5.5);
   glVertex2f(movercarro2 + 2, 6.5);
   glVertex2f(movercarro2 + 4, 6.5);
   glVertex2f(movercarro2 + 4, 5.5);
   glEnd();
   glBegin(GL_QUADS);
   glVertex2f(movercarro2 + 1, 5.5);
   glVertex2f(movercarro2 + 1, 6.0);
   glVertex2f(movercarro2 + 2, 6.0);
   glVertex2f(movercarro2 + 2, 5.5);
   glEnd();
   glPointSize(5.0);
   glBegin(GL_POINTS);
   glColor3f(0.5, 0.5, 0.5);
   glVertex2f(movercarro2 + 1.5, 5.5);
   glVertex2f(movercarro2 + 3.5, 5.5);
   glEnd();
}

//Desenha o onibus
void Onibus()
{
   {
      glColor3f(0.5, 0, 0);
      glBegin(GL_QUADS);
      glVertex2f(mover + 1, 1.5);
      glVertex2f(mover + 1, 2.5);
      glVertex2f(mover + 5, 2.5);
      glVertex2f(mover + 5, 1.5);
      glEnd();
      glPointSize(5.0);
      glBegin(GL_POINTS);
      glColor3f(0.5, 0.5, 0.5);
      glVertex2f(mover + 1.5, 1.5);
      glVertex2f(mover + 4.5, 1.5);
      glEnd();
   }
   {
      //Escrevendo um texto na tela
      //posicionamos na tela
      glRasterPos2f(mover + 1.0, 2.0);
      //String a ser escrita na tela
      char *p = (char *)"Ônibus";
      while (*p != '\0')
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p++);
      }
   }
}

//Movimenta��o automatica ir e voltar  (Busao Jiraya)
void movimentar(int passo)
{
   if (direcao == 1)
   {
      mover += 4;
      if (mover == 36)
         direcao = 0;
   }
   else
   {
      mover -= 4;
      if (mover == -8)
         direcao = 1;
   }

   glutPostRedisplay();
   glutTimerFunc(100 - tempo, movimentar, 1);
}

//Movimenta��o automatica apenas ir
void movimentacarro(int passo) //Carro verde (Caminhao)
{
   {
      movercarro -= 4;
      if (movercarro == -8)
      {
         movercarro = 36;
      }
      glutPostRedisplay();
      glutTimerFunc(100 - tempo, movimentacarro, 1);
   }
}
void movimentacarro2(int passo) //Carro azul (Caminhao2)
{
   {
      movercarro2 -= 4;
      if (movercarro2 == -8)
      {
         movercarro2 = 32;
      }
      glutPostRedisplay();
      glutTimerFunc(100 - tempo, movimentacarro2, 1);
   }
}
//Movimenta��o automatica ir e voltar  (mover madeira)
void movermad(int passo)
{
   {
      movermadeira += 2;
      if (movermadeira == 36)
      {
         movermadeira = -4;
      }
      glutPostRedisplay();
      glutTimerFunc(100 - tempo, movermad, 1);
   }
}
//Movimenta��o automatica apenas ir (Madeira)
void movermad1(int passo) //
{
   {
      movermadeira1 -= 2;
      if (movermadeira1 == -8)
      {
         movermadeira1 = 36;
      }
      glutPostRedisplay();
      glutTimerFunc(100 - tempo, movermad1, 1);
   }
}
//Movimenta��o automatica apenas ir (Madeira)
void movermad2(int passo) //
{
   {
      movermadeira2 -= 2;
      if (movermadeira2 == -8)
      {
         movermadeira2 = 32;
      }
      glutPostRedisplay();
      glutTimerFunc(100 - tempo, movermad2, 1);
   }
}

//Caso o carro passe por cima do sapo, retornar ao inicio
void Colisao()
{
   if ((mover - 10 == moversapox + 1) && (2 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((mover - 10 == moversapox + 2) && (2 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((mover - 10 == moversapox + 3) && (2 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((mover - 10 == moversapox + 4) && (2 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }

   if ((movercarro - 10 == moversapox + 1) && (4 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((movercarro - 10 == moversapox + 2) && (4 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((movercarro - 10 == moversapox + 3) && (4 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((movercarro - 10 == moversapox + 4) && (4 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }

   if ((movercarro2 - 10 == moversapox + 1) && (6 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((movercarro2 - 10 == moversapox + 2) && (6 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((movercarro2 - 10 == moversapox + 3) && (6 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((movercarro2 - 10 == moversapox + 4) && (6 == moversapoy + 1))
   {
      Mix_PlayChannel(1, crash, 0);
      moversapoy = 0;
   }
   if ((7 == moversapoy + 1) && (lado == 0))
      lado = 1; //Mudanca de lado
   if ((7 == moversapoy + 1) && (lado == 2))
      lado = 3; //Mudanca de lado
   if ((7 == moversapoy + 1) && (lado == 4))
      lado = 5; //Mudanca de lado

   glutPostRedisplay();
}
//Caso o sapo caia da madeira ou na agua, retornar ao inicio
void Colisao1()
{
   if ((movermadeira - 10 <= moversapox + 0) && (6 == moversapoy + 1))
      moversapoy = 6;
   if ((movermadeira - 10 >= moversapox + 5) && (6 == moversapoy + 1))
      moversapoy = 6;
   if ((movermadeira - 10 == moversapox + 1) && (6 == moversapoy + 1))
      moversapox = movermadeira - 12;
   if ((movermadeira - 10 == moversapox + 2) && (6 == moversapoy + 1))
      moversapox = movermadeira - 12;
   if ((movermadeira - 10 == moversapox + 3) && (6 == moversapoy + 1))
      moversapox = movermadeira - 12;
   if ((movermadeira - 10 == moversapox + 4) && (6 == moversapoy + 1))
      moversapox = movermadeira - 12;
   if ((movermadeira == 24) && (6 == moversapoy + 1))
      moversapox = 0;
   if ((movermadeira == 24) && (6 == moversapoy + 1))
      moversapoy = 6;

   if ((movermadeira1 - 10 <= moversapox + 0) && (4 == moversapoy + 1))
      moversapoy = 6;
   if ((movermadeira1 - 10 >= moversapox + 5) && (4 == moversapoy + 1))
      moversapoy = 6;
   if ((movermadeira1 - 10 == moversapox + 1) && (4 == moversapoy + 1))
      moversapox = movermadeira1 - 13;
   if ((movermadeira1 - 10 == moversapox + 2) && (4 == moversapoy + 1))
      moversapox = movermadeira1 - 13;
   if ((movermadeira1 - 10 == moversapox + 3) && (4 == moversapoy + 1))
      moversapox = movermadeira1 - 13;
   if ((movermadeira1 - 10 == moversapox + 4) && (4 == moversapoy + 1))
      moversapox = movermadeira1 - 13;
   if ((movermadeira1 == 2) && (4 == moversapoy + 1))
      moversapox = 0;
   if ((movermadeira1 == 2) && (4 == moversapoy + 1))
      moversapoy = 6;

   if ((movermadeira2 - 10 <= moversapox + 0) && (2 == moversapoy + 1))
      moversapoy = 6;
   if ((movermadeira2 - 10 >= moversapox + 5) && (2 == moversapoy + 1))
      moversapoy = 6;
   if ((movermadeira2 - 10 == moversapox + 1) && (2 == moversapoy + 1))
      moversapox = movermadeira2 - 13;
   if ((movermadeira2 - 10 == moversapox + 2) && (2 == moversapoy + 1))
      moversapox = movermadeira2 - 13;
   if ((movermadeira2 - 10 == moversapox + 3) && (2 == moversapoy + 1))
      moversapox = movermadeira2 - 13;
   if ((movermadeira2 - 10 == moversapox + 4) && (2 == moversapoy + 1))
      moversapox = movermadeira2 - 13;
   if ((movermadeira2 == 2) && (2 == moversapoy + 1))
      moversapox = 0;
   if ((movermadeira2 == 2) && (2 == moversapoy + 1))
      moversapoy = 6;

   if ((1 == moversapoy + 1) && (lado == 1))
      lado = 2; //Mudanca de lado
   if ((1 == moversapoy + 1) && (lado == 3))
      lado = 4; //Mudanca de lado
   if ((1 == moversapoy + 1) && (lado == 5))
      lado = 6; //Mudanca de lado

   glutPostRedisplay();
}

//Comentarios superior direito
void Comentarios()
{
   {
      glColor3f(1, 1, 1);
      glRasterPos2f(13.0, 11.0);
      char *p = (char *)"Street Frog";
      while (*p != '\0')
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p++);
      }
   }

   {
      glColor3f(1, 1, 1);
      glRasterPos2f(13.0, 10.5);
      char *p = (char *)"Avaliacao Final da Disciplina Computacao Grafica.";
      while (*p != '\0')
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p++);
      }
   }

   {
      glColor3f(1, 1, 1);
      glRasterPos2f(13.0, 9.5);
      char *p = (char *)"Objetivo: Atravesse a avenida sem ser atropelado, e o rio sem";
      while (*p != '\0')
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p++);
      }
   }

   {
      glColor3f(1, 1, 1);
      glRasterPos2f(13.0, 9.0);
      char *p = (char *)"cair do tronco. Va e volte para concluir os niveis de velocidade.";
      while (*p != '\0')
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p++);
      }
   }

   {
      glColor3f(1, 1, 1);
      glRasterPos2f(13.0, 8.5);
      char *p = (char *)"Comandos: Use as setas do teclado para movimentar o sapo.";
      while (*p != '\0')
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p++);
      }
   }
}
//Comentario final
void Comentarios1()
{
   {
      glColor3f(1, 1, 1);
      glRasterPos2f(9.0, 8.0);
      char *p = (char *)"Street Frog";
      while (*p != '\0')
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
      }
   }

   {
      glColor3f(1, 1, 1);
      glRasterPos2f(9.2, 6.0);
      char *p = (char *)"Parabens! Voce Ganhou!!";
      while (*p != '\0')
      {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
      }
   }
}

//Chama o desenho
void Desenha(void)
{
   switch (lado)
   {
   case 0:
      tempo = 20; //Nivel 1, velocidade dos carros
      Mix_PlayChannel(-1, transito, 0);
      glClear(GL_COLOR_BUFFER_BIT);
      Pista();
      Colisao();
      Onibus();
      Caminhao();
      Caminhao2();
      Sapo();
      Predio();
      Casa();
      Comentarios();
      glutSwapBuffers();
      break;
   case 1:
      tempo = 15; //Nivel 1, velocidade do tronco
      glClear(GL_COLOR_BUFFER_BIT);
      Colisao1();
      Lagoa();
      Madeira();
      Sapo();
      Predio();
      Casa();
      Comentarios();
      glutSwapBuffers();
      break;
   case 2:
      tempo = 35; //Nivel 2, velocidade dos carros
      Mix_PlayChannel(-1, transito, 0);
      glClear(GL_COLOR_BUFFER_BIT);
      Pista();
      Colisao();
      Onibus();
      Caminhao();
      Caminhao2();
      Sapo();
      Predio();
      Casa();
      Comentarios();
      glutSwapBuffers();
      break;
   case 3:
      tempo = 30; //Nivel 2, velocidade do tronco
      glClear(GL_COLOR_BUFFER_BIT);
      Colisao1();
      Lagoa();
      Madeira();
      Sapo();
      Predio();
      Casa();
      Comentarios();
      glutSwapBuffers();
      break;
   case 4:
      tempo = 50; //Nivel 3, velocidade dos carros
      Mix_PlayChannel(-1, transito, 0);
      glClear(GL_COLOR_BUFFER_BIT);
      Pista();
      Colisao();
      Onibus();
      Caminhao();
      Caminhao2();
      Sapo();
      Predio();
      Casa();
      Comentarios();
      glutSwapBuffers();
      break;
   case 5:
      tempo = 45; //Nivel 3, velocidade do tronco
      glClear(GL_COLOR_BUFFER_BIT);
      Colisao1();
      Lagoa();
      Madeira();
      Sapo();
      Predio();
      Casa();
      Comentarios();
      glutSwapBuffers();
      break;
   case 6:
      glClear(GL_COLOR_BUFFER_BIT);
      Comentarios1();
      glutSwapBuffers();
      break;
   }
}

//Funcoes para teclado (atribuicoes de teclas especiais)
void Mover(int key, int x, int y)
{
   if (key == GLUT_KEY_UP)
   {
      moversapoy += 1;
   }
   if (key == GLUT_KEY_DOWN)
   {
      moversapoy -= 1;
   }
   if (key == GLUT_KEY_LEFT)
   {
      moversapox -= 1;
   }
   if (key == GLUT_KEY_RIGHT)
   {
      moversapox += 1;
   }

   //Limitando o sapo, para nao sair da tela
   if (moversapoy < 0)
   {
      moversapoy = 0;
   }
   if (moversapoy > 6)
   {
      moversapoy = 6;
   }
   if (moversapox < -13)
   {
      moversapox = -13;
   }
   if (moversapox > 13)
   {
      moversapox = 13;
   }
}

//Funcoes para teclado (atribuicoes de teclas)
void Teclado(unsigned char key, int x, int y)
{
   //Fazer o predio subir e descer com W e S
   if (key == 119)
   {
      predioy += 1;
   }
   if (key == 115)
   {
      predioy -= 1;
   }
   //Limites minimo e maximo do predio
   if (predioy < 0)
   {
      predioy = 0;
   }
   if (predioy > 2)
   {
      predioy = 2;
   }
   //Tela cheia na tecla f
   if (key == 102)
   {
      glutFullScreen();
   }
   //Redesenha o novo valor
   glutPostRedisplay();
   //Sai ao se precionar a tecla esc
   if (key == 27)
   {
      exit(0);
   }
}

//Funcoes do menu
void MenuJanela(int op)
{
   switch (op)
   {
   case 0:
   {
      glutFullScreen();
   }
   break;
   }

   glutPostRedisplay();
}
/*
//Funcoes do menu
void MenuSom(int op)
{
   switch (op)
   {
   case 0:
   {
      FSOUND_Close();
   }
   break;
   }

   glutPostRedisplay();
}
*/

//Controle do som
void init()
{
   SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
   atexit(SDL_Quit);
   //screen = SDL_SetVideoMode( W, H, 32, SDL_SWSURFACE);
   Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024); //- inicializa SDL_Mixer
   atexit(Mix_CloseAudio);
}

void carregar()
{
   musica = Mix_LoadMUS("theme.ogg");
   transito = Mix_LoadWAV("car.ogg");
   crash = Mix_LoadWAV("crash.ogg");
}

// Gerenciamento do menu principal
void MenuPrincipal(int op)
{
}

//Cria o Menu
void CriaMenu()
{
   int menu, submenu1, submenu2;

   submenu1 = glutCreateMenu(MenuJanela);
   glutAddMenuEntry("Tela Cheia", 0);

   //submenu2 = glutCreateMenu(MenuSom);
   glutAddMenuEntry("Desligar o som", 0);

   menu = glutCreateMenu(MenuPrincipal);
   glutAddSubMenu("Janela", submenu1);
   // glutAddSubMenu("Som",submenu2);

   glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Fun��o callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
   if (button == GLUT_RIGHT_BUTTON)
      if (state == GLUT_DOWN)
         CriaMenu();

   glutPostRedisplay();
}

//Define configuracoes da janela
void Inicializa(void)
{
   // Define a cor de fundo da janela de visualiza��o como preta
   glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
   GLsizei largura, altura;

   // Evita a divisao por zero
   if (h == 0)
      h = 1;

   // Atualiza as vari�veis
   largura = w;
   altura = h;

   // Especifica as dimens�es da Viewport
   glViewport(0, 0, largura, altura);

   // Inicializa o sistema de coordenadas
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // Estabelece a janela de sele��o (esquerda, direita, inferior,
   // superior) mantendo a propor��o com a janela de visualiza��o
   if (largura <= altura)
      gluOrtho2D(0.0f, 23.0f, 0.0f * altura / largura, 13.0f * altura / largura);
   else
      gluOrtho2D(0.0f * largura / altura, 23.0f * largura / altura, 0.0f, 13.0f);
}

//Chamada do main
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   init();
   carregar();
   Mix_PlayMusic(musica, -1);
   //Inicia o som
   /*
   FSOUND_SAMPLE *samp1 = 0;               //cria um ponteiro para armazenar o som em mem�ria
   if (FSOUND_GetVersion() < FMOD_VERSION) // verifica��o da vers�o do fmod caso a vers�o do FSOUND for menor que a do FMOD retorna uma menssagem de erro
   {
      printf("Error : You are using the wrong DLL version!  You should be using FMOD %.02f\n", FMOD_VERSION);
      return 1;
   }
   //    Seleciona a sa�da de audio
   FSOUND_SetOutput(FSOUND_OUTPUT_DSOUND);

   //    Sele��o do driver
   FSOUND_GetOutput();  // indentifica o tipo de saida
   FSOUND_GetMixer();   // indentifica o mixer
   FSOUND_SetDriver(0); // seta o driver de som que vai ser usado

   //    Inicializando o FMOD
   if (!FSOUND_Init(44100, 32, FSOUND_INIT_GLOBALFOCUS)) // se o valor do FSOUND_Init for 0 execute o tratamento de erro
   {
      printf("Error!\n");
      printf("%s\n", FMOD_ErrorString(FSOUND_GetError()));
      return 1;
   }

   // Carrengando o Sample
   // PCM,44,100 Hz, 32 Bit, Mono ou uma mp3 ou outros formatos suportados pelo fmod
   samp1 = FSOUND_Sample_Load(FSOUND_UNMANAGED, "paranoid.ogg", FSOUND_NORMAL | FSOUND_HW2D, 0, 0);
   if (!samp1)
   {
      printf("Error!\n");
      printf("%s\n", FMOD_ErrorString(FSOUND_GetError()));
      return 1;
   }

   // Aqui fala qual maneira o sample ira tocar caso falhe excute o tratamento de erro
   if (!FSOUND_Sample_SetMode(samp1, FSOUND_LOOP_NORMAL)) // o loop normal toca a musica continuamente ate o programa fechar
   {
      printf("Error!\n");
      printf("%s\n", FMOD_ErrorString(FSOUND_GetError()));
   }
   // Aqui sera tocado o sample ,caso falhe, execute o tratamento de erro
   if (!FSOUND_PlaySound(FSOUND_FREE, samp1))
   {
      printf("Error!\n");
      printf("%s\n", FMOD_ErrorString(FSOUND_GetError()));
   }
   //Fim do codigo do som \\o  \o/   o//\o/
*/
   //Sleep(10000);  // executa o som durante 10 segundos     (Essa funcao esta desativada no Street Frog)

   //E por fim a chamada para o OpenGL
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //Modo para nao exibir rastros na tela
   glutInitWindowSize(W, H);                    //Tamanho da janela
   glutInitWindowPosition(50, 50);              //Localizacao inicial da janela
   glutCreateWindow("Street Frog");             //Nome da janela
   glutKeyboardFunc(Teclado);                   //Chama as funcoes do teclado
   glutSpecialFunc(Mover);                      //Chama as funcoes especias do teclado (setas de movimento)
   Inicializa();
   glutDisplayFunc(Desenha);              //Chama o desenho
   glutReshapeFunc(AlteraTamanhoJanela);  //Correcao de largura e altura para a janela
   glutTimerFunc(10, movimentar, 1);      //Chamada de movimento do carro
   glutTimerFunc(10, movimentacarro, 1);  //Chamada de movimento do carro
   glutTimerFunc(10, movimentacarro2, 1); //Chamada de movimento do carro
   glutTimerFunc(10, movermad, 1);        //Chamada de movimento da madeira
   glutTimerFunc(10, movermad1, 1);       //Chamada de movimento da madeira
   glutTimerFunc(10, movermad2, 1);       //Chamada de movimento da madeira
   glutMouseFunc(GerenciaMouse);          //Ativa o botao direito
   glutMainLoop();
   //Final das funcoes do OpenGL

   //    limpando a memoria e fechando o fmod (Som)
   //   FSOUND_Sample_Free(samp1); // limpa a memoria ultilizada pelo ponteiro do sample
   //   FSOUND_Close();            // encerra a API FMOD
}
