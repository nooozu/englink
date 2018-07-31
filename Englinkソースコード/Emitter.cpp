#include "Emitter.h"

Emitter::Emitter()
{

}

Emitter::~Emitter()
{
	p_array.clear();
	r_array.clear();
}

void Emitter::CreateParticle(float fx, float fy, int num, Color c)
{
	MyParticle* pParticle = new MyParticle;
	for (int i = 0; i < num; i++) {
		pParticle->Initialize(fx, fy, 2);
		pParticle->SetColor(c);
		p_array.push_back(*pParticle);
	}
	delete pParticle;
	pParticle = NULL;
}

void Emitter::CreateRipple(float fx, float fy, float fr)
{
	MyRipple* pRipple = new MyRipple;
	pRipple->Initialize(fx, fy, fr);
	pRipple->SetColor(Color(255, 255, 255));
	r_array.push_back(*pRipple);
	delete pRipple;
	pRipple = NULL;
}

void Emitter::Update()
{
	for (int i = 0; i < p_array.size();) {
		p_array[i].Update();

		if (!p_array[i].GetFlag()) {
			p_array.erase(p_array.begin() + i);
		}
		else {
			i++;
		}
	}

	for (int i = 0; i < r_array.size();) {
		r_array[i].Update();

		if (!r_array[i].GetFlag()) {
			r_array.erase(r_array.begin() + i);
		}
		else {
			i++;
		}
	}
}

void Emitter::Draw()
{
	for (int i = 0; i < p_array.size(); i++) {
		p_array[i].Draw();
	}

	for (int i = 0; i < r_array.size(); i++) {
		r_array[i].Draw();
	}
}