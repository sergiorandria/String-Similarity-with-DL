import random

# Lists of common Malagasy first names and last names
malagasy_first_names = [
    "Andry", "Rakoto", "Jean", "Marie", "Nirina", "Hery", "Lova", "Solo", "Faniry", "Mamy",
    "Hanta", "Tojo", "Fara", "Lala", "Tiana", "Iary", "Voahangy", "Ravo", "Tsiry", "Feno",
    "Haja", "Soa", "Tahina", "Sitraka", "Faly", "Hery", "Lanto", "Miora", "Rija", "Sambatra",
    "Tovo", "Aina", "Harinjaka", "Manjaka", "Rasoa", "Rabe", "Ravo", "Tsiky", "Fara", "Lova",
    "Ando", "Rina", "Tia", "Fara", "Hery", "Lanto", "Miora", "Rija", "Sambatra", "Tovo"
]

malagasy_last_names = [
    "Rakotomalala", "Randrianarisoa", "Rasoa", "Rakoto", "Rabe", "Randrianjafy", "Razafy", "Ratsimba",
    "Rakotondrabe", "Rakotoniaina", "Rakotovao", "Rakotondrazaka", "Rakotomalala", "Randrianarisoa",
    "Rasoa", "Rakoto", "Rabe", "Randrianjafy", "Razafy", "Ratsimba", "Rakotondrabe", "Rakotoniaina",
    "Rakotovao", "Rakotondrazaka", "Rakotomalala", "Randrianarisoa", "Rasoa", "Rakoto", "Rabe",
    "Randrianjafy", "Razafy", "Ratsimba", "Rakotondrabe", "Rakotoniaina", "Rakotovao", "Rakotondrazaka",
    "Rakotomalala", "Randrianarisoa", "Rasoa", "Rakoto", "Rabe", "Randrianjafy", "Razafy", "Ratsimba",
    "Rakotondrabe", "Rakotoniaina", "Rakotovao", "Rakotondrazaka"
]

# Function to introduce misspellings
def add_misspelling(name):
    if len(name) == 0:
        return name
    # Randomly decide whether to introduce a misspelling (e.g., 30% chance)
    if random.random() < 0.18:
        name = list(name)
        # Randomly choose a type of misspelling
        action = random.choice(["replace", "delete", "insert"])
        if action == "replace":
            # Replace a random character with another random character
            index = random.randint(0, len(name) - 1)
            name[index] = random.choice("abcdefghijklmnopqrstuvwxyz")
        elif action == "delete":
            # Delete a random character
            index = random.randint(0, len(name) - 1)
            del name[index]
        elif action == "insert":
            # Insert a random character at a random position
            index = random.randint(0, len(name))
            name.insert(index, random.choice("abcdefghijklmnopqrstuvwxyz"))
        name = "".join(name)
    return name

# Function to generate a random Malagasy name
def generate_malagasy_name():
    first_name = random.choice(malagasy_first_names)
    medium_name = random.choice(malagasy_first_names)
    last_name = random.choice(malagasy_last_names)
    # Add misspellings to the first and last names
    first_name = add_misspelling(first_name)
    medium_name = add_misspelling(medium_name)
    last_name = add_misspelling(last_name)
    return f"{last_name} {medium_name} {first_name}"

# Generate 1000 random Malagasy names
malagasy_names = [generate_malagasy_name() for _ in range(1000000)]

# Write the names to a text file
with open("malagasy_names.txt", "w") as file:
    for name in malagasy_names:
        file.write(name + "\n")

print("1000 Malagasy names (with some misspellings) have been generated and saved to 'malagasy_names.txt'.")