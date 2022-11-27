#include<iostream>

using namespace std;

struct box{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show(box);
void cal_volume(box*);

int main(){

	box laokang = { "slslslls", 12.0f, 13.0f,15.5f};
	cal_volume(&laokang);
	show(laokang);


}

void show(box B){
	cout << "The imformation of this box:\n";
	cout << "maker: " << B.maker << endl;
	cout << "height: " << B.height << endl;
	cout << "width: " << B.width << endl;
	cout << "length: " << B.length << endl;
	cout << "volume: " << B.volume << endl;
}

void cal_volume(box * pb){
	pb->volume = pb->height * pb->width * pb->length;
}

