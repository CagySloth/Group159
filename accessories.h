#ifndef ACCESSORIES_H
#define ACCESSORIES_H

void pickup(accessories * &ptr, accessories * &p);
void health_accessories(accessories * &ptr, int d);
void attack_accessories(accessories * ptr, int d);
void defense_accessories(accessories * ptr, int d);
void negative_health_accessories(accessories * ptr, int d);
void negative_attack_accessories(accessories * ptr, int d);
void negative_defense_accessories(accessories * ptr, int d);
void accessories_drop(accessories * ptr, int d);

#endif