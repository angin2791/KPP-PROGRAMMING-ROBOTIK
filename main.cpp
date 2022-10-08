// NAMA		: ADITYA FAIZ
// NRP		: 5023221014
// Jurusan	: TEKNIK BIOMEDIK


#include <iostream>
#include <cmath>
using namespace std;

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

int mencari_V0(int input, int losses)
{
	input -= losses;
  	return input;
}

int speed_dgn_loss(int input)
{
    int losses;
	if (input >= 1 && input <= 10)
    {
        losses = 1;
    }

    else if (input >= 11 && input <= 20)
    {
        losses = 3;
    }

    else if (input >= 21 && input <= 30)
    {
        losses = 5;
    }
    return losses;
}

int main() {
    int input;
    float jarak;
    float Vtangensial;
  	cin >> input;
    jarak = (pow(mencari_V0(input,speed_dgn_loss(input)),2)* sin(SUDUT*3.14159*2/180) / GRAVITASI) - START_PENGUKURAN;
    jarak = round(jarak);
    Vtangensial = sqrt(jarak * GRAVITASI / sin(SUDUT*3.14159*2/180)) + speed_dgn_loss(input);
  	cout << jarak << " " << Vtangensial << endl;
    return 0;
}
