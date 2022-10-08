// NAMA		: ADITYA FAIZ
// NRP		: 5023221014
// Jurusan	: TEKNIK BIOMEDIK


#include <iostream>
#include <cmath>
using namespace std;

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

int mencari_V0(int v, int losses)
{
	v -= losses;
  	return v;
}

int speed_dgn_loss(int v)
{
    int losses;
	if (v >= 1 && v <= 10)
    {
        losses = 1;
    }

    else if (v >= 11 && v <= 20)
    {
        losses = 3;
    }

    else if (v >= 21 && v <= 30)
    {
        losses = 5;
    }
    return losses;
}

int main() {
    int v;
    float jarak, Vtangensial;
  	cin >> v;
    jarak = (pow(mencari_V0(v,speed_dgn_loss(v)),2)* sin(SUDUT*3.14159*2/180) / GRAVITASI) - START_PENGUKURAN;
    jarak = round(jarak);
    Vtangensial = sqrt(jarak * GRAVITASI / sin(SUDUT*3.14159*2/180)) + speed_dgn_loss(v);
  	cout << jarak << " " << Vtangensial << endl;
    return 0;
}
