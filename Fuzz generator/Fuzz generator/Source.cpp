#include <stdio.h>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<random>
#include<ctime>

int main(int argc, char **argv) {
	bool go = true;
	
	ALLEGRO_DISPLAY *display = NULL;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
		
	if (!al_init_primitives_addon()) {
		fprintf(stderr, "failed to initialize primitives!\n");
		return -1;
	}
	display = al_create_display(500, 500);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	srand(time(NULL));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	while (go == true) {
	// generate a random x pos
	//generate a random y pos
		for (int i = 1; i <= 255; i++) {
			for (int j = 1; j <= 255; j++) {
				for (int k = 1; k <= 255; k++) {
					al_draw_filled_circle(rand()%500, rand() % 500, .9, al_map_rgb(i, j, k));

					al_flip_display();
				}
			}
		}
		

	
	}
	
	

	al_destroy_display(display);

	return 0;
}