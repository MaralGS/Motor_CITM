#pragma once

#include "Module.h"
#include "Globals.h"

struct Cilindre
{
    bool DrawCilindre = false;
    float Leght = 3;
    float Radius = 1;
};

struct QUad
{
    float v0[3] = { 0.f, 1.f, 0.f };
    float v1[3] = { 0.f, 0.f, 0.f };
    float v2[3] = { 0.f, 0.f, 1.f };
    float v3[3] = { 0.f, 1.f, 1.f };
    float v4[3] = { 1.f, 1.f, 0.f };
    float v5[3] = { 1.f, 1.f, 1.f, };
    float v6[3] = { 1.f, 0.f, 1.f, };
    float v7[3] = { 1.f, 0.f, 0.f, };


};

class ModuleOPGPrimitives : public Module
{
public:
	ModuleOPGPrimitives(Application* app, bool start_enabled = true);
	~ModuleOPGPrimitives();

	bool Start();
	bool PostUpdate();
	update_status Update(float dt);
	bool PreUpdate();
	bool CleanUp();
    void DrawQuad();
    void DrawCilind(float radius, float leght);
    void DrawPiramid();
    void DrawSphere(float radius);

    bool DrawQuadra = false;
    bool DrawPiramide = false;

    Cilindre CilindreStats;
private:

    float Quad[108] = { 0.f,1.f,0.f, //X Cara1 
                     0.f,0.f,0.f,//Y 
                     0.f,0.f,1.f,//Z

                     0.0f,1.f,1.f,
                     0.f,1.f,0.f,
                     0.f,0.f,1.f,

                     1.f,1.f,0.f, //Cara2
                     0.f,1.f,0.f,
                     0.f,1.f,1.f,

                     1.f,1.f,0.f,
                     0.f,1.f,1.f,
                     1.f,1.f,1.f,

                     0.f,0.f,1.f, // Cara3 
                     1.f,0.f,1.f,
                     0.f,1.f,1.f,

                     1.f,0.f,1.f,
                     1.f,1.f,1.f,
                     0.f,1.f,1.f,

                     1.f, 0.f, 1.f,// Cara4
                     1.f, 0.f, 0.f,
                     1.f, 1.f, 0.f,

                     1.f, 0.f, 1.f,
                     1.f, 1.f, 0.f,
                     1.f, 1.f, 1.f,

                     0.f, 0.f, 0.f, // cara5
                     0.f, 1.f, 0.f,
                     1.f, 1.f, 0.f,

                     0.f, 0.f, 0.f,
                     1.f, 1.f, 0.f,
                     1.f, 0.f, 0.f,

                     0.f, 0.f, 0.f, // cara6
                     1.f, 0.f, 0.f,
                     1.f, 0.f, 1.f,

                     1.f, 0.f, 1.f,
                     0.f, 0.f, 1.f,
                     0.f, 0.f, 0.f,
    };

    float Triangle[36] = { 0.f,0.f,0.f, //X Cara1 
                     2.f,0.f,0.f,//Y 
                     1.f,2.f,-1.f,//Z


                     2.f,0.f,-2.f, //Cara2
                     1.f,2.f,-1.f,
                     2.f,0.f,0.f,

                     2.f,0.f,-2.f, // Cara3 
                     0.f,0.f,-2.f,
                     1.f,2.f,-1.f,

                     0.f,0.f,-2.f, // Cara4 
                     0.f,0.f,-0.f,
                     1.f,2.f,-1.f,
    };

    float TriangleBase[18] = {

                     0.f, 0.f, -2.f,
                     2.f, 0.f, -2.f,
                     2.f, 0.f, 0.f,

                     0.f, 0.f, -2.f,
                     2.f, 0.f, 0.f,
                     0.f, 0.f, 0.f,
    };


};
