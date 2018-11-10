#include<iostream>
#include<string>
#include <windows.h>
#include <mmsystem.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
using namespace std;

int main() {
	bool go = true;
	string answer;
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_BITMAP*bitmap = NULL;

		if (!al_init()) {
			fprintf(stderr, "Failed to initialize allegro.\n");
			return 1;
		}
		if (!al_init_image_addon()) {
			cout << "Failed to initialize al_init_image_addon!" << endl;
				
			return 0;
		}
		display = al_create_display(1000, 1000);

		bitmap = al_load_bitmap("jukebox.jpg");

		

		al_draw_bitmap(bitmap, 0, 0,0);
		al_flip_display();
	while (go == true) {
		cout << "what song do you want to play? 1,2,3,4, or 5, or quit to leave." << endl;
		getline(cin, answer);
		if (answer.compare("1") == 0) {
			PlaySound(TEXT("africa.wav"), NULL, SND_FILENAME);
		}
		if (answer.compare("2") == 0) {
			PlaySound(TEXT("all stars.wav"), NULL, SND_FILENAME);
		}
		if (answer.compare("3") == 0) {
			PlaySound(TEXT("fireflies.wav"), NULL, SND_FILENAME);
		}
		if (answer.compare("4") == 0) {
			PlaySound(TEXT("ocean man.wav"), NULL, SND_FILENAME);
		}
		if (answer.compare("5") == 0) {
			PlaySound(TEXT("shooting stars.wav"), NULL, SND_FILENAME);
		}
		if (answer.compare("q") == 0 || answer.compare("Q") == 0 || answer.compare("quit") == 0 || answer.compare("Quit") == 0) {
			go = false;
		}
	}
}