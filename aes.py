from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

# Generate a random 256-bit (32-byte) AES key
key = get_random_bytes(32)

# Initialize the AES cipher object in ECB mode
cipher = AES.new(key, AES.MODE_ECB)

# Encrypt a message
message = input("Enter a message:- ")
message_bytes = message.encode()
ciphertext = cipher.encrypt(pad(message_bytes, AES.block_size))

print("Encrypted message:", ciphertext)

# Decrypt the message
decipher = AES.new(key, AES.MODE_ECB)
decrypted_message = unpad(decipher.decrypt(ciphertext), AES.block_size).decode()

print("Decrypted message:", decrypted_message)