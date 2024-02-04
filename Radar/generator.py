#!/usr/bin/python3
import random
import sys

def generator(nb_avions, nb_tours, name):
    with open(name, 'w') as fichier:
        for _ in range(nb_avions):
            start_x, start_y = random.randint(30, 1870), random.randint(30, 1020)
            end_x, end_y = random.randint(30, 1870), random.randint(30, 1020)
            speed = random.randint(50, 70)
            wait = random.randint(0, 10)
            ligne = f"A  {start_x}  {start_y}  {end_x}  {end_y}  {speed}  {wait}\n"
            fichier.write(ligne)

        for _ in range(nb_tours):
            x, y = random.randint(30, 1870), random.randint(30, 1020)
            radius = random.randint(10, 500)
            ligne = f"T  {x}  {y}  {radius}\n"
            fichier.write(ligne)

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python script.py <nb_avions> <nb_tours> <nom_fichier>")
        sys.exit(84)

    nb_avions = int(sys.argv[1])
    nb_tours = int(sys.argv[2])
    name = sys.argv[3]

    generator(nb_avions, nb_tours, name)

