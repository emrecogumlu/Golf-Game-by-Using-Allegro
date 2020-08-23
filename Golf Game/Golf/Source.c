#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>



int main()
{

	
	etiket:
	al_init_primitives_addon();
	


	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_TIMER* timer;




	al_init();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();


	display = al_create_display(1200, 500);
	timer = al_create_timer(0.1);
	queue = al_create_event_queue();
	al_start_timer(timer);

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));


	al_clear_to_color(al_map_rgb(0, 255, 0));

	srand(time(NULL));

	

	float ball_xpos = 50 + rand() % 1100;
	float	ball_ypos = 50 + rand() % 450;
	float line_xpos_1 = ball_xpos;
	float	line_ypos_1 = ball_ypos;
	float line_xpos_2 = ball_xpos + 45;
	float line_ypos_2 = ball_ypos;
	int direction_code = 0;

	float hole_xpos = 50 + rand() % 1100;
	float hole_ypos = 50 + rand() % 450;

	


	while ((ball_xpos <= hole_xpos - 18 || ball_xpos >= hole_xpos + 18) || (ball_ypos <= hole_ypos - 18 || ball_ypos >= hole_ypos + 18))
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);


		if (ev.keyboard.keycode >= ALLEGRO_KEY_1 && ev.keyboard.keycode <= ALLEGRO_KEY_7)
		{
			int i;
			int hardness = (ev.keyboard.keycode - ALLEGRO_KEY_1 + 1);


			for (i = 1; i <= hardness * 1000; i++)
			{
				if (direction_code == 6)
				{
					ball_xpos += 0.01;


				}

				else if (direction_code == 9)
				{
					ball_xpos += 0.01;
					ball_ypos -= 0.01;

				}

				else if (direction_code == 8)
				{

					ball_ypos -= 0.01;

				}

				else if (direction_code == 7)
				{
					ball_xpos -= 0.01;
					ball_ypos -= 0.01;

				}

				else if (direction_code == 4)
				{
					ball_xpos -= 0.01;


				}

				else if (direction_code == 1)
				{
					ball_xpos -= 0.01;
					ball_ypos += 0.01;

				}

				else if (direction_code == 2)
				{

					ball_ypos += 0.01;

				}

				else if (direction_code == 3)
				{
					ball_xpos += 0.01;
					ball_ypos += 0.01;

				}


				al_rest(0.00001);
			}

			al_clear_to_color(al_map_rgb(0, 255, 0));



			line_xpos_1 = ball_xpos;
			line_ypos_1 = ball_ypos;
			al_draw_filled_circle(ball_xpos, ball_ypos, 10, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(hole_xpos, hole_ypos, 25, al_map_rgb(0, 0, 0));
		}



		al_flip_display();
		


		if (ev.keyboard.keycode == ALLEGRO_KEY_PAD_6)
		{
			//printf("test");
			direction_code = 6;

			al_clear_to_color(al_map_rgb(0, 255, 0));
			line_xpos_2 = ball_xpos + 45;
			line_ypos_2 = ball_ypos;

			al_draw_filled_circle(ball_xpos, ball_ypos, 10, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(hole_xpos, hole_ypos, 25, al_map_rgb(0, 0, 0));
			al_draw_line(line_xpos_1, line_ypos_1, line_xpos_2, line_ypos_2, al_map_rgb(0, 0, 0), 1);






			al_flip_display();


		}



		


		else if (ev.keyboard.keycode == ALLEGRO_KEY_PAD_9)
		{
			direction_code = 9;
			al_clear_to_color(al_map_rgb(0, 255, 0));
			line_xpos_2 = ball_xpos + 45;
			line_ypos_2 = ball_ypos - 45;

			al_draw_filled_circle(ball_xpos, ball_ypos, 10, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(hole_xpos, hole_ypos, 25, al_map_rgb(0, 0, 0));
			al_draw_line(line_xpos_1, line_ypos_1, line_xpos_2, line_ypos_2, al_map_rgb(0, 0, 0), 1);

			al_flip_display();

		}
		

		else if (ev.keyboard.keycode == ALLEGRO_KEY_PAD_8)
		{
			direction_code = 8;
			al_clear_to_color(al_map_rgb(0, 255, 0));
			line_xpos_2 = ball_xpos;
			line_ypos_2 = ball_ypos - 45;

			al_draw_filled_circle(ball_xpos, ball_ypos, 10, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(hole_xpos, hole_ypos, 25, al_map_rgb(0, 0, 0));
			al_draw_line(line_xpos_1, line_ypos_1, line_xpos_2, line_ypos_2, al_map_rgb(0, 0, 0), 1);
			al_flip_display();
		}
		

		else if (ev.keyboard.keycode == ALLEGRO_KEY_PAD_7)
		{
			direction_code = 7;
			al_clear_to_color(al_map_rgb(0, 255, 0));
			line_xpos_2 = ball_xpos - 45;
			line_ypos_2 = ball_ypos - 45;

			al_draw_filled_circle(ball_xpos, ball_ypos, 10, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(hole_xpos, hole_ypos, 25, al_map_rgb(0, 0, 0));
			al_draw_line(line_xpos_1, line_ypos_1, line_xpos_2, line_ypos_2, al_map_rgb(0, 0, 0), 1);
			al_flip_display();
		}

		else if (ev.keyboard.keycode == ALLEGRO_KEY_PAD_4)
		{
			direction_code = 4;
			al_clear_to_color(al_map_rgb(0, 255, 0));
			line_xpos_2 = ball_xpos - 45;
			line_ypos_2 = ball_ypos;

			al_draw_filled_circle(ball_xpos, ball_ypos, 10, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(hole_xpos, hole_ypos, 25, al_map_rgb(0, 0, 0));
			al_draw_line(line_xpos_1, line_ypos_1, line_xpos_2, line_ypos_2, al_map_rgb(0, 0, 0), 1);
			al_flip_display();
		}

		else if (ev.keyboard.keycode == ALLEGRO_KEY_PAD_1)
		{
			direction_code = 1;
			al_clear_to_color(al_map_rgb(0, 255, 0));
			line_xpos_2 = ball_xpos - 45;
			line_ypos_2 = ball_ypos + 45;

			al_draw_filled_circle(ball_xpos, ball_ypos, 10, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(hole_xpos, hole_ypos, 25, al_map_rgb(0, 0, 0));
			al_draw_line(line_xpos_1, line_ypos_1, line_xpos_2, line_ypos_2, al_map_rgb(0, 0, 0), 1);
			al_flip_display();
		}

		else if (ev.keyboard.keycode == ALLEGRO_KEY_PAD_2)
		{
			direction_code = 2;
			al_clear_to_color(al_map_rgb(0, 255, 0));
			line_xpos_2 = ball_xpos;
			line_ypos_2 = ball_ypos + 45;

			al_draw_filled_circle(ball_xpos, ball_ypos, 10, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(hole_xpos, hole_ypos, 25, al_map_rgb(0, 0, 0));
			al_draw_line(line_xpos_1, line_ypos_1, line_xpos_2, line_ypos_2, al_map_rgb(0, 0, 0), 1);
			al_flip_display();
		}

		else if (ev.keyboard.keycode == ALLEGRO_KEY_PAD_3)
		{
			direction_code = 3;
			al_clear_to_color(al_map_rgb(0, 255, 0));
			line_xpos_2 = ball_xpos + 45;
			line_ypos_2 = ball_ypos + 45;

			al_draw_filled_circle(ball_xpos, ball_ypos, 10, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(hole_xpos, hole_ypos, 25, al_map_rgb(0, 0, 0));
			al_draw_line(line_xpos_1, line_ypos_1, line_xpos_2, line_ypos_2, al_map_rgb(0, 0, 0), 1);
			al_flip_display();
		}

	}


	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font50 = al_load_font("arial.ttf", 50, NULL);
	ALLEGRO_SAMPLE* soundeffect = al_load_sample("soundeffect.wav");

	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_draw_text(font50, al_map_rgb(255, 0, 255), 150, 200, 0, "CONGRATULATIONS, YOU WON!");

	
	al_reserve_samples(1);
    al_play_sample(soundeffect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

	al_flip_display();
	al_destroy_font(font50);
	
	al_rest(3.0);
	al_destroy_display(display);
	

	goto etiket;



	system("Pause");

	return 0;




}