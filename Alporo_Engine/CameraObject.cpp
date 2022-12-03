#include "CameraObject.h"
#include "imgui.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_events.h"

CObject::CObject()
{

	CreateCamBuffer();

	X = float3(1.0f, 0.0f, 0.0f);
	Y = float3(0.0f, 1.0f, 0.0f);
	Z = float3(0.0f, 0.0f, 1.0f);

	Position = float3(0.0f, 0.0f, 5.0f);
	Reference = float3(0.0f, 0.0f, 0.0f);

}

CObject::CObject(GameObject* GOCamera) : Component(GOCamera)
{
	GObjectSelected = GOCamera;
	type = Type::CamObject;


	//aixo es el k fallava joder
	//CalculateViewMatrices();



}

bool CObject::Start()
{

	return false;
}

CObject::~CObject()
{
	glDeleteFramebuffers(1, &cameraBuffer2);
	glDeleteFramebuffers(1, &frameBuffer2);
	glDeleteFramebuffers(1, &bufferObj2);
}

void CObject::GameCameraMovement(GameObject* SecCamera)
{

	
	
	newPos = SecCamera->transform->position;
	Position = newPos;
	int hola = 0;
	// Recalculate matrix -------------
	CalculateViewMatrices();

}

bool CObject::CleanUp()
{
	return false;
}

void CObject::CreateCamBuffer()
{
	glGenFramebuffers(1, &frameBuffer2);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer2);

	glGenTextures(1, &cameraBuffer2);
	glBindTexture(GL_TEXTURE_2D, cameraBuffer2);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, cameraBuffer2, 0);

	glGenRenderbuffers(1, &bufferObj2);
	glBindRenderbuffer(GL_RENDERBUFFER, bufferObj2);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, SCREEN_WIDTH, SCREEN_HEIGHT);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, bufferObj2);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

float* CObject::GetViewMatrix()
{
	return 0;//&ViewMatrix;
}

void CObject::CalculateViewMatrices()
{

	//ViewMatrix = mat4x4(X.x, Y.x, Z.x, 0.0f, X.y, Y.y, Z.y, 0.0f, X.z, Y.z, Z.z, 0.0f, -dot(X, Position), -dot(Y, Position), -dot(Z, Position), 1.0f);
	//ViewMatrixInverse = inverse(ViewMatrix);

}