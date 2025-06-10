def search_character_in_names(name_list, target_char):
    """Search for a character in each string in the name list and print matches."""
    print(f"Searching for character '{target_char}' in names...\n")

    for name in name_list:
        if target_char in name:
            print(f"'{target_char}' found in: {name}")
        else:
            print(f"'{target_char}' not found in: {name}")

# Example input
names = ["aShu", "aA", "aAa", "xyz", "Alpha"]

# Character to search
character = input("Enter a character to search: ").strip()

# Validate input
if len(character) != 1:
    print("Please enter exactly one character.")
else:
    search_character_in_names(names, character)
