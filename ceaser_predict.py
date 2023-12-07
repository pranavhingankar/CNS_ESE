# ciesercypher.py
import string
import nltk
nltk.download('words')

from nltk.corpus import words

english_word_set = set(words.words())


def caesar_encrypt(plain_text, key):
    encrypted_text = ""
    for char in plain_text:
        if char.isalpha():
            shift = ord('a') if char.islower() else ord('A')
            encrypted_text += chr((ord(char) - shift + key) % 26 + shift)
        else:
            encrypted_text += char
    return encrypted_text

def caesar_decrypt(cipher_text, key):
    decrypted_text = ""
    for char in cipher_text:
        if char.isalpha():
            shift = ord('a') if char.islower() else ord('A')
            decrypted_text += chr((ord(char) - shift - key) % 26 + shift)
        else:
            decrypted_text += char 
    return decrypted_text

def all_combinations(cipher_text):
    combinations = []
    for key in range(26):
        decrypted_text = caesar_decrypt(cipher_text, key)
        combinations.append((key, decrypted_text))
    return combinations

def is_english_word(word):
    return word.lower() in english_word_set

def meaningful_decryptions(cipher_text):
    decryptions = []
    for key in range(26):
        decrypted_text = caesar_decrypt(cipher_text, key)
        words = decrypted_text.split()
        meaningful_words = [word for word in words if is_english_word(word)]
        if meaningful_words:
            probability = len(meaningful_words) / len(words)
            decryptions.append((key, decrypted_text, probability))
    decryptions.sort(key=lambda x: x[2], reverse=True)  # Sort by probability in descending order
    return decryptions


def main():
    while True:
        print("\nMenu:")
        print("1. Encrypt Plain Text")
        print("2. Decrypt Cipher Text")
        print("3. Show All Combinations")
        print("4. Show Meaningful Decryptions")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            plain_text = input("Enter plain text: ")
            key = int(input("Enter key: "))
            encrypted_text = caesar_encrypt(plain_text, key)
            print("Encrypted Text:", encrypted_text)

        elif choice == 2:
            cipher_text = input("Enter cipher text: ")
            key = int(input("Enter key: "))
            decrypted_text = caesar_decrypt(cipher_text, key)
            print("Decrypted Text:", decrypted_text)

        elif choice == 3:
            cipher_text = input("Enter cipher text: ")
            combinations = all_combinations(cipher_text)
            for key, decrypted_text in combinations:
                print(f"Key {key}: {decrypted_text}")

        elif choice == 4:
            cipher_text = input("Enter cipher text: ")
            decryptions = meaningful_decryptions(cipher_text)
            for key, decrypted_text, probability in decryptions:
                if probability > 0.5:
                    print(f"Key {key}: {decrypted_text} (Probability: {probability:.2f})")

        elif choice == 5:
            print("Exiting...")
            break

        else:
            print("Invalid choice. Please choose a valid option.")

if __name__=='__main__':
    main()