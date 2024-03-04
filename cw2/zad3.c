#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Point {
	int x;
	int y;
};

struct Rectangle {
	struct Point p1;
	struct Point p2;
	struct Point p3;
	struct Point p4;
};

float odlegloscPunktow(struct Point p1, struct Point p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void poleProstokata(struct Rectangle* r) {
	float dlugoscBoku = odlegloscPunktow(r->p1, r->p2);
	float dlugoscBoku2 = odlegloscPunktow(r->p2, r->p3);
	float pole = dlugoscBoku * dlugoscBoku2;
	printf("Pole prostokata to %f", pole);
}

void obwodProstokata(struct Rectangle* r) {
	float dlugoscBoku = odlegloscPunktow(r->p1, r->p2);
	float dlugoscBoku2 = odlegloscPunktow(r->p2, r->p3);
	printf("Obwod prostokata to %f", 2 * dlugoscBoku + 2 * dlugoscBoku2);
}

void changePoint(struct Point *p, int x, int y) {
	p->x = x;
	p->y = y;
}

int main() {
	struct Point po1;
	po1.x = 5;
	po1.y = 7;
	printf("%d %d\n", po1.x, po1.y);
	changePoint(&po1, 2, 5);
	printf("%d %d\n", po1.x, po1.y);
	struct Point po2;
	po2.x = 7;
	po2.y = 5;
	struct Point po3;
	po3.x = 7;
	po3.y = 2;
	struct Point po4;
	po4.x = 2;
	po4.y = 2;
	struct Rectangle r;
	r.p1 = po1;
	r.p2 = po2;
	r.p3 = po3;
	r.p4 = po4;
	printf("%d\n", r.p1.x);
	poleProstokata(&r);
	obwodProstokata(&r);
	return 0;
}