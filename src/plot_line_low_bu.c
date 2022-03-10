#include "plot_line_low.h"

void plot_line_low(int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0; // Dit is de delta van x
	int dy = y1 - y0; // Dit is de delta van y
	// Deze waardes hebben we nodig om de helling te berekenen.
	// En voor de decision parameter forumule

	int yi = 1; // Dit heeft te maken met of de lijn van boven naar beneden gaat, of andersom.

	// Als dy kleiner is dan 0 -> dan is y0 groter dan y1 ->
	// en loopt de lijn van boven naar beneden
	if (dy < 0)
	{
		yi = -1;
		dy = dy * -1; // Dit maakt dy negatief. Ook dit heeft te maken met de richting van de lijn.
	}

	int D = (2 * dy) - dx; // Decision parameter. Hiermee maak je de 'decision' of je een pixel omhoog moet inkleuren voor de lijn, of dat de pixel op dezelfde hoogte moet blijven. Deze leipe formule is gemaakt omdat het breuken eruit haalt. En zorgt dat alles werkt met ints.
	int y = y0; // Dit is een variabel om y0 in op te slaan. En word later ook gebruikt om y+1 in op te slaan, in het geval dat de decision parameter groter is dan 0.

	int x0_dup = x0;
	while (x0_dup < x1)
	{
		// my_mlx_pixel_put(&img, x0_dup, y, 0x00FF0000);
		printf("(%i, %i)\n", x0_dup, y);

		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else
		{
			D = D + 2 * dy;
		}
		x0_dup++;
	}
}

int main(void)
{
	int x0 = 0;
	int y0 = 0;
	int x1 = 10;
	int y1 = -5;

	plot_line_low(x0, y0, x1, y1);
	return (0);
}